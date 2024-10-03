#ifndef __ISTREAMLOADER_H__
#define __ISTREAMLOADER_H__

#include <iostream>
#include <fstream>

class IStreamLoader
{
    public :
        IStreamLoader();
        virtual ~IStreamLoader();

    public :
        virtual bool Read(const std::string& filePath) = 0;
};

#endif // __ISTREAMLOADER_H__