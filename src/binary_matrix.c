#include <stdlib.h>
#include <stdio.h>
#include "binary_matrix.h"

BinaryMatrix* BinaryMatrix_Create(unsigned rows, unsigned columns)
{
    BinaryMatrix* initialized = malloc(sizeof(BinaryMatrix));

    if (initialized != NULL)
    {
        initialized->rows = rows;
        initialized->columns = columns;
        initialized->matrix = malloc(sizeof(char) * (rows * columns + columns));

        if (initialized->matrix == NULL)
        {
            free(initialized);
            return NULL;
        }
    }

    return initialized;
}

void BinaryMatrix_Delete(BinaryMatrix* binary_matrix)
{
    if (binary_matrix == NULL)
    {
        return;
    }
    free(binary_matrix->matrix);
    free(binary_matrix);
}

void BinaryMatrix_ImportFromArray(BinaryMatrix* binary_matrix, int* source, size_t size)
{
    if (binary_matrix == NULL || source == NULL) 
        return;

    if (size != binary_matrix->rows * binary_matrix->columns)
        return;

    for (unsigned int row = 0; row < binary_matrix->rows; row++)
    {
        for (unsigned int column = 0; column < binary_matrix->columns; column++)
        {
            binary_matrix->matrix[row * binary_matrix->columns + column] = source[row * binary_matrix->columns + column];
        }
    }
}

BinaryMatrix* BinaryMatrix_CreateUnitMatrix(const int size)
{
    BinaryMatrix* binary_matrix = BinaryMatrix_Create(size, size);
    if (binary_matrix == NULL)
        return NULL;

    for (int row = 0, column; row < size; row++) 
    {
        column = row;
        binary_matrix->matrix[row * size + column] = 1;
    }

    return binary_matrix;
}

void BinaryMatrix_Print(BinaryMatrix* binary_matrix)
{
    if (binary_matrix == NULL)
    {
        return;
    }
    
    for (unsigned int row = 0; row < binary_matrix->rows; row++)
    {
        for (unsigned int column = 0; column < binary_matrix->columns; column++)
        {
            printf("%d ", binary_matrix->matrix[row * binary_matrix->columns + column]);
        }
        printf("\n");
    }
    printf("\n");
}

BinaryMatrix* BinaryMatrix_MultiplyMatrices(BinaryMatrix* first_matrix, BinaryMatrix* second_matrix)
{
    if (first_matrix == NULL || second_matrix == NULL)
        return NULL;

    if (first_matrix->columns != second_matrix->rows)
        return NULL;

    BinaryMatrix* result = BinaryMatrix_Create(first_matrix->rows, second_matrix->columns);

    if (result == NULL)
        return NULL;

    for (unsigned int row = 0; row < result->rows; row++)
    {
        for (unsigned int column = 0; column < result->columns; column++)
        {
            for (unsigned int i = 0; i < first_matrix->columns; i++)
            {
                result->matrix[row * result->columns + column] ^= first_matrix->matrix[first_matrix->columns * row + i] & second_matrix->matrix[second_matrix->columns * i + column];
            }
        }
    }

    return result;
}

BinaryMatrix* BinaryMatrix_CreateTransposed(BinaryMatrix* source)
{
    BinaryMatrix* transposed = BinaryMatrix_Create(source->columns, source->rows);
    if (transposed == NULL)
        return NULL;

    for (int row = 0; row < transposed->rows; row++)
    {
        for (int column = 0; column < transposed->columns; column++)
        {
            transposed->matrix[row * transposed->columns + column] = source->matrix[source->columns * column + row];
        }
    }

    return transposed;
}

BinaryMatrix* BinaryMatrix_CombineMatrices(BinaryMatrix* first_matrix, BinaryMatrix* second_matrix)
{
    if (first_matrix == NULL || second_matrix == NULL)
        return NULL;

    if (first_matrix->rows != second_matrix->rows)
        return NULL;

    BinaryMatrix* result = BinaryMatrix_Create(first_matrix->rows, first_matrix->columns + second_matrix->columns);

    for (int row = 0; row < result->rows; row++)
    {
        for (int column = 0; column < first_matrix->columns; column++)
        {
            result->matrix[row * result->columns + column] = first_matrix->matrix[row * first_matrix->columns + column];
        }
    }

    for (int row = 0; row < result->rows; row++)
    {
        for (int column = 0; column < second_matrix->columns; column++)
        {
            result->matrix[row * result->columns + column + first_matrix->columns] = second_matrix->matrix[row * second_matrix->columns + column];
        }
    }

    if (result == NULL)
        return NULL;


    return result;
}
