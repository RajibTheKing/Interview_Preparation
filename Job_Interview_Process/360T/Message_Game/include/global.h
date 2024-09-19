
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
    std::vector<std::string> messages = {
        "The cat jumps over the fence.",
        "A dog barks at the mailman.",
        "The bird sings a beautiful song.",
        "A child plays with a toy.",
        "The teacher explains the lesson.",
        "A computer processes data quickly.",
        "The car drives down the highway.",
        "A tree provides shade on a sunny day.",
        "The student studies for the exam.",
        "An artist paints a stunning landscape.",
        "The sun rises in the east.",
        "A chef cooks a delicious meal.",
        "The wind blows gently through the trees.",
        "A musician plays a captivating tune.",
        "The flowers bloom in the spring.",
        "A writer pens a gripping novel.",
        "The ocean waves crash on the shore.",
        "A firefighter saves a cat from a tree.",
        "The clock ticks softly in the background.",
        "A scientist conducts an important experiment."
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