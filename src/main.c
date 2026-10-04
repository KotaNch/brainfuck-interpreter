#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define TAPE_SIZE 30000

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

static int run(const char *code, size_t len) {
  unsigned char tape[TAPE_SIZE] = {0};
  size_t ptr = 0;
  for (size_t pc = 0; pc < len; pc++) {
    switch (code[pc]) {
    case '+':
      tape[ptr]++;
      break;
    case '-':
      tape[ptr]--;
      break;
    case '>':
      ptr++;
      break;
    case '<':
      ptr--;
      break;
    case '.':
      putchar(tape[ptr]);
      break;
    }
  }
  return 0;
}

int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "usage: %s file.bf\n", argv[0]);
    return 1;
  }
  size_t len;
  char *code = read_file(argv[1], &len);
  if (!code) {
    return 1;
  }

  int status = run(code, len);
  free(code);
  return status;
}
