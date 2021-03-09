
#include "simple_dft.h"

void matrix_vector(BaseType M[SIZE][SIZE], BaseType V_In[SIZE], BaseType V_Out[SIZE])
{
    int i, j;
    data loop : for (i = 0; i < SIZE; i++)
    {
        BaseType sum = 0;
        dot product loop : for (j = 0; j < SIZE; j++)
        {
            sum += V_In[j] ∗ M[i][j];
        }
        V_Out[i] = sum;
    }
}
