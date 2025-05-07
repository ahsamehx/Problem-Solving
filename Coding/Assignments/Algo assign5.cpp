#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct DisjointSet
{
    vector<int> parent;
    vector<int> rank;

    DisjointSet(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
        }
    }

    int findParent(int x)
    {
        if (parent[x] == x)
        {
            return x;
        }
        return parent[x] = findParent(parent[x]);
    }

    void unionSets(int x, int y)
    {
        int xRoot = findParent(x);
        int yRoot = findParent(y);

        if (xRoot == yRoot)
        {
            return;
        }

        if (rank[xRoot] < rank[yRoot])
        {
            parent[xRoot] = yRoot;
        }
        else
        {
            parent[yRoot] = xRoot;
            if (rank[xRoot] == rank[yRoot])
            {
                rank[xRoot]++;
            }
        }
    }
};

struct Edge
{
    int u, v, w;

    bool operator<(const Edge &other) const
    {
        return w < other.w;
    }
};

template <typename T>
void merge(vector<T> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<T> L(n1), R(n2);

    copy(arr.begin() + left, arr.begin() + mid + 1, L.begin());
    copy(arr.begin() + mid + 1, arr.begin() + right + 1, R.begin());

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        arr[k++] = L[i] < R[j] ? L[i++] : R[j++];
    }

    while (i < n1)
    {
        arr[k++] = L[i++];
    }

    while (j < n2)
    {
        arr[k++] = R[j++];
    }
}

template <typename T>
void mergeSort(vector<T> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int kruskalMST(vector<Edge> &edges, int n)
{
    DisjointSet ds(n);
    mergeSort(edges, 0, edges.size() - 1);

    int mstWeight = 0;
    for (Edge &edge : edges)
    {
        if (ds.findParent(edge.u) != ds.findParent(edge.v))
        {
            ds.unionSets(edge.u, edge.v);
            mstWeight += edge.w;
        }
    }

    return mstWeight;
}

int main()
{
    while (true)
    {
        int m, n;
        cin >> m >> n;

        if (m == 0 && n == 0)
        {
            break;
        }

        vector<Edge> edges;
        for (int i = 0; i < n; ++i)
        {
            Edge e;
            cin >> e.u >> e.v >> e.w;
            edges.push_back(e);
        }

        int totalWeight = 0;
        for (Edge &edge : edges)
        {
            totalWeight += edge.w;
        }

        int mstWeight = kruskalMST(edges, m);
        int maxSavings = totalWeight - mstWeight;

        cout << maxSavings << endl;
    }

    return 0;
}