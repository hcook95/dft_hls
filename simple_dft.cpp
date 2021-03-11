
#include "simple_dft.h"

void matrix_vector(BaseType M[SIZE][SIZE], BaseType V_In[SIZE], BaseType V_Out[SIZE])
{
    int i, j;
    BaseType p0, p1, p2, p3, p4, p5, p6, p7, sum0_a, sum1_a, sum2_a, sum3_a, sum0_b, sum1_b;
data_loop:
    for (i = 0; i < SIZE; i++)
    {
        BaseType sum = 0;
    dot_product_loop:
        for (j = 0; j < SIZE; j += 1)
        {
#pragma HLS UNROLL factor=8
            sum += V_In[j] * M[i][j];
        }

        V_out[i] = sum;

        //        p0 = V_In[0] * M[i][0];
        //        p1 = V_In[1] * M[i][1];
        //        p2 = V_In[2] * M[i][2];
        //        p3 = V_In[3] * M[i][3];
        //        p4 = V_In[4] * M[i][4];
        //        p5 = V_In[5] * M[i][5];
        //        p6 = V_In[6] * M[i][6];
        //        p7 = V_In[7] * M[i][7];
        //
        //        sum0_a = p0 + p1;
        //        sum1_a = p2 + p3;
        //        sum2_a = p4 + p5;
        //        sum3_a = p6 + p7;
        //
        //        sum0_b = sum0_a + sum1_a;
        //        sum1_b = sum2_a + sum3_a;
        //
        //        V_out[i] = sum0_b + sum1_b;
    }
}
