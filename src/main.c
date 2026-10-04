#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

static char *read_file(const char *path, size_t *len) {
  FILE *f = fopen(path, "rb");
  if (!f) {
    perror(path);
    return NULL;
  }

  size_t cap = 1024, n = 0;
  char *buf = malloc(cap);
  if (!buf) {
    fclose(f);
    return NULL;
  }

  int c;
  while ((c = getc(f)) != EOF) {
    if (n + 1 >= cap) {
      cap *= 2;
      char *tmp = realloc(buf, cap);
      if (!tmp) {
        free(buf);
        fclose(f);
        return NULL;
      }
      buf = tmp;
    }
    buf[n++] = (char)c;
  }
  fclose(f);
  buf[n] = '\0';
  *len = n;
  return buf;
}

int main(void) { return 0; }
