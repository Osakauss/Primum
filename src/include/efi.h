#ifndef EFI_H
#define EFI_H

#include <types.h>

#define UNICODE

#define EFI_BLACK                               0x00
#define EFI_BLUE                                0x01
#define EFI_GREEN                               0x02
#define EFI_CYAN                                0x03
#define EFI_RED                                 0x04
#define EFI_MAGENTA                             0x05
#define EFI_BROWN                               0x06
#define EFI_LIGHTGRAY                           0x07
#define EFI_DARKGRAY                            0x08
#define EFI_LIGHTBLUE                           0x09
#define EFI_LIGHTGREEN                          0x0A
#define EFI_LIGHTCYAN                           0x0B
#define EFI_LIGHTRED                            0x0C
#define EFI_LIGHTMAGENTA                        0x0D
#define EFI_YELLOW                              0x0E
#define EFI_WHITE                               0x0F
                                               
#define EFI_BACKGROUND_BLACK                    0x00
#define EFI_BACKGROUND_BLUE                     0x10
#define EFI_BACKGROUND_GREEN                    0x20
#define EFI_BACKGROUND_CYAN                     0x30
#define EFI_BACKGROUND_RED                      0x40
#define EFI_BACKGROUND_MAGENTA                  0x50
#define EFI_BACKGROUND_BROWN                    0x60
#define EFI_BACKGROUND_LIGHTGRAY                0x70

#define EFI_FILE_MODE_READ      0x0000000000000001
#define EFI_FILE_MODE_WRITE     0x0000000000000002
#define EFI_FILE_MODE_CREATE    0x8000000000000000

#define EFI_FILE_READ_ONLY      0x0000000000000001
#define EFI_FILE_HIDDEN         0x0000000000000002
#define EFI_FILE_SYSTEM         0x0000000000000004
#define EFI_FILE_RESERVED       0x0000000000000008
#define EFI_FILE_DIRECTORY      0x0000000000000010
#define EFI_FILE_ARCHIVE        0x0000000000000020
#define EFI_FILE_VALID_ATTR     0x0000000000000037

#define EFI_SUCCESS               0x0000000000000000
#define EFI_ERROR                 0x8000000000000000 
#define EFI_LOAD_ERROR            (EFI_ERROR | 0x0000000000000001)
#define EFI_INVALID_PARAMETER     (EFI_ERROR | 0x0000000000000002)
#define EFI_UNSUPPORTED           (EFI_ERROR | 0x0000000000000003)
#define EFI_BAD_BUFFER_SIZE       (EFI_ERROR | 0x0000000000000004)
#define EFI_BUFFER_TOO_SMALL      (EFI_ERROR | 0x0000000000000005)
#define EFI_NOT_READY             (EFI_ERROR | 0x0000000000000006)
#define EFI_DEVICE_ERROR          (EFI_ERROR | 0x0000000000000007)
#define EFI_WRITE_PROTECTED       (EFI_ERROR | 0x0000000000000008)
#define EFI_OUT_OF_RESOURCES      (EFI_ERROR | 0x0000000000000009)
#define EFI_VOLUME_CORRUPTED      (EFI_ERROR | 0x000000000000000A)
#define EFI_VOLUME_FULL           (EFI_ERROR | 0x000000000000000B)
#define EFI_NO_MEDIA              (EFI_ERROR | 0x000000000000000C)
#define EFI_MEDIA_CHANGED         (EFI_ERROR | 0x000000000000000D)
#define EFI_NOT_FOUND             (EFI_ERROR | 0x000000000000000E)
#define EFI_ACCESS_DENIED         (EFI_ERROR | 0x000000000000000F)
#define EFI_NO_RESPONSE           (EFI_ERROR | 0x0000000000000010)
#define EFI_NO_MAPPING            (EFI_ERROR | 0x0000000000000011)
#define EFI_TIMEOUT               (EFI_ERROR | 0x0000000000000012)
#define EFI_NOT_STARTED           (EFI_ERROR | 0x0000000000000013)
#define EFI_ALREADY_STARTED       (EFI_ERROR | 0x0000000000000014)
#define EFI_ABORTED               (EFI_ERROR | 0x0000000000000015)
#define EFI_ICMP_ERROR            (EFI_ERROR | 0x0000000000000016)
#define EFI_TFTP_ERROR            (EFI_ERROR | 0x0000000000000017)
#define EFI_PROTOCOL_ERROR        (EFI_ERROR | 0x0000000000000018)
#define EFI_INCOMPATIBLE_VERSION  (EFI_ERROR | 0x0000000000000019)
#define EFI_SECURITY_VIOLATION    (EFI_ERROR | 0x000000000000001A)
#define EFI_CRC_ERROR             (EFI_ERROR | 0x000000000000001B)
#define EFI_END_OF_MEDIA          (EFI_ERROR | 0x000000000000001C)
#define EFI_END_OF_FILE           (EFI_ERROR | 0x000000000000001D)
#define EFI_INVALID_LANGUAGE      (EFI_ERROR | 0x000000000000001E)
#define EFI_COMPROMISED_DATA      (EFI_ERROR | 0x000000000000001F)
#define EFI_IP_ADDRESS_CONFLICT   (EFI_ERROR | 0x0000000000000020)
#define EFI_HTTP_ERROR            (EFI_ERROR | 0x0000000000000021)

#define EFI_WARN_UNKNOWN_GLYPH     0x0000000000000001
#define EFI_WARN_DELETE_FAILURE    0x0000000000000002
#define EFI_WARN_WRITE_FAILURE     0x0000000000000003
#define EFI_WARN_BUFFER_TOO_SMALL  0x0000000000000004
#define EFI_WARN_STALE_DATA        0x0000000000000005
#define EFI_WARN_FILE_SYSTEM       0x0000000000000006
#define EFI_WARN_RESET_REQUIRED    0x0000000000000007

typedef unsigned short int  u16_t;
typedef unsigned short int  uint_least16_t;
typedef uint_least16_t          CHAR16;



typedef unsigned char       BOOLEAN;

typedef u64               EFI_TPL;
typedef void                *EFI_HANDLE;
typedef u64              EFI_STATUS;
typedef void                *EFI_EVENT;
typedef u64              EFI_PHYSICAL_ADDRESS;
typedef u64              EFI_VIRTUAL_ADDRESS;


typedef struct EFI_GUID
{
    u32    Data1;
    u16    Data2;
    u16    Data3;
    u8     Data4[8];
} EFI_GUID;

struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL;
struct EFI_SIMPLE_TEXT_INPUT_PROTOCOL;
struct EFI_BOOT_SERVICES;
struct EFI_GRAPHICS_OUTPUT_PROTOCOL;
struct EFI_SIMPLE_FILE_SYSTEM_PROTOCOL;
struct EFI_FILE_PROTOCOL;

typedef enum EFI_MEMORY_TYPE
{
    EfiReservedMemoryType,
    EfiLoaderCode,
    EfiLoaderData,
    EfiBootServicesCode,
    EfiBootServicesData,
    EfiRuntimeServicesCode,
    EfiRuntimeServicesData,
    EfiConventionalMemory,
    EfiUnusableMemory,
    EfiACPIReclaimMemory,
    EfiACPIMemoryNVS,
    EfiMemoryMappedIO,
    EfiMemoryMappedIOPortSpace,
    EfiPalCode,
    EfiPersistentMemory,
    EfiUnacceptedMemoryType,
    EfiMaxMemoryType
} EFI_MEMORY_TYPE;

typedef struct EFI_TIME
{
	u16     Year;
	u8      Month;
	u8      Day;
	u8      Hour;
	u8      Minute;
	u8      Second;
	u8      Pad1;
	u32     Nanosecond;
	u16     TimeZone;
	u8      DayLight;
	u8      Pad2;
} EFI_TIME;


typedef struct EFI_TIME_CAPABILITIES
{
	u32      Resolution;
	u32      Accuracy;
	BOOLEAN     SetsToZero;
} EFI_TIME_CAPABILITIES;


typedef enum EFI_RESET_TYPE
{
    EfiResetCold,
    EfiResetWarm,
    EfiResetShutdown,
    EfiResetPlatformSpecific
} EFI_RESET_TYPE;

typedef struct EFI_CONFIGURATION_TABLE
{
    EFI_GUID                    VendorGuid;
    void                        *VendorTable;
} EFI_CONFIGURATION_TABLE;

typedef struct EFI_TABLE_HEADER
{
    u64    Signature;
    u32    Revision;
    u32    HeaderSize;
    u32    CRC32;
    u32    Reserved;
} EFI_TABLE_HEADER;

typedef enum EFI_ALLOCATE_TYPE
{
    AllocateAnyPages,
    AllocateMaxAddress,
    AllocateAddress,
    MaxAllocateType
} EFI_ALLOCATE_TYPE;

typedef enum EFI_TIMER_DELAY
{
    TimerCancel,
    TimerPeriodic,
    TimerRelative
} EFI_TIMER_DELAY;

typedef struct EFI_MEMORY_DESCRIPTOR
{
    u32                   Type;
    EFI_PHYSICAL_ADDRESS     PhysicalStart;
    EFI_VIRTUAL_ADDRESS      VirtualStart;
    u64                   NumberOfPages;
    u64                   Attribute;
} EFI_MEMORY_DESCRIPTOR;

typedef enum EFI_INTERFACE_TYPE
{
    EFI_NATIVE_INTERFACE
} EFI_INTERFACE_TYPE;

typedef enum EFI_LOCATE_SEARCH_TYPE
{
    AllHandles,
    ByRegisterNotify,
    ByProtocol
} EFI_LOCATE_SEARCH_TYPE;

typedef struct EFI_OPEN_PROTOCOL_INFORMATION_ENTRY
{
    EFI_HANDLE                  AgentHandle;
    EFI_HANDLE                  ControllerHandle;
    u32                      Attributes;
    u32                      OpenCount;
} EFI_OPEN_PROTOCOL_INFORMATION_ENTRY;

typedef struct EFI_DEVICE_PATH_PROTOCOL
{
    u8   Type;
    u8   SubType;
    u8   Length[2];
} EFI_DEVICE_PATH_PROTOCOL;

typedef struct EFI_CAPSULE_HEADER
{
    EFI_GUID                    CapsuleGuid;
    u32                      HeaderSize;
    u32                      Flags;
    u32                      CapsuleImageSize;
} EFI_CAPSULE_HEADER;


typedef struct EFI_INPUT_KEY
{
	u16    ScanCode;
	u16    UnicodeChar;
}EFI_INPUT_KEY;

typedef void(*EFI_EVENT_NOTIFY)(EFI_EVENT Event, void *Context);

typedef EFI_STATUS (*EFI_INPUT_RESET)(struct EFI_SIMPLE_TEXT_INPUT_PROTOCOL *This, BOOLEAN ExtendedVerification);


typedef EFI_STATUS (*EFI_INPUT_READ_KEY)(struct EFI_SIMPLE_TEXT_INPUT_PROTOCOL *This, EFI_INPUT_KEY *Key);

typedef struct EFI_SIMPLE_TEXT_INPUT_PROTOCOL
{
	EFI_INPUT_RESET        Reset;
	EFI_INPUT_READ_KEY     ReadKeyStroke;
	EFI_EVENT              WaitForKey;
} EFI_SIMPLE_TEXT_INPUT_PROTOCOL;

typedef struct SIMPLE_TEXT_OUTPUT_MODE
{
    i32                       MaxMode;
    i32                       Mode;
    i32                       Attribute;
    i32                       CursorColumn;
    i32                       CursorRow;
    BOOLEAN                     CursorVisible;
} SIMPLE_TEXT_OUTPUT_MODE;


typedef EFI_STATUS (*EFI_TEXT_RESET)(struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This, BOOLEAN ExtendedVerification);


typedef EFI_STATUS (*EFI_TEXT_STRING)(struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This, CHAR16 *String);

typedef EFI_STATUS (*EFI_TEXT_TEST_STRING)(struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This, CHAR16 *String);
typedef EFI_STATUS (*EFI_TEXT_QUERY_MODE)(struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This, u64 ModeNumber, u64 *Columns, u64 *Rows);
typedef EFI_STATUS (*EFI_TEXT_SET_MODE)(struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This, u64 ModeNumber);

typedef EFI_STATUS (*EFI_TEXT_SET_ATTRIBUTE)(struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This, u64 Attribute);

typedef EFI_STATUS (*EFI_TEXT_CLEAR_SCREEN)(struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This);

typedef EFI_STATUS (*EFI_TEXT_SET_CURSOR_POSITION)(struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This, u64 Column, u64 Row);

typedef EFI_STATUS (*EFI_TEXT_ENABLE_CURSOR)(struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This, BOOLEAN Visible);

typedef struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL
{
    EFI_TEXT_RESET                         Reset;
    EFI_TEXT_STRING                        OutputString;
    EFI_TEXT_TEST_STRING                   TestString;
    EFI_TEXT_QUERY_MODE                    QueryMode;
    EFI_TEXT_SET_MODE                      SetMode;
    EFI_TEXT_SET_ATTRIBUTE                 SetAttribute;
    EFI_TEXT_CLEAR_SCREEN                  ClearScreen;
    EFI_TEXT_SET_CURSOR_POSITION           SetCursorPosition;
    EFI_TEXT_ENABLE_CURSOR                 EnableCursor;
    SIMPLE_TEXT_OUTPUT_MODE                *Mode;
} EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL;

typedef EFI_STATUS (*EFI_RAISE_TPL)(EFI_TPL NewTpl);
typedef EFI_STATUS (*EFI_RESTORE_TPL)(EFI_TPL OldTpl);
typedef EFI_STATUS (*EFI_ALLOCATE_PAGES)(EFI_ALLOCATE_TYPE Type, u64 MemoryType, u64 Pages, EFI_PHYSICAL_ADDRESS *Memory);
typedef EFI_STATUS (*EFI_FREE_PAGES)(EFI_PHYSICAL_ADDRESS Memory, u64 Pages);
typedef EFI_STATUS (*EFI_GET_MEMORY_MAP)(u64 *MemoryMapSize, EFI_MEMORY_DESCRIPTOR *MemoryMap, u64 *MapKey, u64 *DescriptorSize, u32 *DescriptorVersion);
typedef EFI_STATUS (*EFI_ALLOCATE_POOL)(u64 PoolType, u64 Size, void **Buffer);
typedef EFI_STATUS (*EFI_FREE_POOL)(void *Buffer);
typedef EFI_STATUS (*EFI_CREATE_EVENT)(u32 Type, EFI_TPL NotifyTpl, EFI_EVENT_NOTIFY NotifyFunction, void *NotifyContext, EFI_GUID *EventGroup, EFI_EVENT *Event);
typedef EFI_STATUS (*EFI_SET_TIMER)(EFI_EVENT Event, EFI_TIMER_DELAY Type, u64 TriggerTime);
typedef EFI_STATUS (*EFI_WAIT_FOR_EVENT)(u64 NumberOfEvents, EFI_EVENT *Event, u64 *Index);
typedef EFI_STATUS (*EFI_SIGNAL_EVENT)(EFI_EVENT Event);
typedef EFI_STATUS (*EFI_CLOSE_EVENT)(EFI_EVENT Event);
typedef EFI_STATUS (*EFI_CHECK_EVENT)(EFI_EVENT Event);
typedef EFI_STATUS (*EFI_INSTALL_PROTOCOL_INTERFACE)(EFI_HANDLE *Handle, EFI_GUID *Protocol, EFI_INTERFACE_TYPE InterfaceType, void *Interface);
typedef EFI_STATUS (*EFI_REINSTALL_PROTOCOL_INTERFACE)(EFI_HANDLE Handle, EFI_GUID *Protocol, void *OldInterface, void *NewInterface);
typedef EFI_STATUS (*EFI_UNINSTALL_PROTOCOL_INTERFACE)(EFI_HANDLE Handle, EFI_GUID *Protocol, void *Interface);
typedef EFI_STATUS (*EFI_HANDLE_PROTOCOL)(EFI_HANDLE Handle, EFI_GUID *Protocol, void **Interface);
typedef EFI_STATUS (*EFI_REGISTER_PROTOCOL_NOTIFY)(EFI_GUID *Protocol, EFI_EVENT Event, void **Registration);
typedef EFI_STATUS (*EFI_LOCATE_HANDLE)(EFI_LOCATE_SEARCH_TYPE SearchType, EFI_GUID *Protocol, void *SearchKey, u64 *BufferSize, EFI_HANDLE *Buffer);
typedef EFI_STATUS (*EFI_LOCATE_DEVICE_PATH)(EFI_GUID *Protocol, EFI_DEVICE_PATH_PROTOCOL **DevicePath, EFI_HANDLE *Device);
typedef EFI_STATUS (*EFI_INSTALL_CONFIGURATION_TABLE)(EFI_GUID *Guid, void *Table);
typedef EFI_STATUS (*EFI_IMAGE_LOAD)(BOOLEAN BootPolicy, EFI_HANDLE ParentImageHandle, EFI_DEVICE_PATH_PROTOCOL *DevicePath, void *SourceBuffer, u64 SourceSize, EFI_HANDLE *ImageHandle);
typedef EFI_STATUS (*EFI_IMAGE_START)(EFI_HANDLE ImageHandle, u64 *ExitDataSize, CHAR16 **ExitData);
typedef EFI_STATUS (*EFI_EXIT)(EFI_HANDLE ImageHandle, EFI_STATUS ExitStatus, u64 ExitDataSize, CHAR16 *ExitData);
typedef EFI_STATUS (*EFI_IMAGE_UNLOAD)(EFI_HANDLE ImageHandle);
typedef EFI_STATUS (*EFI_EXIT_BOOT_SERVICES)(EFI_HANDLE ImageHandle, u64 MapKey);
typedef EFI_STATUS (*EFI_GET_NEXT_MONOTONIC_COUNT)(u64 *Count);
typedef EFI_STATUS (*EFI_STALL)(u64 Microseconds);
typedef EFI_STATUS (*EFI_SET_WATCHDOG_TIMER)(u64 Timeout, u64 WatchdogCode, u64 DataSize, CHAR16 *WatchdogData);
typedef EFI_STATUS (*EFI_CONNECT_CONTROLLER)(EFI_HANDLE ControllerHandle, EFI_HANDLE *DriverImageHandle, EFI_DEVICE_PATH_PROTOCOL *RemainingDevicePath, BOOLEAN Recursive);
typedef EFI_STATUS (*EFI_DISCONNECT_CONTROLLER)(EFI_HANDLE ControllerHandle, EFI_HANDLE DriverImageHandle, EFI_HANDLE ChildHandle);
typedef EFI_STATUS (*EFI_OPEN_PROTOCOL)(EFI_HANDLE Handle, EFI_GUID *Protocol, void **Interface, EFI_HANDLE AgentHandle, EFI_HANDLE ControllerHandle, u32 Attributes);
typedef EFI_STATUS (*EFI_CLOSE_PROTOCOL)(EFI_HANDLE Handle, EFI_GUID *Protocol, EFI_HANDLE AgentHandle, EFI_HANDLE ControllerHandle);
typedef EFI_STATUS (*EFI_OPEN_PROTOCOL_INFORMATION)(EFI_HANDLE Handle, EFI_GUID *Protocol, EFI_OPEN_PROTOCOL_INFORMATION_ENTRY **EntryBuffer, u64 *EntryCount);
typedef EFI_STATUS (*EFI_PROTOCOLS_PER_HANDLE)(EFI_HANDLE Handle, EFI_GUID ***ProtocolBuffer, u64 *ProtocolBufferCount);
typedef EFI_STATUS (*EFI_LOCATE_HANDLE_BUFFER)(EFI_LOCATE_SEARCH_TYPE SearchType, EFI_GUID *Protocol, void *SearchKey, u64 *NoHandles, EFI_HANDLE **Buffer);
typedef EFI_STATUS (*EFI_LOCATE_PROTOCOL)(EFI_GUID *Protocol, void *Registration, void **Interface);
typedef EFI_STATUS (*EFI_INSTALL_MULTIPLE_PROTOCOL_INTERFACES)(EFI_HANDLE *Handle, ...);
typedef EFI_STATUS (*EFI_UNINSTALL_MULTIPLE_PROTOCOL_INTERFACES)(EFI_HANDLE *Handle, ...);
typedef EFI_STATUS (*EFI_CALCULATE_CRC32)(void *Data, u64 DataSize, u32 *Crc32);
typedef EFI_STATUS (*EFI_COPY_MEM)(void *Destination, void *Source, u64 Length);
typedef EFI_STATUS (*EFI_SET_MEM)(void *Buffer, u64 Size, u8 Value);
typedef EFI_STATUS (*EFI_CREATE_EVENT_EX)(u32 Type, EFI_TPL NotifyTpl, EFI_EVENT_NOTIFY NotifyFunction, void *NotifyContext, EFI_GUID *EventGroup, EFI_EVENT *Event);

typedef struct EFI_BOOT_SERVICES
{
    EFI_TABLE_HEADER                                 Hdr;
    EFI_RAISE_TPL                                    RaiseTPL;
    EFI_RESTORE_TPL                                  RestoreTPL;
    EFI_ALLOCATE_PAGES                               AllocatePages;
    EFI_FREE_PAGES                                   FreePages;
    EFI_GET_MEMORY_MAP                               GetMemoryMap;
    EFI_ALLOCATE_POOL                                AllocatePool;
    EFI_FREE_POOL                                    FreePool;
    EFI_CREATE_EVENT                                 CreateEvent;
    EFI_SET_TIMER                                    SetTimer;
    EFI_WAIT_FOR_EVENT                               WaitForEvent;
    EFI_SIGNAL_EVENT                                 SignalEvent;
    EFI_CLOSE_EVENT                                  CloseEvent;
    EFI_CHECK_EVENT                                  CheckEvent;
    EFI_INSTALL_PROTOCOL_INTERFACE                   InstallProtocolInterface;
    EFI_REINSTALL_PROTOCOL_INTERFACE                 ReinstallProtocolInterface;
    EFI_UNINSTALL_PROTOCOL_INTERFACE                 UninstallProtocolInterface;
    EFI_HANDLE_PROTOCOL                              HandleProtocol;
    void                                             *Reserved;
    EFI_REGISTER_PROTOCOL_NOTIFY                     RegisterProtocolNotify;
    EFI_LOCATE_HANDLE                                LocateHandle;
    EFI_LOCATE_DEVICE_PATH                           LocateDevicePath;
    EFI_INSTALL_CONFIGURATION_TABLE                  InstallConfigurationTable;
    EFI_IMAGE_LOAD                                   LoadImage;
    EFI_IMAGE_START                                  StartImage;
    EFI_EXIT                                         Exit;
    EFI_IMAGE_UNLOAD                                 UnloadImage;
    EFI_EXIT_BOOT_SERVICES                           ExitBootServices;
    EFI_GET_NEXT_MONOTONIC_COUNT                     GetNextMonotonicCount;
    EFI_STALL                                        Stall;
    EFI_SET_WATCHDOG_TIMER                           SetWatchdogTimer;
    EFI_CONNECT_CONTROLLER                           ConnectController;
    EFI_DISCONNECT_CONTROLLER                        DisconnectController;
    EFI_OPEN_PROTOCOL                                OpenProtocol;
    EFI_CLOSE_PROTOCOL                               CloseProtocol;
    EFI_OPEN_PROTOCOL_INFORMATION                    OpenProtocolInformation;
    EFI_PROTOCOLS_PER_HANDLE                         ProtocolsPerHandle;
    EFI_LOCATE_HANDLE_BUFFER                         LocateHandleBuffer;
    EFI_LOCATE_PROTOCOL                              LocateProtocol;
    EFI_INSTALL_MULTIPLE_PROTOCOL_INTERFACES         InstallMultipleProtocolInterfaces;
    EFI_UNINSTALL_MULTIPLE_PROTOCOL_INTERFACES       UninstallMultipleProtocolInterfaces;
    EFI_CALCULATE_CRC32                              CalculateCrc32;
    EFI_COPY_MEM                                     CopyMem;
    EFI_SET_MEM                                      SetMem;
    EFI_CREATE_EVENT_EX                              CreateEventEx;
} EFI_BOOT_SERVICES;

typedef EFI_STATUS (*EFI_GET_TIME)(EFI_TIME *Time, EFI_TIME_CAPABILITIES *Capabilities);
typedef EFI_STATUS (*EFI_SET_TIME)(EFI_TIME *Time);
typedef EFI_STATUS (*EFI_GET_WAKEUP_TIME)(BOOLEAN *Enabled, BOOLEAN *Pending, EFI_TIME *Time);
typedef EFI_STATUS (*EFI_SET_WAKEUP_TIME)(BOOLEAN Enable, EFI_TIME *Time);
typedef EFI_STATUS (*EFI_SET_VIRTUAL_ADDRESS_MAP)(u64 MemoryMapSize, u64 DescriptorSize, u32 DescriptorVersion, EFI_MEMORY_DESCRIPTOR *VirtualMap);
typedef EFI_STATUS (*EFI_CONVERT_POINTER)(u64 DebugDisposition, void **Address);
typedef EFI_STATUS (*EFI_GET_VARIABLE)(CHAR16 *VariableName, EFI_GUID *VendorGuid, u32 *Attributes, u64 *DataSize, void *Data);
typedef EFI_STATUS (*EFI_GET_NEXT_VARIABLE_NAME)(u64 *VariableNameSize, CHAR16 *VariableName, EFI_GUID *VendorGuid);
typedef EFI_STATUS (*EFI_SET_VARIABLE)(CHAR16 *VariableName, EFI_GUID *VendorGuid, u32 Attributes, u64 DataSize, void *Data);
typedef EFI_STATUS (*EFI_GET_NEXT_HIGH_MONO_COUNT)(u32 *HighCount);
typedef EFI_STATUS (*EFI_RESET_SYSTEM)(EFI_RESET_TYPE ResetType, EFI_STATUS ResetStatus, u64 DataSize, void *ResetData);
typedef EFI_STATUS (*EFI_UPDATE_CAPSULE)(EFI_CAPSULE_HEADER **CapsuleHeaderArray, u64 CapsuleCount, EFI_PHYSICAL_ADDRESS ScatterGatherList);
typedef EFI_STATUS (*EFI_QUERY_CAPSULE_CAPABILITIES)(EFI_CAPSULE_HEADER **CapsuleHeaderArray, u64 CapsuleCount, u64 *MaximumCapsuleSize, EFI_RESET_TYPE *ResetType);
typedef EFI_STATUS (*EFI_QUERY_VARIABLE_INFO)(u32 Attributes, u64 *MaximumVariableStorageSize, u64 *RemainingVariableStorageSize, u64 *MaximumVariableSize);

typedef struct EFI_RUNTIME_SERVICES
{
    EFI_TABLE_HEADER                    Hdr;
    EFI_GET_TIME                        GetTime;
    EFI_SET_TIME                        SetTime;
    EFI_GET_WAKEUP_TIME                 GetWakeupTime;
    EFI_SET_WAKEUP_TIME                 SetWakeupTime;
    EFI_SET_VIRTUAL_ADDRESS_MAP         SetVirtualAddressMap;
    EFI_CONVERT_POINTER                 ConvertPointer;
    EFI_GET_VARIABLE                    GetVariable;
    EFI_GET_NEXT_VARIABLE_NAME          GetNextVariableName;
    EFI_SET_VARIABLE                    SetVariable;
    EFI_GET_NEXT_HIGH_MONO_COUNT        GetNextHighMonotonicCount;
    EFI_RESET_SYSTEM                    ResetSystem;
    EFI_UPDATE_CAPSULE                  UpdateCapsule;
    EFI_QUERY_CAPSULE_CAPABILITIES      QueryCapsuleCapabilities;
    EFI_QUERY_VARIABLE_INFO             QueryVariableInfo;
} EFI_RUNTIME_SERVICES;

typedef struct EFI_FILE_IO_TOKEN
{
    EFI_EVENT   Event;
    EFI_STATUS  Status;
    u64       BufferSize;
    void        *Buffer;
} EFI_FILE_IO_TOKEN;

typedef struct EFI_FILE_INFO {
    u64      Size;
    u64      FileSize;
    u64      PhysicalSize;
    EFI_TIME    CreateTime;
    EFI_TIME    LastAccessTime;
    EFI_TIME    ModificationTime;
    u64      Attribute;
    CHAR16      FileName[];
} EFI_FILE_INFO;

typedef EFI_STATUS (*EFI_FILE_OPEN)(struct EFI_FILE_PROTOCOL *This, struct EFI_FILE_PROTOCOL **NewHandle, CHAR16 *FileName, u64 OpenMode, u64 Attributes);
typedef EFI_STATUS (*EFI_FILE_CLOSE)(struct EFI_FILE_PROTOCOL *This);
typedef EFI_STATUS (*EFI_FILE_DELETE)(struct EFI_FILE_PROTOCOL *This);
typedef EFI_STATUS (*EFI_FILE_READ)(struct EFI_FILE_PROTOCOL *This, u64 *BufferSize, void *Buffer);
typedef EFI_STATUS (*EFI_FILE_WRITE)(struct EFI_FILE_PROTOCOL *This, u64 *BufferSize, void *Buffer);
typedef EFI_STATUS (*EFI_FILE_GET_POSITION)(struct EFI_FILE_PROTOCOL *This, u64 *Position);
typedef EFI_STATUS (*EFI_FILE_SET_POSITION)(struct EFI_FILE_PROTOCOL *This, u64 Position);
typedef EFI_STATUS (*EFI_FILE_GET_INFO)(struct EFI_FILE_PROTOCOL *This, void* InformationType, u64* BufferSize, void* Buffer);
typedef EFI_STATUS (*EFI_FILE_SET_INFO)(struct EFI_FILE_PROTOCOL *This, EFI_GUID *InformationType, u64 BufferSize, void *Buffer);
typedef EFI_STATUS (*EFI_FILE_FLUSH)(struct EFI_FILE_PROTOCOL *This);
typedef EFI_STATUS (*EFI_FILE_OPEN_EX)(struct EFI_FILE_PROTOCOL *This, struct EFI_FILE_PROTOCOL **NewHandle, CHAR16 *FileName, u64 OpenMode, u64 Attributes, EFI_FILE_IO_TOKEN *Token);
typedef EFI_STATUS (*EFI_FILE_READ_EX)(struct EFI_FILE_PROTOCOL *This, EFI_FILE_IO_TOKEN *Token);
typedef EFI_STATUS (*EFI_FILE_WRITE_EX)(struct EFI_FILE_PROTOCOL *This, EFI_FILE_IO_TOKEN *Token);
typedef EFI_STATUS (*EFI_FILE_FLUSH_EX)(struct EFI_FILE_PROTOCOL *This, EFI_FILE_IO_TOKEN *Token);

typedef struct EFI_FILE_PROTOCOL
{
    u64                  Revision;
    EFI_FILE_OPEN           Open;
    EFI_FILE_CLOSE          Close;
    EFI_FILE_DELETE         Delete;
    EFI_FILE_READ           Read;
    EFI_FILE_WRITE          Write;
    EFI_FILE_GET_POSITION   GetPosition;
    EFI_FILE_SET_POSITION   SetPosition;
    EFI_FILE_GET_INFO       GetInfo;
    EFI_FILE_SET_INFO       SetInfo;
    EFI_FILE_FLUSH          Flush;
    EFI_FILE_OPEN_EX        OpenEx;
    EFI_FILE_READ_EX        ReadEx;
    EFI_FILE_WRITE_EX       WriteEx;
    EFI_FILE_FLUSH_EX       FlushEx;
} EFI_FILE_PROTOCOL;

typedef EFI_STATUS (*EFI_SIMPLE_FILE_SYSTEM_PROTOCOL_OPEN_VOLUME)(struct EFI_SIMPLE_FILE_SYSTEM_PROTOCOL *This, EFI_FILE_PROTOCOL **Root);

typedef struct EFI_SIMPLE_FILE_SYSTEM_PROTOCOL
{
    u64                                       Revision;
    EFI_SIMPLE_FILE_SYSTEM_PROTOCOL_OPEN_VOLUME  OpenVolume;
} EFI_SIMPLE_FILE_SYSTEM_PROTOCOL;

typedef struct EFI_SYSTEM_TABLE
{
	EFI_TABLE_HEADER                              hdr;
	CHAR16                                        *FirmwareVendor;
	u32                                        FirmwareVersion;
	EFI_HANDLE                                    ConsoleInHandle;
	EFI_SIMPLE_TEXT_INPUT_PROTOCOL                *ConIn;
	EFI_HANDLE                                    ConsoleOutHandle;
	EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL               *ConOut;
	EFI_HANDLE                                    StandardErrorHandle;
	EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL               *StdErr;
	EFI_RUNTIME_SERVICES                          *RuntimeServices;
	EFI_BOOT_SERVICES                             *BootServices;
	u64                                         NumberOfTableEntries;
	EFI_CONFIGURATION_TABLE                       *ConfigurationTable;
} EFI_SYSTEM_TABLE;

typedef struct EFI_LOADED_IMAGE_PROTOCOL
{
    u32                      Revision;
    EFI_HANDLE                  ParentHandle;
    EFI_SYSTEM_TABLE            *SystemTable;
    EFI_HANDLE                  DeviceHandle;
    EFI_DEVICE_PATH_PROTOCOL    *FilePath;
    void                        *Reserved;
    u32                      LoadOptionsSize;
    void                        *LoadOptions;
    void                        *ImageBase;
    u64                      ImageSize;
} EFI_LOADED_IMAGE_PROTOCOL;

typedef enum EFI_GRAPHICS_OUTPUT_BLT_OPERATION
{
    EfiBltVideoFill,
    EfiBltVideoToBltBuffer,
    EfiBltBufferToVideo,
    EfiBltVideoToVideo,
    EfiGraphicsOutputBltOperationMax
} EFI_GRAPHICS_OUTPUT_BLT_OPERATION;

typedef struct EFI_GRAPHICS_OUTPUT_BLT_PIXEL
{
    u8   Blue;
    u8   Green;
    u8   Red;
    u8   Reserved;
} EFI_GRAPHICS_OUTPUT_BLT_PIXEL;

typedef enum EFI_GRAPHICS_PIXEL_FORMAT
{
    PixelRedGreenBlueReserved8BitPerColor,
    PixelBlueGreenRedReserved8BitPerColor,
    PixelBitMask,
    PixelBltOnly,
    PixelFormatMax
} EFI_GRAPHICS_PIXEL_FORMAT;

typedef struct EFI_PIXEL_BITMASK
{
    u32    RedMask;
    u32    GreenMask;
    u32    BlueMask;
    u32    ReservedMask;
} EFI_PIXEL_BITMASK;

typedef struct EFI_GRAPHICS_OUTPUT_MODE_INFORMATION
{
    u32                      Version;
    u32                      HorizontalResolution;
    u32                      VerticalResolution;
    EFI_GRAPHICS_PIXEL_FORMAT   PixelFormat;
    EFI_PIXEL_BITMASK           PixelInformation;
    u32                      PixelsPerScanLine;
} EFI_GRAPHICS_OUTPUT_MODE_INFORMATION;

typedef struct EFI_GRAPHICS_OUTPUT_PROTOCOL_MODE
{
    u32                                MaxMode;
    u32                                Mode;
    EFI_GRAPHICS_OUTPUT_MODE_INFORMATION  *Info;
    u64                                 SizeOfInfo;
    EFI_PHYSICAL_ADDRESS                  FrameBufferBase;
    u64                                 FrameBufferSize;
} EFI_GRAPHICS_OUTPUT_PROTOCOL_MODE;

typedef EFI_STATUS (*EFI_GRAPHICS_OUTPUT_PROTOCOL_QUERY_MODE)(struct EFI_GRAPHICS_OUTPUT_PROTOCOL *This, u32 ModeNumber, u64 *SizeOfInfo, EFI_GRAPHICS_OUTPUT_MODE_INFORMATION **Info);
typedef EFI_STATUS (*EFI_GRAPHICS_OUTPUT_PROTOCOL_SET_MODE)(struct EFI_GRAPHICS_OUTPUT_PROTOCOL *This, u32 ModeNumber);
typedef EFI_STATUS (*EFI_GRAPHICS_OUTPUT_PROTOCOL_BLT)(struct EFI_GRAPHICS_OUTPUT_PROTOCOL *This, EFI_GRAPHICS_OUTPUT_BLT_PIXEL *BltBuffer, EFI_GRAPHICS_OUTPUT_BLT_OPERATION BltOperation, u64 SourceX, u64 SourceY, u64 DestinationX, u64 DestinationY, u64 Width, u64 Height, u64 Delta);

typedef struct EFI_GRAPHICS_OUTPUT_PROTOCOL
{
    EFI_GRAPHICS_OUTPUT_PROTOCOL_QUERY_MODE  QueryMode;
    EFI_GRAPHICS_OUTPUT_PROTOCOL_SET_MODE    SetMode;
    EFI_GRAPHICS_OUTPUT_PROTOCOL_BLT         Blt;
    EFI_GRAPHICS_OUTPUT_PROTOCOL_MODE        *Mode;
} EFI_GRAPHICS_OUTPUT_PROTOCOL;


#endif
