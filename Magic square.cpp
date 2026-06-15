#include <iostream>
#include <vector>
using namespace std;

void generateMagicSquare(int n) {
    vector<vector<int>> magicSquare(n, vector<int>(n, 0));

    // Initial position for number 1
    int i = 0, j = n / 2;

    for (int num = 1; num <= n * n; ++num) {
        magicSquare[i][j] = num;
        int newi = (i - 1 + n) % n;
        int newj = (j + 1) % n;

        if (magicSquare[newi][newj] != 0) {
            i = (i + 1) % n;
        } else {
            i = newi;
            j = newj;
        }
    }

    // Output the magic square
    cout << "Magic Square of size " << n << ":\n";
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < n; ++y) {
            cout << magicSquare[x][y] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the size of the magic square (odd number): ";
    cin >> n;

    if (n % 2 == 0) {
        cout << "Magic square is only possible for odd numbers." << endl;
        return 1;
    }

    generateMagicSquare(n);
    return 0;
}