#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

double fractionalKnapsack(int capacity, const vector<double>& val, const vector<double>& wt) {
    int n = val.size();

    vector<int> indices(n);
    for (int i = 0; i < n; ++i)
        indices[i] = i;

    // Sort indices based on value/weight ratio
    sort(indices.begin(), indices.end(), [&](int a, int b) {
        return (val[a] / wt[a]) > (val[b] / wt[b]);
    });

    double totalValue = 0.0;

    for (int i = 0; i < n && capacity > 0; ++i) {
        int idx = indices[i];
        if (wt[idx] <= capacity) {
            totalValue += val[idx];
            capacity -= wt[idx];
        } else {
            totalValue += val[idx] * (capacity / wt[idx]);
            break;
        }
    }

    return totalValue;
}

// Driver Code
int main() {
    cout << fixed << setprecision(6);

    cout << fractionalKnapsack(50, {60, 100, 120}, {10, 20, 30}) << endl;  // Output: 240.000000
    cout << fractionalKnapsack(50, {60, 100}, {10, 20}) << endl;           // Output: 160.000000
    cout << fractionalKnapsack(100, {10, 20, 30}, {5, 10, 15}) << endl;  

    return 0;
}
