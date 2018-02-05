/* Kattis: 10kindsofpeople
 *
 * Topic: Graph Algorithms
 *
 * Level: challenging
 *
 * Brief problem description:
 *
 *   Given a matrix of 0, 1. See if there is a way to go from a point to another not crossing 0 to 1 or 1 to 0
 *
 * Solution Summary:
 *
 *   Graph - union find
 *
 * Used Resources:
 *
 *  Code-Archive
 *
 * I hereby certify that I have produced the following solution myself
 * using only the resources listed above in accordance with the CMPUT
 * 403 collaboration policy.
 *
 *
 * Hung Nguyen
 */

#include <stdio.h>
#include <iostream>
#include <utility>

using namespace std;

char x[1000][1001] = {};
int r, c, q;

#define MAXN 1000000

int sets[MAXN] = {-1};

// convert coordinate to single number
int convertSingle(int x, int y) {
    return x * 1000 + y;
}

int find(int x){
    // cout << "root of " << x << " is " << sets[x] << "\n";
    if(sets[x] < 0) return x;
    return sets[x] = find(sets[x]);
}

void join(int r1, int c1, int r2, int c2){
    // cout << "join " << r1 << ", "<< c1 << "    " << r2 << ", " << c2 << "\n";
    int a = convertSingle(r1, c1);
    int b = convertSingle(r2, c2);

    int ra = find(a);
    // cout << "a " << ra << "\n";
    int rb = find(b);
    // cout << "a " << ra << " " << "b " << rb << "\n";

    if(ra != rb){
        // cout << a << b << "not yet connected \n";
        sets[ra] += sets[rb];
        sets[rb] = ra;
    }
    // cout << "a " << a << " " << "ra " << sets[a] << "\n";
}

int main() {

    cin >> r >> c;

    // init
    for (int i = 0; i < MAXN; i ++) {
        sets[i] = -1;
    }

    for (int i = 0; i < r; i++) {
        cin >> x[i];
    }

    // first row
    for (int i = 0; i < c - 1; i++) {
        // cout << i;
        if (x[0][i] == x[0][i + 1]) {
            join(0, i, 0, i + 1);
        }
    }

    // row 1 to r - 1
    for (int i = 1; i < r; i++) {
        for (int j = 0; j < c - 1; j++) {

            if (x[i][j] == x[i][j + 1])
                join(i, j, i, j + 1);

            if (x[i][j] == x[i - 1][j])
                join(i, j, i - 1, j);

        }

        // last col
        if (x[i][c - 1] == x[i - 1][c - 1])
            join(i, c - 1, i - 1, c - 1);
    }

    // cout << "finish map \n";

    int r1, c1, r2, c2;
    cin >> q;

    while (q--) {
        cin >> r1 >> c1 >> r2 >> c2;
        // cout << "query " << r1 << c1 << r2 << c2 << "\n";
        if (find(convertSingle(r1 - 1, c1 - 1)) != find(convertSingle(r2 - 1, c2 - 1)))
            cout << "neither\n";
        else
            if (x[r1 - 1][c1 - 1] == '1') {
                cout << "decimal\n";
            } else {
                cout << "binary\n";
            }

    }

    return 0;
}



