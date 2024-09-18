#include "common.h"
#include "player.h"

int main(int argc, const char **argv)
{
    MG::Player *player1 = new MG::Player("Alex", Role::INITIATOR);
    MG::Player *player2 = new MG::Player("Bob", Role::ACTOR);
    player1->startGame();
    player2->startGame();

    // wait until both player1 and player2 finish playing
    while (player1->isActive() || player2->isActive())
    {
        std::this_thread::sleep_for(2000ms);
    }
    return 0;
}