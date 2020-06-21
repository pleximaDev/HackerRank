#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHAR_NUM 26
int lexicographic_sort(const char* a, const char* b) 
{
    return strcmp(a, b);
}

int lexicographic_sort_reverse(const char* a, const char* b) 
{
    return strcmp(b, a);
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) 
{
    /* using this and lexicographic_sort(a_, b_) or distance and ptr = ptr - distance
    const char* a_;
    const char* b_;
    a_ = a;
    b_ = b;
    */

    int alphabet_a[CHAR_NUM] = {0}, alphabet_b[CHAR_NUM] = {0};
    int j = CHAR_NUM, distance = 0;
    int two_dist[2] = {0};
    char ch;
    while(*a != '\0')
    {
        distance++;
        ch = (*a++) - 'a';
        if(ch < 26 && ch >= 0) alphabet_a[ch]++;
    }a = a - distance;

    while(j --> 0)
    {
        if(*(alphabet_a + j)) 
        {
            two_dist[0]++;
        }
    }

    j = CHAR_NUM;
    distance = 0;
    while(*b != '\0')
    {
        distance++;
        ch = (*b++) - 'a';
        if(ch < 26 && ch >= 0) alphabet_b[ch]++;
    }b = b - distance;

    while(j --> 0)
    {
        if(*(alphabet_b + j)) 
        {
            two_dist[1]++;
        }
    }
    return *(two_dist) - *(two_dist + 1) ? *(two_dist) - *(two_dist + 1) : lexicographic_sort(a, b);
}

int sort_by_length(const char* a, const char* b) 
{
    return strlen(a) - strlen(b) ? strlen(a) - strlen(b) : lexicographic_sort(a, b);
}

void string_sort(char** arr, const int len, int (*cmp_func)(const char* a, const char* b))
{
    void swap(char** a, int j);
    for(int i = 0; i < len - 1; i++)
    {
        for(int j = 0; j < len - 1 - i; j++)
        {
            if(cmp_func(arr[j], arr[j + 1]) > 0)
            {
                swap(arr, j);
            }
        }
    }
}
void swap(char** a, int j){ char* temp = *(a + j); *(a + j) = *(a + j + 1); *(a + j + 1) = temp; }


int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}
