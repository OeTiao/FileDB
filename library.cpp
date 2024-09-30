// src/FileDB.cpp
#include "library.h"
#include <filesystem>
#include <fstream>
#include <utility>
#include <iostream>

// Definindo a variável estática
int DBInstance::NumOfValues = 0;

File::File(const int CID, const std::string& CValue) : ID(CID), Value(CValue)
{
    // Cria o arquivo com o nome baseado no ID
    std::filesystem::path filePath = std::to_string(ID) + ".txt";
    std::ofstream NewFile(filePath); // Cria e abre o arquivo
    if (NewFile) {
        NewFile << Value; // Escreve o valor no arquivo
    } else {
        throw std::runtime_error("Erro ao criar o arquivo: " + filePath.string());
    }
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

void DBInstance::DeleteFile(const File& Value)
{
   // std::filesystem::remove(Path )
}


// Definições específicas de função template devem estar aqui
template File DBInstance::CreateFile<std::string>(std::string Value); // Exemplo de instância específica
template File DBInstance::CreateFile<const char*>(const char*);
