#ifndef FILEDB_H
#define FILEDB_H

#include <filesystem>
#include <string>

class File
{
public:
    int ID{};
    std::string Value;

    File(int CID, const std::string& CValue);
};

class DBInstance
{
public:
    static int NumOfValues;
    std::string Name;
    std::filesystem::path Path; // A variável Path deve ser constante

    DBInstance(std::string  CName, std::filesystem::path  CPath); // Use '&' para passar por referência
    template<typename T>
    File CreateFile(T Value); // Criará valor e aumentará numofvalues by 1
    void DeleteFile(const File& Value); // Tirará valor e abaixará numofvalues by 1
    auto ReadFile(File Value); // Procurará o valor e retornará seu valor
    void OverwriteFile(File Value); // Vai substituir um valor
};

#endif // FILEDB_H
