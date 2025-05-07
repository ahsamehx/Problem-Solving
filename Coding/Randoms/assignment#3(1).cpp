#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Patient
{
public:
    string name = "";
    int age = 0;
    string condition = "";
    int priority = 0;

    Patient() {}
    Patient(string name, int age, string condition, int priority) : name(name), age(age), condition(condition), priority(priority) {}
    ~Patient() {}
};

class Node
{
public:
    Patient info;
    Node* next;
};

Node* front = NULL;
int counter = 0;

/*---------------Enqueue------------------*/

void add_patient(Patient& item)
{
    Node* temp;
    Node* newNode = new Node();
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
    Node* temp;
    if (front == NULL)
        cout << "Queue is empty" << endl;
    else
    {
        temp = front;
        cout << "Deleted patient is: " << temp->info.name << ", age: " << temp->info.age << ", condition: " << temp->info.condition
            << ", Priority " << temp->info.priority << endl;
        front = front->next;
        delete temp;
        counter--;
    }
}
/*--------------End of dequeue--------------*/

void update_patient(Patient& patient, int new_priority)
{
    if (front == NULL)
    {
        cout << "Queue is empty" << endl;
        return;
    }
    if (patient.priority == new_priority)
    {
        cout << "The new priorty of patient " << patient.name << " is the same as the old one" << endl;
        return;
    }
    Node* curr = front, * prev = NULL;
    while (!(curr->info.name == patient.name && curr->info.age == patient.age && curr->info.condition == patient.condition && curr->info.priority == patient.priority))
    {
        prev = curr;
        curr = curr->next;
    }
    if (prev == NULL)
        front = curr->next;
    else
        prev->next = curr->next;

    curr->info.priority = new_priority;
    if (new_priority == 1)
        curr->info.condition = "Normal";
    else if (new_priority == 2)
        curr->info.condition = "Urgent";
    else if (new_priority == 3)
        curr->info.condition = "Critical";

    add_patient(curr->info);
    counter--;
}

int queue_size()
{
    return counter;
}

string front_patient()
{
    if (front == NULL)
    {
        throw runtime_error("Queue is empty");
        // throw new exception("Queue is empty");
    }
    else
    {
        return front->info.name;
    }
}

void display_queue()
{
    Node* temp;
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

vector<string> splitLine(string line) {
    vector<string> elements;
    string currentElement;

    for (char ch : line) {
        if (ch == ' ' || ch == '=' || ch == ';' || ch == '(' || ch == ')' || ch == '\t') {
            if (!currentElement.empty()) {
                elements.push_back(currentElement);
                currentElement.clear();
            }
        }
        else {
            currentElement += ch;
        }
    }

    if (!currentElement.empty()) {
        elements.push_back(currentElement);
    }

    return elements;
}

struct Variable {
    string name;
    string datatype;
    string value;

    Variable(const string& n, const string& dt, const string& val)
    {
        name = n;
        datatype = dt;
        value = val;
    }
};

class node {
public:
    Variable data;
    node* next;
    node(const Variable& d) : data(d), next(nullptr) {}
};


class Stack {
public:
    node* head;

    Stack() : head(nullptr) {}

    void push(const string& datatype, const string& name, const string& value) {
        node* current = head;
        while (current != nullptr) {
            if (current->data.name == name) {
                // Update the value of the existing variable
                current->data.value = value;
                displayStack();
                return;
            }
            current = current->next;
        }

        // If the variable doesn't exist, add it to the stack
        node* newnode = new node(Variable(name, datatype, value));
        newnode->next = head;
        head = newnode;

        displayStack();
    }

    void pop() {
        if (head == nullptr) {
            cout << "Empty stack can not pop ..." << endl;
            return;
        }

        node* current = head;
        head = head->next;
        delete current;
    }

    void update(const string& name, const string& val) {
        node* current = head;
        while (current != nullptr) {
            if (current->data.name == name) {
                current->data.value = val;
                displayStack();
                return;
            }
            current = current->next;
        }
    }

    void displayStack() {
        node* dis = head;
        cout << "Stack Contents:" << endl;
        while (dis != nullptr) {
            cout << "Name: " << dis->data.name << ", Type: " << dis->data.datatype << ", Value: " << dis->data.value << ";" << endl;
            dis = dis->next;
        }
        cout << "-------------------------------------------------\n";
    }

    ~Stack() {
        while (head != nullptr) {
            node* current = head;
            head = head->next;
            delete current;
        }
    }
};

void processLine(ifstream& file, Stack& mystack) {
    string line;
    while (getline(file, line)) {
        vector<string> elements = splitLine(line);

        // Check if it's the end of the program
        if (elements.size() >= 2 && elements[0] == "return" && elements[1] == "0") {
            mystack.pop();
            return;
        }

        // Ensure that elements contain at least two elements (datatype and name)
        if (elements.size() >= 2) {
            if (elements.size() == 3) { // If value is present
                mystack.push(elements[0], elements[1], elements[2]);
            }
            else { // If no value, update existing variable
                mystack.update(elements[0], elements[1]);
            }
        }
        else {
            cout << "Error: Invalid line - \"" << line << "\"" << endl;
        }
    }
}

void processFile(const string& filename) {
    Stack mystack;
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Unable to open file " << filename << endl;
        return;
    }

    // Read and discard the first line
    string firstLine;
    getline(file, firstLine);

    processLine(file, mystack);
    file.close();
}


int main()
{
    int x = 99, num;
    while (x--)
    {
        string name;
        int age;
        string condition;
        int priority;
        bool flag = false;
        cout << "::Choose a number for an operation::" << endl
            << "1 - Add Patient" << endl
            << "2 - Remove/Process first patient " << endl
            << "3 - Update the priority of a Patient " << endl
            << "4 - Get the size of the Queue" << endl
            << "5 - Retrieve the first Patient on the Queue " << endl
            << "6 - Display the Queue of Patients" << endl
            << "0 - Exit" << endl;

        cin >> num;

        switch (num)
        {
        case (1):
        {

            cout << "Enter the name, age, condition and priority: " << endl;
            cin >> name >> age >> condition >> priority;
            Patient a(name, age, condition, priority);
            add_patient(a);
            break;
        }
        case (2):
        {
            process_patient();
            break;
        }
        case (3):
        {
            cout << "Enter the name, age, condition and priority: " << endl;
            cin >> name >> age >> condition >> priority;
            int new_priority;
            cout << "Enter the New Priority: " << endl;
            cin >> new_priority;
            Patient a(name, age, condition, priority);
            update_patient(a, new_priority);
            break;
        }
        case (4):
        {
            int size = queue_size();
            cout << "The Queue size is: " << size << endl;
            break;
        }

        case (5):
        {

            try
            {
                cout << front_patient() << endl;
            }
            catch (const runtime_error& error)
            {
                cerr << error.what() << endl;
            }
            break;
        }

        case (6):
        {
            display_queue();
            break;
        }
        default:
        {
            flag = true;
            break;
        }
        }
        if (flag)
            break;
    }
    cout << "================================= Task 2 ==================================" << endl;

    processFile("code.txt");
}