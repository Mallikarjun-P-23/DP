#include <iostream>
#include <vector>
using namespace std;

int findPeakElement(vector<int>& arr) {
    int n = arr.size();
    int low = 0, high = n - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] < arr[mid + 1]) {
   
            low = mid + 1;
        } else {
      
            high = mid;
        }
    }
    return low; 
}

bool isCorrectPeak(vector<int>& arr, int idx) {
    int n = arr.size();
    long long left = (idx == 0) ? LLONG_MIN : arr[idx - 1];
    long long right = (idx == n - 1) ? LLONG_MIN : arr[idx + 1];
    return (arr[idx] > left && arr[idx] > right);
}

int main() {
    vector<int> arr = {10, 20, 15, 2, 23, 90, 80};
    int idx = findPeakElement(arr);
    cout << (isCorrectPeak(arr, idx) ? "true" : "false") << endl;
    return 0;
}
