#ifndef __BUFFERMANAGER_H__
#define __BUFFERMANAGER_H__

class BufferManager
{
    private :
        BufferManager();
        virtual ~BufferManager();

    public :
        BufferManager& GetInstance();
};

#endif // __BUFFERMANAGER_H__