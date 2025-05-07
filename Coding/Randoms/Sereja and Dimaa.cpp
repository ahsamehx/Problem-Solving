#include <iostream>
#include <deque>
using namespace std;

int main()
{
    int n, Sereja = 0, Dima = 0;
    cin >> n;
    deque<int> dq(n);
    for (auto &val : dq)
    {
        cin >> val;
    }

    for (int i = 0; i < n; i++)
    {
        if (dq.front() > dq.back())
        {
            if (i % 2 == 0)
                Sereja += dq.front();
            else
                Dima += dq.front();
            dq.pop_front();
        }
    
        else
        {
            if (i % 2 == 0)
                Sereja += dq.back();
            else
                Dima += dq.back();
            dq.pop_back();
        }
    }
    cout << Sereja << " " << Dima << endl;
}