/* UVa problem: 10026
 *
 * Topic: Data structure
 *
 * Level: simple
 *
 * Brief problem description:
 *
 *  Minimize the penalty based on the penalty per day and how many days to finish the task.
 *
 * Solution Summary:
 *
 *   sorting
 *
 * Used Resources:
 *
 *
 *
 * I hereby certify that I have produced the following solution myself
 * using only the resources listed above in accordance with the CMPUT
 * 403 collaboration policy.
 *
 *
 * Hung Nguyen
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

bool sortValue(pair<int, float> i, pair<int, float>j) {
    if (i.second == j.second) {
        return i.first < j.first;
    } else {
        return i.second > j.second;
    }
}

int main() {
    int N;
    int numOrders;
    int t, p;
    vector<pair<int, float>> rat;

    cin >> N;

    while (N--) {

        cin >> numOrders;
        for (int i = 0; i < numOrders; i++) {
            cin >> t >> p;
            rat.push_back(make_pair(i, (float)p/t));
        }

        // for (vector<pair<int, float>>::iterator it = rat.begin(); it != rat.end(); ++it) {
        //     cout << (*it).first + 1 << "[" <<(*it).second << "]" << " ";
        // }
        // cout << "\n";

        sort (rat.begin(), rat.end(), sortValue);

        vector<pair<int, float>>::iterator it;
        for (it = rat.begin(); it != rat.end() - 1; ++it) {
            // cout << (*it).first + 1 << "[" <<(*it).second << "]" << " ";
            cout << (*it).first + 1 << " ";
        }
        cout << (*it).first + 1 << "\n";

        if (N != 0)
            cout << "\n";

        rat.clear();
    }

    return 0;
}