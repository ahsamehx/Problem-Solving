#include <iostream>
using namespace std;

int main(){
int test_case_num, n, x;
cin >> test_case_num;
while (test_case_num--)
{
    cin >> n;
    int freq[200001] = {0};
    char arr[n] = {'a'};
    int counter = 0;
    while (n--)
    {
        cin >> x;
        char c = ('a' + freq[x]);
        freq[x]++;
        arr[counter] = c;
        counter++;
    }
    for (int i = 0; i < counter; i++)
    {
        cout << arr[i];
    }
    cout << endl;
}
}
