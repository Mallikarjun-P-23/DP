#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int getMinDiff(vector<int> &arr, int n, int k) {
    if (n == 1) return 0;

    sort(arr.begin(), arr.end());
    int ans = arr[n - 1] - arr[0];

    for (int i = 0; i < n ; ++i) {
        if(arr[i]-k<0) continue; 
        int minVal = min(arr[0] + k, arr[i] - k);
        int maxVal = max(arr[n - 1] - k, arr[i - 1] + k);

        if (minVal < 0) continue;

        ans = min(ans, maxVal - minVal);
    }

    return ans;
}

int main() {
    vector<int> arr1 = {1, 5, 8, 10};
    int n1 = arr1.size();
    int k1 = 2;

    cout << getMinDiff(arr1, n1, k1) << endl; 
    return 0;
}
