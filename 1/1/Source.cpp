#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include<Windows.h>
using namespace std;

BOOL printFileInfo(string FileName);
BOOL printFileText(string Filename);
BOOL delRowFileTxt(string FileName, DWORD Row);
int main()
{
  system("chcp 1251");

    LPWSTR FileName = LPWSTR("C:\\for_univer\\sisproga\\1\\1.txt");
    string FileName1 = "D:\\2.txt";

    //printFileInfo(FileName);
    printFileText(FileName1);
    delRowFileTxt(FileName1,4);
    return 0;
}

//BOOL printFileInfo(string FileName) {
//
//    try
//    {
//        char l[] = "C:\\Users\\akach\\OneDrive\\Desktop\\системная прога\\1\\1.txt";
//        FILETIME ftCreate, ftAccess, ftWrite;
//        SYSTEMTIME stUTC, stLocal;
//        HANDLE  hFile = CreateFile(LPWSTR("C:\\Users\\akach\\OneDrive\\Desktop\\1.txt"),               // file to open
//            GENERIC_READ,          // open for reading
//            FILE_SHARE_READ,       // share for reading
//            NULL,                  // default security
//            OPEN_EXISTING,         // existing file only
//            FILE_ATTRIBUTE_NORMAL, // normal file
//            NULL);
//        if (!GetFileTime(hFile, &ftCreate, &ftAccess, &ftWrite))
//            return FALSE;
//        LPTSTR lpszString = LPTSTR(" ");
//        // Преобразуем время последней записи в местное время.
//        FileTimeToSystemTime(&ftWrite, &stUTC);
//        SystemTimeToTzSpecificLocalTime(NULL, &stUTC, &stLocal);
//
//        // Создаем строку, показывающую дату и время.
//        /*wsprintf(lpszString, TEXT("%02d/%02d/%d  %02d:%02d"),
//            stLocal.wMonth, stLocal.wDay, stLocal.wYear,
//            stLocal.wHour, stLocal.wMinute);*/
//            //cout<< lpszString <<endl;
//        //cout << ftWrite. << endl;
//    }
//    catch (const std::exception&)
//    {
//        return false;
//    }
//
//    return true;
//
//}
BOOL printFileText(string Filename) {
    ifstream file("D:\\1.txt");
    string v;
    if (!file)
    {
        cout << "Файл не открыт\n";
        return -1;
    }
    else
    {
        cout << "Файл открыт\n";
        while (!file.eof()) {
            getline(file, v);
            cout << v << endl;
        }
        return 1;
    }


    return true;
}

BOOL delRowFileTxt(string FileName, DWORD Row) {
    vector<string> vec;
    //string path = FileName;
    ifstream file((FileName));
    if (file.is_open())
    {
        string str;
        while (getline(file, str)) {
            vec.push_back(str);
            cout << str<<endl;
        }
        file.close();
        if (vec.size() < Row)
            return false;
        vec.erase(vec.begin() + Row);
        ofstream outfile(FileName);
        if (outfile.is_open())
        {
            std::copy(vec.begin(), vec.end(),
                ostream_iterator<string>(outfile, "\n"));
            outfile.close();
            return true;
        }
        return false;
    }
    return false;
}

   