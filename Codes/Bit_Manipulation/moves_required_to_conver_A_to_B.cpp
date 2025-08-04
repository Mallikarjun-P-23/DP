#include <iostream>
#include <bitset>
using namespace std;

int minBitFlips(int start, int goal) {
    return bitset<32>(start ^ goal).count();
}

int main() {
    cout << minBitFlips(10, 7) << endl; 
    cout << minBitFlips(3, 3) << endl; 
    cout << minBitFlips(0, 15) << endl; 
    return 0;
}
