// GROUP:   SWE 1
// ID:      20226002
// Assign:  01
// Assign:  ArrayHeap
// UVA:     10954
// Name:    AHMED SAMEH AHMED OMAR KHALIL

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class Value>
struct Array
{
    int n, sz;
    Value *arr;

    void Initialize();
    void Destroy();
    void AddLast(Value v);
    void RemoveLast();
    Value &operator[](int i);
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class Elem>
struct Heap
{
    Array<Elem> a;
    bool (*IsBefore)(Elem &, Elem &);

    void Initialize(bool (*_IsBefore)(Elem &, Elem &));
    void Destroy();
    int Child(int i);
    int Parent(int i);
    void MoveUp(int ind);
    void MoveDown(int ind);
    void Add(Elem e);
    Elem GetFirst();
    Elem RetrieveFirst();
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool IsBeforeInt(int &a, int &b)
{
    return a < b;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Array Implementation

template <class Value>
void Array<Value>::Initialize()
{
    sz = 1;
    n = 0;
    arr = new Value[sz];
}

template <class Value>
void Array<Value>::Destroy()
{
    delete[] arr;
    arr = nullptr;
    sz = 0;
    n = 0;
}

template <class Value>
void Array<Value>::AddLast(Value v)
{
    if (n == sz)
    {

        sz *= 2; // Like what vector does
        Value *newArr = new Value[sz];
        for (int i = 0; i < n; i++)
        {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr; // pointer pointing at another pointer
    }
    arr[n++] = v;
}

template <class Value>
void Array<Value>::RemoveLast()
{
    if (n > 0)
        n--;
    else
        cout << "The Array is empty!" << endl;
}

template <class Value>
Value &Array<Value>::operator[](int i)
{
    return arr[i];
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class Elem>
void Heap<Elem>::Initialize(bool (*_IsBefore)(Elem &, Elem &))
{
    a.Initialize();
    IsBefore = _IsBefore;
}

template <class Elem>
void Heap<Elem>::Destroy()
{
    a.Destroy();
}

template <class Elem>
int Heap<Elem>::Child(int i)
{
    return 2 * i + 1;
}

template <class Elem>
int Heap<Elem>::Parent(int i)
{
    return (i - 1) / 2;
}

template <class Elem>
void Heap<Elem>::MoveUp(int ind)
{
    while (ind > 0)
    {
        int p = Parent(ind);
        if (!IsBefore(a[ind], a[p]))
            break;
        swap(a[ind], a[p]);
        ind = p;
    }
}

template <class Elem>
void Heap<Elem>::MoveDown(int ind)
{
    while (true)
    {
        int left = Child(ind);
        int right = left + 1;
        int smallest = ind;
            if (left < a.n && IsBefore(a[left], a[smallest]))
            {
                smallest = left;
            }
        if (right < a.n && IsBefore(a[right], a[smallest]))
        {
            smallest = right;
        }
        if (smallest == ind)
            break;
        swap(a[ind], a[smallest]);
        ind = smallest;
    }

}

template <class Elem>
void Heap<Elem>::Add(Elem e)
{
    a.AddLast(e);
    MoveUp(a.n - 1); // postion of last element
}

template <class Elem>
Elem Heap<Elem>::GetFirst()
{
    return a[0];
}

template <class Elem>
Elem Heap<Elem>::RetrieveFirst()
{
    Elem first = a[0];
    a[0] = a[a.n - 1];
    a.RemoveLast();
    if (a.n > 0)
        MoveDown(0);
    return first;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    while (true)
    {
        Heap<int> h;
        h.Initialize(IsBeforeInt);

        int n, x, sum, totalCost = 0;
        cin >> n;
        if (n == 0)
            break;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            h.Add(x);
        }
        while (n > 1)
        {
            for (int i = 0; i < n; ++i)
            {
                sum += h.a[i];
            }
            totalCost += sum;
            n--;
            sum = 0;
        }

        cout << totalCost << endl;

        h.Destroy();
    }
}