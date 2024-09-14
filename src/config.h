typedef struct {
  int print_logo;
  char *logo_color;
} Config;

void read_config(Config *config);
