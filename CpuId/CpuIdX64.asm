;Intel X64 platform only!!!
;Buffer is in rcx
;Leaf is in edx
;SubLeaf is in r8d


.CODE
READ_CPUID PROC

  mov r9, rcx
  mov eax, edx
  mov ecx, r8d
  cpuid
  mov DWORD PTR [r9], eax
  mov DWORD PTR [r9 + 4], ebx
  mov DWORD PTR [r9 + 8], ecx
  mov DWORD PTR [r9 + 12], edx

  ret
READ_CPUID ENDP
END
