#ifndef MATRIX_OPS_H
#define MATRIX_OPS_H

#include <iostream>

// Configurable constants
extern const int MIN_SIZE;
extern const int MAX_SIZE;

// Function to get and validate user input for matrix size
int getValidatedMatrixSize();

// Functions for matrix operations
void generateRandomImage(int** image, int size);
void displayMatrix(int** matrix, int size, const char* title);
void initializeWithZeros(int** matrix, int size);

// Memory management functions
int** allocateMatrix(int size);
void deallocateMatrix(int** matrix, int size);

#endif // MATRIX_OPS_H
