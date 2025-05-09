#ifndef MATRIX_OPS_H
#define MATRIX_OPS_H

struct ImageMatrix {
    int** data;
    int size;
};

struct KernelMatrix {
    int data[3][3];
};

// Matrix operation functions
ImageMatrix* createImageMatrix(int size);
void deleteImageMatrix(ImageMatrix* matrix);
void displayMatrix(const ImageMatrix* matrix, const char* title);
void generateRandomImage(ImageMatrix* matrix);

#endif
