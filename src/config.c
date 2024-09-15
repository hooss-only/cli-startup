#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#define CONFIG_PATH "/.config/cli-startup/config"
#define KEYWORDS_LENGTH 4
#define KEYWORDS_TOGGLE_LENGTH 2

const char *KEYWORDS[KEYWORDS_LENGTH] = {
  "print_logo",
  "logo_color",
  "wise_saying"
};

const char *KEYWORDS_TOGGLE[KEYWORDS_TOGGLE_LENGTH] = {
  "print_logo",
  "wise_saying"
};

char* get_config_path(char* file) {
  strcpy(file, getenv("HOME"));
  strcat(file, CONFIG_PATH);
  
  return file;
}

typedef struct {
  bool print_logo;
  char *logo_color;
  bool wise_saying;
} Config;

void create_config() {
  char *path;
  path = malloc(strlen(getenv("HOME")) + strlen(CONFIG_PATH) + 1);
  get_config_path(path);

  FILE *config_file;
  config_file = fopen(path, "a");

  for (int i = 0, l = KEYWORDS_TOGGLE_LENGTH; i < l; i++) {
    fprintf(config_file, "%s=true\n", KEYWORDS_TOGGLE[i]);
  }

  fclose(config_file);
  free(path);
}

int8_t get_bool_from_option(char *option) {
  const int length = 3;
  char *yes[] = { "yes", "true", "on" };
  char *no[] = { "no", "false", "off" };
  
  for (int i=0; i<length; i++) {
    if (strcmp(option, yes[i]) == 0) {
      return 1;
    } else if (strcmp(option, no[i]) == 0) {
      return 0;
    }
  }

  return -1;
}

void change_config(Config *config, char *keyword, char *option, int line_number) {
  int8_t opt;
  
  int is_toggle = 0;
  for (int i = 0; i < KEYWORDS_TOGGLE_LENGTH; i++) {
    if (!strcmp(keyword, KEYWORDS_TOGGLE[i])) {
      is_toggle = 1;
      break;
    }
  }
    
  if (is_toggle) {
    opt = get_bool_from_option(option);

    if (opt == -1) {
      fprintf(stderr, "line %d of config, %s is not a type of option.\n", line_number, option);
      exit(1);
    }
  }

  if (!strcmp(keyword, "print_logo")) {
    config->print_logo = opt;
    return;
  }

  if (!strcmp(keyword, "logo_color")) {
    char *color_code = NULL;
    
    char *colors[] = { "black", "red", "green", "yellow", "blue", "purple", "cyan", "white" };
    char *color_codes[] = { "\033[0;30m", "\033[0;31m", "\033[0;32m", "\033[0;33m", "\033[0;34m", "\033[0;35m", "\033[0;36m", "\033[0;37m" };

    for (int i = 0; i < 8; i++)
      if (!strcmp(option, colors[i]))
        color_code = color_codes[i];

    if (color_code == NULL) {
      fprintf(stderr, "%s is not an available color.", option);
      exit(1);
    }

    config->logo_color = color_code;
    return;
  }

  if (!strcmp(keyword, "wise_saying")) {
    config->wise_saying = opt;
    return;
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
    
    change_config(config, keyword, option, line_number);
    line_number++;
  }
  
  if (line)
    free(line);

  fclose(config_file);
  free(path);
}
