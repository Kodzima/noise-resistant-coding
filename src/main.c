#include <stdio.h>
#include "binary_matrix.h"


int main()
{
    BinaryMatrix* first_matrix = BinaryMatrix_Create(1,8);
    BinaryMatrix* second_matrix = BinaryMatrix_Create(8,5);

    BinaryMatrix* b = BinaryMatrix_Create(1,2);

    int first_array[8] = {0,1,1,0,1,1,0,1};
    int second_array[40] = 
        {
            0,0,1,1,1,
            0,1,0,1,1,
            0,1,1,0,1,
            1,0,0,0,0,
            0,1,0,0,0,
            0,0,1,0,0,
            0,0,0,1,1,
            0,0,0,0,1
        };
    int barr[2] = {0,1};
    BinaryMatrix_ImportFromArray(first_matrix, first_array, 8);
    BinaryMatrix_Print(first_matrix);
    BinaryMatrix_ImportFromArray(second_matrix, second_array, 40);
    BinaryMatrix_Print(second_matrix);
    BinaryMatrix_ImportFromArray(b, barr, 2);

    BinaryMatrix* result = BinaryMatrix_MultiplyMatrices(first_matrix, second_matrix);

    BinaryMatrix* transposed = BinaryMatrix_CreateTransposed(second_matrix);
    BinaryMatrix_Print(transposed);

    BinaryMatrix* combined = BinaryMatrix_CombineMatrices(first_matrix, b);
    BinaryMatrix_Print(combined);

    BinaryMatrix_Print(result);
    
    return 0;
}
