#include <stdio.h>
#include "binary_matrix.h"
#include "binary_vector.h"

int NoiseResistant_GetWeightOfVector(BinaryVector* binary_vector)
{

}

BinaryMatrix* NoiseResistant_CreateGeneratorMatrix(int d, int k, int n, int r)
{
    BinaryMatrix* generator_matrix = BinaryMatrix_Create(k,n);

    if (generator_matrix == NULL)
        return NULL;


    return generator_matrix;
}
