#include <QCoreApplication>
#include <zlib.h>
 #include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <QDebug>

using namespace std;

int UnCompress(char * DestName, char *SrcName)
 {
    char uSorceBuffer[102400] = {0};  //the source buffer of unzip the files
    FILE* fp3;  //the pointer to open the compressed files which should be uncompressed
    FILE* fp4;  //the pointer to create the decompression of the file
    errno_t err; //The definition of error variable
    //open the file should be uncompressed
    fp3 = fopen(SrcName, "r");
   /*
    err = fopen_s(&fp3,SrcName,"r");
    if(err)
    {
        qDebug() << "fail to opel the file!";
        return 1;
    }
    */
     //get the length of the file should be uncompressed
    long ucur = ftell(fp3);
    fseek(fp3,0L,SEEK_END);
    long ufileLength = ftell(fp3);
    fseek(fp3,ucur,SEEK_SET);


    //读取文件到buffer
    fread(uSorceBuffer,ufileLength,1,fp3);
    fclose(fp3);

    uLongf uDestBufferLen=1024000;//此处长度需要足够大以容纳解压缩后数据
    char* uDestBuffer=(char*)::calloc((uInt)uDestBufferLen, 1);
    //解压缩buffer中的数据
    err=uncompress((Bytef*)uDestBuffer,(uLongf*)&uDestBufferLen,(Bytef*)uSorceBuffer,(uLongf)ufileLength);

    if(err!=Z_OK)
    {
        qDebug() <<"解压缩失败："<<err<<endl;
         return 1;
    }

    //创建一个文件用来写入解压缩后的数据
    err = fopen_s(&fp4,DestName,"wb");
    if(err)
    {
        printf("解压缩文件创建失败! \n");
        return 1 ;
    }

    printf("写入数据... \n");
    fwrite(uDestBuffer,uDestBufferLen,1,fp4);
    fclose(fp4);
    return 0;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString zipFile("example.zip");
    QString unZip("unCompressed.txt");
    QByteArray ba1 = zipFile.toLatin1();
    QByteArray ba2 = unZip.toLatin1();

    char * c_str1 = ba1.data();
    char * c_str2 = ba2.data();
    qDebug() << UnCompress(c_str2, c_str1);
    return a.exec();
}
