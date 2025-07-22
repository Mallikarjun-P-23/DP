#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSubarraySum(vector<int> &arr) {
    int res = arr[0];

  	for(int i = 0; i < arr.size(); i++) {
    	int currSum = 0;
  
        for(int j = i; j < arr.size(); j++) {
        	currSum = currSum + arr[j];

            res = max(res, currSum);
        }
    }
    return res;
}

int main() {
    vector<int> arr = {2, 3, -8, 7, -1, 2, 3};
    cout << maxSubarraySum(arr);
    return 0;
}

/*Given an integer array arr[], find the subarray (containing at least one element) 
which has the maximum possible sum, and return that sum.
Note: A subarray is a continuous part of an array.*/ 