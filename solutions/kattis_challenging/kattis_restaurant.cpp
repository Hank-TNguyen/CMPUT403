/* Kattis: restaurant
 *
 * Topic: others
 *
 * Level: challenging
 *
 * Brief problem description:
 *
 *   Do operations based on order
 *
 * Solution Summary:
 *
 *   basic IO
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

#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

int main() {

    int N;

    cin >> N;

    while (N != 0) {
        int m, pile_1, pile_2;
        string action;

        m = 0;
        pile_1 = 0;
        pile_2 = 0;

        for (int i = 0; i < N; i++) {
            cin >> action >> m;

            if (action == "DROP") {
                pile_2 += m;
                cout << "DROP 2 " << m << "\n";
            } else {
                if (pile_1 >= m) {
                    pile_1 -= m;
                    cout << "TAKE 1 " << m << "\n";
                } else {
                    if (pile_1 != 0) {
                        cout << "TAKE 1 " << pile_1 << "\n";
                        m -= pile_1;
                        pile_1 = 0;
                    }
                    cout << "MOVE 2->1 " << pile_2 << "\n";
                    pile_1 = pile_2 - m;
                    pile_2 = 0;
                    cout << "TAKE 1 " << m << "\n";
                }
            }
        }

        cin >> N;

        if (N != 0) {
            cout << "\n";
        }
    }

    return 0;
}
