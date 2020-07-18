#include <iostream>

#define N 9

bool checkDublication(int sudoku[N][N], int row, int column, int n)
{

    for (int i = 0; i < N; ++i)
    {
        if ((sudoku[i][column] == n && row !=i) || (sudoku[row][i] == n && column != i))
        {
            return false;
        }
    }

    int subRow = row / 3;
    int subColumn = column / 3;
    for (int i = subRow * 3, j = subColumn * 3; i < (subRow * 3 + 3), j < (subColumn * 3 + 3); ++i, ++j)
    {
        if (sudoku[i][j] == n && i != row && j != column)
        {
            return false;
        }
    }
    return true;
}

bool empty(int sudoku[N][N], int* row, int* column)
{
    for(*row = 0;*row < N; ++(*row))
    {
        for(*column = 0; *column < N; ++(*column))
        {
            if(sudoku[*row][*column] == 0)
            {
                return 0;
            }
        }
    }
    return 1;
}

bool sudokuSolver(int sudoku[N][N])
{
    int row = 0;
    int column = 0;

    if (empty(sudoku, &row, &column))
    {
        return 1;
    }

    for (int i = 1; i <= N; ++i)
    {
        if (checkDublication(sudoku, row, column, i))
        {
            sudoku[row][column] = i;
            if (sudokuSolver(sudoku))
            {
                return true;
            }
            sudoku[row][column] = 0;
        }
    }
    return false;
}

void desplaySudoku(int sudoku[N][N])
{
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            std::cout << sudoku[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

int main()
{
    int sudoku[9][9] = {{0, 2, 0, 5, 0, 1, 0, 9, 0},
                        {8, 0, 0, 2, 0, 3, 0, 0, 6},
                        {0, 3, 0, 0, 6, 0, 0, 7, 0},
                        {0, 0, 1, 0, 0, 0, 6, 0, 0},
                        {5, 4, 0, 0, 0, 0, 0, 1, 9},
                        {0, 0, 2, 0, 0, 0, 7, 0, 0},
                        {0, 9, 4, 0, 3, 0, 0, 8, 0},
                        {2, 0, 0, 8, 0, 4, 0, 0, 7},
                        {0, 1, 0, 9, 0, 7, 0, 6, 0}};

    std::cout << "  GIVEN SUDOKU" << std::endl;
    std::cout << "-----------------" << std::endl;
    desplaySudoku(sudoku);
    std::cout << "-----------------" << std::endl;

    if (sudokuSolver(sudoku) == true)
    {
        std::cout << "\n     SOLVED" << std::endl;
        std::cout << "-----------------" << std::endl;
        desplaySudoku(sudoku);
        std::cout << "-----------------" << std::endl;
    }
    else
    {
        std::cout << "Solution Does Not Exist!" << std::endl;
        std::cout << "-----------------" << std::endl;
    }

    return 0;
}