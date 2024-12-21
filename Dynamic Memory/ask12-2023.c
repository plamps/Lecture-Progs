#include <stdio.h>
#include <stdlib.h> /* malloc etc, exit */
#include <string.h>

#define title_LEN 25

struct movie
{
    int code;
    char title[title_LEN + 1];
    int year;
} *moviesArray;

int max_movies = 4;
int num_movies = 0;

int find_movie(int code);
void insert(void);
void search(void);
void update(void);
void print(void);
void erase(void);

/**********************************************************
 * main: Prompts the user to enter an operation code,     *
 *       then calls a function to perform the requested   *
 *       action. Repeats until the user enters the        *
 *       command 'q'. Prints an error message if the user *
 *       enters an illegal code.                          *
 **********************************************************/
int main(void)
{
    char code;

    printf(" ####################################################################\n ");
    printf("##########    Welcome to movies administration system ##########\n ");
    printf("####################################################################\n ");
    printf("\n\n ");

    printf("Enter operation code: ");
    printf("\ni for insert ");
    printf("\ns for search ");
    printf("\nu for update ");
    printf("\ne for erase ");
    printf("\np for print ");
    printf("\nq for quit ");

    for (;;)
    {
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while (getchar() != '\n')
            ; /* skips to end of line */

        switch (code)
        {
        case 'i':
            insert();
            break;
        case 's':
            search();
            break;
        case 'u':
            update();
            break;
        case 'p':
            print();
            break;
        case 'e':
            erase();
            break;
        case 'q':
            return 0;
        default:
            printf("Illegal code\n");
        }
        printf("\n");
    }
    free(moviesArray);
    return 0;
}

/**********************************************************
 * find_movie: Looks up a movie code in the moviesArray     *
 *            array. Returns the array index if the movie  *
 *            code is found; otherwise, returns -1.     *
 **********************************************************/
int find_movie(int code)
{
    int i;

    for (i = 0; i < num_movies; i++)
        if (moviesArray[i].code == code)
            return i;
    return -1;
}

/**********************************************************
 * insert: Prompts the user for information about a new   *
 *         movie and then inserts the movie into the        *
 *         database. Prints an error message and returns  *
 *         prematurely if the movie already exists or the  *
 *         database is full.                              *
 **********************************************************/
void insert(void)
{
    int movie_code;

    if (num_movies < 1)
    {
        moviesArray = (struct component *)malloc(max_movies * sizeof(struct movie));
        if (!moviesArray)
        {
            printf("Error: malloc failed\n");
            exit(EXIT_FAILURE);
        }
    }

    if ((num_movies % max_movies ==0) && (num_movies >=max_movies)){
    if ((moviesArray = realloc(moviesArray, sizeof(struct movie) * (num_movies+max_movies)))
        == NULL)
    {
        printf("Error: realloc failed\n");
        exit(EXIT_FAILURE);
    }
  }

    

    printf("Enter movie code: ");
    scanf("%d", &movie_code);
    if (find_movie(movie_code) >= 0)
    {
        printf("movie already exists.\n");
        return;
    }

    moviesArray[num_movies].code = movie_code;
    printf("Enter movie title: ");
    getchar();
    fgets(&moviesArray[num_movies].title, 30, stdin);
    printf("Enter year of movie: ");
    scanf("%d", &moviesArray[num_movies].year);
    num_movies++;
}

/**********************************************************
 * search: Prompts the user to enter a movie code, then  *
 *         looks up the movie in the database. If the movie *
 *         exists, prints the title and quantity on hand;  *
 *         if not, prints an error message.               *
 **********************************************************/
void search(void)
{
    int i, code;

    printf("Enter movie code: ");
    scanf("%d", &code);
    i = find_movie(code);
    if (i >= 0)
    {
        printf("Movie title: %s\n", moviesArray[i].title);
        printf("Year of movie: %d\n", moviesArray[i].year);
    }
    else
        printf("Movie not found.\n");
}

/**********************************************************
 * update: Prompts the user to enter a movie code.       *
 *         Prints an error message if the movie doesn't    *
 *         exist; otherwise, prompts the user to enter    *
 *         change in quantity on hand and updates the     *
 *         database.                                      *
 **********************************************************/
void update(void)
{
    int i, code, change;

    printf("Enter movie code: ");
    scanf("%d", &code);
    i = find_movie(code);
    if (i >= 0)
    {
        printf("Enter change in year of movie: ");
        scanf("%d", &change);
        moviesArray[i].year = change;
    }
    else
        printf("Movie not found.\n");
}

/**********************************************************
 * print: Prints a listing of all movies in the database,  *
 *        showing the movie code, movie title, and         *
 *        quantity on hand. movies are printed in the      *
 *        order in which they were entered into the       *
 *        database.                                       *
 **********************************************************/
void print(void)
{
    int i;

    printf("Movie code   Movie title             Year of movie\n");
    for (i = 0; i < num_movies; i++)
        printf("%7d       %-25s%11d\n", moviesArray[i].code,
               moviesArray[i].title, moviesArray[i].year);
}

/**********************************************************
 * erase: Prompts the user to enter a movie code, then   *
 *        attempts to erase that movie from the database.  *
 *        If the movie doesn't exist, prints an error      *
 *        message.                                        *
 **********************************************************/
void erase(void)
{

    int n, i;
    printf("Enter movie code: ");
    scanf("%d", &n);

    i = find_movie(n);

    if (i < 0)
    {
        printf("\nMovie not found\n");
        return;
    }
    else
    {

        for (int j = i; j <= num_movies - 1; j++)
        {
            moviesArray[j] = moviesArray[j + 1];
        }

        int lastIndex = num_movies - 1;

        printf("Num_movies: %d\n", num_movies);

        if ((num_movies % max_movies ==0) && (num_movies >=max_movies))
        {
            moviesArray = realloc(moviesArray, sizeof(struct movie) * (num_movies));
            if (!moviesArray)
            {
                printf("Error: realloc failed\n");
                exit(EXIT_FAILURE);
            }
        }

        if (num_movies < 1)
        {
            free(moviesArray);
        }

        num_movies--;
        return;
    }
}
