#ifndef FILE_H
#define FILE_H

#include <stdio.h>
#include "string.h"

/**
 * Read a csv file via the file name and return the pointer
 * @param file_name string - The file name
 * @returns FILE* - The file pointer
 */
FILE *read_file(string file_name);
/**
 * Read the file lines and return a string array
 * @param fptr FILE* - The file pointer
 * @returns StringArray - The string array
 */
StringArray read_file_lines(FILE *fptr);

#endif