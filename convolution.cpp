#include "convolution.h"
#include <iostream>
#include <cstring>

KernelMatrix* selectKernel() {
    KernelMatrix* kernel = new KernelMatrix;
    int choice;
    
    std::cout << "\nSelect kernel type:\n"
              << "1. Horizontal Edge Detection\n"
              << "2. Vertical Edge Detection\n"
              << "3. Sharpen\n"
              << "Choice: ";
    std::cin >> choice;

    switch (choice) {
        case 1: // Horizontal edge detection
            {
                int values[3][3] = {{-1, -1, -1},
                                  { 0,  0,  0},
                                  { 1,  1,  1}};
                std::memcpy(kernel->data, values, sizeof(values));
            }
            break;
        case 2: // Vertical edge detection
            {
                int values[3][3] = {{-1, 0, 1},
                                  {-1, 0, 1},
                                  {-1, 0, 1}};
                std::memcpy(kernel->data, values, sizeof(values));
            }
            break;
        case 3: // Sharpen
            {
                int values[3][3] = {{ 0, -1,  0},
                                  {-1,  5, -1},
                                  { 0, -1,  0}};
                std::memcpy(kernel->data, values, sizeof(values));
            }
            break;
        default:
            {
                int values[3][3] = {{-1, 0, 1},
                                  {-1, 0, 1},
                                  {-1, 0, 1}};
                std::memcpy(kernel->data, values, sizeof(values));
            }
    }
    return kernel;
}

void applyPadding(ImageMatrix* paddedMatrix, const ImageMatrix* originalMatrix) {
    // Initialize padded matrix with zeros
    for(int i = 0; i < paddedMatrix->size; i++) {
        for(int j = 0; j < paddedMatrix->size; j++) {
            paddedMatrix->data[i][j] = 0;
        }
    }

    // Copy original matrix to center of padded matrix
    for(int i = 0; i < originalMatrix->size; i++) {
        for(int j = 0; j < originalMatrix->size; j++) {
            paddedMatrix->data[i + 1][j + 1] = originalMatrix->data[i][j];
        }
    }
}

void performConvolution(ImageMatrix* result, const ImageMatrix* paddedMatrix, const KernelMatrix* kernel) {
    for(int i = 0; i < result->size; i++) {
        for(int j = 0; j < result->size; j++) {
            result->data[i][j] = 0;
            for(int ki = 0; ki < 3; ki++) {
                for(int kj = 0; kj < 3; kj++) {
                    result->data[i][j] += paddedMatrix->data[i + ki][j + kj] * 
                                        kernel->data[ki][kj];
                }
            }
        }
    }
}
