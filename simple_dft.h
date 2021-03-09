//===========================================================================
// digitrec.h
//===========================================================================
// @brief: This header file defines the interface for the core functions.

#ifndef DIGITREC_H
#define DIGITREC_H

#include "typedefs.h"
#include "training_data.h"

// The K_CONST value: number of nearest neighbors
#ifndef K_CONST
#define K_CONST 3
#endif

#define SIZE 8
typedef float BaseType;

// Top function for digit recognition
int matrix_vector(BaseType M[SIZE][SIZE], BaseType V_In[SIZE], BaseType V_Out[SIZE]);

#endif
