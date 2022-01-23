#include "processMovieFile.h"
#include "movie.h"
#include "util.h"

/*
 * Process a movies file in the current directory with a prefix of movies_ and
 * an extension of .csv.
 * 
 * The user can either specify a filename, or get the largest or smallest file
 * with the aforementioned prefix and extension.
 */
void processMovieFile(int specifyFile, int getLargestFile) {
    const int SIZE = 256;
    char *fileNotFound = "\nA movies file was not found.\n";
    char *filename = malloc(sizeof(char) * SIZE);
    if (specifyFile) {
        getFilename(filename, SIZE);
    } else {
        char *prefix = "movies_";
        char *extension = ".csv";
        getParsedFilename(filename, prefix, extension, getLargestFile);
    }
    if (!isValidFile(filename)) {
        printf("%s", fileNotFound);
    } else {
        processData(filename);
    }
    free(filename);
}

/*
 * Process the movie data in a passed file.
 *
 * Get all movies released in each unique year in the file.
 * 
 * Create a directory for the file, with each year as a file.
 * 
 * The function iterates through a list of movies two times. The first list
 * keeps track of year, and each new year is added to the year list. If the
 * current year is in the list, the year is skipped. Otherwise, the second loop
 * is entered.
 * 
 * The second loop will iterate through the list, searching for movies released
 * in the current year.
 */
void processData(char *filename) {
    struct Movie *head;
    struct Movie *curr;
    struct Movie *temp;
    const int MAX = 99999;
    const int MAX_LENGTH = 5;
    const int FILENAME_LENGTH = 8;
    int *yearList = malloc(sizeof(int));
    int year = 0;
    int count = 0;
    int match = 0;
    char yearString[5];
    char *name = "torresju.movies.";
    char *dirname = malloc(sizeof(char) * (stringLength(name) + MAX_LENGTH + 1));
    char *outputFile = malloc(sizeof(char) * (FILENAME_LENGTH + 1));
    char *path = malloc(sizeof(char) * (stringLength(name) + MAX_LENGTH + FILENAME_LENGTH + 2));
    char *fileExtension = ".txt";
    head = NULL;
    head = createListFromFile(filename);
    curr = head;
    createDirectory(dirname, name, MAX, MAX_LENGTH);
    while (curr != NULL) {
        temp = head;
        year = *(curr->year);
        for (int i = 0; i < count; i++) {
            if (*(yearList + i) == year) {
                match = 1;
                break;
            }
        }
        if (!match) {
            intToString(year, yearString);
            concatStrings(yearString, fileExtension, outputFile);
            createPath(dirname, outputFile, path);
            createFile(path);
            count++;
            yearList = realloc(yearList, sizeof(int) * count);
            *(yearList + count - 1) = year;
            while (temp != NULL) {
                if (*(temp->year) == year) {
                    appendToFile(path, temp->title);
                }
                temp = temp->next;
            }
        }
        match = 0;
        curr = curr->next;
    }
    printf("\nThe output was written to directory %s.\n", dirname);
    freeList(head);
    free(yearList);
    free(dirname);
    free(outputFile);
    free(path);
}