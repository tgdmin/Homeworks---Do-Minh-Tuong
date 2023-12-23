
//You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.
//One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.
//Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).
//Note: You cannot rotate an envelope.
//The input is number of envelopes N and N lines of widths and lengths of envelopes 

#include <iostream>
using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition_for_qs(int** arr, int low, int high) {        // This function is the partition which is used later for quicksort
    int p = arr[high][0];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j][0] <= p) {
            i++;
            for (int k = 0; k < 2; k++) {
                swap(arr[i][k], arr[j][k]);
            }
        }
    }
    for (int k = 0; k < 2; k++) {
        swap(arr[i + 1][k], arr[high][k]);
    }
    return i + 1;
}

void quickSort(int** arr, int low, int high) {          // Sorting all the values
    if (low < high) {
        int pi = partition_for_qs(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int max_Russiandoll(int** arr, int n) {         // Find the maximum value which is the answer
    if (n == 0) {
        return 0;
    }

    quickSort(arr, 0, n - 1);

    int res = 1;
    int max_H = arr[0][1];

    for (int i = 1; i < n; i++) {
        if (arr[i][1] > max_H) {
            res++;
            max_H = arr[i][1];
        }
    }

    return res;
}

int main() {
    int n;
    cout << "The number of input: " << endl;
    cin >> n;
    int** arr = new int*[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[2];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> arr[i][j];
        }
    }
    int answer = max_Russiandoll(arr, n);

    cout << "Maximum number of envelopes that can be Russian doll: " << answer;

    for (int i = 0; i < n; i++) {       // Delete the memories which indicated before
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}
