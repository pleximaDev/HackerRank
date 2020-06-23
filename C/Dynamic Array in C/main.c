#include <stdio.h>
#include <stdlib.h>

/*
 * This stores the total number of books in each shelf.
 */
int* total_number_of_books;

/*
 * This stores the total number of pages in each book of each shelf.
 * The rows represent the shelves and the columns represent the books.
 */
int** total_number_of_pages;
/*
type 1:
    1 0 15
    1 - type
    0 - shelf's number
    15 - book's pages
    ... put this 15 page book at the end of shelf 0;


type 2:
    2 3 0
    2 - type
    3 shelf's number
    0 - book's number
    returns 0th book's number of pages on the 3rd shelf;


type 3:
    3 0
    3 - type
    0 - shelf's number
    returns number of books on the 0th shelf;


*/

int main()
{  
    int total_number_of_shelves;
    scanf("%d", &total_number_of_shelves);

    total_number_of_books = (int*)malloc(total_number_of_shelves * sizeof(int));
    total_number_of_pages = (int**)malloc(total_number_of_shelves * sizeof(int*));

    int total_number_of_queries;
    scanf("%d", &total_number_of_queries);

    for(int i = 0; i < total_number_of_shelves; i++)
    {
        *(total_number_of_books + i) = 0;
        *(total_number_of_pages + i) = (int*)malloc(sizeof(int));
    }
    
    while (total_number_of_queries--) {
        int type_of_query;
        scanf("%d", &type_of_query);
        
        if (type_of_query == 1) {
            int x, y;
            scanf("%d %d", &x, &y);
            // x -- shelf's number\n y -- book's pages\n
            
            *(total_number_of_books + x) = *(total_number_of_books + x) + 1;

            if(*(total_number_of_books + x) == 1)
              *(total_number_of_pages + x) = malloc(sizeof(int)); 
         else
              *(total_number_of_pages + x) = realloc(*(total_number_of_pages + x), \
              *(total_number_of_books + x)*sizeof(int));

        *(*(total_number_of_pages + x) + *(total_number_of_books + x) - 1) = y;

        } else if (type_of_query == 2) {
            int x, y;
            scanf("%d %d", &x, &y);
            printf("%d\n", *(*(total_number_of_pages + x) + y));
        } else {
            int x;
            scanf("%d", &x);
            printf("%d\n", *(total_number_of_books + x));
        }
    }

    if (total_number_of_books) {
        free(total_number_of_books);
    }
    
    for (int i = 0; i < total_number_of_shelves; i++) {
        if (*(total_number_of_pages + i)) {
            free(*(total_number_of_pages + i));
        }
    }
    
    if (total_number_of_pages) {
        free(total_number_of_pages);
    }
    
    return 0;
}
