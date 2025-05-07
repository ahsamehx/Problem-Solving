#include <iostream>
using namespace std;

template <class T>
class Node
{
    T info;
    Node *next;

public:
    Node() { next = 0; }
    Node(T, Node *in = 0);
    Node *getNext();
    void setNext(Node *);
    T getInfo();
    void setInfo(T);
};

template <class T>
class SLL
{
    Node<T> *head, *tail;
    int listSize;

public:
    SLL()
    {
        head = tail = 0;
        listSize = 0;
    }
    void addToHead(T);
    void addToTail(T);
    // returns list size
    int getSize();
    bool moveTailToFront()
    {
        Node *temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        tail->next = head;
        head = tail;
        tail = temp;
        tail->next = NULL;
    }
};

int main()
{
}