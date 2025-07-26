
#include <iostream>
using namespace std;
#include <vector>
bool isSubsetSumRec(vector<int>& arr, int n, int sum) {
  
    if (sum == 0)
        return true;
    if (n == 0)
        return false;

    if (arr[n - 1] > sum)
        return isSubsetSumRec(arr, n - 1, sum);

    return isSubsetSumRec(arr, n - 1, sum) 
      		|| isSubsetSumRec(arr, n - 1, sum - arr[n - 1]);
}

bool isSubsetSum(vector<int>& arr, int sum) {
    return isSubsetSumRec(arr, arr.size(), sum);
}

int main() {
  
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int sum = 9;

    if (isSubsetSum(arr, sum))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}