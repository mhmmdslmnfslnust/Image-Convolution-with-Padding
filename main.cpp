#include <iostream>
#include <cstdlib>
#include <ctime>
#include "matrix_ops.h"
#include "convolution.h"

/**
 * Image Convolution Program with Padding
 * 
 * This program demonstrates the application of convolution operations
 * on matrices that represent images, with support for padding.
 * 
 * Features:
 * - Configurable matrix sizes
 * - Multiple kernel options
 * - Dynamic memory allocation
 * - Zero padding to handle boundaries
 */

int main() {
    // Seed the random number generator for reproducibility
    srand(static_cast<unsigned int>(time(nullptr)));
    
    // Get validated matrix size from user
    std::cout << "=== Image Convolution with Padding ===" << std::endl;
    int imageSize = getValidatedMatrixSize();
    
    // Calculate padded matrix size (original + 2 for padding)
    int paddedSize = imageSize + 2;
    
    // Allocate memory for matrices
    int** originalImage = allocateMatrix(imageSize);
    int** paddedImage = allocateMatrix(paddedSize);
    int** resultImage = allocateMatrix(imageSize);
    
    // Initialize original image with random values
    generateRandomImage(originalImage, imageSize);
    displayMatrix(originalImage, imageSize, "Original Image Matrix");
    
    // Get kernel selection from user and initialize it
    int kernelType = selectKernelType();
    int kernel[3][3];
    initializeKernel(kernel, kernelType);
    displayKernel(kernel);
    
    // Apply zero padding around the original image
    applyPadding(paddedImage, paddedSize, originalImage, imageSize);
    
    // Perform convolution operation
    performConvolution(resultImage, imageSize, paddedImage, paddedSize, kernel);
    
    // Display the result
    displayMatrix(resultImage, imageSize, "Convolution Result");
    
    // Clean up allocated memory
    deallocateMatrix(originalImage, imageSize);
    deallocateMatrix(paddedImage, paddedSize);
    deallocateMatrix(resultImage, imageSize);
    
    return 0;
}
