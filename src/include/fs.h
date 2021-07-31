#ifndef __FS_HEADER__
#define __FS_HEADER__
#include <types.h>
extern void InitializeFILESYSTEM();
extern void readFile(CHAR16* FileName);
extern void* OSBuffer_Handle;
#endif