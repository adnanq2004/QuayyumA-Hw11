#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int * makenumbos(int n) {

  int file = open("/dev/random", 0644);
  int * arr = malloc(sizeof(int) * n);
  read(file, arr, sizeof(int));
  return arr;

}

void printnumbos(int * arr, int length) {

  int count;
  for (count = 0; count < length; count++) {
    printf("Random Number %d: %d\n", count, arr[count]);
  }

}

void writenumbos(int * temparr, int size) {

  int file = open("rando.txt", 0644);
  write(file, temparr, sizeof(int));

}

void readnumbos(int * temparr, int size) {

  int file = open("rando.txt", 0644);
  read(file, temparr , sizeof(int));

}

int main() {

  printf("Generating random numbers:\n");
  int * randoarray = makenumbos(10);
  printnumbos(randoarray, 10);

  printf("Writing numbers to file...\n");
  writenumbos(randoarray, 10);

  printf("Reading numbers from file...\n");
  readnumbos(randoarray, 10);

  printf("Verification that they are the same:\n");
  printnumbos(randoarray, 10);

}
