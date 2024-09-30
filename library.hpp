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
    std::filesystem::path Path; // A variável Path deve ser constante

    DBInstance(std::string  CName, std::filesystem::path CPath); // Use '&' para passar por referência
    template<typename T>
    File CreateFile(T Value); // Criará valor e aumentará numofvalues by 1
    void DeleteFile(const File& Value); // Tirará valor e abaixará numofvalues by 1
    auto ReadFile(File Value); // Procurará o valor e retornará seu valor
    void OverwriteFile(File Value); // Vai substituir um valor
};

#endif // FILEDB_H
