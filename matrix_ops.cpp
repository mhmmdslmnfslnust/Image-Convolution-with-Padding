#include "matrix_ops.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>

// Define configurable constants
const int MIN_SIZE = 3;
const int MAX_SIZE = 12;

int getValidatedMatrixSize() {
    int size;
    do {
        std::cout << "Enter matrix size (" << MIN_SIZE << "-" << MAX_SIZE << "): ";
        std::cin >> size;
        
        if (size < MIN_SIZE || size > MAX_SIZE) {
            std::cout << "Invalid size. Please enter a value between " 
                      << MIN_SIZE << " and " << MAX_SIZE << ".\n";
        }
    } while (size < MIN_SIZE || size > MAX_SIZE);
    
    return size;
}

int** allocateMatrix(int size) {
    // Allocate memory for the matrix
    int** matrix = new int*[size];
    for (int i = 0; i < size; i++) {
        matrix[i] = new int[size];
    }
    return matrix;
}

void deallocateMatrix(int** matrix, int size) {
    // Free the allocated memory
    for (int i = 0; i < size; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void generateRandomImage(int** image, int size) {
    // Generate random values for the image matrix
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            // Values between 0 and 255 for grayscale image
            image[i][j] = rand() % 256;
        }
    }
}

void displayMatrix(int** matrix, int size, const char* title) {
    std::cout << title << ":" << std::endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << std::setw(5) << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void initializeWithZeros(int** matrix, int size) {
    // Initialize all elements to zero
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = 0;
        }
    }
}
