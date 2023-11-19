
//Given a positive integer n, generate an n x n matrix filled with elements from 1 to n^2 in spiral order.

#include <iostream>
using namespace std;

void Spiraling(int res[][10], int n, int& val, int& top, int& bottom, int& left, int& right) {
    while ((left <= right) && (top <= bottom)) {

        for (int c = left; c <= right; c++) {
            res[top][c] = val;
            val += 1;
        }
        top += 1;

        for (int r = top; r <= bottom; r++) {
            res[r][right] = val;
            val += 1;
        }
        right -= 1;

        for (int c = right; c >= left; c--) {
            res[bottom][c] = val;
            val += 1;
        }
        bottom -= 1;

        for (int r = bottom; r >= top; r--) {
            res[r][left] = val;
            val += 1;
        }
        left += 1;
    }
}

void print_Matrix(int res[][10], int n) {
    for (int i = 0; i < n; i++) {
        cout << "[";
        for (int j = 0; j < n; j++) {
            cout << res[i][j] << " ";
        }
        cout << "]" << endl;
    }
}

void creat_SpiralMatrix(int n) {
    int res[10][10] = {0};
    int val = 1;
    int top = 0, bottom = n - 1;
    int left = 0, right = n - 1;

    Spiraling(res, n, val, top, bottom, left, right);
    print_Matrix(res, n);
}

int main() {
    int n;
    cout << "Enter the size of the square matrix n x n: ";
    cin >> n;

    cout << "The result spiral matrix: " << endl;
    creat_SpiralMatrix(n);

    return 0;
}

