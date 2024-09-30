#ifndef FILEDB_H
#define FILEDB_H

#include <filesystem>
#include <string>

class DBInstance;

class File
{
public:
    int ID{}; //is the same as int ID = 0;
    std::string Value;


    File(int CID, std::string CValue, std::filesystem::path FilePath, std::string Name);
};

class DBInstance
{
public:
    static int NumOfValues; //static because it will be the same for all instances of the class
    std::string Name;
    std::filesystem::path Path;

    DBInstance(std::string  CName, std::filesystem::path CPath);
    template<typename T>
    File CreateFile(T Value);
    void DeleteFile(const File& Value); /
    auto ReadFile(File Value);
    void OverwriteFile(File Value);
};

#endif // FILEDB_H
