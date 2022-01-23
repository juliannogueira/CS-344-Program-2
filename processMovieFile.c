#include "processMovieFile.h"
#include "util.h"

/*
 * Process the largest movie file in the current directory with a prefix of
 * movies_ and an extension of .csv.
 */
void processMovieFile(int getLargestFile) {
    char *prefix = "movies_";
    char *extension = ".csv";
    char *filename = malloc(sizeof(char) * 256);
    *filename = '\0';
    getParsedFilename(filename, prefix, extension, getLargestFile);
    if (*filename != '\0') {
        printf("\n%s\n", filename);
    }
    free(filename);
}