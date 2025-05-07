#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class Value>
struct Array {
    int n, sz;
    Value* arr;

    void Initialize() {
        n = 0;  // Current number of elements
        sz = 1;  // Initial size of the array
        arr = (Value*)malloc(sz * sizeof(Value));  // Allocate memory
    }

    void Destroy() {
        free(arr);  // Free allocated memory
    }

    void AddLast(Value v) {
        if (n == sz) {  // If the array is full, double its size
            sz *= 2;
            arr = (Value*)realloc(arr, sz * sizeof(Value));
        }
        arr[n++] = v;  // Add the new element and increment the count
    }

    Value& operator[](int i) {
        return arr[i];  // Return the element at index i
    }
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct Node {
    Array<int> adj;

    void Initialize() {
        adj.Initialize();  // Initialize the adjacency list
    }

    void Destroy() {
        adj.Destroy();  // Destroy the adjacency list
    }
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct Graph {
    int n;
    Node* nodes;

    void Initialize(int _n) {
        n = _n;  // Number of nodes in the graph
        nodes = (Node*)malloc(n * sizeof(Node));  // Allocate memory for nodes

        for (int i = 0; i < n; i++) {
            nodes[i].Initialize();  // Initialize each node's adjacency list
        }
    }

    void Destroy() {
        for (int i = 0; i < n; i++) {
            nodes[i].Destroy();  // Destroy each node's adjacency list
        }
        free(nodes);  // Free the memory allocated for nodes
    }
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class Type>
struct Queue {
    int f, n, size;
    Type* elems;

    void Initialize(int _size) {
        size = _size;
        n = 0;  // No elements initially
        f = 0;  // Front pointer
        elems = (Type*)malloc(size * sizeof(Type));  // Allocate memory for the queue
    }

    void Destroy() {
        free(elems);  // Free the allocated memory for the queue
    }

    void Add(Type t) {
        elems[(f + n) % size] = t;  // Add element at the correct position (mod size to wrap around)
        n++;  // Increase the size of the queue
    }

    Type Pop() {
        Type ret = elems[f];  // Get the front element
        f = (f + 1) % size;  // Move the front pointer forward
        n--;  // Decrease the number of elements
        return ret;
    }

    int Num() {
        return n;  // Return the number of elements in the queue
    }
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////

void bfs(Graph& graph, int source, int& max_boom_size, int& first_boom_day) {
    vector<int> visited(graph.n, -1);  // Track the day each node receives the news
    vector<int> boom(graph.n, 0);  // Track the number of employees receiving the news each day

    Queue<int> q;
    q.Initialize(graph.n);  // Initialize a queue with capacity for all employees

    visited[source] = 0;  // The source employee receives the news on day 0
    q.Add(source);

    // BFS to simulate the news spreading day by day
    while (q.Num() > 0) {
        int u = q.Pop();
        int current_day = visited[u];

        for (int i = 0; i < graph.nodes[u].adj.n; ++i) {
            int neighbor = graph.nodes[u].adj[i];
            if (visited[neighbor] == -1) {  // If neighbor hasn't received the news yet
                visited[neighbor] = current_day + 1;  // Neighbor receives news the next day
                boom[current_day + 1]++;  // Increment boom count for the next day
                q.Add(neighbor);  // Add neighbor to the queue to continue BFS
            }
        }
    }

    // Find the maximum boom size and its first occurrence
    max_boom_size = 0;
    first_boom_day = 0;
    for (int day = 1; day < graph.n; ++day) {
        if (boom[day] > max_boom_size) {
            max_boom_size = boom[day];
            first_boom_day = day;
        }
    }

    q.Destroy();  // Cleanup the queue
}

int main() {
    int E;  // Number of employees
    cin >> E;

    Graph graph;
    graph.Initialize(E);

    // Reading the friendship relations
    for (int i = 0; i < E; ++i) {
        int N;  // Number of friends
        cin >> N;
        for (int j = 0; j < N; ++j) {
            int friend_id;
            cin >> friend_id;
            graph.nodes[i].adj.AddLast(friend_id);  // Add friendship
        }
    }

    int T;  // Number of test cases
    cin >> T;

    while (T--) {
        int source;
        cin >> source;

        int max_boom_size = 0, first_boom_day = 0;
        bfs(graph, source, max_boom_size, first_boom_day);

        if (max_boom_size == 0) {
            cout << "0" << endl;
        } else {
            cout << max_boom_size << " " << first_boom_day << endl;
        }
    }

    graph.Destroy();  // Cleanup the memory

    return 0;
}
