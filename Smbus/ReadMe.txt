How to compile?
  It is similair to compile CpuId. 
  Because of AppPkg is short of SmbusLib, it's need to add 
  "SmbusLib|MdePkg\Library\DxeSmbusLib\DxeSmbusLib.inf"
  to [LibraryClasses] section of AppPkg.dsc file.
