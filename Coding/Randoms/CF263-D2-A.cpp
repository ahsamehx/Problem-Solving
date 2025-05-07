#include<iostream>
using namespace std;

int main (){

    int matrix [5][5];
    int nummoves, row, column;
    for (int i = 0; i <5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> matrix[i][j];
        }
    }
    // get the index of 1 
    // assign the index values to new variables 
    // subtract 3 from these values
    for (int i = 0; i <5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (1 == matrix[i][j])
            {
                row = i;
                column = j;
            }
        }
    }

    nummoves = abs(2 - row) + abs(2 - column);

    cout << nummoves << endl;
    return 0;
}