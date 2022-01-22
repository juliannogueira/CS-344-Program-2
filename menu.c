#include "menu.h"
#include "processMovieFile.h"

/*
 * Display the main menu to the user.
 * 
 * The user is prompted to enter a menu option.
 * 
 * If the user enters an invalid option, the user is notified. Otherwise, the
 * user will be taken to the submenu or the program will be terminated.
 */
void runMenu() {
    int isRunning = 1;
    const int SIZE = 255;
    char buffer[SIZE];
    char option = '\0';
    char *header =         "-------------------- Movies by Year: Main Menu ---------------------\n";
    char *headerLine =     "--------------------------------------------------------------------\n";
    char *option1 =        "1) Select a file to process\n";
    char *option2 =        "2) Quit the program\n";
    char *prompt =         "\nEnter a valid menu option: ";
    char *invalidOption =  "\nAn invalid menu option was entered.\n";

    while (isRunning) {
        printf("\n\n%s", headerLine);
        printf("%s", header);
        printf("%s", headerLine);
        printf("%s", option1);
        printf("%s", option2);
        printf("%s", prompt);

        fgets(buffer, SIZE, stdin);
        option = buffer[0];

        switch (option) {
            case '1':
                runSubmenu();
                break;
            case '2':
                isRunning = 0;
                printf("\n\n");
                break;
            default:
                printf("%s", invalidOption);
                break;
        }
    }
}

/*
 * Display the submenu to the user.
 * 
 * The user is prompted to enter a menu option.
 * 
 * If the user enters an invalid option, the user is notified. Otherwise, the
 * user chooses to process the largest, smallest, or specified file.
 * 
 * The user also has the choice to return to the main menu.
 */
void runSubmenu() {
    int isRunning = 1;
    const int SIZE = 255;
    char buffer[SIZE];
    char option = '\0';
    char *header =         "------------------ Movies by Year: Process a File ------------------\n";
    char *headerLine =     "--------------------------------------------------------------------\n";
    char *option1 =        "1) Process the largest file\n";
    char *option2 =        "2) Process the smallest file\n";
    char *option3 =        "3) Process a specified file\n";
    char *option4 =        "4) Return to the main menu\n";
    char *prompt =         "\nEnter a valid menu option: ";
    char *invalidOption =  "\nAn invalid menu option was entered.\n";

    while (isRunning) {
        printf("\n\n%s", headerLine);
        printf("%s", header);
        printf("%s", headerLine);
        printf("%s", option1);
        printf("%s", option2);
        printf("%s", option3);
        printf("%s", option4);
        printf("%s", prompt);

        fgets(buffer, SIZE, stdin);
        option = buffer[0];

        switch (option) {
            case '1':
                printf("\nCase 1.\n");
                processMovieFile(1);
                break;
            case '2':
                printf("\nCase 2.\n");
                break;
            case '3':
                printf("\nCase 3.\n");
                break;
            case '4':
                isRunning = 0;
                break;
            default:
                printf("%s", invalidOption);
                break;
        }
    }
}

/*
 * Display all movies released in a specified year.
 *
 * The user is prompted for the year.
 * 
 * The year and the movies struct linked list head is passed to the respective
 * function, and the results are displayed.
 */
void getMoviesByYear(struct Movie *head) {
    const int SIZE = 255;
    const int SIZE_YEAR = 4;
    int year = 0;
    char buffer[SIZE];
    char choice[SIZE_YEAR + 1];
    char *header =         "-------------- Movies: Released in a Specified Year ----------------\n";
    char *headerLine =     "--------------------------------------------------------------------\n";
    char *prompt =         "\nEnter the year: ";

    printf("\n\n%s", headerLine);
    printf("%s", header);
    printf("%s", headerLine);
    printf("%s", prompt);
    
    fgets(buffer, SIZE, stdin);
    
    for (int i = 0; i < SIZE_YEAR; i++) {
        if (isValidDigit(buffer[i])) {
            choice[i] = buffer[i];
        } else {
            choice[i] = '\0';
        }
    }
    
    choice[SIZE_YEAR] = '\0';

    sscanf(choice, "%d", &year);

    printf("\n");

    readListMoviesByYear(head, year);
}

/*
 * Display the highest rated movie per year.
 *
 * The function displays the header and immediately calls the respective
 * function to get the highest rated movies per year, such that a new list is
 * returned.
 * 
 * A function to read the list is called, such that the results are displayed.
 * 
 * The memory allocated to the new list is freed before resuming control to the
 * calling function.
 */
void getHighestRatedMoviePerYear(struct Movie *head) {
    struct Movie *highestRatedList = NULL;
    char *header =         "----------------- Movies: Highest Rated Per Year -------------------\n";
    char *headerLine =     "--------------------------------------------------------------------\n";

    printf("\n\n%s", headerLine);
    printf("%s", header);
    printf("%s", headerLine);

    highestRatedList = createListHighestRatedMoviePerYear(head);

    printf("\n");

    readListYearRatingValueTitle(highestRatedList);

    freeList(highestRatedList);
}

/*
 * Display all movies available in a specified language.
 * 
 * The user is prompted to enter a language.
 * 
 * The language is passed with the head of the movie struct linked list to the
 * respective function to search for all movies available in that language.
 * 
 * The results are displayed immediately by the called function.
 */
void getMoviesByLanguage(struct Movie *head) {
    const int SIZE = 255;
    const int SIZE_LANGUAGE = 20;
    char *header =         "----------- Movies: Available in a Specified Language --------------\n";
    char *headerLine =     "--------------------------------------------------------------------\n";
    char *prompt =         "\nEnter the language: ";
    char buffer[SIZE];
    char language[SIZE_LANGUAGE + 1];

    for (int i = 0; i < SIZE_LANGUAGE; i++) {
        language[i] = '\0';
    }

    printf("\n\n%s", headerLine);
    printf("%s", header);
    printf("%s", headerLine);
    printf("%s", prompt);

    fgets(buffer, SIZE, stdin);

    for (int i = 0; i < SIZE_LANGUAGE; i++) {
        if (buffer[i] == '\n') {
            break;
        }

        language[i] = buffer[i];
    }

    language[SIZE_LANGUAGE] = '\0';

    readListMoviesByLanguage(head, language);

    printf("\n");
}