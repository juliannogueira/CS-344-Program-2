Author: Julian Torres
Course: CS-344
Assignment: Program-1

To compile the code:
    make

To run the program:
    Method 1:
        make run file={file}

    Method 2:
        ./movies {file}

To check for memory leaks:
    Method 1:
        make check file={file}

    Method 2:
        valgrind --leak-check=yes ./movies {file}
