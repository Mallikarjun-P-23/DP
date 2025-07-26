#include <iostream>
#include <vector>
using namespace std;

int findMissingPositive(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        while (arr[i] > 0 && arr[i] <= n && arr[arr[i] - 1] != arr[i]) {
            swap(arr[i], arr[arr[i] - 1]);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (arr[i] != i + 1)
            return i + 1;
    }

    return n + 1;
}

int main() {
    vector<int> arr1 = {2, -3, 4, 1, 1, 7};
    vector<int> arr2 = {5, 3, 2, 5, 1};
  

    cout << findMissingPositive(arr1) << endl;
    cout << findMissingPositive(arr2) << endl;


    return 0;
}
