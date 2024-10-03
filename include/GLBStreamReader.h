#ifndef __GLBSTREAMREADER_H__
#define __GLBSTREAMREADER_H__

#include "GLBStreamLoader.h"

class GLBStreamReader
{
    public :
        GLBStreamReader() = delete;
        GLBStreamReader(const std::shared_ptr<GLBStreamLoader>&& glbStreamLoader);
        virtual ~GLBStreamReader();

    public :
        
};

#endif // __GLBSTREAMREADER_H__