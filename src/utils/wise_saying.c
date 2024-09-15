#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define WISE_TEXTS_PATH "/.config/cli-startup/wise_texts"

void create_default_wise_texts() {
  char *path;
  path = malloc(strlen(getenv("HOME")) + strlen(WISE_TEXTS_PATH) + 1);
  strcpy(path, getenv("HOME"));
  strcat(path, WISE_TEXTS_PATH);

  FILE *fp = fopen(path, "a");

  const char *DEFAULT[] = {
    "Believe in yourself. -Anonymous",
    "Never lose sight of the face that the most important yard stick to your success is how you treat other people. – Barbara Bush",
    "Success is not final; failure is not fatal: It is the courage to continue that counts. – Winston S. Churchill",
    "If you really look closely, most overnight successes took a long time. – Steve Jobs",
    "Think Different - Steve Jobs",
    "Stay Hungry, Stay Foolish - Steve Jobs"
  };

  int l = sizeof(DEFAULT)/sizeof(char*);
  
  fprintf(fp, "%d\n", l);
  for (int i = 0; i<l; i++) {
    fprintf(fp, "%s\n", DEFAULT[i]);
  }

  fclose(fp);
  free(path);
}

void print_wise_saying() {
  char *path;
  path = malloc(strlen(getenv("HOME")) + strlen(WISE_TEXTS_PATH) + 1);
  strcpy(path, getenv("HOME"));
  strcat(path, WISE_TEXTS_PATH);

  FILE *fp = fopen(path, "r");

  if (fp == NULL) {
    create_default_wise_texts();
    print_wise_saying();
    return;
  }

  srand(time(NULL));
  int r;

  char * line = NULL;
  int line_number = 0;
  size_t len = 0;
  ssize_t read;
  
  while ((read = getline(&line, &len, fp)) != -1) {
    if (line_number == 0) {
      r = 1 + (rand() % (atoi(line)-1));
      line_number++;
      continue;
    }

    if (line_number == r) {
      printf("%s", line);
      return;
    }

    line_number++;
  }
 

  fclose(fp);
  free(path);
}
