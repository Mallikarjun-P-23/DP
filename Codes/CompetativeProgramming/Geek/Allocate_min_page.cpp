#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
 
 bool ispossible(vector<int> &arr,int k,int m)
    {
        int s=1,p=0;
        
        for(auto x:arr)
        {
            if(p+x>m)
            {
                s++;
                p=x;
                if(s>k) return false;
            }
            else {
                p+=x;
            }
        }
        return true;
    }
    
    int findPages(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        if(k>n) return -1;
        
        int l=*max_element(arr.begin(),arr.end());
        int h= accumulate(arr.begin(),arr.end(),0);
        int a=-1;
        while(l<=h)
        {
            int m=l+(h-l)/2;
            if(ispossible(arr,k,m))
            {
                a=m;
                h=m-1;
            }
            else{
                l=m+1;
            }
        }
        
        return a;
    }

int main()
{
    vector<int> arr = {12, 34, 67, 90};
    int k = 2;
    cout << "Minimum number of pages = " << findPages(arr, k) << endl;
    return 0;
}