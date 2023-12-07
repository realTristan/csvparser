#ifndef STRING_H
#define STRING_H

#include <stdlib.h>

typedef char *string;
typedef struct
{
  size_t size;
  string *values;
} StringArray;

/**
 * Create a new string array
 * @return The string array
 */
StringArray new_string_array();

/**
 * Append a string to the string array
 * @param StringArray The string array
 * @param string The string to append
 * @return The string array
 */
StringArray append_str(StringArray, string);

/**
 * Split a string by a delimiter
 * @param string The string to split
 * @param delim The delimiter
 * @return The string array
 */
StringArray split_str(string, char);

#endif