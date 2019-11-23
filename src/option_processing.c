
// option_processing.c

#include <stdlib.h>
#include <getopt.h>
#include <stdio.h>

#include "constants.h"
#include "option_processing.h"
#include "utils.h"

struct option long_options[] = {
  {"special-chars",      no_argument,       0, SPECIAL_CHARS},
  {"numbers",            no_argument,       0, NUMBERS},
  {"lowercase-letters",  no_argument,       0, LCASE_LETTERS},
  {"uppercase-letters",  no_argument,       0, UCASE_LETTERS},
  {"no-similar-chars",   no_argument,       0, NO_SIMILAR_CHARS},
  {"no-ambiguous-chars", no_argument,       0, NO_AMBIGUOUS_CHARS},
  {"nato",               no_argument,       0, PRINT_NATO},
  {"length",             required_argument, 0, LENGTH},
  {"password-only",     no_argument,       0, ONLY_PWD},
  {"help",               no_argument,       0, HELP},
  {0, 0, 0, 0}
};

void process_options(int argc, char* argv[]){
  int c;
  __pwd_len = 0;
  __option_flags = 0;
  opterr = 0; // Disable default getopt error handling
  while(1){
    if((c = getopt_long(argc, argv, "sncCLl:Nwph", long_options, NULL)) == -1) break;
    switch(c){
    case 'h':
    case HELP:
      usage();
      exit(0);
      break;
    case 's':
    case SPECIAL_CHARS:
      SET_OPTION(SPECIAL_CHARS_BIT);
      break;
    case 'n':
    case NUMBERS:
      SET_OPTION(NUMBERS_BIT);
      break;
    case 'c':
    case LCASE_LETTERS:
      SET_OPTION(LCASE_LETTERS_BIT);
      break;
    case 'C':
    case UCASE_LETTERS:
      SET_OPTION(UCASE_LETTERS_BIT);
      break;
    case 'L':
      SET_OPTION(LCASE_LETTERS_BIT);
      SET_OPTION(UCASE_LETTERS_BIT);
      break;
    case NO_SIMILAR_CHARS:
      SET_OPTION(NO_SIMILAR_CHARS_BIT);
      break;
    case NO_AMBIGUOUS_CHARS:
      SET_OPTION(NO_AMBIGUOUS_CHARS_BIT);
      break;
    case 'N':
    case PRINT_NATO:
      SET_OPTION(PRINT_NATO_BIT);
      break;
    case 'l':
    case LENGTH:
      __pwd_len = (unsigned int) atoi(optarg);
      break;
    case 'w':
    case NO_WARNINGS:
      SET_OPTION(NO_WARNINGS_BIT);
      break;
    case 'p':
    case ONLY_PWD:
      SET_OPTION(ONLY_PWD_BIT);
      break;
    case ':':
      fprintf(stderr, "%s: ERROR: Option \'%s\' requires an argument N...\n\tIgnoring option and using default settings...\n", PROGRAM_NAME, argv[optind-1]);
      break;
    case '?':
      fprintf(stderr, "%s: ERROR: Unknown option \'%s\'\n", PROGRAM_NAME, argv[optind-1]);
      break;
    }
  }
}

void validate_options(void){
  /* Check if atleast 1 character set is picked */
  if(!IS_OPTION_SET(NUMBERS_BIT) &&
     !IS_OPTION_SET(LCASE_LETTERS_BIT) &&
     !IS_OPTION_SET(UCASE_LETTERS_BIT) &&
     !IS_OPTION_SET(SPECIAL_CHARS_BIT)){
    if(!IS_OPTION_SET(NO_WARNINGS_BIT))
      fprintf(stderr, "%s: WARNING: Must select atleast one character set!\n\tUsing defaults (lowercase letters and numbers)...\n", PROGRAM_NAME);
    SET_OPTION(NUMBERS_BIT);
    SET_OPTION(LCASE_LETTERS_BIT);
  }

  /* Check if length specified */
  if(__pwd_len == 0){
    if(!IS_OPTION_SET(NO_WARNINGS_BIT))
      fprintf(stderr, "%s: WARNING: No password length picked!\n\tUsing default length 8\n", PROGRAM_NAME);
    __pwd_len = 8;
  }
}
