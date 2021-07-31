#include <efilibs.h>
#include <elflib.h>
#include <stdlib.h>
#include <fs.h>
#include <ConfigReader/reader.h>
#include <gop.h>
#define HEX      16
#define DECIMAL  10

EFI_STATUS efi_main(EFI_HANDLE IH, EFI_SYSTEM_TABLE *ST)
{
    ImageHandle = IH;
    SystemTable = ST;
	
    

	InitializeSystem();

    SetColor(EFI_WHITE);

    readFile(L"primum.cfg");
    scan(OSBuffer_Handle);
    SetConfiguredMode();

    char * kernel_name;
    SystemTable->BootServices->AllocatePool(EfiLoaderData, 128, (void**)&kernel_name);
    kernel_name = lookup("KERNEL");

    if (kernel_name == NULL){
        Print(L"Could not find kernel name in config file\n\r");
        while(1){__asm__ ("hlt");}
    }

    u16 *kernel_name__;
    SystemTable->BootServices->AllocatePool(EfiLoaderData, 128, (void**)&kernel_name__);
    memset(kernel_name__, 0, 128);

    for (int i=0; i < strlen(kernel_name);i++){
        kernel_name__[i] = kernel_name[i];
    }

    EFI_FILE_PROTOCOL * kernel = getFile(kernel_name__);

    SystemTable->BootServices->FreePool(OSBuffer_Handle);
    SystemTable->BootServices->FreePool(kernel_name__);
    //SystemTable->BootServices->FreePool(kernel_name);

    if (kernel == NULL){
        Print(L"Error: Could not find kernel");
        while(1){__asm__ ("hlt");}
    }
    
    // get the elf header
    Elf64_Ehdr Kernel_elf_header = GetElfHeader(kernel);

    // get the program header from the elf binary

    Elf64_Phdr* Kernel_prog_header;
	{
		kernel->SetPosition(kernel, Kernel_elf_header.e_phoff);
		
        u64 sz = Kernel_elf_header.e_phnum * Kernel_elf_header.e_phentsize;
		
        SystemTable->BootServices->AllocatePool(EfiLoaderData, sz, (void**)&Kernel_prog_header);
		
        kernel->Read(kernel, &sz, Kernel_prog_header);
	}

    for (Elf64_Phdr* prog_header = Kernel_prog_header; 
        (char*)prog_header < (char*)Kernel_prog_header + Kernel_elf_header.e_phnum * Kernel_elf_header.e_phentsize;
        prog_header = (Elf64_Phdr*)((char*)prog_header + Kernel_elf_header.e_phentsize)){


        switch (prog_header->p_type){
			case PT_LOAD:
			{
				int pages = (prog_header->p_memsz + 0x1000 - 1) / 0x1000;

				Elf64_Addr segment = prog_header->p_paddr;

				SystemTable->BootServices->AllocatePages(AllocateAddress, EfiLoaderData, pages, &segment);

				kernel->SetPosition(kernel, prog_header->p_offset);
				u64 size = prog_header->p_filesz;
				kernel->Read(kernel, &size, (void*)segment);
				break;
			}
		}

    }
    
	
	
    u64* kernelFileSize = (u64*)GetFileSize(kernel);


    bi.kernelInfo.kernelFileSize = kernelFileSize;

    
	
    u64                  MemoryMapSize = 0;
    EFI_MEMORY_DESCRIPTOR  *MemoryMap;
    u64                  MapKey;
    u64                  DescriptorSize;
    u32                 DescriptorVersion;
    
    SystemTable->BootServices->GetMemoryMap(&MemoryMapSize, MemoryMap, &MapKey, &DescriptorSize, &DescriptorVersion);
    MemoryMapSize += 2 * DescriptorSize;
    SystemTable->BootServices->AllocatePool(2, MemoryMapSize, (void **)&MemoryMap);
    SystemTable->BootServices->GetMemoryMap(&MemoryMapSize, MemoryMap, &MapKey, &DescriptorSize, &DescriptorVersion);	


	__attribute__((sysv_abi)) void (*KernelEntry)(LETTRE_PROTOCAL*) = ((__attribute__((sysv_abi)) void (*)(LETTRE_PROTOCAL*) ) Kernel_elf_header.e_entry);

    bi.memmap.MMap = MemoryMap;
	bi.memmap.MMapSize = MemoryMapSize;
	bi.memmap.MMapDescriptorSize = DescriptorSize;

    SystemTable->BootServices->ExitBootServices(ImageHandle, MapKey);

    KernelEntry(&bi);
    


    
    while(1){__asm__ ("hlt");}
	
    // We should not make it to this point.
    return EFI_SUCCESS;
}
