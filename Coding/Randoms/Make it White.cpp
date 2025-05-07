#include<iostream>
using namespace std;

int main()
{
    string str = "";
    int begin = 0, end =0, str_len = 0;
    double test_case_num = 0;
    
    cin >> test_case_num;
    int* arr = new int[test_case_num];

    for (int i = 0; i < test_case_num; i++)
    {
        cin >> str_len;
        cin >> str;

        for (int j = 0; j < str.length(); j++)
        {
            if (str[j] == 'B') 
            {
                begin = j;
                break;
            }
        }
        for (int j = 0; j < str.length(); j++)
        {
            if (str[j] == 'B') end = j;
        }
        arr[i] = end - begin + 1;
    }

    for (int i = 0; i < test_case_num; i++)
    {
        cout << arr[i] << endl;
    }

}
