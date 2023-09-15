#include "Onegin1.h"

int main()
{
    FILE* file_ptr = fopen("OnEgIn.txt", "r");

    char* buffer = nullptr;
    size_t buf_size = 0;

    struct stat st;
    stat("OnEgIn.txt", &st);
    buf_size = st.st_size;
    buffer = (char*) calloc(buf_size, sizeof(char));

    ReadBuffer(buffer, buf_size, file_ptr);

    size_t line_num = (buf_size / 2) + 1;

    char** line_array = (char**) calloc(line_num, sizeof(char*));

    size_t count_of_lines = FillLineArray(line_array, buffer, buf_size, line_num);

    if (count_of_lines <= line_num) {
        line_num = count_of_lines;
    } else {
        printf("Error! count_of_lines > line_num\n");
        return 0;
    }

    /*printf("Сортировка справа налево:\n\n");

    SortBubbleArray(line_array, line_num, StrcmpRightLeft);
    PrintLineArray(line_array, line_num); */

    printf("\nСортировка слева направо:\n\n");

    SortingByQsort(line_array, line_num);

    PrintLineArray(line_array, line_num);

    free(buffer);
    buffer = nullptr;
    free(line_array);
    line_array = nullptr;

    return 0;
}

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

void PrintLineArray(char** line_array, const size_t line_num)
{
    for (size_t i = 0; i < line_num; i++) {
        printf("[%d] %s\n", i, line_array[i]);
    }
}
