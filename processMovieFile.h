#ifndef PROCESS_MOVIE_FILE_H
#define PROCESS_MOVIE_FILE_H

#include "movie.h"

/*
 * The process movie file contains functions to process movie data files.
 *
 * A file is either specified, or the largest or smallest movie data file is
 * looked for in the current directory.
 * 
 * The file is processed and a directory is created with movies written to a
 * file per year.
 */

void processMovieFile(int specifyFile, int getLargestFile);

void processData(char *filename); 

#endif