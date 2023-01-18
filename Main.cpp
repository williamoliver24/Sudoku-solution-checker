#include <iostream>
#include<set>

// This function checks rows for multiple occurences of the same number and ensures that there are no zeroes
bool rowCheck(unsigned int board[9][9])
{
    for (int i{}; i < 9; ++i)
    {
        std::set<int> rowSet(board[i], board[i] + 9);
        if (rowSet.size() != 9 || rowSet.find(0) != rowSet.end() )
        {
            return false;
        }
    }
    return true;
}

// This function checks columns for multiple occurences of the same number
bool colCheck(unsigned int board[9][9])
{
    for (int i{}; i < 9; ++i)
    {
        std::set<int> colSet;
        for (int j{}; j < 9; ++j)
        {
            colSet.insert(board[i][j]);
        }
        if (colSet.size() != 9)
        {
            return false;
        }
    }
    return true;
}

// This function checks each 3x3 sub-grid for multiple occurences of the same number
bool gridCheck(unsigned int board[9][9])
{
    for (int m{}; m < 9; m += 3)
    {
        std::set<int> gridSet;
        for (int n{}; n < 9; n += 3)
        {
            for (int i{}; i < 3; ++i)
            {
                for (int j{}; j < 3; ++j)
                {
                    gridSet.insert(board[i + n][j + m]);
                }
            }
            if (gridSet.size() != 9)
            {
                return false;
            }
        }
    }
    return true;
}


// This function takes a sudoku in the form of a 9x9 array of unsigned integers from 0-9 (with 0 representing a blank space) and determines whether the sudoku is a valid solution
bool validSolution(unsigned int board[9][9])
{
    if (!rowCheck(board))
    {
        return false;
    }
    if (!colCheck(board))
    {
        return false;
    }
    if (!gridCheck(board))
    {
        return false;
    }

    return true;
}



int main()
{
    unsigned int validSudoku[9][9]{
        {5, 3, 4, 6, 7, 8, 9, 1, 2},
        {6, 7, 2, 1, 9, 5, 3, 4, 8},
        {1, 9, 8, 3, 4, 2, 5, 6, 7},
        {8, 5, 9, 7, 6, 1, 4, 2, 3},
        {4, 2, 6, 8, 5, 3, 7, 9, 1},
        {7, 1, 3, 9, 2, 4, 8, 5, 6},
        {9, 6, 1, 5, 3, 7, 2, 8, 4},
        {2, 8, 7, 4, 1, 9, 6, 3, 5},
        {3, 4, 5, 2, 8, 6, 1, 7, 9},
    };

    unsigned int invalidSudoku[9][9]{
        {5, 3, 4, 6, 7, 8, 9, 1, 2},
        {6, 7, 2, 1, 9, 0, 3, 4, 8},
        {1, 0, 0, 3, 4, 2, 5, 6, 0},
        {8, 5, 9, 7, 6, 1, 0, 2, 0},
        {4, 2, 6, 8, 5, 3, 7, 9, 1},
        {7, 1, 3, 9, 2, 4, 8, 5, 6},
        {9, 0, 1, 5, 3, 7, 2, 1, 4},
        {2, 8, 7, 4, 1, 9, 6, 3, 5},
        {3, 0, 0, 4, 8, 1, 1, 7, 9},
    };

    unsigned int invalidSudoku2[9][9]{
        {5, 3, 4, 6, 7, 8, 9, 0, 2},
        {6, 7, 2, 1, 9, 5, 3, 4, 8},
        {1, 9, 8, 3, 4, 2, 5, 6, 7},
        {8, 5, 9, 7, 6, 1, 4, 2, 3},
        {4, 2, 6, 8, 5, 3, 7, 9, 1},
        {7, 1, 3, 9, 2, 4, 8, 5, 6},
        {9, 6, 1, 5, 3, 7, 2, 8, 4},
        {2, 8, 7, 4, 1, 9, 6, 3, 5},
        {3, 4, 5, 2, 8, 6, 1, 7, 9},
    };

    std::cout << std::boolalpha << validSolution(validSudoku) << '\n';
    std::cout << validSolution(invalidSudoku) << '\n';
    std::cout << validSolution(invalidSudoku2) << '\n';

    return 0;
}