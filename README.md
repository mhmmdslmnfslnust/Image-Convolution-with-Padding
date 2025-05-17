# Image Convolution with Padding

This C++ program performs 2D convolution on dynamically-sized grayscale images using various kernels. It demonstrates image processing concepts such as zero padding, kernel application, and matrix-based convolution operations.

The program showcases fundamental image processing operations common in computer vision, edge detection, and digital filtering applications.

## Table of Contents
- [Overview](#overview)
- [Features](#features)
- [Code Structure](#code-structure)
- [How It Works](#how-it-works)
- [Output Example](#output-example)
- [Dependencies](#dependencies)
- [Build Instructions](#build-instructions)
- [Limitations](#limitations)
- [Possible Improvements](#possible-improvements)

---

## Overview

The program performs the following operations:
1. Allows the user to specify the image size (3-12)
2. Generates a random grayscale image (values 0-255)
3. Offers multiple kernel options (edge detection, sharpening, blur)
4. Applies zero-padding around the original image
5. Performs convolution between the padded image and the chosen kernel
6. Outputs the convolution result

---

## Features

- Configurable matrix sizes (3-12)
- Multiple kernel options:
  - Vertical Edge Detection
  - Horizontal Edge Detection
  - Sharpen
  - Blur
- Dynamic memory allocation for matrices
- Input validation for user selections
- Zero-padding implementation
- 2D convolution operation
- Formatted output display
- Well-organized modular code structure

---

## Code Structure

The project is organized into multiple files for better code management:

### Main Program
- `main.cpp`: Contains the main control flow

### Matrix Operations Module
- `matrix_ops.h`: Declarations for matrix-related functions
- `matrix_ops.cpp`: Implementations of matrix functions:
  - `getValidatedMatrixSize()`: Validates and retrieves user input for matrix size
  - `allocateMatrix()`: Allocates memory for a matrix
  - `deallocateMatrix()`: Releases allocated memory
  - `generateRandomImage()`: Creates a matrix with random pixel values
  - `displayMatrix()`: Outputs a matrix to the console
  - `initializeWithZeros()`: Sets all matrix elements to zero

### Convolution Operations Module
- `convolution.h`: Declarations for convolution-related functions
- `convolution.cpp`: Implementations of convolution functions:
  - `selectKernelType()`: Gets user choice for kernel type
  - `initializeKernel()`: Sets up the kernel based on the selected type
  - `displayKernel()`: Outputs the kernel to the console
  - `applyPadding()`: Creates a padded version of the original image
  - `performConvolution()`: Executes the convolution operation

---

## How It Works

1. The program starts by seeding the random number generator
2. It asks the user to specify the image size (within the range 3-12)
3. It allocates memory for:
   - The original image matrix
   - The padded image matrix
   - The result matrix
4. It generates random values for the image
5. It asks the user to select a kernel type
6. It applies zero-padding to the original image
7. It performs the convolution operation using the selected kernel
8. It displays the result
9. It cleans up allocated memory before exiting

---

## Output Example

```
=== Image Convolution with Padding ===
Enter matrix size (3-12): 6
Original Image Matrix:
  156  248    9   87   22   81
  234   46  103   30  135  144
  213   93  112   32  132  111
   22  219  144  215  128  251
   89   63   63   27   30  187
  163  157  206   82   47   73

Select kernel type:
1. Vertical Edge Detection
2. Horizontal Edge Detection
3. Sharpen
4. Blur
Enter your choice (1-4): 1
Selected Kernel:
  -1   0   1
  -1   0   1
  -1   0   1

Convolution Result:
  294 -278 -177   45  108 -157
  387 -379 -238   65  187 -289
  358 -110  -81   36  229 -395
  375   -5 -101  -29  275 -290
  439  139 -115 -208  187 -205
  220   17 -111 -192  151  -77
```

---

## Dependencies

- C++ compiler with STL support
- Standard libraries:
  - `<iostream>` for I/O operations
  - `<cstdlib>` for random number generation
  - `<ctime>` for seeding the random generator
  - `<iomanip>` for formatted output

---

## Build Instructions

1. Compile all source files together:
```bash
g++ main.cpp matrix_ops.cpp convolution.cpp -o image_convolution
```

2. Run the executable:
```bash
./image_convolution
```

---

## Limitations

- Only supports square matrices
- Limited to grayscale images (single channel)
- Uses simple zero-padding only
- Random image generation (no file input)
- Fixed kernel size (3×3)
- No visualization beyond text output

---

## Possible Improvements

1. Add support for image file input/output
2. Implement different padding strategies (reflect, replicate, etc.)
3. Support non-square matrices and images
4. Add more kernel options and custom kernels
5. Implement normalization strategies for outputs
6. Add graphical visualization of results
7. Support multi-channel (color) image processing
8. Implement more boundary handling options
9. Add benchmarking capabilities
10. Implement multi-threading for performance on larger matrices

---

This implementation demonstrates important concepts of digital image processing while providing a flexible, modular codebase for educational purposes.

