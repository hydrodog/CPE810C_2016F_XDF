#ifndef __ZHead__ 
#define __ZHead__
 
#include "common.h"
/*
Fuction：Decompress the .epub file to a specified folder(将压缩文件解压到指定目录)
Parameters：
  1.LPSTR lpszZipPathName     The name of .epub file(压缩文件名)
      "\aa.zip"

  2.LPSTR lpszDestDirectory      The Target Directory which the file is extracted to.(解压到目标目录)
      "f:\\aa\\cc"
return：0 succeed ，else will return other values(否则其他值)
attention：the pointer will be checkout the legitimacy from other .cpp file.(指针由外界校验合法性)
*/
DWORD UnZipToDirectory( LPCSTR lpszZipPathName, LPCSTR lpszDestDirectory );

#endif // __ZHead__  
