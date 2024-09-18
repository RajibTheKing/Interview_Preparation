
#ifndef GLOBAL_H
#define GLOBAL_H

#include "common.h"

namespace MG
{
    static std::queue< std::pair<std::thread::id, std::string> > messageQueue;
    static std::mutex mtx;
    static std::condition_variable cv;

    // Static storage of random messages
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
}

#endif