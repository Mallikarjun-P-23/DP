#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &b, vector<int> &c, vector<int> &a)
{
    int i = 0, j = 0, k = 0, p = b.size(), q = c.size();
    while(i < p and j < q) 
    {
        a[k++] = ((b[i] <= c[j]) ? b[i++] : c[j++]);
    }
    if(i == p) 
    {
        while(j < q) a[k++] = c[j++];
    }
    else {
        while(i < p) a[k++] = b[i++];
    }
}

void mergesort(vector<int> &a){
    int n = a.size();
    if(n > 1)
    {
        vector<int> b(a.begin(), a.begin() + n/2);
        vector<int> c(a.begin() + n/2, a.end());
        mergesort(b);
        mergesort(c);
        merge(b, c, a);
    }
}

int main()
{
    vector<int> a{5,5,5,1,8,9,6,4,5,8,5,3,0,2,4,7};
    mergesort(a);
    for(int i : a)cout << i << ' ';
} 