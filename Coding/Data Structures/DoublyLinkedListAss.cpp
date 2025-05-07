#include <iostream>
#include <istream>

using namespace std;

struct node
{
    char item;
    node *next;
    node *prev;
};

class DLinkedList
{

public:
    node *first;
    node *last;
    int count;

    DLinkedList()
    {
        first = NULL;
        last = NULL;
        count = 0;
    }

    void insertfirst(char element)
    {
        node *newnode = new node;
        newnode->item = element;
        if (count == 0)
        {
            first = last = newnode;
            newnode->next = newnode->prev = NULL;
        }
        else
            newnode->next = first;
        newnode->prev = NULL;
        first->prev = newnode;
        first = newnode;
        count++;
    }

    void insertlast(char element)
    {
        node *newnode = new node;
        newnode->item = element;
        if (count == 0)
        {
            first = last = newnode;
            newnode->next = newnode->prev = NULL;
        }
        else
        {
            newnode->next = NULL;
            newnode->prev = last;
            last->next = newnode;
            last = newnode;
        }
        count++;
    }

    void insertAt(char item, int pos)
    {
        if (pos < 0 || pos > count)
            cout << "out of range " << endl;
        else
        {
            node *newnode = new node;
            newnode->item = item;
        }
        if (pos == 0)
            insertfirst(item);
        else if (pos == count)
            insertlast(item);
        else
        {
            node *newnode = new node;
            node *temp = first;
            for (int i = 0; i < pos; i++)
            {
                temp = temp->next;
            }
            newnode->next = temp->next;
            newnode->prev = temp;
            temp->next = newnode;
            temp->next->prev = newnode;
            count++;
        }
    }

    void deleteAt(int index)
    {
        int counter = 0;
        if (count == 0)
            cout << "Empty List" << endl;

        else if (index == 0)
        {
            node *temp = first;
            first = first->next;
            if (first != NULL)
            {
                first->prev = NULL;
            }
            else
            {
                last = NULL;
            }
            delete temp;
        }
        else if (count == 1)
        {
            delete last;
            last = first = NULL;
        }
        else if (count - 1 == index)
        {
            node *temp = last;
            last = last->prev;
            last->next = NULL;
            delete temp;
        }
        else
        {
            node *temp = first;
            while (temp != NULL && counter != index)
            {
                temp = temp->next;
                counter++;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
        }

        count--;
    }

    void substring(int index, int length)
    {
        node *temp = first;
        int counter = 0;
        string substring = "";
        while (temp != NULL && counter != index)
        {
            temp = temp->next;
            counter++;
        }
        if (temp == NULL || counter != index)
        {
            cout << "Index out of bounds." << endl;
            return;
        }

        for (; length != 0 && temp != NULL; length--)
        {
            substring += temp->item;
            temp = temp->next;
        }
        cout << "Substring: " << substring << endl;
    }
    // check the index 0 error

    int search(string str)
    {
        node *temp = first;
        int counter = 0;
        int index = -1;

        while (temp != NULL)
        {
            if (temp->item == str[0])
            {
                node *current = temp;
                int i = 0;
                while (current != NULL && current->item == str[i])
                {
                    current = current->next;
                    i++;
                }
                if (i == str.length())
                {
                    index = counter;
                    break;
                }
            }
            temp = temp->next;
            counter++;
        }
        if (index == -1)
        {
            cout << "The substring is not in the list" << endl;
            return index;
        }
        else
        {
            return index;
        }
    }

    void replaceSubstring(string oldSub, string newSub)
    {
        if (first == nullptr)
        {
            cout << "List is empty!" << endl;
            return;
        }

        node *current = first;
        while (current != nullptr)
        {
            // Check if the current position matches the oldSub
            node *match = current;
            string matchStr;
            while (match != nullptr && matchStr.length() < oldSub.length())
            {
                matchStr += match->item;
                match = match->next;
            }

            if (matchStr == oldSub)
            {
                // Replace characters of oldSub with characters of newSub
                if (newSub.length() > oldSub.length())
                {
                    // If the new substring is longer, insert extra nodes
                    for (int i = 0; i < newSub.length() - oldSub.length(); ++i)
                    {
                        node *newNode = new node;
                        newNode->item = newSub[i + oldSub.length()];
                        newNode->next = current->next;
                        newNode->prev = current;
                        if (current->next != nullptr)
                        {
                            current->next->prev = newNode;
                        }
                        current->next = newNode;
                    }
                }
                else if (newSub.length() < oldSub.length())
                {
                    // If the new substring is shorter, remove extra nodes
                    for (int i = 0; i < oldSub.length() - newSub.length(); ++i)
                    {
                        node *temp = current->next;
                        current->next = current->next->next;
                        if (current->next != nullptr)
                        {
                            current->next->prev = current;
                        }
                        delete temp;
                    }
                }
                // Replace characters of oldSub with characters of newSub
                for (int i = 0; i < newSub.length(); ++i)
                {
                    current->item = newSub[i];
                    current = current->next;
                }
            }
            else
            {
                current = current->next;
            }
        }
    }

    void display()
    {
        node *temp = first;
        while (temp != NULL)
        {
            cout << temp->item;
            temp = temp->next;
        }
        cout << endl;
    }
    void reverse()
    {
        if (count <= 1)
        {
            // No need to reverse if the list is empty or has only one node
            return;
        }

        // Initialize three pointers to traverse the list
        node *current = first;
        node *nextNode = nullptr;
        node *prevNode = nullptr;

        // Traverse the list and reverse the next and prev pointers of each node
        while (current != nullptr)
        {
            // Store the next node before swapping pointers
            nextNode = current->next;

            // Reverse the next and prev pointers of the current node
            current->next = prevNode;
            current->prev = nextNode;

            // Move pointers to the next node
            prevNode = current;
            current = nextNode;
        }

        // Update the first and last pointers after reversing
        last = first;
        first = prevNode;
    }

    void display()
    {
        node *temp = first;
        while (temp != NULL)
        {
            cout << temp->item;
            temp = temp->next;
        }
        cout << endl;
    }
};

void stringToList(string &input, DLinkedList &list)
{
    for (char ch : input)
    {
        list.insertlast(ch);
    }
}

DLinkedList conc(DLinkedList list1, DLinkedList list2)
{
    if (list1.first == nullptr)
    {
        return list2;
    }

    if (list2.first == nullptr)
    {
        return list1;
    }

    list1.last->next = list2.first;
    list2.first->prev = list1.last;

    list1.last = list2.last;

    return list1;
}

int main()
{
    string str1, str2, word, substr1, substr2;
    int index;
    int ind, len;
    DLinkedList list1, list2, list3;
    cout << "Enter string to add to list 1:  ";
    getline(cin, str1);
    cout << "Enter string to add to list 2:  ";
    getline(cin, str2);
    stringToList(str1, list1);
    stringToList(str2, list2);
    list3 = conc(list1, list2);
    cout << "Concatenated Lists: ";
    list3.display();
    cout << "Choose a character by index to remove: ";
    cin >> index;
    list1.deleteAt(index);
    cout << "List after removal: ";
    list1.display();
    cout << "Enter index and length to get substring: ";
    cin >> ind >> len;
    list3.substring(ind, len);
    cout << "Search for a string in the list: ";
    cin >> word;
    index = list3.search(word);
    cout << "Found at index: " << index << endl;
    cout << "Enter 2 substrings to replace one with another: ";
    cin >> substr1 >> substr2;
    list3.replaceSubstring(substr1, substr2);
    cout << "List After replacement: ";
    list3.display();
}