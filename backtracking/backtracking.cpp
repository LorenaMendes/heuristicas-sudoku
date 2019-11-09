#include <iostream>
#define UNASSIGNED 0 
#define N 9 
  
bool FindUnassignedLocation(int grid[N][N], int &row, int &col);
bool isSafe(int grid[N][N], int row, int col, int num); 
bool SolveSudoku(int grid[N][N]);
bool UsedInRow(int grid[N][N], int row, int num);
bool UsedInCol(int grid[N][N], int col, int num);
bool UsedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num);
void printGrid(int grid[N][N]);

int main() {

    int dim;
    scanf("%d", &dim);

    int matrix[N][N];

    for (int i = 0; i < dim; ++i)
        for (int j = 0; j < dim; ++j)
            scanf("%d", &matrix[i][j]);
    

    if (SolveSudoku(matrix) == true) printGrid(matrix); 
    else printf("No solution exists");

    return 0; 
}

bool SolveSudoku(int grid[N][N]) { 
    int row, col; 
  
    // If there is no unassigned location, we are done 
    if (!FindUnassignedLocation(grid, row, col)) 
       return true; // success! 
  
    // consider digits 1 to 9 
    for (int num = 1; num <= 9; num++) { 
        // if looks promising 
        if (isSafe(grid, row, col, num)) { 
            // make tentative assignment 
            grid[row][col] = num; 
  
            // return, if success, yay! 
            if (SolveSudoku(grid)) 
                return true; 
  
            // failure, unmake & try again 
            grid[row][col] = UNASSIGNED; 
        } 
    } 
    return false; // this triggers backtracking 
} 

bool FindUnassignedLocation(int grid[N][N], int &row, int &col) { 
    for (row = 0; row < N; row++) 
        for (col = 0; col < N; col++) 
            if (grid[row][col] == UNASSIGNED) 
                return true; 
    return false; 
} 
  
bool UsedInRow(int grid[N][N], int row, int num) { 
    for (int col = 0; col < N; col++) 
        if (grid[row][col] == num) 
            return true; 
    return false; 
} 
  
bool UsedInCol(int grid[N][N], int col, int num) { 
    for (int row = 0; row < N; row++) 
        if (grid[row][col] == num) 
            return true; 
    return false; 
} 
  
bool UsedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num) { 
    for (int row = 0; row < 3; row++) 
        for (int col = 0; col < 3; col++) 
            if (grid[row+boxStartRow][col+boxStartCol] == num) 
                return true; 
    return false; 
} 
  
bool isSafe(int grid[N][N], int row, int col, int num) { 
    return !UsedInRow(grid, row, num) && 
           !UsedInCol(grid, col, num) && 
           !UsedInBox(grid, row - row%3 , col - col%3, num)&& 
            grid[row][col]==UNASSIGNED; 
} 
  
void printGrid(int grid[N][N]) { 
    for (int row = 0; row < N; row++) { 
       for (int col = 0; col < N; col++) 
             printf("%2d", grid[row][col]); 
        printf("\n"); 
    } 
}