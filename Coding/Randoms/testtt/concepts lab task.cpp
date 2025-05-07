#include<bits/stdc++.h>
using namespace std;
struct Call {
    int curLoc;
    int n;
};

int main (){
  stack<Call> calls;
    Call c;
    c.curLoc = 0;
    cin >> c.n;
    calls.push(c);
    int returnVal = 0;
    while (!calls.empty()) {
        Call& call= calls.top();
        if (call.curLoc == 0) {
            if (call.n <= 1) {
                returnVal = 1;
                calls.pop();
            }
            else {
                Call new_Call;
                new_Call.curLoc = 0;
                new_Call.n = call.n -1;
                calls.push(new_Call);
                call.curLoc = 1;
            }
        }
        else if (call.curLoc == 1) {
            returnVal *= call.n;
            calls.pop();
        }
    }
    cout << returnVal << endl;
    return 0;
}