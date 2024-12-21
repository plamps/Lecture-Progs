#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_MOVIES 100
#define BATCH_SIZE 4

typedef struct movie {
    uint32_t id;
    char title[26];
    uint16_t year;
} Movies;

void insertMovie(struct movie **movies, uint32_t *numMovies, uint32_t *maxMovies) {

    uint32_t newMaxMovies;

    if (*numMovies >= *maxMovies) {
        if (*maxMovies == MAX_MOVIES) {
            printf("\nMaximum movie limit (%d) reached. Cannot add more movies.\n\n", MAX_MOVIES);
            return;
        }

        newMaxMovies = *maxMovies + BATCH_SIZE;
        if (newMaxMovies > MAX_MOVIES) {
            newMaxMovies = MAX_MOVIES;
        }
        *movies = (struct movie *)realloc(*movies, newMaxMovies * sizeof(struct movie));
        if (*movies == NULL) {
            printf("\nMemory allocation failed.\n\n");
            exit(1);
        }
        *maxMovies = newMaxMovies;
    }

    struct movie newMovie;
    printf("\nEnter movie id: ");
    scanf("%u", &newMovie.id);
    printf("Enter movie title: ");
    scanf(" %[^\n]", newMovie.title);
    printf("Enter release year: ");
    scanf("%hu", &newMovie.year);

    int duplicate = 0;
    for (uint32_t i = 0; i < *numMovies; i++) {
        if ((*movies)[i].id == newMovie.id) {
            duplicate = 1;
            break;
        }
    }

    if (duplicate) {
        printf("\nMovie with id %u already exists. Cannot insert.\n\n", newMovie.id);
    }
    else {
        (*movies)[*numMovies] = newMovie;
        (*numMovies)++;
        printf("\nMovie added successfully!\n\n");
    }
}

void searchMovie(const struct movie movies[], uint32_t numMovies) {

    uint32_t searchID;
    uint8_t found = 0;

    if (numMovies == 0) {
        printf("\nNo movies in the database.\n\n");
    }
    else {
        printf("\nEnter movie id to search for: ");
        scanf("%u", &searchID);
        for (uint32_t i = 0; i < numMovies; i++) {
            if (movies[i].id == searchID)  {
                printf("\nMovie found:\n");
                printf("Title: %s\n", movies[i].title);
                printf("Year: %hu\n\n", movies[i].year);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("\nMovie not found.\n\n");
        }
    }
}

void updateMovie(struct movie movies[], uint32_t numMovies) {

    uint32_t updateID;

    if (numMovies == 0) {
        printf("\nNo movies in the database.\n\n");
    }
    else {
        printf("\nEnter movie id to update: ");
        scanf("%u", &updateID);
        int found = 0;
        for (uint32_t i = 0; i < numMovies; i++) {
            if (movies[i].id == updateID) {
                printf("\nEnter updated information:\n");
                printf("Enter release year: ");
                scanf("%hu", &movies[i].year);
                printf("Movie updated successfully!\n\n");
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("\nMovie not found.\n\n");
        }
    }
}

void deleteMovie(struct movie **movies, uint32_t *numMovies, uint32_t *maxMovies) {

    uint32_t deleteID;

    if (*numMovies == 0) {
        printf("\nNo movies in the database.\n\n");
        return;
    }

    printf("\nEnter movie id to delete: ");
    scanf("%u", &deleteID);

    for (uint32_t i = 0; i < *numMovies; i++) {
        if ((*movies)[i].id == deleteID) {
            for (uint32_t j = i; j < *numMovies - 1; j++) {
                (*movies)[j] = (*movies)[j + 1];
            }
            (*numMovies)--;

            if (*maxMovies - *numMovies >= BATCH_SIZE && *maxMovies > BATCH_SIZE) {
                *maxMovies -= BATCH_SIZE;
                *movies = (struct movie *) realloc(*movies, *maxMovies * sizeof(struct movie));
                if (*movies == NULL) {
                    printf("\nMemory allocation failed.\n\n");
                    exit(1);
                }
            }
            printf("\nMovie deleted successfully!\n\n");
            return;
        }
    }

    printf("\nMovie not found.\n\n");
}

void printMovies(const struct movie movies[], uint32_t numMovies)
{
    if (numMovies == 0) {
        printf("\nNo movies in the database.\n\n");
    }
    else {
        printf("\nList of Movies:\n");
        printf("Entry\t\tMovie id\t\tMovie Title\t\tMovie Year\n");
        for (uint32_t i = 0; i < numMovies; i++) {
            printf("%d\t\t%u\t\t\t%s\t\t\t%hu\n", i + 1, movies[i].id, movies[i].title, movies[i].year);
        }
        printf("\n\n");
    }
}

int main() {

    uint16_t numStarSymbols;
    struct movie *movies = NULL;
    uint32_t numMovies = 0;
    uint32_t maxMovies = 0;
    char choice;

    for (numStarSymbols = 0; numStarSymbols < 97; numStarSymbols++) {
        printf("*");
    }

    printf("\n");

    for (numStarSymbols = 0; numStarSymbols < 20; numStarSymbols++) {
        printf("*");
    }

    printf(" Movie Administration System - Dynamic Memory Allocation ");

    for (numStarSymbols = 0; numStarSymbols < 20; numStarSymbols++) {
        printf("*");
    }

    printf("\n");

    for (numStarSymbols = 0; numStarSymbols < 97; numStarSymbols++) {
        printf("*");
    }

    printf("\n\n");

    while (1) {
        printf("i - Insert a movie\n");
        printf("s - Search for a movie\n");
        printf("u - Update a movie\n");
        printf("e - Erase a movie\n");
        printf("p - Print all movies\n");
        printf("q - Quit\n\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
        case 'i':
            insertMovie(&movies, &numMovies, &maxMovies);
            break;

        case 's':
            searchMovie(movies, numMovies);
            break;

        case 'u':
            updateMovie(movies, numMovies);
            break;

        case 'e':
            deleteMovie(&movies, &numMovies, &maxMovies);
            break;

        case 'p':
            printMovies(movies, numMovies);
            break;

        case 'q':
            free(movies);
            return 0;

        default:
            printf("\nInvalid choice. Please try again.\n\n");
        }
    }

    return 0;
}