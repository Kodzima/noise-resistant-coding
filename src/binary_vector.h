typedef struct
{
    size_t length;
    char* vector;
} BinaryVector;

BinaryVector* BinaryVector_Create(size_t length);
void BinaryVector_Delete(BinaryVector* target);
void BinaryVector_ImportFromColumn(BinaryVector* target, BinaryMatrix* source, int column);
void BinaryVector_ImportFromArray(BinaryVector* target, int* source, size_t length);
void BinaryVector_ImportFromRow(BinaryVector* target, BinaryMatrix* source, int row);
void BinaryVector_Print(BinaryVector* target);
