#include "common.h"
#include "player.h"

int main(int argc, const char **argv)
{
    std::cout << "Hello World" << std::endl;

    MG::Player *player1 = new MG::Player(Role::INITIATOR);
    MG::Player *player2 = new MG::Player(Role::ACTOR);

    return 0;
}