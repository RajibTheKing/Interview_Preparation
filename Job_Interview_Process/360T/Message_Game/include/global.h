
#ifndef GLOBAL_H
#define GLOBAL_H

#include "common.h"

namespace MG
{
    static std::queue< std::pair<std::thread::id, std::string> > messageQueue;
    static std::mutex mtx;
    static std::condition_variable cv;
}

#endif