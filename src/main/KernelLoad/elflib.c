#include <efilibs.h>
#include <efi.h>
#include <elf.h>



Elf64_Ehdr GetElfHeader(EFI_FILE_PROTOCOL *file){

    Elf64_Ehdr elf_header;

    
    file->SetPosition(file, 0);
    
    // read the elf header into the elf_header variable
    u64 size = sizeof(elf_header);
    file->Read(file, &size, &elf_header);
    return (elf_header);

}
