#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "utils.h"
#include "option_processing.h"
#include "pwdgen.h"
#include "nato.h"

unsigned int __option_flags;
unsigned int __pwd_len;

int main(int argc, char** argv){
  struct timespec t;
  char* password;
  
  clock_gettime(CLOCK_MONOTONIC, &t);
  srand(t.tv_sec * t.tv_nsec);
  
  process_options(argc, argv);
  validate_options();
  
  password = malloc((__pwd_len + 1) * sizeof(char));
  if(pwdgen(password) != 0){
    fprintf(stderr, "%s: Error occured while generating password...\n", PROGRAM_NAME);
    exit(1);
  }

  if(!IS_OPTION_SET(ONLY_PWD_BIT)){
    fprintf(stdout, "Generated Password:\n%s\n", password);
    if(IS_OPTION_SET(PRINT_NATO_BIT))
      nato_ize(password);
  }
  else
    fprintf(stdout, "%s\n", password);
  
  free(password);
  
  exit(0);
}
