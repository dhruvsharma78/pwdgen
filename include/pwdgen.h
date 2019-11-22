#ifndef PWDGEN_H
#define PWDGEN_H

#define NUM_START 0x30
#define NUM_END   0x39
#define UCASE_START 0x41
#define UCASE_END   0x5A
#define LCASE_START 0x61
#define LCASE_END   0x7A

int pwdgen(char*);
unsigned int generate_char_pool(char*);

#endif
