#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    char label;
    int cost;
};
class minHeap
{
    vector<Node> heap;
    Node *heap; // an array of nodes
    int _size;  // size of heap
    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }

public:
    minHeap()
    {
        _size = 0;
    }
    void swapNodes(int i, int j)
    {
        Node temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
    }
    void min_heapify(vector<Node> heap, int i, int n)
    {
        int l = leftChild(i);
        int r = rightChild(i);
        int smallest = i;
        if (r < n && heap[r].cost < heap[i].cost)
            smallest = r;
        else if (l < n && heap[l].cost < heap[smallest].cost)
            smallest = l;
        if (smallest != i)
        {
            swap(heap[i], heap[smallest]);
            min_heapify(heap, smallest, n);
        }
    }
    void insert(Node newNode)
    {
        heap.push_back(newNode);
        _size++;
        int i = _size - 1;
        while (i > 0 && heap[parent(i)].cost > heap[i].cost)
        {
            swapNodes(i, parent(i));
            i = parent(i);
        }
    }
    Node extractMin()
    {
        if (_size <= 0)
        {
            cout << "Heap is empty!" << endl;
            return;
        }
        else if (_size == 1)
        {
            _size--;
            Node minNode = heap.front();
            heap.pop_back();
            return minNode;
        }
        else
        {
            Node minNode = heap[0];
            heap[0] = heap[_size - 1];
            _size--;
            heap.pop_back();
            min_heapify(heap, 0, _size);
            return minNode;
        }
    }
};

class WeightedGraph
{
    int **g;
    int nVertices;
    minHeap heap;

public:
    WeightedGraph(int vertices) : nVertices(vertices), heap()
    {
        g = new int *[nVertices];
        for (int i = 0; i < nVertices; ++i)
        {
            g[i] = new int[nVertices];
            for (int j = 0; j < nVertices; ++j)
            {
                g[i][j] = -1;
            }
        }
        int getNVertices()
        {
            return nVertices;
        }
        int getWeight(char ch1, char ch2)
        {
            return g[ch1 - 'A'][ch2 - 'A'];
        } // returns weight of the edge connecting the given
        int *returnNeighbors(int v)
        {
            vector<int> neighbors;
            for (int i = 0; i < nVertices; ++i)
            {
                if (g[v][i] != -1)
                {
                    neighbors.push_back(i);
                }
            }
        }
    } 
};