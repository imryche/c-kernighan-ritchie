#include <stdio.h>
#include <stdlib.h>

int main() {
  int day, month, year;
  char monthname[20];

  char *line;
  size_t linesize = 100;

  line = (char *)malloc(linesize * sizeof(char));
  if (line == NULL) {
    printf("error: unable to allocate buffer");
    exit(1);
  }

  while (getline(&line, &linesize, stdin) > 0) {
    if (sscanf(line, "%d %s %d", &day, monthname, &year) == 3)
      printf("valid: %s\n", line);
    else if (sscanf(line, "%d/%d/%d", &month, &day, &year) == 3)
      printf("valid: %s\n", line);
    else
      printf("invalid: %s\n", line);
  }

  free(line);

  return 0;
}
