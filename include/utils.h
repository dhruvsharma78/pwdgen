#ifndef UTILS_H
#define UTILS_H

// Bit field manipulation
#define SET_BIT(field, bit) field |= (1 << bit)
#define CLEAR_BIT(field, bit) field &= ~(1 << bit)
#define TOGGLE_BIT(field, bit) field ^= (1 << bit)
#define IS_BIT_SET(field, bit) (field & (1 << bit))

#define PROGRAM_NAME "pwdgen"

#endif
