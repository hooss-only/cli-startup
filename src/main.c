#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "config.h"

int main() {
  Config config;

  read_config(&config);
  
  return 0;
}

