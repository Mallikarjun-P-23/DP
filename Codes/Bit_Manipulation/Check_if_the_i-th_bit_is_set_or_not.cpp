#include <iostream>
#include <bitset>
using namespace std;

bool isIthBitSet(int n, int i) {
    bitset<32> bits(n);
    return bits.test(i);// Check if the i-th bit is set
}

int main() {
    cout << boolalpha;

    cout << isIthBitSet(5, 0) << endl;  
    cout << isIthBitSet(10, 1) << endl; 
    cout << isIthBitSet(10, 2) << endl; 

    return 0;
}
