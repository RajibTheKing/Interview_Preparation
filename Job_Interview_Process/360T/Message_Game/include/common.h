
#ifndef COMMON_H
#define COMMON_H

#include <iostream>
#include <chrono>
#include <mutex>
#include <queue>
#include <string>
#include <thread>
#include <condition_variable>
using namespace std::chrono_literals;


enum Role {
  INITIATOR,
  ACTOR
};

#endif