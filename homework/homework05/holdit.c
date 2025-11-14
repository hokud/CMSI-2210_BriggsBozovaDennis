#include <stdio.h>
#include <time.h>

int main(void) {
  printf("This program will time how long you can hold your breath.\n");
  printf("Take a deep breath, then press Enter to begin.\n");
  printf("When you absolutely have to exhale, press Enter again.\n\n");
  printf("Press Enter to start...");
  getchar(); // Wait for first Enter

  time_t start = time(NULL); // start timing

  printf("Timing... Press Enter when you must exhale.\n");
  getchar(); // Wait for second Enter

  time_t end = time(NULL); // end timing

  double elapsed = difftime(end, start); // seconds difference

  int minutes = (int)elapsed / 60;
  int seconds = (int)elapsed % 60;

  printf("\nYou held your breath for %d minute(s) and %d second(s)!\n", minutes, seconds);

  return 0;
}

