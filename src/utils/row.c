#ifndef ROW_C
#define ROW_C

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
RowArray new_row_array()
{
  return (RowArray){0, NULL};
}

/**
 * Append a row to the row array
 * @param rows RowArray - The row array
 * @param row Row - The row to append
 */
RowArray append_row(RowArray rows, Row row)
{
  // Reallocate the array
  rows.values = realloc(rows.values, sizeof(Row) * (rows.size + 1));

  // Append the row to the array
  rows.values[rows.size] = row;
  rows.size++; // Increment the size

  // Return the array
  return rows;
}

#endif