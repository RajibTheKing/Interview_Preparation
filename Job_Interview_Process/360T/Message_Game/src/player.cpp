#include "player.h"
#include "global.h"

namespace MG
{
    Player::Player(Role r)
    {
        std::cout << "Player Constructor Called" << std::endl;
        playerRole = r;
    }
}