#include<iostream>
#include<vector>
#include<deque>

using namespace std;

int main()
{
    int score0 = 0, score1 = 0, n;
    // score0 --> Sereja, score1 --> Dima
    cin >> n;
    deque<int> v;
    v.resize(n);

    for (auto &it : v)
    {
        cin >> it;
    }
    int ind = 0, a = 0, b = n-1;
    while (n--)
    {

        if (ind%2 ==0){
        if (v[a] > v[b])
        {
            score0+= v[a];
            a++;
        }
        else 
        {
            score0+= v[b];
            b--;
        }
        }
        else{
        if (v[a] > v[b])
        {
            score1+= v[a];
            a++;
        }
        else
        {
            score1+= v[b];
            b--;
        }
        }
        ind++;
    }
    cout << score0 << " " << score1 << endl;
}
