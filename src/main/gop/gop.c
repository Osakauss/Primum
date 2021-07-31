#include <types.h>
#include <efilibs.h>
#include <stdlib.h>
#include <ConfigReader/reader.h>

EFI_GRAPHICS_OUTPUT_PROTOCOL* gop;
static struct EFI_GUID EFI_GRAPHICS_OUTPUT_PROTOCOL_GUID    = {0x9042a9de, 0x23dc, 0x4a38, {0x96, 0xfb, 0x7a, 0xde, 0xd0, 0x80, 0x51, 0x6a}};

void InitializeGOP()
{
    SystemTable->BootServices->LocateProtocol(&EFI_GRAPHICS_OUTPUT_PROTOCOL_GUID, 0, (void**)&gop);
    bi.framebuffer.BaseAddress        = (void*)gop->Mode->FrameBufferBase;
    bi.framebuffer.BufferSize         = gop->Mode->FrameBufferSize;
    bi.framebuffer.ScreenWidth        = gop->Mode->Info->HorizontalResolution;
    bi.framebuffer.ScreenHeight       = gop->Mode->Info->VerticalResolution;
    bi.framebuffer.PixelsPerScanLine  = gop->Mode->Info->PixelsPerScanLine;
}

void SetConfiguredMode(){
	int width_ = 0;
	int height_ = 0;
	char* width = lookup("WIDTH");
	char* height = lookup("HEIGHT");

	if (width == NULL){
		Print(L"Warning: Could not find the width in config file\n\r");
	}
	else{
		width_ = atio(width);
	}
	if (height == NULL){
		Print(L"Warning: Could not find the height in config file\n\r");
	}
	else{
		height_ = atio(height);
	}
	if (height_ != 0 && width_ != 0){
		int modeMax = gop->Mode->MaxMode;
		EFI_GRAPHICS_OUTPUT_MODE_INFORMATION modeInfo_;
		EFI_GRAPHICS_OUTPUT_MODE_INFORMATION *modeinfo = &modeInfo_;
		u64 modeSize;
		u64 good_mode = 0;
		BOOLEAN found_good_mode; 
		for (int x = 0; x < modeMax; x++){
			gop->QueryMode(gop, x, &modeSize, &modeinfo);
			if (modeinfo->HorizontalResolution >= height_ && modeinfo->VerticalResolution >= width_){
				found_good_mode = 1;
				break;
			}
			good_mode++;
		}
		SetColor(EFI_YELLOW);
		if (found_good_mode == 0){
			Print(L"Warning: can't find the resolution close to what you want. Just using default\n\r");	
		}
		else{
			gop->SetMode(gop, good_mode);
		}
	}
	bi.framebuffer.BaseAddress        = (void*)gop->Mode->FrameBufferBase;
    bi.framebuffer.BufferSize         = gop->Mode->FrameBufferSize;
    bi.framebuffer.ScreenWidth        = gop->Mode->Info->HorizontalResolution;
    bi.framebuffer.ScreenHeight       = gop->Mode->Info->VerticalResolution;
    bi.framebuffer.PixelsPerScanLine  = gop->Mode->Info->PixelsPerScanLine;
}