/* Kattis: digitsum
 *
 * Topic: Number theory
 *
 * Level: challenging
 *
 * Brief problem description:
 *
 *   Sum of all the digits of numbers between 2 numbers
 *
 * Solution Summary:
 *
 *   Number theory, counting
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
#include <iostream>

using namespace std;

long int sumOfDigits(long int n) {
    long int q = n, _r, sum = 0;
    while (q) {
        _r = q % 10;
        q = q / 10;
        sum += _r;
    }
    return sum;
}

long int sumUnder10(long int i) {
    return (1 + i) * i / 2;
}

long int sumToN(long int n) {
    long int t, r;
    t = n / 10;
    r = n % 10;
    if (n < 10) {
        return sumUnder10(n);
    }

    // cout << t << " " << r <<  " " << 10 * sumToN(t - 1) << "\n";
    return ((45 * t) + (10 * sumToN(t - 1)) + (r * (r + 1) / 2) + ((r + 1) * sumOfDigits(t)));
}

int main() {

    int T;

    cin >> T;
    // int i = 31;
    // while (i--)
    //     cout << i << " " << sumToN(i) << "\n";

    // cout << sumToN(31) << "\n";

    while (T--) {
        long int a, b;
        cin >> a >> b;
        cout << (sumToN(b) - sumToN(a - 1)) << "\n";
        // cout << sumOfDigits(30) << "\n";

    }

    return 0;
}
