#include <stdbool.h>

typedef struct {
  bool print_logo;
  char *logo_color;
} Config;

void read_config(Config *config);
