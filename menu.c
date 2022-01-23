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
    const int SIZE = 255;
    int isRunning = 1;
    int getLargestFile = 0;
    int specifyFile = 0;
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
                specifyFile = 0;
                getLargestFile = 1;
                processMovieFile(specifyFile, getLargestFile);
                break;
            case '2':
                specifyFile = 0;
                getLargestFile = 0;
                processMovieFile(specifyFile, getLargestFile);
                break;
            case '3':
                specifyFile = 1;
                getLargestFile = -1;
                processMovieFile(specifyFile, getLargestFile);
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