#include <stdbool.h>

typedef struct {
  bool print_logo;
  char *logo_color;
  bool wise_saying;
} Config;

void read_config(Config *config);
