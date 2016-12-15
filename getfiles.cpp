#include <string>
#include <io.h>
#include <vector>
#include <iostream>
#include <QString>
using namespace std;
string nameoffiles[500];//save names of all the files
string pathoffiles[500];//save the path of all the files
string pathofimage[500];//save the path of all the images(jpg,png,flif)
QString imagepath[500];//for image team，tranform into QString
int countnumber;//for function getFiles
/************************************************************************/
/*  get all name and path in the folder given
    import：
        path	:	path of folder
        exd	:   extension,such as jpg； if want all files, exd = ""
    outpute：
        files	   files gotted

    Xiao, 20161107
*/
/************************************************************************/
void getFiles( string path, string exd, vector<string>& files )
{

    long hFile = 0;
    // file infomation
    struct _finddata_t fileinfo;
    string pathName, exdName;

    if (0 != strcmp(exd.c_str(), ""))
    {
        exdName = "\\*." + exd;
    }
    else
    {
        exdName = "\\*";
    }
    if((hFile = _findfirst(pathName.assign(path).append(exdName).c_str(),&fileinfo)) !=  -1)
    {
        do
        {

            //if there are folders in folders, interation
            //if not, get it
            if((fileinfo.attrib & _A_SUBDIR))//is it a folder? If it is.
            {
                if(strcmp(fileinfo.name,".") != 0 && strcmp(fileinfo.name,"..") != 0)
                    getFiles( pathName.assign(path).append("\\").append(fileinfo.name), exd, files );//interation
            }
            else//not a folder
            {
                if(strcmp(fileinfo.name,".") != 0 && strcmp(fileinfo.name,"..") != 0)
                {
                    nameoffiles[countnumber]= fileinfo.name;//save the name
                    countnumber++;
                    files.push_back(pathName.assign(path).append("\\").append(fileinfo.name));
                }
            }
        }while(_findnext(hFile, &fileinfo)  == 0);//do it for every file
        _findclose(hFile);//end
    }
}

int main()
{
    string filePath = "C:\\Users\\lenovo\\Desktop\\2478944";//path of the folder you give
    vector<string> files;//define vector files
    getFiles(filePath, "", files);//get all the files in the folder
    int size = files.size();//numbers of files
    for (int i = 0;i < size;i++)
    {
        pathoffiles[i] = files[i].c_str();//save the pathes
        //cout << pathoffiles[i] << endl;//Verify what is in pathoffiles[].nameoffiles[i] and pathoffiles[i] are corresponding
    }
   //Verify the name in nameoffiles[]
    /*for(int i = 0;i<size;i++)
   {
       cout<< nameoffiles[i]<<endl;
   }*/
    int n = 0;//for imagepath[] count
    for(int i = 0; i < size; i++)
    {//is it jpg，png，flif?
        if(pathoffiles[i].find(".jpg") != -1 || pathoffiles[i].find(".png") != -1 || pathoffiles[i].find(".flif") != -1 )
        {
            pathofimage[n] = pathoffiles[i];//save in pathofimage[]
            imagepath[n] = QString::fromStdString(pathofimage[n]);//for image team，tranform into QString
            //cout << pathofimage[n] << endl;//Verify the path of image
            n++;
        }
    }

}



