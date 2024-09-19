
#ifndef COMMON_H
#define COMMON_H

#include <chrono>
#include <iostream>
#include <mutex>
#include <queue>
#include <random>
#include <string>
#include <string_view>
#include <thread>
#include <condition_variable>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


using namespace std::chrono_literals;
using namespace std::literals;
namespace MG
{
    enum Role
    {
        INITIATOR,
        ACTOR
    };

    enum Approach
    {
        SAME_PROCESS,
        DIFFERENT_PROCESS
    };
}

#endif