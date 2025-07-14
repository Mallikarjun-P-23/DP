#include <iostream>
using namespace std;


int decToBin(int d)
{
    if (d == 0) 
        return 0; 
    else
        return (d % 2 + 10 * decToBin(d / 2));
}
int main()
{
    int d = 7;
    cout << decToBin(d);
    return 0;
}