#ifndef ROW_H
#define ROW_H

#include <stdlib.h>
#include "string.h"

typedef StringArray Row;

typedef struct
{
  size_t size;
  Row *values;
} RowArray;

/**
 * Create a new row array
 * @return The row array
 */
RowArray new_row_array();

/**
 * Append a row to the row array
 * @param rows RowArray - The row array
 * @param row Row - The row to append
 */
RowArray append_row(RowArray rows, Row row);

#endif