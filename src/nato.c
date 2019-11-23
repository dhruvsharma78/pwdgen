#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "option_processing.h"
#include "nato.h"

char* number_names[] = {
  "ZERO",
  "ONE",
  "TWO",
  "THREE",
  "FOUR",
  "FIVE",
  "SIX",
  "SEVEN",
  "EIGHT",
  "NINE"
};

char* NATO_phonetics[] = {
  "ALPHA",
  "BRAVO",
  "CHARLIE",
  "DELTA",
  "ECHO",
  "FOXTROT",
  "GOLF",
  "HOTEL",
  "INDIA",
  "JULIETT",
  "KILO",
  "LIMA",
  "MIKE",
  "NOVEMBER",
  "OSCAR",
  "PAPA",
  "QUEBEC",
  "ROMEO",
  "SIERRA",
  "TANGO",
  "UNIFORM",
  "VICTOR",
  "WHISKEY",
  "XRAY",
  "YANKEE",
  "ZULU"
};

int getNumberName(char c, char* buf){
  int num = (int) c - '0';
  if(num < 0 || num > 9) return -1;
  strcpy(buf, number_names[num]);
  return 0;
}

int getAlphaPhonetic(char c, char* buf){
  char ch = toupper(c);
  if(ch < 0x41 || ch > 0x5A) return -1;
  strcpy(buf, NATO_phonetics[ch - 0x41]);
  return 0;
}

int nato_ize(char* pwd){
  unsigned int i;
  char buf[10];
  for(i=0; i<__pwd_len; ++i){
    if(isdigit(pwd[i]))
      getNumberName(pwd[i], buf);
    else if(isalpha(pwd[i]))
      getAlphaPhonetic(pwd[i], buf);

    fprintf(stdout, "%s ", buf);
  }
  fprintf(stdout, "\n");
  return 0;
}
