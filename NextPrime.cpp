/*     Next Prime Number
Given an integer n. Write a program to find the first prime number greater than n.

Examples:
Input: n = 15
Output: 17
Explanation: 17 is next prime number.
Input: n = 7
Output: 11
Explanation: 11 is the prime number next to 7.   */

#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int num) {
    if (num < 2) return false;
    if (num == 2 || num == 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;

    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
}

int nextPrime(int N) {
    int next = N + 1;
    while (true) {
        if (isPrime(next)) return next;
        next++;
    }
}

int main() {
    int N;
    cin >> N;
    cout << nextPrime(N) << endl;
    return 0;
}
