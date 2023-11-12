typedef struct
{
    unsigned rows;
    unsigned columns;
    char *matrix;
} BinaryMatrix;


BinaryMatrix* BinaryMatrix_Create(unsigned rows, unsigned columns);
void BinaryMatrix_Delete(BinaryMatrix* binary_matrix);
BinaryMatrix* BinaryMatrix_CreateUnitMatrix(const int size);
void BinaryMatrix_Print(BinaryMatrix* binary_matrix);
BinaryMatrix* BinaryMatrix_MultiplyMatrices(BinaryMatrix* first_matrix, BinaryMatrix* second_matrix);
int BinaryMatrix_Transpose(BinaryMatrix* binary_matrix);
BinaryMatrix* BinaryMatrix_CombineMatrices(BinaryMatrix* first_matrix, BinaryMatrix* second_matrix);
void BinaryMatrix_ImportFromArray(BinaryMatrix* binary_matrix, int* source, size_t size);
BinaryMatrix* BinaryMatrix_CreateTransposed(BinaryMatrix* source);
BinaryMatrix* BinaryMatrix_CombineMatrices(BinaryMatrix* first_matrix, BinaryMatrix* second_matrix);
