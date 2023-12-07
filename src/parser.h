#ifndef PARSER_H
#define PARSER_H

#include "utils/string.h"
#include "utils/row.h"

/**
 * Parse a csv file and return the data
 * @param file_name string - The file name
 * @returns RowArray - The csv file data
 */
RowArray parse_csv(string file_name);

/**
 * Parse the csv rows and return a row array
 * @param file_lines string* - The file lines
 * @returns RowArray - The row array
 */
RowArray parse_rows(StringArray file_lines);

#endif