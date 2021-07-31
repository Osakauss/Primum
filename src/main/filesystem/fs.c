#include <efi.h>
#include <efilibs.h>
#include <types.h>
#include <stdlib.h>
void* OSBuffer_Handle;
EFI_FILE_PROTOCOL* RootFS;
EFI_SIMPLE_FILE_SYSTEM_PROTOCOL *Volume;
//static struct EFI_GUID EFI_FILE_INFO_GUID                   = {0x09576e92, 0x6d3f, 0x11d2, {0x8e, 0x39, 0x00, 0xa0, 0xc9, 0x69, 0x72, 0x3b}};
static struct EFI_GUID EFI_SIMPLE_FILE_SYSTEM_PROTOCOL_GUID = {0x964e5b22, 0x6459, 0x11d2, {0x8e, 0x39, 0x00, 0xa0, 0xc9, 0x69, 0x72, 0x3b}};
static struct EFI_GUID EFI_LOADED_IMAGE_PROTOCOL_GUID       = {0x5b1b31a1, 0x9562, 0x11d2, {0x8e, 0x3f, 0x00, 0xa0, 0xc9, 0x69, 0x72, 0x3b}};
static struct EFI_GUID EFI_DEVICE_PATH_PROTOCOL_GUID        = {0x09576e91, 0x6d3f, 0x11d2, {0x8e, 0x39, 0x00, 0xa0, 0xc9, 0x69, 0x72, 0x3b}};


void InitializeFILESYSTEM()
{
    EFI_LOADED_IMAGE_PROTOCOL *LoadedImage;
	EFI_DEVICE_PATH_PROTOCOL *DevicePath;
	
    if((SystemTable->BootServices->HandleProtocol(ImageHandle, &EFI_LOADED_IMAGE_PROTOCOL_GUID, (void**)&LoadedImage)) == EFI_SUCCESS)
	{
		if((SystemTable->BootServices->HandleProtocol(LoadedImage->DeviceHandle, &EFI_DEVICE_PATH_PROTOCOL_GUID, (void**)&DevicePath)) == EFI_SUCCESS)
		{
			if((SystemTable->BootServices->HandleProtocol(LoadedImage->DeviceHandle, &EFI_SIMPLE_FILE_SYSTEM_PROTOCOL_GUID, (void**)&Volume)) == EFI_SUCCESS)
			{
				if((Volume->OpenVolume(Volume, &RootFS)) != EFI_SUCCESS)
				{
					Print(L"Loading Root File System FAILED!");
				}
			} else {
		        Print(L"Volume Handle FAILED!");
	        }
		} else {
		    Print(L"DevicePath FAILED!");
	    }
	} else {
		Print(L"LoadedImage FAILED!");
	}
}

EFI_FILE_PROTOCOL* getFile(CHAR16* FileName)
{
    // This opens a file from the EFI FAT32 file system volume.
    // It loads from root, so you must supply full path if the file is not in the root.
    // Example : "somefolder//myfile"  <--- Notice the double forward slash.
    EFI_FILE_PROTOCOL* FileHandle = NULL;
    if((RootFS->Open(RootFS, &FileHandle, FileName, EFI_FILE_MODE_READ | EFI_FILE_MODE_WRITE, 0)) == EFI_NOT_FOUND)
	{
		SetColor(EFI_CYAN);
		Print(L"\r\nWARNING : Unable to find File.\r\n\r\n");
	}
    
    return FileHandle;
}

EFI_FILE_PROTOCOL* getDir(CHAR16* DirName)
{
    EFI_FILE_PROTOCOL* FileHandle = NULL;
    if((RootFS->Open(RootFS, &FileHandle, DirName, EFI_FILE_MODE_READ | EFI_FILE_MODE_WRITE, EFI_FILE_DIRECTORY)) == EFI_NOT_FOUND)
	{
		SetColor(EFI_CYAN);
		Print(L"\r\nWARNING : Unable to find Directory.\r\n\r\n");
	}
    
    return FileHandle;
}

void closeFile(EFI_FILE_PROTOCOL* FileHandle)
{
    if((FileHandle->Close(FileHandle)) != EFI_SUCCESS)
	{
        SetColor(EFI_BROWN);
        Print(L"Closing File Handle FAILED\r\n");
	}
}

void closeDir(EFI_FILE_PROTOCOL* FileHandle)
{
    if((FileHandle->Close(FileHandle)) != EFI_SUCCESS)
	{
		SetColor(EFI_BROWN);
		Print(L"Closing Directory Handle FAILED\r\n");
	}
}

EFI_FILE_PROTOCOL* createFile(CHAR16* FileName)
{
    EFI_FILE_PROTOCOL* FileHandle = NULL;
    if((RootFS->Open(RootFS, &FileHandle, FileName, EFI_FILE_MODE_CREATE | EFI_FILE_MODE_READ | EFI_FILE_MODE_WRITE, 0)) == EFI_NOT_FOUND)
	{
		SetColor(EFI_CYAN);
		Print(L"\r\nWARNING : Unable to create file. Please check your path.\r\n\r\n");
	}
    
    return FileHandle;
}

u64* GetFileSize (EFI_FILE_PROTOCOL* FileName)
{
    u64* Size = 0;
    FileName->SetPosition(FileName, 0xFFFFFFFFFFFFFFFFULL);
    FileName->GetPosition(FileName, Size);
	FileName->SetPosition(FileName, 0);
    return Size;
}


void removeDir(CHAR16* dirName)
{
	EFI_FILE_PROTOCOL* FileHandle = getDir(dirName);
	if(FileHandle != NULL)
	{
		if((FileHandle->Delete(FileHandle)) != EFI_SUCCESS)
		{
			SetColor(EFI_BROWN);
		    Print(L"Deleting Directory FAILED\r\n");
		}
	}
}

void makeDir(CHAR16* dirName)
{
    EFI_FILE_PROTOCOL* FileHandle = NULL;
	
    if((RootFS->Open(RootFS, &FileHandle, dirName, EFI_FILE_MODE_CREATE | EFI_FILE_MODE_READ | EFI_FILE_MODE_WRITE, EFI_FILE_DIRECTORY)) != EFI_SUCCESS)
	{
		SetColor(EFI_BROWN);
		Print(L"Creating Directory FAILED\r\n");
	}
	closeDir(FileHandle);
}

void deleteFile(CHAR16* FileName)
{
	EFI_FILE_PROTOCOL* FileHandle = getFile(FileName);
	if(FileHandle != NULL)
	{
		if((FileHandle->Delete(FileHandle)) != EFI_SUCCESS)
		SetColor(EFI_BROWN);
		Print(L"Deleting File FAILED\r\n");
	}
}

void WriteToFile(char* buf, CHAR16* FileName)
{
	u64 fileSize = strlen(buf);
	EFI_FILE_PROTOCOL* writefilehandle = createFile(FileName);
	if(writefilehandle != NULL)
	{
		if((writefilehandle->Write(writefilehandle, &fileSize, buf)) != EFI_SUCCESS)
		{
			SetColor(EFI_BROWN);
			Print(L"Writing to File FAILED\r\n");
		}
		closeFile(writefilehandle);
	}
}


void readFile(CHAR16* FileName)
{
	// We get the file size, allocate memory for it,
    // read the file into the buffer, then we close the file.
    EFI_FILE_PROTOCOL* FileHandle = getFile(FileName);
    if(FileHandle != NULL)
    {
		
		u64* FileSize = (u64*)GetFileSize(FileHandle);
		if((SystemTable->BootServices->AllocatePool(EfiLoaderData, *FileSize+100, (void**)&OSBuffer_Handle)) != EFI_SUCCESS)
		{
			SetColor(EFI_BROWN);
			Print(L"Allocating Pool FAILED\r\n");
		}
		memset(OSBuffer_Handle, 0, *FileSize+100);
		FileHandle->SetPosition(FileHandle, 0);
		
        if((FileHandle->Read(FileHandle, FileSize, OSBuffer_Handle)) != EFI_SUCCESS)
		{
			SetColor(EFI_BROWN);
			Print(L"Reading File FAILED\r\n");
		}
		
        closeFile(FileHandle);
    }
}
