#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

int main()
{
    vector<int> a;
    vector<int>::iterator itr;
    itr = a.end();
    if (itr)
        cout << "Hee";
    return 0;
}