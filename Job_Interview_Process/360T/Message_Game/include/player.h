#ifndef PLAYER_H
#define PLAYER_H

#include "common.h"

namespace MG
{
    class Player
    {
    public:
        Player(std::string name, Role role, Approach a);
        ~Player()
        {
            std::cout << "Player Destructor Called" << std::endl;
        }
        void startGame();
        bool isActive();
        
    private:
        void play_SameProcess();
        void play_DifferentProcess();

    private:
        std::string playerName;
        Role playerRole;
        Approach solutionApproach;
        bool active;

    };
}

#endif