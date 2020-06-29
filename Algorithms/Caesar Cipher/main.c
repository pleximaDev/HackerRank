#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* caesarCipher(char* s, int k) 
{
    int shift = k, t = 0;
    char* alph = "abcdefghijklmnopqrstuvwxyz";
    char* shifted = (char*)malloc((int)('z' - 'a' + 1) * sizeof(char));

    while(shift > ('z' - 'a') + 1)
    {
        shift -= ('z' - 'a' + 1);
    }
    for(int i = 0, j = shift; i < 'z' - 'a' + 1; i++, j++)
    {
        if(j < 'z' - 'a' + 1)
        {
            *(shifted + i) = *(alph + j);
        }
        else if(j >= 'z' - 'a' + 1)
        {
            j = 0;
            *(shifted + i) = *(alph + j);
        }
    }
    do
    {
        if(*(s + t) >= 'a' && *(s + t) <= 'z')
        {
            *(s + t) = *(shifted + (*(s + t) - 'a'));
        }
        else if( *(s + t) >= 'A' && *(s + t) <= 'Z' )
        {
            *(s + t) = *(shifted + (*(s + t) - 'A')) - ('a' - 'A');
        }
    }while(*(s + ++t) != '\0');
    return s;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* n_endptr;
    char* n_str = readline();
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    char* s = readline();

    char* k_endptr;
    char* k_str = readline();
    int k = strtol(k_str, &k_endptr, 10);

    if (k_endptr == k_str || *k_endptr != '\0') { exit(EXIT_FAILURE); }

    char* result = caesarCipher(s, k);

    fprintf(fptr, "%s\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}
