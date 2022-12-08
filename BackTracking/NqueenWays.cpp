#include <bits/stdc++.h>
using namespace std;

void printBoard(int n, int board[][20])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool canPlace(int board[][20], int n, int x, int y)
{
    // column
    for (int k = 0; k < x; k++)
    {
        if(board[k][y] == 1)
        {
            return false;
        }
    }
    
    // Left Diagonal
    int i = x;
    int j = y;
    while (i >= 0 && j >= 0)
    {
        if(board[i][j] == 1)
        {
            return false;
        }
        i--; j--;
    }
    
    // Right Diagonal
    i = x;
    j = y;
    while (i >= 0 && j < n)
    {
        if(board[i][j] == 1)
        {
            return false;
        }
        i--; j++;
    }
    return true;
}

int solveNQueen(int n, int board[][20], int i)
{
    // Base case

    if(i == n)
    {
        // Print the board
        // printBoard(n, board);
        // return true;

        return 1;
    }

    // Recursive case
    // Try to place the queen in every row
    int ways = 0;

    for(int j = 0; j < n; j++)
    {
        // Weather the current i, j is safe or not
        if(canPlace(board, n, i, j))
        {
            board[i][j] = 1;
            ways += solveNQueen(n, board, i + 1);

            // Backtracking
            board[i][j] = 0;
        }
    }
    return ways;
}

int main()
{
    // vector<vector<int>> board(n, vector<int>(n, 0));
    int board[20][20] = {0};
    int n;
    cin >> n;
    cout << "No. of ways to solve N-Queen problem = " << solveNQueen(n, board, 0);
    return 0;
}