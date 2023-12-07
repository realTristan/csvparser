#include <stdlib.h>
#include <stdio.h>
#include "../parser.h"

/**
 * Main function
 */
int main(void)
{
  RowArray data = parse_csv("data.csv");

  // Iterate over each row
  for (size_t i = 0; i < data.size; i++)
  {
    Row row = data.values[i];

    // Iterate over each value in the row
    for (size_t j = 0; j < row.size; j++)
    {
      printf("%s ", row.values[j]); // Print the row value
    }

    printf("\n");
  }

  return 0;
}