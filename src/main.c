#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "config.h"

void print_logo();

int main() {
  Config config;

  read_config(&config);
  
  if (config.print_logo) {
    print_logo();
  }
  
  return 0;
}

void print_logo() {
  const char *LOGO_PATH = "/.config/cli-startup/logo";
  char *path;
  path = malloc(strlen(getenv("HOME")) + strlen(LOGO_PATH) + 1);
  strcpy(path, getenv("HOME"));
  strcat(path, LOGO_PATH);
  
  FILE *fp = fopen(path, "r");

  if (fp == NULL) {
    fprintf(stderr, "Not found: %s\n", path);
    exit(1);
  }
   
  long size;
  char *fcontent;

  fseek(fp, 0, SEEK_END); 
  size = ftell(fp);
  fseek(fp, 0, SEEK_SET);

  fcontent = malloc(size);
  fread(fcontent, 1, size, fp);

  fputs(fcontent, stdout);

  fclose(fp);
  free(fcontent);
  free(path);
}
