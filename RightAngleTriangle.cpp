#include <iostream>
using namespace std;

void printTriangle(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i || i == n - 1) // First column, last column, or last row
                cout << "* ";
            else
                cout << "  "; // Space for the hollow part
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    printTriangle(n);
    return 0;
}
