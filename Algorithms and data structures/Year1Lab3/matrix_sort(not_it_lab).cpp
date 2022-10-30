//
// Created by razuv on 29.10.2022.
//

#include <iostream>
#include <cstdlib>

int main()
{
    const int rows = 3;
    const int cols = 3;
    int matrix[rows][cols] = {5, 2, 1, 1, 10, 200, 20, 30, 3};

    std::cout << "Our base matrix (kirill pidor): " << std::endl;
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j)
            std::cout << matrix[i][j] << " ";

        std::cout << std::endl;
    }
    /* СОРТИРУЕМ СТРОКИ */
    /* по принципу действия что-то типо сортировки перестановками (insertion sort) */
    for(int k = 0; k < rows * cols; ++k) {
        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                if(j != cols - 1) {
                    if(matrix[i][j+1] < matrix[i][j]) {
                        int tmp = matrix[i][j+1];
                        matrix[i][j+1] = matrix[i][j];
                        matrix[i][j] = tmp;
                    }
                }
                /* СОРТИРУЕМ СТОЛБЦЫ */
                else {
                    if((matrix[i+1][0] < matrix[i][j]) && (i != rows - 1)) {
                        int tmp = matrix[i+1][0];
                        matrix[i+1][0] = matrix[i][j];
                        matrix[i][j] = tmp;
                    }
                }
            }
        }
    }

    std::cout << "Sorted by matrix massive (dima pidor semen molodec): " << std::endl;
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j)
            std::cout << matrix[i][j] << " ";

        std::cout << std::endl;
    }
}