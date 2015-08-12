This application can read the CPUID with Leaf number and SubLeaf given by user.


How to build?
  Assume that you have had EDK2 source code and set up EDK2 build environment.
  Put CpuId directory in EDK2 root directory
  Add "CpuId\CpuId.inf" in [Components] of file AppPkg.dsc
  Use command "build -a X64 -p AppPkg\AppPkg.dsc"
