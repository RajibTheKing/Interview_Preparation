#ifndef PLAYER_H
#define PLAYER_H

#include "common.h"

namespace MG
{
    class Player
    {
    public:
        Player(std::string name, Role role);
        ~Player()
        {
            std::cout << "Player Destructor Called" << std::endl;
        }
        void startGame();
        bool isActive();
        
    private:
        void play();

    private:
        Role playerRole;
        std::string playerName;
        bool active;

    };
}

#endif