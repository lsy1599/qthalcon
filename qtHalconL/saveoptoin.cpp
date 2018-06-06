#include "saveoptoin.h"

saveOptoin::saveOptoin(const HImage &imageSaved):
    m_HImageSaved(imageSaved)
{

}

void saveOptoin::Save(std::string & filePath)
{
    const char *filePathSaved = filePath.data();
    HTuple hfilePath = filePathSaved;
    WriteTuple(hfilePath,"D://name");
   WriteImage(m_HImageSaved,"bmp",0,hfilePath);
}
