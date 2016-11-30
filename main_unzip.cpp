#include <iostream>
#include <string>
#include <windows.h>
#include "unzip.h"


using namespace std;


int main()
{
    TCHAR mZipFileFullPath[200];
    TCHAR  mUnPackDir[200];

    cout << "please input the epub file: ";
    wcin >> mZipFileFullPath;

    cout << "please input the upzip dir name: ";
    wcin >> mUnPackDir;

    //call the function of the minzlib library, open the compressed file, get the operarion handle.
    HZIP hz = OpenZip(mZipFileFullPath, 0);
    if (hz == 0)
    {
        //failed to open Zip file
        cout << "failed to open Zip file" << endl;
        return -1;
    }

    //call the function of the minzlib library,
    //associate the handle of the above zip file with the directory name which ready to be uncompressed
    ZRESULT zr = SetUnzipBaseDir(hz, mUnPackDir);
    if (zr != ZR_OK)
    {
        //bind the compressed file catalogue
        cout << "failed to bind the compressed file directory" << endl;
        CloseZip(hz);
        return -1;
    }

    ZIPENTRY ze;
    //call the function of minzlib library, get the amount of file in the handle of zip file.
    zr = GetZipItem(hz, -1, &ze);
    if (zr != ZR_OK)
    {
        //failed to get the number of the files in the zip file
        cout << "fail to get the number of the files in the Zip file" << endl;
        CloseZip(hz);
        return -1;
    }

    int numitems = ze.index;
    for (int i = 0; i < numitems; i++)
    {
        //move the handle of zip file, point to the address of the i file
        zr = GetZipItem(hz, i, &ze);
        //uncompress the data from the current address.
        zr = UnzipItem(hz, i, ze.name);
        if (zr != ZR_OK)
        {
            cout << "fail to uncompress the Zip file" << endl;
            CloseZip(hz);
            return -1;
        }
    }

    CloseZip(hz);
    cout << "Succeed to uncompress the Zip file" << endl;
    TCHAR pBuf[250];                                   //storage the variable of path.
    GetCurrentDirectory(250, pBuf);                   //get the current directory

    wcout << "uncompressed directory：" << pBuf << "\\" << mUnPackDir <<endl ;
    return 0;
}
