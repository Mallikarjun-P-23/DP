#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxMeetings(vector<int>& start, vector<int>& end) {
    int n = start.size();
    vector<pair<int, int>> m;

    for (int i = 0; i < n; i++) {
        m.push_back({end[i], start[i]}); 
    }

    sort(m.begin(), m.end());

    int count = 0;
    int lastEndTime = -1;

    for (int i = 0; i < n; i++) {
        if (m[i].second > lastEndTime) {
            count++;
            lastEndTime = m[i].first;
        }
    }

    return count;
}

int main() {
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};

    cout << "Maximum number of meetings: " << maxMeetings(start, end) << endl;

    return 0;
}
