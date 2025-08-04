#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSumIS(vector<int> &arr) {
    int ans = 0;
    
    vector<int> dp(arr.size());

    for (int i=0; i<arr.size(); i++) {
        dp[i] = arr[i];
        
        for (int j=0; j<i; j++) {
            if (arr[j]<arr[i]) {
                dp[i] = max(dp[i], arr[i]+dp[j]);
            }
        }
        
        ans = max(ans, dp[i]);
    }
    
    return ans;
}

int main() {
    vector<int> arr = {1, 101, 2, 3, 100};
    cout << maxSumIS(arr);

    return 0;
}