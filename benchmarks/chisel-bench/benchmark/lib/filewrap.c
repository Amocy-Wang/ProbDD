#include <stdio.h>
#include <stdlib.h>

int fclose(FILE *stream) { return -1; }

FILE *fdopen(int handle, const char *type) { return NULL; }

FILE *fopen(const char *filename, const char *mode) { return NULL; }

int ferror(FILE *stream) { return 1000; }

int fflush(FILE *stream) { return -1; }

char *fgets(char *string, int n, FILE *stream) { return NULL; }

int fileno(FILE *stream) { return -1; }

int fprintf(FILE *stream, const char *format_string, ...) { return -2; }

int fputc(int c, FILE *stream) { return -2; }

int fputs(const char *string, FILE *stream) { return -2; }

FILE *freopen(const char *filename, const char *mode, FILE *stream) {
  return NULL;
}

int fseek(FILE *stream, long int offset, int origin) { return 1; }

int fsetpos(FILE *stream, const fpos_t *pos) { return 1; }

long int ftell(FILE *stream) { return -1L; }

int setvbuf(FILE *stream, char *buf, int type, size_t size) { return 1; }

int vfprintf(FILE *stream, const char *format, va_list arg_ptr) { return -1; }

int vfscanf(FILE *stream, const char *format, va_list arg_ptr) { return -1; }

int vfwprintf(FILE *stream, const wchar_t *format, va_list arg) { return -1; }

int vfwscanf(FILE *stream, const wchar_t *format, va_list arg_ptr) {
  return -1;
}
