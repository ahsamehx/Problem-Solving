#include <iostream>
using namespace std;

int main (){
	
	int num, h, w = 0; 
	cin >> num >> h;
	int array[num];
	
	for (int i = 0; i < num; i++)
	{
		cin >> array[i];
		
	}
	
	for (int i = 0; i < num; i++)
	{
		if (array[i] <= h)
		{
			w++;
		}
		else 
		{
			w+= 2;
		}
	}
	cout << w << endl;
	return 0;
}