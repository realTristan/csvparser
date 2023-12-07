#ifndef FILE_C
#define FILE_C

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "string.h"

/**
 * Read a csv file via the file name and return the pointer
 * @param file_name string - The file name
 * @returns FILE* - The file pointer
 */
FILE *read_file(string file_name)
{
  FILE *fptr;

  fptr = fopen(file_name, "r+");

  return fptr;
}

/**
 * Read the file lines and return a string array
 * @param fptr FILE* - The file pointer
 * @returns StringArray - The string array
 */
StringArray read_file_lines(FILE *fptr)
{
  StringArray file_lines = new_string_array();

  char *line = NULL;
  size_t len = 0;
  ssize_t read;

  while ((read = getline(&line, &len, fptr)) != -1)
  {
    // Set the last character to null
    line[strlen(line) - 1] = '\0';

    // Append the line to the file lines
    file_lines = append_str(file_lines, line);
  }

  return file_lines;
}

#endif