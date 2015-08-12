#include <Uefi.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiLib.h>
#include <stdio.h>

extern void READ_CPUID();


INTN main( IN UINTN Argc, IN CHAR16 ** Argv)
{
    UINT32 Buffer[4] = {0}, Leaf = 0, SubLeaf = 0;

    Print(L"Please input the CPUID Leaf:");

    scanf("%x",&Leaf);
    Print(L"Please input the CPUID SubLeaf:");
    scanf("%x",&SubLeaf);

    Print(L"Leaf = %x, SubLeaf = %x\n", Leaf, SubLeaf);



    READ_CPUID(Buffer, Leaf, SubLeaf);

    Print(L"EAX=%x\nEBX=%x\nECX=%x\nEDX=%x\n", Buffer[0], Buffer[1], Buffer[2], Buffer[3]);

    return 0;
}
