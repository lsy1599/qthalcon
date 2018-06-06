#ifndef SAVEOPTOIN_H
#define SAVEOPTOIN_H
#include "HalconCpp.h"
using namespace HalconCpp;
class saveOptoin
{
public:
    saveOptoin(const HImage &imageSaved);
    void Save(std::string & filePath);
private:
    HImage m_HImageSaved;
};

#endif // SAVEOPTOIN_H
