#include <iostream>
using namespace std;

int cutRod(vector<int> &price) {
    int n = price.size();
    vector<int> dp(price.size()+1, 0);

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=i; j++) {
            dp[i] = max(dp[i], price[j-1]+dp[i-j]);
        }
    }
    
    return dp[n];
}

int main() {
    vector<int> price =  { 1, 5, 8, 9, 10, 17, 17, 20};
    cout << cutRod(price);
    return 0;
}