class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        int n = arr.size();
        int totalSum = 0;

        int max_end_here = arr[0], max_so_far = arr[0];
        int min_end_here = arr[0], min_so_far = arr[0];

        totalSum = arr[0];

        for (int i = 1; i < n; ++i) {
            int num = arr[i];
            totalSum += num;

            max_end_here = max(num, max_end_here + num);
            max_so_far = max(max_so_far, max_end_here);

            min_end_here = min(num, min_end_here + num);
            min_so_far = min(min_so_far, min_end_here);
        }

 
        if (max_so_far < 0)
            return max_so_far;

        return max(max_so_far, totalSum - min_so_far);
    }
};
#include <iostream>
#include <vector>
using namespace std;

int main() {
    Solution s;
    vector<int> arr = {8, -8, 9, -9, 10, -11, 12};
    cout << s.maxCircularSum(arr) << endl; 
}
