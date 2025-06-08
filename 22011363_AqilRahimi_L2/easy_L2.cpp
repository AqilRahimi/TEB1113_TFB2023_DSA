#include <iostream>
using namespace std;

// Muhammad Aqil Rahimi bin Mohamad Rasidi 
//22011363
int main() {
    int rows, column;
    int k, temp;

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
            cout << mat[i][j];
        }
        cout << endl;
    }

    cout << "Snake Arrangements:"<<endl;
    for(int i = 0; i < rows; i++){
    
        if(i%2 == 0){
            for(int j = 0; j < column; j++){
                cout << mat[i][j];
            }
        }
        else{
            for(int j = column - 1; j >= 0; j--){
                cout << mat[i][j];
            }
        }
    }

    return 0;
}


