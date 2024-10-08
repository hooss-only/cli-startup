#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "config.h"
#include "utils/print_logo.h"
#include "utils/wise_saying.h"

void init();

int main() {
  Config config;

  init(&config);

  read_config(&config);
  
  if (config.print_logo) {
    print_logo(config.logo_color);
  }

  if (config.wise_saying) {
    print_wise_saying();
  }
  
  return 0;
}

void init(Config *config) {
  config->logo_color = "\033[0;34m";
  config->print_logo = true;
  config->wise_saying = true;
}
