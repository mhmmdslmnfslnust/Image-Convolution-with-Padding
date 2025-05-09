#include "matrix_ops.h"
#include <iostream>
#include <iomanip>

ImageMatrix* createImageMatrix(int size) {
    ImageMatrix* matrix = new ImageMatrix;
    matrix->size = size;
    matrix->data = new int*[size];
    for(int i = 0; i < size; i++) {
        matrix->data[i] = new int[size];
    }
    return matrix;
}

void deleteImageMatrix(ImageMatrix* matrix) {
    for(int i = 0; i < matrix->size; i++) {
        delete[] matrix->data[i];
    }
    delete[] matrix->data;
    delete matrix;
}

void displayMatrix(const ImageMatrix* matrix, const char* title) {
    std::cout << "\n" << title << ":\n";
    for(int i = 0; i < matrix->size; i++) {
        for(int j = 0; j < matrix->size; j++) {
            std::cout << std::setw(5) << matrix->data[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void generateRandomImage(ImageMatrix* matrix) {
    for(int i = 0; i < matrix->size; i++) {
        for(int j = 0; j < matrix->size; j++) {
            matrix->data[i][j] = rand() % 256;
        }
    }
}
