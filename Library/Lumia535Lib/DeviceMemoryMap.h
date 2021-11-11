#ifndef _DEVICE_MEMORY_MAP_H_
#define _DEVICE_MEMORY_MAP_H_

#include <Library/ArmLib.h>

#define MAX_ARM_MEMORY_REGION_DESCRIPTOR_COUNT 64

/* Below flag is used for system memory */
#define SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES \
                EFI_RESOURCE_ATTRIBUTE_PRESENT |                 \
                EFI_RESOURCE_ATTRIBUTE_INITIALIZED |             \
                EFI_RESOURCE_ATTRIBUTE_TESTED |                  \
                EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE |             \
                EFI_RESOURCE_ATTRIBUTE_WRITE_COMBINEABLE |       \
                EFI_RESOURCE_ATTRIBUTE_WRITE_THROUGH_CACHEABLE | \
                EFI_RESOURCE_ATTRIBUTE_WRITE_BACK_CACHEABLE |    \
                EFI_RESOURCE_ATTRIBUTE_EXECUTION_PROTECTABLE

typedef enum {
    NoHob,
    AddMem,
    AddDev,
    MaxMem
} DeviceMemoryAddHob;

typedef struct {
	EFI_PHYSICAL_ADDRESS				Address;
	UINT64						Length;
	EFI_RESOURCE_TYPE				ResourceType;
	EFI_RESOURCE_ATTRIBUTE_TYPE			ResourceAttribute;
	ARM_MEMORY_REGION_ATTRIBUTES			ArmAttributes;
	DeviceMemoryAddHob				HobOption;
	EFI_MEMORY_TYPE					MemoryType;
} ARM_MEMORY_REGION_DESCRIPTOR_EX, *PARM_MEMORY_REGION_DESCRIPTOR_EX;

static ARM_MEMORY_REGION_DESCRIPTOR_EX gDeviceMemoryDescriptorEx[] = 
{
	/* Address,	  Length,     ResourceType, Resource Attribute,                                  ARM MMU Attribute,                  HobOption, EFI Memory Type */
	/*DBI Dump*/
	{ 0x00010000, 0x00011000, EFI_RESOURCE_MEMORY_MAPPED_IO, EFI_RESOURCE_ATTRIBUTE_INITIALIZED, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE, NoHob, EfiConventionalMemory },	
	/*HLOS Mem 0*/
	{ 0x00100000, 0x00100000, EFI_RESOURCE_SYSTEM_MEMORY, SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK, AddMem, EfiConventionalMemory },
	/*UEFI FD*/
	{ 0x00200000, 0x00100000, EFI_RESOURCE_SYSTEM_MEMORY, SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK, AddMem, EfiBootServicesData },
	/*MPPark Code*/
	{ 0x00300000, 0x00040000, EFI_RESOURCE_MEMORY_RESERVED, EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_UNCACHED_UNBUFFERED, AddMem, EfiRuntimeServicesCode},
	/*Reserved Uncached 1*/
	{ 0x00340000, 0x00040000, EFI_RESOURCE_SYSTEM_MEMORY, SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_UNCACHED_UNBUFFERED, AddMem, EfiBootServicesData },
	/*FBPT Payload*/
	{ 0x00380000, 0x00001000, EFI_RESOURCE_SYSTEM_MEMORY, SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_UNCACHED_UNBUFFERED, AddMem, EfiRuntimeServicesData },
	/*DBG2*/
	{ 0x00381000, 0x00004000, EFI_RESOURCE_SYSTEM_MEMORY, SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_UNCACHED_UNBUFFERED, AddMem, EfiLoaderData },
	/*Capsule Header*/
	{ 0x00385000, 0x00001000, EFI_RESOURCE_SYSTEM_MEMORY, SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_UNCACHED_UNBUFFERED, AddMem, EfiRuntimeServicesData },
	/*TPM Control Area*/
	{ 0x00386000, 0x00003000, EFI_RESOURCE_SYSTEM_MEMORY, SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_UNCACHED_UNBUFFERED, AddMem, EfiRuntimeServicesData },
    /*UEFI Info Block*/
	{ 0x0FF00000, 0x00800000, EFI_RESOURCE_SYSTEM_MEMORY, SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_UNCACHED_UNBUFFERED, AddMem, EfiRuntimeServicesData },
	/* Reset Data */
	{ 0x0038A000, 0x00003000, EFI_RESOURCE_SYSTEM_MEMORY, SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_UNCACHED_UNBUFFERED, AddMem, EfiRuntimeServicesData },
    /*Reserved Uncached 0*/
	{ 0x0038D000, 0x00073000, EFI_RESOURCE_SYSTEM_MEMORY, SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_UNCACHED_UNBUFFERED, AddMem, EfiBootServicesData},
    /*Display Reserved*/
    { 0x00400000, 0x00800000, EFI_RESOURCE_MEMORY_RESERVED, EFI_RESOURCE_ATTRIBUTE_WRITE_THROUGH_CACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_THROUGH, AddMem, EfiMaxMemoryType },
	/*UEFI Stack*/
	{ 0x00C00000, 0x00040000, EFI_RESOURCE_SYSTEM_MEMORY, SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK, AddMem, EfiBootServicesData },
	/*CPU Vectors*/
	{ 0x00C40000, 0x00010000, EFI_RESOURCE_SYSTEM_MEMORY, SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK, AddMem, EfiBootServicesData },
	/*Reserved Cached 0*/	
	{ 0x00C50000, 0x000B0000, EFI_RESOURCE_SYSTEM_MEMORY, SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK, AddMem, EfiBootServicesData },
	/*HLOS Mem 1*/
	{ 0x00D00000, 0x03300000, EFI_RESOURCE_SYSTEM_MEMORY, SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK, AddMem, EfiBootServicesData },
	/*HLOS Mem 2*/
	{ 0x04000000, 0x04800000, EFI_RESOURCE_SYSTEM_MEMORY, SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK, AddMem, EfiBootServicesData },
	/*Subsystem Reserved 0*/
	{ 0x08800000, 0x03D00000, EFI_RESOURCE_SYSTEM_MEMORY, SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE, AddMem, EfiReservedMemoryType },
	/*HLOS Mem 3*/
	{ 0x0C500000, 0x01400000, EFI_RESOURCE_SYSTEM_MEMORY, SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK, AddMem, EfiConventionalMemory },
	/*!!SMEM*/
	{ 0x0D900000, 0x00100000, EFI_RESOURCE_MEMORY_RESERVED, EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_UNCACHED_UNBUFFERED, NoHob, EfiMaxMemoryType },
	/*HLOS Mem 4*/
	{ 0x0DA00000, 0x00100000, EFI_RESOURCE_SYSTEM_MEMORY, SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK, AddMem, EfiConventionalMemory },
	/*NonRelocatable 0*/
	{ 0x0D900000, 0x00100000, EFI_RESOURCE_SYSTEM_MEMORY, SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE, AddMem, EfiReservedMemoryType },
	/*TZ Apps*/
	{ 0x0DF00000, 0x00200000, EFI_RESOURCE_SYSTEM_MEMORY, SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE, AddMem, EfiReservedMemoryType },
	/*BGRT Logo*/
	{ 0x0E100000, 0x00300000, EFI_RESOURCE_SYSTEM_MEMORY, SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK, AddMem, EfiBootServicesData },
	/*HLOS Mem 5*/
	{ 0x0E400000, 0x31C00000, EFI_RESOURCE_SYSTEM_MEMORY, SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK, AddMem, EfiConventionalMemory },
	/* Other memory regions */
	/*IMEM Boot Base*/
	{ 0xFE800000, 0x00040000, EFI_RESOURCE_SYSTEM_MEMORY, EFI_RESOURCE_ATTRIBUTE_INITIALIZED, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE, NoHob, EfiConventionalMemory },
	/*IMEM Cookie Base*/
	{ 0xFC42B000, 0x00001000, EFI_RESOURCE_MEMORY_MAPPED_IO, EFI_RESOURCE_ATTRIBUTE_INITIALIZED, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE, AddDev, EfiConventionalMemory },
	/*IMEM Cookie Base 2*/	
	{ 0xFE805000, 0x00001000, EFI_RESOURCE_MEMORY_MAPPED_IO, EFI_RESOURCE_ATTRIBUTE_INITIALIZED, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE, AddDev, EfiConventionalMemory },
	/*RPM CODE_DATARAM Dump*/
	//{ 0xFC100000, 0x00100000, EFI_RESOURCE_MEMORY_MAPPED_IO, EFI_RESOURCE_ATTRIBUTE_INITIALIZED, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE, AddDev, EfiConventionalMemory },
	/* Register regions */
	/*1*/
	{ 0xF9000000, 0x02000000, EFI_RESOURCE_MEMORY_MAPPED_IO, EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE, AddDev, EfiMemoryMappedIO },
	/*2*/
	{ 0xFC400000, 0x00002000, EFI_RESOURCE_MEMORY_MAPPED_IO, EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE, AddDev, EfiMemoryMappedIO },
	/*3*/
	{ 0xFC428000, 0x00008000, EFI_RESOURCE_MEMORY_MAPPED_IO, EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE, AddDev, EfiMemoryMappedIO },
	/*4*/
	{ 0xFC4AB000, 0x00001000, EFI_RESOURCE_MEMORY_MAPPED_IO, EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE, AddDev, EfiMemoryMappedIO },
	/*5*/
	{ 0xFC4C0000, 0x00040000, EFI_RESOURCE_MEMORY_MAPPED_IO, EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE, AddDev, EfiMemoryMappedIO },
	/*6*/
	{ 0xFD400000, 0x00D00000, EFI_RESOURCE_MEMORY_MAPPED_IO, EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE, AddDev, EfiMemoryMappedIO },
	/*7*/
	{ 0xFC4B8000, 0x00008000, EFI_RESOURCE_MEMORY_MAPPED_IO, EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE, AddDev, EfiMemoryMappedIO },
	/*8*/
	{ 0xFC4A9000, 0x00001000, EFI_RESOURCE_MEMORY_MAPPED_IO, EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE, AddDev, EfiMemoryMappedIO },
	/* Terminator */
	{ }
};

#endif
