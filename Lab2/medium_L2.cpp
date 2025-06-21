#include <iostream>
using namespace std;

/** Name: Muhammad Aqil Rahimi bin Mohamad Rasidi 
    id:   22011363
**/
int main() {
    int rows, column;
    int k;
    int rowindex = 0;
    int colindex = 0;

    cout << "Enter the number of rows: ";
    cin >> rows;

    cout << "Enter the number of column: ";
    cin >> column;

    int mat[rows][column];
    
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < column; j++){
            cout << "Enter a number:";
            cin >> mat[i][j];
        }
    }

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < column; j++){
            cout << mat[i][j] <<" ";
        }
        cout << endl;
    }

    for(int i = 0; i < rows; i++){
        if(i >= 1 && mat[i-1][column -1] >= mat[rowindex][colindex]){
                rowindex = i -1;
                colindex = column -1;
            }
        for(int j = 1; j < column; j++){
            k = j-1;
            if(mat[i][k] >= mat[rowindex][colindex]){
                rowindex = i;
                colindex = k;
            }
        }
    }

    cout << "Peak element found at index: "<< rowindex << ", " << colindex;
    return 0;
}