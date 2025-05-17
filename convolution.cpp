#include "convolution.h"
#include <iostream>
#include <iomanip>

int selectKernelType() {
    int choice;
    
    std::cout << "\nSelect kernel type:\n"
              << "1. Vertical Edge Detection\n"
              << "2. Horizontal Edge Detection\n"
              << "3. Sharpen\n"
              << "4. Blur\n"
              << "Enter your choice (1-4): ";
    std::cin >> choice;
    
    // Validate input
    while(choice < 1 || choice > 4) {
        std::cout << "Invalid choice. Please enter a value between 1 and 4: ";
        std::cin >> choice;
    }
    
    return choice;
}

void initializeKernel(int kernel[3][3], int kernelType) {
    switch(kernelType) {
        case VERTICAL_EDGE_DETECTION:
            // Vertical edge detection filter
            kernel[0][0] = -1; kernel[0][1] = 0; kernel[0][2] = 1;
            kernel[1][0] = -1; kernel[1][1] = 0; kernel[1][2] = 1;
            kernel[2][0] = -1; kernel[2][1] = 0; kernel[2][2] = 1;
            break;
            
        case HORIZONTAL_EDGE_DETECTION:
            // Horizontal edge detection filter
            kernel[0][0] = -1; kernel[0][1] = -1; kernel[0][2] = -1;
            kernel[1][0] = 0;  kernel[1][1] = 0;  kernel[1][2] = 0;
            kernel[2][0] = 1;  kernel[2][1] = 1;  kernel[2][2] = 1;
            break;
            
        case SHARPEN:
            // Sharpen filter
            kernel[0][0] = 0;  kernel[0][1] = -1; kernel[0][2] = 0;
            kernel[1][0] = -1; kernel[1][1] = 5;  kernel[1][2] = -1;
            kernel[2][0] = 0;  kernel[2][1] = -1; kernel[2][2] = 0;
            break;
            
        case BLUR:
            // Simple blur filter - all ones (will normalize during convolution)
            kernel[0][0] = 1; kernel[0][1] = 1; kernel[0][2] = 1;
            kernel[1][0] = 1; kernel[1][1] = 1; kernel[1][2] = 1;
            kernel[2][0] = 1; kernel[2][1] = 1; kernel[2][2] = 1;
            break;
            
        default:
            // Default to vertical edge detection
            kernel[0][0] = -1; kernel[0][1] = 0; kernel[0][2] = 1;
            kernel[1][0] = -1; kernel[1][1] = 0; kernel[1][2] = 1;
            kernel[2][0] = -1; kernel[2][1] = 0; kernel[2][2] = 1;
    }
}

void displayKernel(int kernel[3][3]) {
    std::cout << "Selected Kernel:" << std::endl;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            std::cout << std::setw(3) << kernel[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void applyPadding(int** paddedMatrix, int paddedSize, int** originalMatrix, int originalSize) {
    // Initialize padded matrix with zeros
    for(int i = 0; i < paddedSize; i++) {
        for(int j = 0; j < paddedSize; j++) {
            paddedMatrix[i][j] = 0;
        }
    }
    
    // Copy original matrix to center of padded matrix
    int padding = (paddedSize - originalSize) / 2;
    for(int i = 0; i < originalSize; i++) {
        for(int j = 0; j < originalSize; j++) {
            paddedMatrix[i + padding][j + padding] = originalMatrix[i][j];
        }
    }
}

void performConvolution(int** result, int resultSize, int** paddedMatrix, int paddedSize, int kernel[3][3]) {
    for(int i = 0; i < resultSize; i++) {
        for(int j = 0; j < resultSize; j++) {
            // Initialize the result cell
            result[i][j] = 0;
            
            // Apply convolution operation
            for(int ki = 0; ki < 3; ki++) {
                for(int kj = 0; kj < 3; kj++) {
                    result[i][j] += paddedMatrix[i + ki][j + kj] * kernel[ki][kj];
                }
            }
            
            // Normalize the result specifically for blur kernel (kernel type 4)
            if(kernel[0][0] == 1 && kernel[0][1] == 1 && kernel[0][2] == 1 &&
               kernel[1][0] == 1 && kernel[1][1] == 1 && kernel[1][2] == 1 &&
               kernel[2][0] == 1 && kernel[2][1] == 1 && kernel[2][2] == 1) {
                result[i][j] /= 9;
            }
        }
    }
}
