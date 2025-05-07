#include <bits/stdc++.h>
using namespace std;
// #define Ahmed int
// #define int long long
#define inf 1e25

int N = 1e5 + 19;

int main()
{
    int t, op, x;
    map<int, int> mpcount; // element with the occurance
    map<int, int> mpfreq;  // number of occurance with
    cin >> t;
    while (t--)
    {
        cin >> op >> x;
        if (op == 1)
        {
            if (mpcount[x])
            {
                mpfreq[mpcount[x]]--;
                if (!(mpfreq[mpcount[x]]))
                    mpfreq.erase(mpcount[x]);
            }
            mpcount[x]++;
            mpfreq[mpcount[x]]++;
        }

        else if (op == 2)
        {
            if(mpcount.count(x))
            {
                mpfreq[mpcount[x]]--;
                if (!(mpfreq[mpcount[x]]))
                    mpfreq.erase(mpcount[x]);
                mpcount[x]--;
                if(mpcount[x]==0)
                    mpcount.erase(x);
                else 
                    mpfreq[mpcount[x]]++;
            }
        }

        else
        {
            cout << (mpfreq.count(x)) << endl;
        }
    }
}