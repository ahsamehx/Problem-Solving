#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n, q, a;
    cin >> n;
    stack<int> st;

    for (int i = 0; i < st.size(); i++)
    {
        cin >> q;
        if (q = 1)
        {
            cin >> a;
            st.push(a);
        }
        else if (q = 2)
        {
            if (!st.empty())
            {
                st.pop();
            }
        }
        else if (q = 3)
        {
            if (!st.empty())
                cout << st.top() << endl;
            else
                cout << "Empty!" << endl;
        }
    }
}