#include "fileIO.h"
#include <fstream>

void getFile(std::fstream *file, std::string fileName)
{
    file->open(fileName);
}