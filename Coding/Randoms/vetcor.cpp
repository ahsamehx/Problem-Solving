#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

//implace function is faster than push function or insert 

int main()
{
    deque<char> deq{'r', 'e', 'w', 'f'};
    deq.push_back('o');
    deq.push_front('d');
    auto it = deq.begin();
    cout << it[3];
    cout << deq.max_size() << endl;
    
    deq.clear();
    // for(auto it = deq.rbegin(); it != deq.rend(); it++)
    // {
    //     cout << *it << " ";
    // }
}
