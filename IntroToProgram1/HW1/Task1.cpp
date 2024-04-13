
//Given a length if a number sequence and the sequence itself in the next line, that might contain duplicates, return all possible unique permutations in any order.

#include <iostream>
using namespace std;

void change_positions(int&x , int& y) {     // This is the function to change inputs positions
    int temp = x;
    x = y;
    y = temp;
}

bool duplicate(int numbers[], int begin, int end) {     // This is the function to check if the inputs has any dupblicate digits
    for (int i = begin; i < end; i++) {
        if (numbers[i] == numbers[end]) {
            return 1;
        }
    }
    return 0;
}

void permutations(int numbers[], int length_of_sequence, int current) {     // This is the function to generate permutations
    if (current == length_of_sequence) {
        for (int i = 0; i < length_of_sequence; i++) {
            cout << numbers[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = current; i < length_of_sequence; i++) {        // These are actions using functions to generate permutations
        if (!duplicate(numbers, current, i)) {
            change_positions(numbers[i], numbers[current]);
            permutations(numbers, length_of_sequence, current + 1);
            change_positions(numbers[i], numbers[current]);
        }
    }
}

int main() {
    int length_of_sequence;
    cout << "Enter the length :";
    cin >> length_of_sequence;
    
    cout << "Enter the numbers :";
    int numbers[length_of_sequence];
    for (int i = 0; i < length_of_sequence; i++) {
        cin >> numbers[i];
    }

    permutations(numbers, length_of_sequence, 0);
    
    return 0;
}
