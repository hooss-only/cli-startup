#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char *LOGO_PATH = "/.config/cli-startup/logo";

void create_logo_file() {
  char *path;
  path = malloc(strlen(getenv("HOME")) + strlen(LOGO_PATH) + 1);
  strcpy(path, getenv("HOME"));
  strcat(path, LOGO_PATH);

  FILE *fp = fopen(path, "a");

  fputs(" ██████╗██╗     ██╗      ███████╗████████╗ █████╗ ██████╗ ████████╗██╗   ██╗██████╗ \n", fp);
  fputs("██╔════╝██║     ██║      ██╔════╝╚══██╔══╝██╔══██╗██╔══██╗╚══██╔══╝██║   ██║██╔══██╗\n", fp);
  fputs("██║     ██║     ██║█████╗███████╗   ██║   ███████║██████╔╝   ██║   ██║   ██║██████╔╝\n", fp);
  fputs("██║     ██║     ██║╚════╝╚════██║   ██║   ██╔══██║██╔══██╗   ██║   ██║   ██║██╔═══╝ \n", fp);
  fputs("╚██████╗███████╗██║      ███████║   ██║   ██║  ██║██║  ██║   ██║   ╚██████╔╝██║     \n", fp);
  fputs(" ╚═════╝╚══════╝╚═╝      ╚══════╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝    ╚═════╝ ╚═╝     \n", fp);
  
  fclose(fp);
  free(path);
}

void print_logo(char *color_code) {
  printf("%s\n", color_code);
  char *path;
  path = malloc(strlen(getenv("HOME")) + strlen(LOGO_PATH) + 1);
  strcpy(path, getenv("HOME"));
  strcat(path, LOGO_PATH);
  
  FILE *fp = fopen(path, "r");

  if (fp == NULL) {
    create_logo_file();
    print_logo(color_code);
    return;
  }
   
  long size;
  char *fcontent;

  fseek(fp, 0, SEEK_END); 
  size = ftell(fp);
  fseek(fp, 0, SEEK_SET);

  fcontent = malloc(size);
  fread(fcontent, 1, size, fp);

  printf("%s%s", color_code, fcontent);

  fclose(fp);
  free(fcontent);
  free(path);
}
