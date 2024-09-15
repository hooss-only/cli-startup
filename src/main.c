#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "config.h"
#include "utils/print_logo.h"

int main() {
  Config config;

  read_config(&config);
  
  if (config.print_logo) {
    print_logo(config.logo_color);
  }
  
  return 0;
}
