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
    
  }

  struct string *string = (struct string*) malloc(sizeof(struct string));

  

  return string;
}

int main() {
  const char *file_name = "src/main.cpp";
  return 0;
}
