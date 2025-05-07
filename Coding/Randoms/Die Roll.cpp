#include <iostream>
using namespace std;

int main() {

    int w, y;
    cin >> w >> y;
    int temp = 7 - max(w,y);
    if(temp == 0) cout << "0/1" << endl;
    else if(temp == 1) cout << "1/6" << endl;
    else if(temp == 2) cout << "1/3" << endl;
    else if(temp == 3) cout << "1/2" << endl;
    else if(temp == 4) cout << "2/3" << endl;
    else if(temp == 5) cout << "5/6" << endl;
    else cout << "1/1" << endl;






}