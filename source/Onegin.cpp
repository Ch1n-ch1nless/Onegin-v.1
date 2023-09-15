#include "Onegin1.h"

void ReadBuffer(char* buffer, const size_t buf_size, FILE* file_ptr)
{
    const size_t symbol_number = fread(buffer, sizeof(char), buf_size, file_ptr);

    if (symbol_number != buf_size) {
        #if 0
        if (feof(file_ptr)) {
            printf("Error reading OnEgIn.txt: unexpected end of file\n");
        } else if (ferror(file_ptr)) {
            printf("Error reading OnEgIn.txt");
        }
        return;
        #endif
    }
}

size_t FillLineArray(char** line_array, char* buffer, const size_t buf_size, const size_t line_num)
{
    size_t count_of_lines = 0;

    assert(line_array != nullptr);
    assert(buffer != nullptr);

    line_array[count_of_lines] = buffer;
    count_of_lines++;

    int count_of_n = 0;

    for (size_t i = 0; i < buf_size-1; i++) {
        if (buffer[i] == '\n') {
            buffer[i] = '\0';
            if (count_of_n == 1) {
                line_array[count_of_lines] = &buffer[i+1];
                count_of_lines++;
                count_of_n = 0;
            } else {
                count_of_n++;
            }
        } else if (buffer[i] == '\0') {
            break;
        }
    }

    return count_of_lines;
}

void PrintLineArray(const char* filename, char** line_array, const size_t line_num)
{
    FILE* file_ptr = fopen(filename, "w");
    for (size_t i = 0; i < line_num; i++) {
        fprintf(file_ptr, "[%d] %s\n", i, line_array[i]);
    }
}

void BubbleSortRightToLeft(char** line_array, const size_t line_num)
{
    const char* filename = "BubbleSort.txt";
    FILE* file_ptr = fopen(filename, "w");

    fprintf(file_ptr, "Right -> Left:\n\n");

    SortBubbleArray(line_array, line_num, StrcmpRightLeft);
    PrintLineArray(filename, line_array, line_num);
}

void QsortLeftToRight(char** line_array, const size_t line_num)
{
    const char* filename = "qsort.txt";
    FILE* file_ptr = fopen(filename, "w");

    fprintf(file_ptr, "Left -> Right:\n\n");

    SortingByQsort(line_array, line_num);

    PrintLineArray(filename, line_array, line_num);
}

void PrintOriginalText(char* buffer, const size_t buf_size)
{
    const char* filename = "originaltext.txt";
    FILE* file_ptr = fopen(filename, "w");

    size_t count_of_lines = 0;
    fprintf(file_ptr, "{%d} ", count_of_lines);
    count_of_lines++;

    for (size_t i = 0; i < buf_size; i++) {
        if (buffer[i] == '\0') {
            fprintf(file_ptr, "\n{%d} ", count_of_lines);
            count_of_lines++;
            i++;
        } else {
            fprintf(file_ptr, "%c[%d]", buffer[i], buffer[i]);
        }
    }
}

void FreeText(char** line_array, char*  buffer)
{
    free(buffer);
    buffer = nullptr;
    free(line_array);
    line_array = nullptr;
}
