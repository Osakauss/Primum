#ifndef __STDLIB_HEADER__
#define __STDLIB_HEADER__
#include <types.h>
#include <stdarg.h>
extern char *itoa(int value, char *str, int base);
extern u32 digit_count(int num);
extern usize strlen(const char* str);
extern int strcmp(const char *X, const char *Y);
extern int   memcmp(const void*, const void*, usize);
extern void *memcpy(void* __restrict, const void* __restrict, usize);
extern void *memmove(void*, const void*, usize);
extern void *memset(void*, u8, u64);
extern int atio(char* str);

#endif