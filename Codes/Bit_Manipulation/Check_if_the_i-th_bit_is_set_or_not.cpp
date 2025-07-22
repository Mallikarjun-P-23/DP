#include <iostream>
#include <bitset>
using namespace std;

bool isIthBitSet(int n, int i) {
    bitset<32> bits(n);
    return bits.test(i);// Check if the i-th bit is set
}

int main() {
    cout << boolalpha;

    cout << isIthBitSet(5, 0) << endl;  // true (5 = 000...0101)
    cout << isIthBitSet(10, 1) << endl; // true (10 = 000...1010)
    cout << isIthBitSet(10, 2) << endl; // false (10 = 000...1010)

    return 0;
}
