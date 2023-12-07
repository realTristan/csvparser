#ifndef PARSER_C
#define PARSER_C

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "utils/string.h"
#include "utils/file.h"
#include "utils/row.h"

/**
 * Function prototypes
 */
RowArray parse_csv(string);
RowArray parse_rows(StringArray);

/**
 * Parse a csv file and return the data
 * @param file_name string - The file name
 * @returns RowArray - The csv file data
 */
RowArray parse_csv(string file_name)
{
  // Read the csv file and get the file lines
  FILE *fptr = read_file(file_name);

  // Read the file lines
  StringArray file_lines = read_file_lines(fptr);

  // Read the rows
  RowArray rows = parse_rows(file_lines);

  // Close the file
  fclose(fptr);

  // Return the data
  return rows;
}

/**
 * Parse the csv rows and return a row array
 * @param file_lines string* - The file lines
 * @returns RowArray - The row array
 */
RowArray parse_rows(StringArray file_lines)
{
  RowArray rows = new_row_array();

  for (int i = 0; i < file_lines.size; i++)
  {
    string line = file_lines.values[i];

    // Split the line by the comma
    StringArray row = split_str(line, ',');

    // Append the row to the rows array
    rows = append_row(rows, row);
  }

  return rows;
}

#endif