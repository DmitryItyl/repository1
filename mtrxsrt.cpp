#include <iostream>

void fillArray(int** array, int count_rows, int count_cols);
void showArray(int** array, int count_rows, int count_cols);

int main()
{

    std::cout << "How many rows:" << std::flush;
    int rows;
    std::cin >> rows;

    std::cout << "How many columns: " << std::flush;
    int columns;
    std::cin >> columns;

    int **matrix = new int* [rows];
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new int[columns];
    }
    fillArray(matrix, rows, columns);

    std::cout << "Your matrix:" << std::endl;
    showArray(matrix, rows, columns);

    //checkers is to store each row's average value and indicies
    float* checkers = new float[rows];

    for (int i = 0; i < rows; i++)
    {
        int sum{ 0 };
        for (int j = 0; j < columns; j++)
        {
            sum += matrix[i][j];
        }

        checkers[i] = sum / columns;
    }


    // bubble sort
    bool swap = true;
    while (swap)
    {
        swap = false;
        for (int i = 0; i < rows - 1; i++) {
            if (checkers[i] > checkers[i + 1]) {
                std::swap(checkers[i], checkers[i + 1]);
                std::swap(matrix[i], matrix[i + 1]);
                swap = true;
            }
        }
    }

    std::cout << "Sorted matrix:" << std::endl;
    showArray(matrix, rows, columns);
    

    for (int i = 0; i < rows; i++)
    {
        delete[]matrix[i];
    }
    delete[]matrix;

    delete[]checkers;

    return 0;
}

void fillArray(int** array, int count_rows, int count_cols)
{
    for (int i = 0; i < count_rows; i++)
    {
        for (int j = 0; j < count_cols; j++)
        {
            array[i][j] = std::rand() % 100;
        }
    }

}

void showArray(int** array, int count_rows, int count_cols)
{
    for (int i = 0; i < count_rows; i++)
    {
        for (int j = 0; j < count_cols; j++)
        {
            std::cout << array[i][j] << " " << std::flush;
        }

        std::cout << std::endl;
    }
}