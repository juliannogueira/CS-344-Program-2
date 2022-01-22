#ifndef MENU_H
#define MENU_H

#include "movie.h"

/*
 * The menu file provides the user with menu options to process movie data by
 * year.
 *
 * The user can process data for the largest file in the directory.
 * 
 * The user can process data for the smallest file in the directory.
 * 
 * The user can process data a specified file in the directory.
 */

void runMenu();

void runSubmenu();

void getMoviesByYear(struct Movie *head);

void getHighestRatedMoviePerYear(struct Movie *head);

void getMoviesByLanguage(struct Movie *head);

#endif