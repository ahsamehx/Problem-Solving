#include <iostream>
using namespace std;

class Patient
{
public:
    string name;
    int age;
    string condition;
    int priority;

    Patient()
    {
        name = "";
        age = 0;
        condition = "";
        priority = 0;
    }
    Patient(string n, int a, string cond, int pr)
    {
        name = n;
        age = a;
        condition = cond;
        priority = pr;
    }
};

class Node
{
public:
    Patient info;
    Node *next;
};

Node *front = NULL;
int counter = 0;

/*---------------Enqueue------------------*/

void add_patient(Patient item)
{
    Node *temp;
    Node *newNode = new Node();
    newNode->info = item;

    /*Queue is empty or item to be added has priority more than first item*/
    if (front == NULL || item.priority > front->info.priority)
    {
        newNode->next = front;
        front = newNode;
    }
    else
    {
        temp = front;
        while (temp->next != NULL && temp->next->info.priority >= item.priority)
        {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }
    counter++;
}

/*-----------End of insert------------*/

/*-------------Begin of dequeue-------------*/
void process_patient()
{
    Node *temp;
    if (front == NULL)
        cout << "Queue is empty" << endl;
    else
    {
        temp = front;
        cout << "Deleted patient is: " << temp->info.name << ", age: " << temp->info.age << ", condition: " << temp->info.condition
             << ", Priority " << temp->info.priority << endl;
        front = front->next;
        delete temp;
    }
    counter--;
}
/*--------------End of dequeue--------------*/

void update_patient(Patient patient, int new_priority)
{
    if (front == NULL)
        cout << "Queue is empty" << endl;
    else if (patient.priority == new_priority)
    {
        cout << "The new priorty of patient " << patient.name << " is the same as the old one" << endl;
    }
    else
    {
        Node *temp;
        Node *prev;
        temp = front;
        prev = temp;
        while (!(temp->info.name == patient.name && temp->info.age == patient.age && temp->info.condition == patient.condition && temp->info.priority == patient.priority))
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        temp->info.priority = new_priority;
        if (new_priority == 1)
            temp->info.condition = "Normal";
        else if (new_priority == 2)
            temp->info.condition = "Urgent";
        else if (new_priority == 3)
            temp->info.condition = "Critical";
        Node *ptr = front;
        prev = front;
        while (ptr->next != NULL && ptr->info.priority >= temp->info.priority)
        {
            prev = ptr;
            ptr = ptr->next;
        }
        temp->next = ptr;
        prev->next = temp;
    }
}
// void refresh_patient()
// {
//     if (front != NULL)
//     {
//         Node *temp;
//         temp = front;
//         Node *newNode = new Node();
//         while (temp->next != NULL && temp->next->info.priority >= temp->next->next->info.priority)
//         {
//             temp = temp->next;
//         }

//     }
// }
/*------------Begin of display---------------*/
void display_queue()
{
    Node *temp;
    temp = front;
    if (front == NULL)
        cout << "Queue is empty" << endl;
    else
    {
        while (temp != NULL)
        {
            cout << "Name: " << temp->info.name << ", age: " << temp->info.age << ", condition: " << temp->info.condition
                 << ", Priority " << temp->info.priority << endl;

            temp = temp->next;
        }
    }
    cout << endl;
}

int main()
{
    Patient a = {"Ahmed", 20, "Urgent", 2};
    Patient b = {"Omar", 21, "Critical", 3};
    Patient e = {"Abdallah", 21, "Normal", 1};
    Patient c = {"Omar", 21, "Normal", 1};
    Patient f = {"Osama", 29, "Urgent", 2};
    Patient s = {"Ziad", 29, "Normal", 1};
    Patient z = {"Osama", 29, "Critical", 3};

    add_patient(a);
    add_patient(b);
    add_patient(c);
    add_patient(e);
    add_patient(f);
    add_patient(s);
    add_patient(z);
    display_queue();
    update_patient(e, 3);
    update_patient(z, 1);
    update_patient(s, 2);
    update_patient(b, 1);
    display_queue();
}