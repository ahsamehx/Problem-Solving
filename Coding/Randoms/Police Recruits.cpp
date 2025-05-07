#include<iostream>
using namespace std;

int main()
{
   int n, police =0, input =0, crime = 0;
   cin >> n;

   while (n--)
   {
        cin >> input;
        if (input > 0) police += input;
        if(input == -1)
        {
            if (police > 0) police--;
            else crime++;
        }
        
   } 
   cout << crime << endl;
}