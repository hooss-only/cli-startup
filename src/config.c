#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CONFIG_PATH "/.config/cli-startup/config"
#define KEYWORDS_LENGTH 1

const char *KEYWORDS[KEYWORDS_LENGTH] = {
  "print_logo"
};

char* get_config_path(char* file) {

  strcpy(file, getenv("HOME"));
  strcat(file, CONFIG_PATH);
  
  return file;
}

typedef struct {
  int print_logo;
} Config;

void create_config() {
  char *path;
  path = malloc(strlen(getenv("HOME")) + strlen(CONFIG_PATH) + 1);
  get_config_path(path);

  FILE *config_file;
  config_file = fopen(path, "a");

  for (int i = 0, l = KEYWORDS_LENGTH; i < l; i++) {
    fprintf(config_file, "%s=true\n", KEYWORDS[i]);
  }

  fclose(config_file);
  free(path);
}

void read_config(Config *config) {
  char *yes[] = { "yes", "true", "on" };
  char *no[] = { "no", "false", "off" };
  
  char *path;
  path = malloc(strlen(getenv("HOME")) + strlen(CONFIG_PATH) + 1);
  
  get_config_path(path);

  FILE *config_file;
  config_file = fopen(path, "r");
  
  if (config_file == NULL) {
    create_config();
    read_config(config);
    return;
  }

  fclose(config_file);
  free(path);

  return;
}
