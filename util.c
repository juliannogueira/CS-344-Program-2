#include "util.h"

/*
 * Convert an integer to a string.
 */
void intToString(int num, char *destination) {
    sprintf(destination, "%d", num);
}

/*
 * Concatenate two strings together.
 *
 * The destination string must have enough space for the null-terminator.
 */
void concatStrings(char *str1, char *str2, char *destination) {
    for (int i = 0; i < stringLength(str1); i++) {
        *(destination + i) = str1[i];
    }
    for (int i = 0; i < stringLength(str2); i++) {
        *(destination + stringLength(str1) + i) = str2[i];
    }
    *(destination + stringLength(str1) + stringLength(str2)) = '\0';
}

/*
 * Get a random number.
 */
int getRandomNumber(int max) {
    time_t t;
    int num;
    srand((unsigned) time(&t));
    num = rand() % (max + 1);
    return num;
}

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
    char charList[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
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
 *
 * The source string must be null-terminated.
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
 * The type specifies the file size, where a 0 returns the smallest file, and a
 * 1 returns the largest file.
 */
void getParsedFilename(char *filename, char *prefix, char *extension, int getLargestFile) {
    DIR* dir = opendir(".");
    struct dirent *entry;
    struct stat buffer;
    int size = -1;

    while ((entry = readdir(dir)) != NULL) {
        if (parseString(prefix, entry->d_name) &&\
            parseExtension(extension, entry->d_name)) {
            stat(entry->d_name, &buffer);
            if (getLargestFile) {
                if (size < buffer.st_size) {
                    size = buffer.st_size;
                    copyString(entry->d_name, filename);
                }
            } else {
                if (size == -1) {
                    size = buffer.st_size;
                    copyString(entry->d_name, filename);
                } else if (size > buffer.st_size) {
                    size = buffer.st_size;
                    copyString(entry->d_name, filename);
                }
            }
        }
    }

    closedir(dir);
}

/*
 * Get a filename from the user.
 * 
 * If the user enters a new line, convert the new line character to a
 * null-terminator. 
 */
void getFilename(char *buffer, int size) {
    char *prompt = "\nEnter the filename: ";
    printf("%s", prompt);
    
    fgets(buffer, size, stdin);

    for (int i = 0; i < size; i++) {
        if (buffer[i] == '\n') {
            buffer[i] = '\0';
            break;
        }
    }
}

/*
 * Create a pseudorandom directory name.
 */
void createDirectoryName(char *dirname, char *name, int max, int maxLength) {
    int num = 0;
    char postfix[maxLength];
    num = getRandomNumber(max);
    sprintf(postfix, "%d", num);
    for (int i = 0; i < stringLength(name); i++) {
        *(dirname + i) = name[i];
    }
    for (int i = 0; i < stringLength(postfix); i++) {
        *(dirname + stringLength(name) + i) = postfix[i];
    }
    *(dirname + stringLength(name) + stringLength(postfix)) = '\0';
}

/*
 * Create a directory with a pseudorandom name.
 *
 * If the directory exists, keep generating directory names until a new
 * directory name exists. Then, create the directory.
 */
void createDirectory(char *dirname, char *name, int max, int maxLength) {
    struct stat buffer;
    do {
        createDirectoryName(dirname, name, max, maxLength);
    } while (stat(dirname, &buffer) == 0);
    mkdir(dirname, 0750);
}

/*
 * Create a file at the specified path.
 */
void createFile(char *path) {
    FILE *fp;
    fp = fopen(path, "w");
    fclose(fp);
    chmod(path, 0640);
}

/*
 * Append text to a passed file.
 */
void appendToFile(char *path, char *text) {
    FILE *fp;
    fp = fopen(path, "a");
    fputs(text, fp);
    fputc('\n', fp);
    fclose(fp);
}

/*
 * Create a path from a given dirname and filename.
 */
void createPath(char *dirname, char *filename, char *path) {
    for (int i = 0; i < stringLength(dirname); i++) {
        *(path + i) = *(dirname + i);
    }
    *(path + stringLength(dirname)) = '/';  
    for (int i = 0; i < stringLength(filename); i++) {
        *(path + stringLength(dirname) + 1 + i) = *(filename + i);
    }
    *(path + stringLength(dirname) + stringLength(filename) + 1) = '\0';
}