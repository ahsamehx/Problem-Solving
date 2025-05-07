#include <iostream>
#include <set>

using namespace std;

int main()
{
    int x;
    set<int> st;
    for (int i = 0; i < 4; i++)
    {
        cin >> x;
        st.insert(x);
    }
    cout << 4 - st.size() << endl;
}