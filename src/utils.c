#include "utils.h"
#include <stdio.h>

void usage(void){
  fprintf(stdout, "Usage: pwdgen [OPTION]...\n");
  fprintf(stdout, "\nOptions:\n");
  fprintf(stdout, "\t -l , --length \t\t\t Length of password\n");
  fprintf(stdout, "\t -n , --numbers \t\t Use numbers\n");
  fprintf(stdout, "\t -c , --lowercase-letters \t Use uppercase letters\n");
  fprintf(stdout, "\t -C , --uppercase-letters \t Use lowercase letters\n");
  fprintf(stdout, "\t --no-similar-chars \t\t Length of password\n");
  fprintf(stdout, "\t --no-ambiguous-chars \t\t Length of password\n");
  fprintf(stdout, "\t -N , --nato \t\t\t Print with NATO phonetics\n");
  fprintf(stdout, "\t -p , --password-only \t\t Length of password\n");
  fprintf(stdout, "\t -w \t\t\t\t Don't print warnings\n");
  fprintf(stdout, "\t -h , --help \t\t\t Help\n");
}
