
#include <iostream>
#include <cmath>
using namespace std;

int jumpSearch(int arr[], int x, int n)
{
    int step = sqrt(n); //get the size of the block
    int prev = 0;
    while (arr[min(step, n)-1] < x)// get the valid interval 
    {
        prev = step;
        step += sqrt(n);
        if (prev >= n)
            return -1;
    }

   
    while (arr[prev] < x)
    {
        prev++;

        if (prev == min(step, n))
            return -1;
    }

    if (arr[prev] == x)
        return prev;

    return -1;
}


int main()
{
    int arr[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21,
                34, 55, 89, 144, 233, 377, 610 };
    int x = 55;
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int index = jumpSearch(arr, x, n);

    cout << "\nNumber " << x << " is at index " << index;
    return 0;
}
/* 
  Jump Search is a searching algorithm for sorted arrays. The basic idea is to 
  check fewer elements (than linear search) by jumping ahead by fixed steps or 
  skipping some elements in place of searching all elements.

For example, suppose we have an array arr[] of size n and a block (to be jumped) 
of size m. Then we search in the indexes arr[0], arr[m], arr[2m].....arr[km], and 
so on. Once we find the interval (arr[km] < x < arr[(k+1)m]), we perform a linear 
search operation from the index km to find the element x.
Let’s consider the following array: (0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610).
 The length of the array is 16. The Jump search will find the value of 55 with the following steps 
 assuming that the block size to be jumped is 4. 
STEP 1: Jump from index 0 to index 4; 
STEP 2: Jump from index 4 to index 8; 
STEP 3: Jump from index 8 to index 12; 
STEP 4: Since the element at index 12 is greater than 55, we will jump back a step to come to index 8. 
STEP 5: Perform a linear search from index 8 to get the element 55.
*/