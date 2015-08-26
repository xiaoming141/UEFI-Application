/*
 * Read DIMM SPD information with SmbusLib read byte interface
 * SlaveAddress    SMBUS Slave Address.  Range 0..127(only 7 bits).
 */

#include <Uefi.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiLib.h>
#include <stdio.h>
#include <Library/SmbusLib.h>

VOID ShowSpd(VOID * Ptr)
{
  UINT8 *p = (UINT8 *)Ptr;
  UINT16 i;
  for(i = 0; i < 256; i++)
  {
    if((i%16) == 0)
      Print(L"\n");

    Print(L"%02x ", *(p + i));
  }
}

INTN main( IN UINTN Argc, IN CHAR16 ** Argv)
{

  UINT8   SlaveAddr;
  UINT8   Command = 0;    //SPD offset
  UINT8   Length = 0;
  UINT8   Pec = 0;         //Package error check
  UINTN   SmBusAddress;
  UINT8   Buffer[256];
  EFI_STATUS  Status;
  UINT16  i;

  Print(L"Please enter the DIMM SMBUS Slave device address,Range 0-0x7F(HEX): ");
  scanf("%x",&SlaveAddr);

  for(i = 0; i < 256; i++)
  {
    Command = (UINT8) i;
    SmBusAddress = SMBUS_LIB_ADDRESS(SlaveAddr, Command, Length, Pec);
    Buffer[i] = SmBusReadDataByte(SmBusAddress, &Status);

    if(EFI_ERROR(Status))
    {
      Print(L"Byte Read operation error!Status = %x\n", Status);
      return Status;
    }
    Print(L"Buffer[%d] = %x\n", i, Buffer[i]);
  }


  ShowSpd(Buffer);

  return 0;
}
