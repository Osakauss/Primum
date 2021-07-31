#ifndef __EFILIBS_HEADER__
#define __EFILIBS_HEADER__ 
#include <types.h>
#include <efi.h>
#include <lettre/lettre.h>

extern void InitializeSystem();
EFI_FILE_PROTOCOL* getFile(CHAR16* FileName);
extern void SetColor(u64 Attribute);
extern u64* GetFileSize (EFI_FILE_PROTOCOL* FileName);
extern void Print(CHAR16* str);
extern EFI_SYSTEM_TABLE* SystemTable;
extern EFI_HANDLE ImageHandle;
extern LETTRE_PROTOCAL bi;
void itoa_(unsigned long int n, unsigned short int* buffer, int basenumber);
#endif