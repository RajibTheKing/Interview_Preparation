
#ifndef GLOBAL_H
#define GLOBAL_H

#include "common.h"

namespace MG
{
    static std::queue< std::pair<std::thread::id, std::string> > messageQueue;
    static std::mutex mtx;
    static std::condition_variable cv;
    static int numberOfIteration = 10;

    // static storage of random messages
    static std::vector<std::string> messages = {
        "Hello, how are you today?",
        "What a beautiful day!",
        "Are you ready for the weekend?",
        "Keep smiling and stay positive.",
        "Let's make the most of this moment.",
        "Did you hear the latest news?",
        "It's a great time to learn something new.",
        "Wishing you all the best today!",
        "Don't forget to take a break.",
        "Enjoy the little things in life."
    };

    // create a random number generator
    static std::random_device rd;  // Seed the generator
    static std::mt19937 gen(rd()); // Mersenne Twister engine
    static std::uniform_int_distribution<> distribute(0, 10000); // Define the range

    // necessary variables to play with different process
    static std::string fifoPath = "./build/message_fifo";
    static int mode = 0666;
    static int bufferSize = 1000;

}

#endif