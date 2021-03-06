#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <Sparrow/BaseType.h>
#include <Uefi.h>

typedef enum {
    FREE_MEMORY,
    OS_CODE,
    OS_DATA,
    AP_CODE,
    AP_DATA,
    UEFI_MEMORY,
    MMIO_MEMORY,
    RESERVED_MEMORY,
} MEMORY_TYPE;

typedef struct MEMORY_DESCRIPTOR_NODE {
    PHYSICAL_ADDRESS               Start;
    U64                            PageSize;
    MEMORY_TYPE                    Type;
    struct MEMORY_DESCRIPTOR_NODE *Next;
} MEMORY_DESCRIPTOR_NODE;

typedef struct FREE_MEMORY_NODE {
    PHYSICAL_ADDRESS         Start;
    U64                      PageSize;
    MEMORY_TYPE              Type;
    struct FREE_MEMORY_NODE *Next;
} FREE_MEMORY_NODE;

typedef struct
{
    MEMORY_TYPE      Type;
    PHYSICAL_ADDRESS Start;
    U64              PageSize;
} MEMORY_DESCRIPTOR;

STATUS_CODE InitMemory(IN MEMORY_MAP *MM);

STATUS_CODE MemCopy(IN PHYSICAL_ADDRESS source, IN PHYSICAL_ADDRESS destination, IN U64 size);

STATUS_CODE SetZero(IN PHYSICAL_ADDRESS addr, IN U64 size);

#endif
