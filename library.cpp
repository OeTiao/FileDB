// src/FileDB.cpp
#include "library.hpp"
#include <filesystem>
#include <fstream>
#include <utility>
#include <iostream>


int DBInstance::NumOfValues = 0;

File::File(const int CID, std::string  CValue, const std::filesystem::path& FilePath, const std::string& Name) : ID(CID), Value(std::move(CValue))
{

    std::ofstream NewFile(FilePath.string() + "/" + Name + "/" + std::to_string(CID) + ".sdb");

    NewFile << Value;
    NewFile.close();
}



DBInstance::DBInstance(std::string CName, std::filesystem::path CPath)
{
    Name = std::move(CName);
    Path = std::move(CPath);
    std::filesystem::create_directory(Path / Name);
    NumOfValues = 0;
}

template <typename T>
File DBInstance::CreateFile(T Value)
{
    NumOfValues++;
    return File(NumOfValues, Value, DBInstance::Path, DBInstance::Name);
}

void DBInstance::DeleteFile(const File& Value)
{
    // std::filesystem::remove(Path )
}



template File DBInstance::CreateFile<std::string>(std::string Value);
template File DBInstance::CreateFile<const char*>(const char*);
