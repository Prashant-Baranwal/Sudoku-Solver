#include <iostream>
#include <vector>
using namespace std;

// Rules to solve a Sudoku
// 1. Each digits from 1 to 9 should appear exactly once in a Row
// 2. Each digits from 1 to 9 should appear exactly once in a Column
// 3. Each digits from 1 to 9 should appear exactly once in a (3x3) Square

bool isValid(vector<string>& board, int row, int col, char c)
{
    for (int k=0; k<9; k++)
    {
        if (board[row][k] == c)
        {
            return false;
        }
        if (board[k][col] == c)
        {
            return false;
        }
        if (board[3*(row/3) + (k/3)][3*(col/3) + (k % 3)] == c)
        {
            return false;
        }
    }
    return true;
}

bool Solve_Sudoku(vector<string>& board)
{
    for (int i=0; i<board.size(); i++)
    {
        for (int j=0; j<board[0].length(); j++)
        {
            if (board[i][j] == '.')
            {
                for (char c='1'; c<='9'; c++)
                {
                    if (isValid(board,i,j,c))
                    {
                        board[i][j] = c;
                        if (Solve_Sudoku(board))
                        {
                            return true;
                        }
                        else
                        {
                            board[i][j] = '.';
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

main()
{
    int n = 9;
    vector <string> board;
    for (int i=0; i<n; i++)
    {
        string s;
        cin>>s;
        board.push_back(s);
    }
    cout<<endl;
    cout<<"Before Solving --->"<<endl;
    cout<<endl;
    for (int i=0; i<9; i++)
    {
        if (i%3 == 0)
        {
            cout<<" -----------------------"<<endl;
        }
        for (int j=0; j<9; j++)
        {
            if (j%3 == 0)
            {
                cout<<"|"<<" ";
            }
            if (board[i][j] != '.')
            {
                cout<<board[i][j]<<" ";
            }
            else
            {
                cout<<"  ";
            }
        }
        cout<<"|"<<endl;
    }
    cout<<" -----------------------"<<endl;
    Solve_Sudoku(board);
    cout<<endl;
    cout<<"After Solving --->"<<endl;
    cout<<endl;
    for (int i=0; i<9; i++)
    {
        if (i%3 == 0)
        {
            cout<<" -----------------------"<<endl;
        }
        for (int j=0; j<9; j++)
        {
            if (j%3 == 0)
            {
                cout<<"|"<<" ";
            }
            cout<<board[i][j]<<" ";
        }
        cout<<"|"<<endl;
    }
    cout<<" -----------------------"<<endl;
}