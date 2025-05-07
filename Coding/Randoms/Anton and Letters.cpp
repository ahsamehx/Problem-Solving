#include <iostream>
using namespace std;

int main()
{
    string input;
    getline(cin, input);
    int count = 0, all = 0;
    for (int i = 0; i < input.length(); i++)
    {

        if (input[i] >= 'a' && input[i] <= 'z')
        {
            all++;
            for (int j = i + 1; j < input.length(); j++)
            {
                if (input[i] == input[j])
                {
                    count++;
                    break;
                }
            }
        }
    }
    cout << all - count << endl;
}