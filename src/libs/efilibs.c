// UEFI From Scratch Tutorials - ThatOSDev ( 2021 )
// https://github.com/ThatOSDev/UEFI-Tuts

#ifndef EFILIBS_H
#define EFILIBS_H

#include <lettre/lettre.h>
#include <types.h>
#include <fs.h>
#include <gop.h>

EFI_HANDLE ImageHandle;

u64* LoaderFileSize;
EFI_SYSTEM_TABLE* SystemTable;


void ResetScreen()
{
    SystemTable->ConOut->Reset(SystemTable->ConOut, 1);
}

void ClearScreen()
{
    SystemTable->ConOut->ClearScreen(SystemTable->ConOut);
}

void SetColor(u64 Attribute)
{
    SystemTable->ConOut->SetAttribute(SystemTable->ConOut, Attribute);
}

void Print(CHAR16* str)
{
    SystemTable->ConOut->OutputString(SystemTable->ConOut, str);
}



LETTRE_PROTOCAL bi;



void InitializeSystem()
{
    ResetScreen();
    InitializeGOP();
	InitializeFILESYSTEM();
}

#endif