#include <stdlib.h>

#include "binary_matrix.h"
#include "binary_vector.h"

BinaryVector* BinaryVector_Create(size_t length)
{
    BinaryVector* initialized = malloc(sizeof(BinaryVector));

    if (initialized == NULL)
    {
        return NULL;
    }

    initialized->length = length;
    initialized->vector = malloc(sizeof(char) * length);
    
    if (initialized->vector == NULL)
    {
        free(initialized);
        return NULL;
    }

    return initialized;
}

void BinaryVector_Delete(BinaryVector* target)
{
    if (target == NULL)
        return;

    free(target->vector);
    free(target);
}

void BinaryVector_ImportFromArray(BinaryVector* target, int* source, size_t length)
{
    if (target == NULL || source == NULL)
    {
        return;
    }

    if (target->length != length)
    {
        return;
    }

    for (int i = 0; i < length; i++)
    {
        target->vector[i] = source[i];
    }
}

void BinaryVector_ImportFromColumn(BinaryVector* target, BinaryMatrix* source, int column)
{
    /// TODO Зробити
}

void BinaryVector_ImportFromRow(BinaryVector* target, BinaryMatrix* source, int row)
{
    /// TODO Зробити
}


