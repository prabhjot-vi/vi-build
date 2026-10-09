#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

long get_file_size(const char* file_name) {
  long file_size;
  struct stat file_status;

  if (stat(file_name, &file_status) == -1) {
    perror("Error getting file status");
    return -1;
  }
 
  return (long) file_status.st_size;
}

char *get_file_content(const char* file_name) {
  const char *file_mode = "r";
  long file_size = get_file_size(file_name);

  char *file_content = (char*) malloc(sizeof(char) * file_size);

  FILE *file = fopen(file_name, file_mode);

  fread(file_content, sizeof(char), file_size, file);

  return file_content;
}

struct string {
  size_t length;
  size_t offset;
  char *ptr;
};

struct string *string_new(const char *c_string) {
  size_t string_length = strlen(c_string);

  // error out if c_string is empty
  if (string_length == 0) {
    perror("c_string can't be empty");
    return NULL;
  }

  if (c_string[string_length] != '\0') {
    perror("c_string should be null terminating");
    return NULL;
  }

  struct string *string = (struct string*) malloc(sizeof(struct string));

  string->length = string_length;
  string->offset = 0;
  string->ptr = (char*) malloc(sizeof(char) * string_length); 

  return string;
}

int main() {
  struct string *file_name = string_new("hello.txt");

  // printf("%*s", (int) file_name->length, file_name->ptr);
  return 0;
}
