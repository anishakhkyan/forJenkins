#include <iostream>

int InputAndCheck();
int **InputElements (int row, int column);
void ShowMatrix (int **Matrix, int row, int column);
int **MultConstAndMatrix(int constNumber, int **Matrix, int row, int column);
int **SumOfTwoMatrix(int **Matrix1, int **Matrix2, int row, int column);
int **SubOfTwoMatrix(int **Matrix1, int **Matrix2, int row, int column);
int **MultOfTwoMatrix(int **Matrix1, int **Matrix2, int row1, int column1, int row2, int column2);
void DestroyMatrix(int** Matrix, int row, int column);

int main() {
    int row1 = 0;
    int column1 = 0;
    int row2 = 0;
    int column2 = 0;

    std::cout << "Please, enter count of the rows for the Matrix 1: ";
    row1 = InputAndCheck();
    std::cout << "Please, enter count the columns for Matrix 1: ";
    column1 = InputAndCheck();
    int **Matrix1 = InputElements(row1, column1);

    std::cout << "\nPlease, enter count of the rows for the Matrix 2: ";
    row2 = InputAndCheck();
    std::cout << "Please, enter count the columns for Matrix 2: ";
    column2 = InputAndCheck();
    int **Matrix2 = InputElements(row2, column2);

    std::cout << "\nMatrix 1 is: " << std::endl;
    ShowMatrix(Matrix1, row1, column1);
    std::cout << "\nMatrix 2 is: " << std::endl;
    ShowMatrix(Matrix2, row2, column2);

    std::cout << "\nInsert a constant number with which each Matrix should be multiplied: ";
    int constNumber = InputAndCheck();

    std::cout << "\nMultiplication of inputted constant number and Matrix 1 is: " <<std::endl;
    int **MultConst1 = MultConstAndMatrix(constNumber, Matrix1, row1, column1);
    ShowMatrix(MultConst1, row1, column1);
    DestroyMatrix(MultConst1, row1, column1);

    std::cout << "\nMultiplication of inputted constant number and Matrix 2 is: " <<std::endl;
    int **MultConst2 = MultConstAndMatrix(constNumber, Matrix2, row2, column2);
    ShowMatrix(MultConst2, row2, column2);
    DestroyMatrix(MultConst2, row2, column2);

    if ((row1 == row2) && (column1 ==column2)) {
        std::cout << "\nAddition of Matrix 1 and Matrix 2 is: " << std::endl;
        int **SumMatrix = SumOfTwoMatrix(Matrix1, Matrix2, row1, column1);
        ShowMatrix(SumMatrix, row1, column1);
        DestroyMatrix(SumMatrix, row1, column1);
    } else {
        std::cout << "\nThese two matrices can NOT be added. They DO NOT setisfy the condition of addition." << std::endl;
    }

    if ((row1 == row2) && (column1 ==column2)) {
        std::cout << "\nSubtraction of Matrix 1 and Matrix 2 is: " << std::endl;
        int **SubMatrix = SubOfTwoMatrix(Matrix1, Matrix2, row1, column1);
        ShowMatrix(SubMatrix, row1, column1);
        DestroyMatrix(SubMatrix, row1, column1);
    } else {
        std::cout << "\nThese two matrices can NOT be subtracted. They DO NOT setisfy the condition of subtraction." << std::endl;
    }

    if (row2 == column1) {
        int **MultMatrix = MultOfTwoMatrix(Matrix1, Matrix2, row1, column1, row2, column2);
        std::cout << "\nMultiplication of Matrix 1 and Matrix 2 is: " << std::endl;
        ShowMatrix(MultMatrix, row1, column2);
        DestroyMatrix(MultMatrix, row2, column2);
    } else {
        std::cout << "\nThese two matrices can NOT be multiplicated. They DO NOT setisfy the condition of multiplication." << std::endl;
    }

    DestroyMatrix(Matrix1, row1, column1);
    DestroyMatrix(Matrix2, row2, column2);

    return 0;
}

/*InputAndCheck is a function which will input smth and check whether input is integer or not*/
/* if input is not an integer function will send a message to try again */
int InputAndCheck() {
int input = 0;
std::cin >> input;

        while(std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(100,'\n');
            std::cout << "Please, enter an integer: ";
            std::cin >> input;
        }
        return input;
}

/* InputElement is a function which will input elements of Matrix */
/* function will call inputAndCheck() function to input and check inputed elements of Matrix */
int **InputElements (int row, int column) {
    std::cout << "Please, enter elements of Matrix" << std::endl;
    int **Matrix = new int *[row];
    for (int i = 0; i < row; ++i) {
        Matrix[i] = new int[column];
        for (int j = 0; j < column; ++j) {
            std::cout << "element[" << i << ", " << j << "] = ";
            Matrix[i][j] = InputAndCheck();
        }
    }
    return Matrix;
}

/* ShowMatrix is a function which will print Matrix with its elements */
void ShowMatrix (int **Matrix, int row, int column) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            std::cout << Matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

/* MultConstAndMatrix is a function which multiplicate Matric by inputted constant number */
int **MultConstAndMatrix(int constNumber, int **Matrix, int row, int column) {
    int **multConst = new int *[row];

    for (int i = 0; i < row; ++i) {
        multConst[i] = new int[column];
    }

    for(int i = 0; i < row; ++i) {
        for(int j = 0; j < column; ++j) {
            multConst[i][j] = constNumber * Matrix[i][j];
        }
    }
    return multConst;
}

/* SumOfTwoMatrix is a function calculates the sum of the two Matrices */
int **SumOfTwoMatrix(int **Matrix1, int **Matrix2, int row, int column) {
    int **sumMatrix = new int *[row];
    for (int i = 0; i < row; ++i) {
        sumMatrix[i] = new int[column];
    }

    for(int i = 0; i < row; ++i) {
        for(int j = 0; j < column; ++j) {
            sumMatrix[i][j] = Matrix1[i][j] + Matrix2[i][j];
        }
    }
    return sumMatrix;
}

/* SubOfTwoMatrix is a function calculates the subtraction between the two Matrices */
int **SubOfTwoMatrix(int **Matrix1, int **Matrix2, int row, int column) {
    int **subMatrix = new int *[row];

    for (int i = 0; i < row; ++i) {
        subMatrix[i] = new int[column];
    }

    for(int i = 0; i < row; ++i) {
        for(int j = 0; j < column; ++j) {
            subMatrix[i][j] = Matrix1[i][j] - Matrix2[i][j];
        }
    }
    return subMatrix;
}


/* MultOfTwoMatrix is a function multiplicate two Matrices */
int **MultOfTwoMatrix(int **Matrix1, int **Matrix2, int row1, int column1, int row2, int column2) {
    int **multMatrix = new int *[row1];

    for (int i = 0; i < row1; ++i) {
        multMatrix[i] = new int[column2];
    }

    for (int i = 0; i < row1; ++i) {
        for (int j = 0; j < column2; ++j) {
            multMatrix[i][j] = 0;
        }
    }

    for (int i = 0; i < row1; ++i) {
        for (int j = 0; j < column2; ++j) {
            for (int k = 0; k < column1; ++k) {
                multMatrix[i][j] = multMatrix[i][j] + Matrix1[i][k] * Matrix2[k][j];
            }
        }
    }
    return multMatrix;
}

/* DestroyMatrix is a function which will deallocate the dynemically allocated 2D array using delete operator */
void DestroyMatrix(int** Matrix, int row, int column) {
    for (int i = 0; i < row; ++i) {
        delete [] Matrix[i];
    }
    delete [] Matrix;
}