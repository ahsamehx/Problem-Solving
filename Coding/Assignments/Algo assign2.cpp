// GROUP:   SWE #1
// ID:      20226002
// Assign:  02
// Assign:  DisjointSets
// UVA:     10608
// Name:    Ahmed Sameh Ahmed Omar

#include <iostream>
#include <vector>
using namespace std;

struct DisjointSets
{
    int n;
    vector<int> parent;
    vector<int> num_nodes; // Tracks the size of each set

    // Initialize the disjoint set with n elements
    void Initialize(int _n)
    {
        n = _n;
        parent.resize(n + 1); // Use 1-based indexing
        num_nodes.resize(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            parent[i] = i;    // Each element is its own parent
            num_nodes[i] = 1; // Each set has one node initially
        }
    }

    // Find the root of the set containing i, with path compression
    int Find(int i)
    {
        if (parent[i] != i)
        {
            parent[i] = Find(parent[i]); // Path compression
        }
        return parent[i];
    }

    // Union the sets containing i and j, union by size
    bool Union(int i, int j)
    {
        int root_i = Find(i);
        int root_j = Find(j);

        if (root_i != root_j)
        {
            // Union by size: attach the smaller tree under the larger one
            if (num_nodes[root_i] < num_nodes[root_j])
            {
                parent[root_i] = root_j;
                num_nodes[root_j] += num_nodes[root_i];
            }
            else
            {
                parent[root_j] = root_i;
                num_nodes[root_i] += num_nodes[root_j];
            }
            return true;
        }
        return false; // i and j are already in the same set
    }

    // Get the size of the largest set
    int getLargestSetSize()
    {
        int largest = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (parent[i] == i)
            { // Root node
                largest = max(largest, num_nodes[i]);
            }
        }
        return largest;
    }
};

int main()
{
    int test_cases;
    cin >> test_cases;

    while (test_cases--)
    {
        int N, M;
        cin >> N >> M;

        DisjointSets ds;
        ds.Initialize(N);

        // Read pairs of friendships and union them
        for (int i = 0; i < M; ++i)
        {
            int A, B;
            cin >> A >> B;
            ds.Union(A, B);
        }

        // Output the size of the largest group of friends
        cout << ds.getLargestSetSize() << endl;
    }

    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////