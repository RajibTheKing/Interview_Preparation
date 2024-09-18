
#ifndef COMMON_H
#define COMMON_H

#include <chrono>
#include <iostream>
#include <mutex>
#include <queue>
#include <random>
#include <string>
#include <thread>
#include <condition_variable>
using namespace std::chrono_literals;


enum Role {
  INITIATOR,
  ACTOR
};

#endif