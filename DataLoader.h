#ifndef DATALOADER_H
#define DATALOADER_H

#include <string>
#include "Vector.h"
#include "WindLog.h"

class DataLoader
{
public:
    Vector<WindLog> loadData(const std::string& filePath);
};

#endif // DATALOADER_H
