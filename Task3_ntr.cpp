#include <iostream>
#include <cmath>
using namespace std;

void bubbleSort(float arr[], int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
 
        if (swapped == false)
            break;
    }
}

void Euclid(int arr[][2], int n, int k){
    float ans[n];
    for (int i = 0; i < n; i++){
        ans[i] = sqrt(pow((arr[i][0]),2) + pow((arr[i][1]),2));
    }
    float temp[n];
    for (int i = 0; i < n; i++){
        temp[i] = ans[i];
    }
    bubbleSort(temp, n);

    for (int i = 0; i < n; i++){
        for (int j = 0; j < k; j++){
            if (ans[i] == temp[j]){
                cout << arr[i][0] <<" "<< arr[i][1];
            }
        }
        cout << endl;
    }
}
int main(){
    int n,k;
    cout << "The number of points input: ";
    cin >> n;
    cout << "The number of points you want return: ";
    cin >> k;
    cout << "Enter points : ";
    int arr[n][2];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 2; j++){
            cin >> arr[i][j];
        }
    }
    cout << "The " << k <<" point(s) near the origin: " ;
    Euclid(arr, n, k);
    return 0;

}