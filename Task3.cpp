
//Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).
//The distance between two points on the X-Y plane is the Euclidean distance 
//You may return the answer in any order.
//In the first line number of points N and k are given from the keyboard, after that goes N lines of points with x and y coordinate divided by a space

#include <iostream>
using namespace std;

int dis(int a, int b){              
    int dis;
    dis = a*a + b*b;
    return dis;
}

int main()
{   
    cout << "Enter the numbers of points: ";
    int n, i, j;
    cin >> n;

    int m = 2*n;
    int points[m];
    for(i = 0; i < m; i++){
        if(i%2==0)
            cout << "Enter the coordinates of " << i/2 + 1 << "th point: ";
        cin >> points[i];
    }

    cout << "Enter k: ";
    int k;
    cin >> k;
    
    int dis_to_origin[n];                                             
    for(i = 0; i < n; i++){
        dis_to_origin[i] = dis(points[i*2], points[i*2+1]);
    }
    
    for (i = 0; i < n - 1; i++) {                         
        for (j = i + 1; j < n; j++) {
	        if(dis_to_origin[i] > dis_to_origin[j]) { 
		        swap(dis_to_origin[i], dis_to_origin[j]);
            }
        }
    }

    cout << "The " << k << " closest points to the origin: " << endl;
   
    int check = 0;   
    
    for(i = 0; i < n; i++){                                                         
        if(dis(points[i*2], points[i*2+1]) < dis_to_origin[k]){
            cout << "[" << points[i*2] << ", " << points[i*2+1] << "]" << endl;
        check++;
        }
    }
    
    if(check == 0){
        for(i = 0; i < n; i++){                                                         
            if(dis(points[i*2], points[i*2+1]) <= dis_to_origin[k]){
                cout << "[" << points[i*2] << ", " << points[i*2+1] << "]" << endl;
                check++;
                if(check == k) break;
            }
        }
    }
    return 0;
}