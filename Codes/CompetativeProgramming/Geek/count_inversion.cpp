#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    long long mergeAndCount(vector<int>& a, int l, int m, int r) {
        vector<int> left(a.begin() + l, a.begin() + m + 1);
        vector<int> right(a.begin() + m + 1, a.begin() + r + 1);

        int i = 0, j = 0, k = l;
        long long c = 0;

        while (i < left.size() && j < right.size()) {
            if (left[i] <= right[j]) {
                a[k++] = left[i++];
            } else {
                a[k++] = right[j++];
                c += (left.size() - i);  // all remaining left are greater
            }
        }

        while (i < left.size()) a[k++] = left[i++];
        while (j < right.size()) a[k++] = right[j++];

        return c;
    }

    long long mergesortcount(vector<int>& a, int l, int r) {
        long long c = 0;
        if (l < r) {
            int m = l + (r - l) / 2;
            c += mergesortcount(a, l, m);
            c += mergesortcount(a, m + 1, r);
            c += mergeAndCount(a, l, m, r);
        }
        return c;
    }

    long long inversionCount(vector<int>& arr) {
        return mergesortcount(arr, 0, arr.size() - 1);
    }
};

int main() {
    Solution sol;
    vector<int> arr = {2, 4, 1, 3, 5};
    cout << sol.inversionCount(arr) << endl; // Output: 3
}
