#include <iostream>
#include <bitset>
using namespace std;


bool isPowerOfTwo(int n) {
    return n > 0 && bitset<32>(n).count() == 1;
}


int main() {
    cout << boolalpha;

    cout << isPowerOfTwo(1) << endl;  
    cout << isPowerOfTwo(16) << endl;  
    cout << isPowerOfTwo(18) << endl;  
    cout << isPowerOfTwo(0) << endl;   
    cout << isPowerOfTwo(-2) << endl;  

    return 0;
}
