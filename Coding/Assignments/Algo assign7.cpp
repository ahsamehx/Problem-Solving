#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <climits>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class Value>
struct Array
{
	int n, sz;
	Value* arr;

	void Initialize() {
		n = 0;
		sz = 1;
		arr = new Value[sz];
	}

	void Destroy() {
		delete[] arr;
	}

	void AddLast(Value v) {
		if (n == sz) {
			sz *= 2;
			Value* newArr = new Value[sz];
			memcpy(newArr, arr, n * sizeof(Value));
			delete[] arr;
			arr = newArr;
		}
		arr[n++] = v;
	}

	void RemoveLast() {
		if (n > 0) n--;
	}

	Value& operator[](int i) {
		return arr[i];
	}
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class Elem>
struct Heap
{
	int* pos;
	Array<Elem> a;
	bool (*IsBefore)(Elem&, Elem&);

	void Initialize(bool (*_IsBefore)(Elem&, Elem&), int n) {
		IsBefore = _IsBefore;
		a.Initialize();
		pos = new int[n];
		for (int i = 0; i < n; i++) pos[i] = -1;
	}

	void Destroy() {
		delete[] pos;
		a.Destroy();
	}

	int Child(int i) { return 2 * i + 1; }

	int Parent(int i) { return (i - 1) / 2; }

	Elem GetFirst() { return a[0]; }

	Elem RetrieveFirst() {
		Elem first = a[0];
		a[0] = a[a.n - 1];
		pos[a[0].v] = 0;
		a.RemoveLast();
		MoveDown(0);
		pos[first.v] = -1;
		return first;
	}

	void Add(Elem e) {
		pos[e.v] = a.n;
		a.AddLast(e);
		MoveUp(a.n - 1);
	}

	void MoveUp(int ind) {
		while (ind > 0 && IsBefore(a[ind], a[Parent(ind)])) {
			swap(a[ind], a[Parent(ind)]);
			pos[a[ind].v] = ind;
			ind = Parent(ind);
		}
		pos[a[ind].v] = ind;
	}

	void MoveDown(int ind) {
		while (true) {
			int left = Child(ind);
			int right = left + 1;
			int smallest = ind;

			if (left < a.n && IsBefore(a[left], a[smallest])) smallest = left;
			if (right < a.n && IsBefore(a[right], a[smallest])) smallest = right;
			if (smallest == ind) break;

			swap(a[ind], a[smallest]);
			pos[a[ind].v] = ind;
			ind = smallest;
		}
		pos[a[ind].v] = ind;
	}
};


struct Edge {
	int v, w;
};

struct Node {
	Array<Edge> adj;

	void Initialize() { adj.Initialize(); }

	void Destroy() { adj.Destroy(); }
};

struct Graph {
	int n;
	Node* nodes;

	void Initialize(int _n) {
		n = _n;
		nodes = new Node[n];
		for (int i = 0; i < n; i++) nodes[i].Initialize();
	}

	void Destroy() {
		for (int i = 0; i < n; i++) nodes[i].Destroy();
		delete[] nodes;
	}
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool IsBefore(Edge& a, Edge& b) { return a.w < b.w; }


void Dijkstra(Graph& graph, int src, Array<int>& dist) {
	int n = graph.n;

	dist.Initialize();
	for (int i = 0; i < n; i++) dist.AddLast(INT_MAX);
	dist[src] = 0;

	Heap<Edge> pq;
	pq.Initialize(IsBefore, n);
	pq.Add({src, 0});

	while (pq.a.n > 0) {
		Edge e = pq.RetrieveFirst();
		int u = e.v;
		if (e.w > dist[u]) continue;

		for (int i = 0; i < graph.nodes[u].adj.n; i++) {
			Edge& edge = graph.nodes[u].adj[i];
			int v = edge.v, weight = edge.w;

			if (dist[u] + weight < dist[v]) {
				dist[v] = dist[u] + weight;
				pq.Add({v, dist[v]});
			}
		}
	}

	pq.Destroy();
}


int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m, src, dest;
		cin >> n >> m >> src >> dest;

		Graph graph;
		graph.Initialize(n);

		for (int i = 0; i < m; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			graph.nodes[u].adj.AddLast({v, w});
			graph.nodes[v].adj.AddLast({u, w});
		}

		Array<int> dist;
		Dijkstra(graph, src, dist);

		if (dist[dest] == INT_MAX)
			cout << "unreachable" << endl;
		else
			cout << dist[dest] << endl;

		dist.Destroy();
		graph.Destroy();
	}

	return 0;
}