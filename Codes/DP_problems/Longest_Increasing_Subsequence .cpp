#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int LIS(vector<int>&a,int n)
{
  vector<int>dp(n,1);
  for (int i = 0; i < n; i++)
  {
    /* code */ for (int j = 0; j< i; j++)
    {
        if(a[i]>a[j]&&dp[i]<dp[j]+1)
        {
            dp[i]=dp[j]+1;
        }
    }
    
  }
  return *max_element(dp.begin(),dp.end());

}

int main()
{
    vector<int> arr = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int n = arr.size();
    cout<< "Length of Longest Increasing Subsequence is: "<<LIS(arr, n) << endl;

}