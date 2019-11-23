#include <stdlib.h>
#include "pwdgen.h"
#include "option_processing.h"

void swap(char* a, char* b){
  char temp;
  temp = *a; 
  *a = *b; 
  *b = temp;
}

void shuffle(char* buf, unsigned int start, unsigned int end){
  unsigned int i,j;
  for (i=end-1; i>start; --i){ 
    j = rand() % (i+1);
    swap(&buf[i], &buf[j]); 
  } 
}

int pwdgen(char* buf){
  char* char_pool;
  unsigned int i, size;
  char_pool = malloc(1024 * sizeof(char));
  size = generate_char_pool(char_pool);
  for(i=0; i<__pwd_len; ++i){
    buf[i] = char_pool[(int)rand() % size];
  }
  buf[i] = 0;
  free(char_pool);
  return 0;
}

unsigned int add_to_pool(char* pool, unsigned int* pool_index, unsigned int start, unsigned int end){
  unsigned int i, size;
  size = 0;
  for(i=start; i<=end; ++i){
    pool[*pool_index] = (char) i;
    *pool_index += 1;
    ++size;
  }
  return size;
}

unsigned int generate_char_pool(char* pool){
  unsigned int pool_index, pool_size;
  pool_index = 0;
  pool_size = 0;

  /* Add numbers if allowed */
  if(IS_OPTION_SET(NUMBERS_BIT))
    pool_size += add_to_pool(pool, &pool_index, NUM_START, NUM_END);
  /* Add lowercase if allowed */
  if(IS_OPTION_SET(LCASE_LETTERS_BIT))
    pool_size += add_to_pool(pool, &pool_index, LCASE_START, LCASE_END);
  /* Add uppercase if allowed */
  if(IS_OPTION_SET(UCASE_LETTERS_BIT))
    pool_size += add_to_pool(pool, &pool_index, UCASE_START, UCASE_END);
  
  return pool_size;
}
