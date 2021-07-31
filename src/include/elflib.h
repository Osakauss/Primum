#ifndef EFILIBS_H
#define EFILIBS_H
#include <efi.h>
#include <elf.h>
#include <types.h>

extern Elf64_Ehdr GetElfHeader(EFI_FILE_PROTOCOL *file);

#endif