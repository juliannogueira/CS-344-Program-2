CC = gcc -std=c99
CFLAGS = -g -Wall
TARGET = movies_by_year

output: main.o util.o movie.o processMovieFile.o menu.o
	$(CC) $(CFLAGS) main.o util.o movie.o processMovieFile.o menu.o -o $(TARGET)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

util.o: util.c util.h
	$(CC) $(CFLAGS) -c util.c

movie.o: movie.c movie.h
	$(CC) $(CFLAGS) -c movie.c

processMovieFile.o: processMovieFile.c processMovieFile.h
	$(CC) $(CFLAGS) -c processMovieFile.c

menu.o: menu.c menu.h
	$(CC) $(CFLAGS) -c menu.c

clean:
	rm -f *.o $(TARGET)
	rm -rf torresju.movies.*

run:
	./$(TARGET)

check:
	valgrind --leak-check=yes ./$(TARGET)