#ifndef PLAYER_H
#define PLAYER_H

#include "common.h"

namespace MG
{
    class Player
    {
    public:
        Player(Role role);
        ~Player()
        {
            std::cout << "Player Destructor Called" << std::endl;
        }

    private:
        Role playerRole;

    };
}

#endif