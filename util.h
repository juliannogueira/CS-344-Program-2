#ifndef UTIL_H
#define UTIL_H

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

/*
 * The util file contains helper functions to be used by main, movie, and menu.
 * 
 * There are functions to check for command line arguments, valid files, and
 * input.
 * 
 * There is also a function to get the number of characters in a
 * null-terminated string.
 * 
 * Function comments are included util.c.
 */

void intToString(int num, char *destination);

void concatStrings(char *str1, char *str2, char *destination);

int getRandomNumber(int max); 

int hasCommandLineArgument(char *argv[]);

int isValidFile(char *filename);

int isValidChoice(char ch);

int isValidChar(char ch);

int isValidDigit(char ch); 

void clearBuffer(char *buffer, int size);

int stringLength(char *string);

void copyString(char *source, char *destination);

int parseString(char *pattern, char *string);

int parseExtension(char *extension, char *filename);

void getParsedFilename(char *filename, char *prefix, char *extension, int getLargestFile);

void getFilename(char *buffer, int size);

void createDirectoryName(char *dirname, char *name, int max, int maxLength);

void createDirectory(char *dirname, char *name, int max, int maxLength);

void createFile(char *path);

void appendToFile(char *path, char *text);

void createPath(char *dirname, char *filename, char *path);

#endif