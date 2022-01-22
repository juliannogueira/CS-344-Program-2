#include "processMovieFile.h"
#include "util.h"

/*
 * Process the largest movie file in the current directory with a prefix of
 * movies_ and an extension of .csv.
 */
void processMovieFile(int type) {
    char *prefix = "movies_";
    char *extension = ".csv";
    char *filename = malloc(sizeof(char) * 256);
    *filename = '\0';
    getParsedFile(filename, prefix, extension, type);
    if (*filename != '\0') {
        printf("\n%s\n", filename);
    }
    free(filename);
}