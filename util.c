#include "util.h"

/*
 * Check if a command line argument was passed.
 */
int hasCommandLineArgument(char *argv[]) {
    if (*(argv + 1) != NULL) {
        return 1;
    } else {
        return 0;
    }
}

/*
 * Check if the passed file can be opened.
 */
int isValidFile(char *filename) {
    FILE *fp;
    fp = fopen(filename, "r");
    if (fp != NULL) {
        fclose(fp);
        return 1;
    } else {
        return 0;
    }
}

/*
 * Check if the character is a valid choice.
 */
int isValidChoice(char ch) {
    char charList[98] = {'1', '2', '3', '4'};
    for (int i = 0; i < 4; i++) {
        if (ch == charList[i]) {
            return 1;
        }
    }
    return 0;
}

/* 
 * Check if a character is printable.
 */
int isValidChar(char ch) {
    char charList[98] = {'!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+',
                    ',', '-', '.', '/', '0', '1', '2', '3', '4', '5', '6', '7',
                    '8', '9', ':', ';', '<', '=', '>', '?', '@', 'A', 'B', 'C',
                    'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O',
                    'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '[',
                    '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e', 'f',
                    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                    's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}', '~',
                    ' ', '\n', '\t', '\r'};
    for (int i = 0; i < 98; i++) {
        if (ch == charList[i]) {
            return 1;
        }
    }
    return 0;
}

/*
 * Check if the character is a number.
 */
int isValidDigit(char ch) {
    char charList[98] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    for (int i = 0; i < 10; i++) {
        if (ch == charList[i]) {
            return 1;
        }
    }
    return 0;
}

/*
 * Clear the content of a buffer.
 */
void clearBuffer(char *buffer, int size) {
    for (int i = 0; i < size; i++) {
        buffer[i] = '\0';
    }
}

/*
 * Get the size of a string.
 */
int stringLength(char *string) {
    int i = 0;
    while (string[i] != '\0') {
        i++;
    }
    return i;
}

/*
 * Copy the contents of a source string into a destination string.
 */
void copyString(char *source, char *destination) {
    int length = stringLength(source);
    for (int i = 0; i < length; i++) {
        *(destination + i) = *(source + i);
    }
    *(destination + length) = '\0';
}

/*
 * Parse a string for a pattern.
 *
 * If the pattern is found, return 1. Otherwise, return 0.
 */
int parseString(char *pattern, char *string) {
    for (int i = 0; i < stringLength(string); i++) {
        if (*(pattern + 0) == *(string + i)) {
            for (int j = 0; j < stringLength(pattern); j++) {
                if ((i + stringLength(pattern)) > stringLength(string)) {
                    break;
                } else if (*(pattern + j) != *(string + i + j)) {
                    break;
                } else if (j == (stringLength(pattern) - 1)) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

/*
 * Parse a file for an extension.
 *
 * If the extension is found, return 1. Otherwise, return 0.
 */
int parseExtension(char *extension, char *filename) {
    for (int i = 0; i < stringLength(filename); i++) {
        if (*(extension + 0) == *(filename + i)) {
            for (int j = 0; j < stringLength(extension); j++) {
                if ((i + stringLength(extension)) > stringLength(filename)) {
                    break;
                } else if (*(extension + j) != *(filename + i + j)) {
                    break;
                } else if (j == (stringLength(extension) - 1) &&\
                          i + j == (stringLength(filename) - 1)) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

/*
 * Get a file in the current directory with the passed prefix and extension.
 * 
 * The type specifies the file size, where a 1 returns the smallest file, and a
 * 2 returns the largest file.
 */
void getParsedFile(char *filename, char *prefix, char *extension, int type) {
    DIR* dir = opendir(".");
    struct dirent *entry;

    while ((entry = readdir(dir)) != NULL) {
        if (parseString(prefix, entry->d_name) &&\
           parseExtension(extension, entry->d_name)) {
            printf("%s\n", entry->d_name);
            copyString(entry->d_name, filename);
        }
    }

    closedir(dir);
}
