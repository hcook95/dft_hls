//===========================================================================
// digitrec.h
//===========================================================================
// @brief: This header file defines the interface for the core functions.

#ifndef SIMPLE_DFT_H
#define SIMPLE_DFT_H

#define SIZE 8
typedef float BaseType;

// Top function for digit recognition
void matrix_vector(BaseType M[SIZE][SIZE], BaseType V_In[SIZE], BaseType V_Out[SIZE]);

#endif
