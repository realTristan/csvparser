#ifndef STRING_C
#define STRING_C

#include <stdlib.h>
#include <string.h>

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
StringArray new_string_array()
{
  return (StringArray){0, NULL};
}

/**
 * Append a string to the string array
 * @param arr The string array
 * @param str The string to append
 * @return The string array
 */
StringArray append_str(StringArray arr, string str)
{
  // Reallocate the array
  arr.values = realloc(arr.values, sizeof(string) * (arr.size + 1));

  // Allocate a new string
  string new_str = malloc(sizeof(string) * strlen(str));
  strcpy(new_str, str);

  // Append the string to the array
  arr.values[arr.size] = new_str;
  arr.size++; // Increment the size

  // Return the array
  return arr;
}

/**
 * Split a string by a delimiter
 * @param str The string to split
 * @param delim The delimiter
 * @return The string array
 */
StringArray split_str(string str, char delim)
{
  // Store the size of the string
  size_t str_len = strlen(str);

  // Allocate a new string array
  StringArray arr = new_string_array();

  // Allocate a new temp string
  string tmp = malloc(sizeof(string) * str_len);

  // Iterate over the
  for (int i = 0; i < str_len; i++)
  {
    if (str[i] == delim)
    {
      // Append the tmp string to the string array
      arr = append_str(arr, tmp);

      // Clear the tmp string
      strcpy(tmp, "");

      continue;
    }

    // Append the current character to the tmp string
    strncat(tmp, &str[i], 1);
  }

  // If the string isn't empty
  if (strlen(tmp) > 0)
  {
    // Append the tmp string to the string array
    arr = append_str(arr, tmp);
  }

  return arr;
}

#endif