
//An axis-aligned rectangle is represented as a two dots — bottom left and top right. User writes the dots for two rectangles as two lines with four numbers in each:
//x1 y1 x2 y2
//X1 Y1 X2 Y2
//where (x1, y1) is the coordinate of first rectangle bottom-left corner, and (x2, y2) is the coordinate of its top-right corner. Its top and bottom edges are parallel to the X-axis, and its left and right edges are parallel to the Y-axis.
//Two rectangles overlap if the area of their intersection is positive. To be clear, two rectangles that only touch at the corner or edges do not overlap.
//Given two axis-aligned rectangles, return true if they overlap, otherwise return false.

#include <iostream>
using namespace std;

void overlap(int rec1[], int rec2[]){       // This function is used to declare the condition of overlapping rectangles
    if ((rec2[0] >= rec1[2]) || (rec1[0] >= rec2[2]) || (rec2[1] >= rec1[3]) || (rec1[1] >= rec2[3])) {
        cout << "False";
    } else {
        cout << "True";
    }
}

int main() {
    int rec1[4];
    int rec2[4];
  
    cout << "Enter the value of the 1st rectangle: ";
    for(int i = 0; i < 4; i++){
        cin >> rec1[i];
        }

    cout << "Enter the value of the 2nd rectangle: ";
    for(int i = 0; i < 4; i++){
        cin >> rec2[i];
        }
  
    cout << "Two rectangles overlap: ";
    overlap(rec1, rec2);

    return 0;
}
