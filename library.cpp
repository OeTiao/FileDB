// src/FileDB.cpp
#include "library.h"
#include <filesystem>
#include <fstream>
#include <utility>

// Definindo a variável estática
int DBInstance::NumOfValues = 0;

File::File(const int CID, const std::string& CValue)
{
    Value = CValue;
    ID = CID;

    std::ofstream NewFile(std::to_string(CID) + ".txt");
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
    return File(NumOfValues, Value);
}

// Definições específicas de função template devem estar aqui
template File DBInstance::CreateFile<std::string>(std::string Value);
