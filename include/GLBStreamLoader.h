#ifndef __GLBSTREAMLOADER_H__
#define __GLBSTREAMLOADER_H__

#include "IStreamLoader.h"

class GLBStreamLoader : public IStreamLoader
{
    public :
        GLBStreamLoader();
        virtual ~GLBStreamLoader();

    public :
        bool Read(const std::string& filePath) override;
};

#endif // __GLBSTREAMLOADER_H__