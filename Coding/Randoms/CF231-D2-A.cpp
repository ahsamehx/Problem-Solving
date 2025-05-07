#include<iostream>
using namespace std;

int main (){

    int x1, x2, x3, n, sum, answer = 0;
    cin >> n;
    for(int i =0; i < n; i++)
    {
        sum =0;
        cin >> x1 >> x2 >> x3;
        sum = x1 + x2 + x3;
        if (sum >= 2) answer++;

    }
    cout << answer << endl;

    return 0;
}