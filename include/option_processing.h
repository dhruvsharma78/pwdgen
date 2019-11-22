#ifndef OPTION_PROCESSING_H
#define OPTION_PROCESSING_H

#include "utils.h"
#include <getopt.h>

// Bit Field to store options for pwd generation
extern unsigned int __option_flags;
#define SET_OPTION(bit) SET_BIT(__option_flags, bit)
#define IS_OPTION_SET(bit) IS_BIT_SET(__option_flags, bit)

/* Bit meanings, from right to left */
enum __OPTION_BITS{
  SPECIAL_CHARS_BIT,      // Bit 0: Include Special Characters (!@#$%^&*(){}[]\|`~,.<>/?;:'") 
  NUMBERS_BIT,            // Bit 1: Include Numbers
  LCASE_LETTERS_BIT,      // Bit 2: Include Lowercase Characters
  UCASE_LETTERS_BIT,      // Bit 3: Include Uppercase Characters
  NO_SIMILAR_CHARS_BIT,   // Bit 4: Exclude Similar Characters (iIoO0lL)
  NO_AMBIGUOUS_CHARS_BIT, // Bit 5: Exclude Ambiguous Special Characters ({}[]()/\'"`~,;:.<>)
  PRINT_NATO_BIT,         // Bit 6: Print NATO format
  NO_WARNINGS_BIT,
  ONLY_PWD_BIT
};

extern unsigned int __pwd_len;

enum __OPTIONS{	       
  SPECIAL_CHARS,
  NUMBERS,
  LCASE_LETTERS,
  UCASE_LETTERS,
  NO_SIMILAR_CHARS,
  NO_AMBIGUOUS_CHARS,
  PRINT_NATO,
  LENGTH,
  NO_WARNINGS,
  ONLY_PWD,
  HELP
};

extern struct option long_options[];

void process_options(int, char**);
void validate_options(void);

#endif
