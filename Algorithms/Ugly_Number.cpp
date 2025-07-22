#include<iostream>
using namespace std;

int maxdivide(int n, int x)
{
    while(n%x==0) n=n/x;
    return n;
}

int isUgly(int n)
{
    if(n<=0) return 0;
   int v=maxdivide(n,2);
    v=maxdivide(v,3);
    v=maxdivide(v,5);
    if(v==1) return 1;
    else return 0;

}

int UglyNymber(int n){
    int i=1,c=1;
    while(n>c)
    {
        i++;
        if(isUgly(i)) c++;
    }
   return i;
}

int main(){
    int n;
    cin>>n;
    cout<<UglyNymber(n);
}