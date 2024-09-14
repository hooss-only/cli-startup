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

int get_bool_from_option(char *option) {
  const int length = 3;
  char *yes[] = { "yes", "true", "on" };
  char *no[] = { "no", "false", "off" };
  
  int opt = -1;
  for (int i=0; i<length; i++) {
    if (strcmp(option, yes[i]) == 0) {
      opt = 1;
      break;
    } else if (strcmp(option, no[i]) == 0) {
      opt = 0;
      break;
    }
  }

  return opt;
}

void change_config(Config *config, char *keyword, int opt) {
  if (!strcmp(keyword, "print_logo")) {
    *config = opt;
  }
}

void read_config(Config *config) {
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

  char * line = NULL;
  int line_number = 1;
  size_t len = 0;
  ssize_t read;
  
  while ((read = getline(&line, &len, config_file)) != -1) {
    char keyword[read] = {};
    char option[read] = {};
  
    int end_keyword = 0;
    for (int i=0; 1; i++) {
      char c = line[i];
      if (c == '\n' || c == 0) break;
      
      if (c == '=') end_keyword = i;

      if (!strcmp(keyword, "//")) break;

      if (end_keyword) {
        option[i-end_keyword-1] = c;
      } else {
        keyword[i] = c;
      }
    }
    
    int opt = get_bool_from_option(option);

    if (opt == -1) {
      fprintf(stderr, "line %d, %s is not a type of option.\n", line_number, option);
      exit(1);
    }
    
    change_config(config, keyword, opt);
    line_number++;
  }
  
  if (line)
    free(line);

  fclose(config_file);
  free(path);
}
