#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath> // Include the cmath library for sqrt
#include <vector>
#include <algorithm>
#include <limits>
#include <iomanip>

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class Value>
struct Array
{
    int n, sz;
    Value *arr;

    void Initialize()
    {
        n = 0;
        sz = 1;
        arr = new Value[sz];
    }

    void Destroy()
    {
        delete[] arr;
        n = 0;
        sz = 0;
    }

    void AddLast(Value v)
    {
        if (n == sz)
        {
            sz *= 2;
            Value *newArr = new Value[sz];
            for (int i = 0; i < n; i++)
                newArr[i] = arr[i];
            delete[] arr;
            arr = newArr;
        }
        arr[n++] = v;
    }

    void RemoveLast()
    {
        if (n > 0)
            n--;
    }

    Value &operator[](int i)
    {
        return arr[i];
    }
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct Edge
{
    int v;    // ID of the adjacent node
    double w; // Edge weight (distance between nodes)
};

struct Node
{
    int x, y; // Coordinates of the node
    Array<Edge> adj;

    void Initialize()
    {
        adj.Initialize();
    }

    void Destroy()
    {
        adj.Destroy();
    }
};

struct Graph
{
    int n;
    Node *nodes;

    void Initialize(int _n)
    {
        n = _n;
        nodes = new Node[n];
        for (int i = 0; i < n; i++)
        {
            nodes[i].Initialize();
        }
    }

    void Destroy()
    {
        for (int i = 0; i < n; i++)
        {
            nodes[i].Destroy();
        }
        delete[] nodes;
    }
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////

double Distance(int x1, int y1, int x2, int y2)
{
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

double Prim(Graph &graph)
{
    vector<double> maxDist(graph.n, numeric_limits<double>::infinity());
    vector<bool> visited(graph.n, false);
    maxDist[0] = 0;

    double maxEdgeInPath = 0;

    for (int i = 0; i < graph.n; i++)
    {
        // Find the unvisited node with the minimum max distance
        int u = -1;
        for (int j = 0; j < graph.n; j++)
        {
            if (!visited[j] && (u == -1 || maxDist[j] < maxDist[u]))
            {
                u = j;
            }
        }
        
        if (u == -1)
            break; // No more nodes reachable
        visited[u] = true;

        if (u == 1)
        {
            maxEdgeInPath = maxDist[u];
            break;
        }

        // Update maxDist values for adjacent nodes
        for (int j = 0; j < graph.nodes[u].adj.n; j++)
        {
            int v = graph.nodes[u].adj[j].v;
            double weight = graph.nodes[u].adj[j].w;

            if (!visited[v] && maxDist[v] > max(maxDist[u], weight))
            {
                maxDist[v] = max(maxDist[u], weight);
            }
        }
    }

    return maxEdgeInPath;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    int scenario = 1;

    while (true)
    {
        int n;
        cin >> n;
        if (n == 0)
            break;

        Graph graph;
        graph.Initialize(n);

        for (int i = 0; i < n; i++)
        {
            cin >> graph.nodes[i].x >> graph.nodes[i].y;
        }

        for (int i = 0; i < n; i++)
        { // build the graph of distances
            for (int j = i + 1; j < n; j++)
            {
                double dist = Distance(graph.nodes[i].x, graph.nodes[i].y, graph.nodes[j].x, graph.nodes[j].y);
                graph.nodes[i].adj.AddLast({j, dist});
                graph.nodes[j].adj.AddLast({i, dist}); //the edge is bidirectional
            }
        }

        double frogDistance = Prim(graph);

        cout << "Scenario #" << scenario++ << endl;
        cout << "Frog Distance = " << fixed << setprecision(3) << frogDistance << endl
             << endl;

        graph.Destroy();
    }

    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
