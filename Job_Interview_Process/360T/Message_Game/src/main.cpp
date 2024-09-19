#include "common.h"
#include "player.h"

Approach getSolutionApproach(const char* argument)
{
    if (argument == "different_process"sv)
        return Approach::DIFFERENT_PROCESS;
    
    // default
    return Approach::SAME_PROCESS;
}

Role getPlayerRole(const char* argument)
{
    if (argument == "initiator"sv)
        return Role::INITIATOR;
    
    // default
    return Role::ACTOR;
}

int main(int argc, const char **argv)
{
    pid_t process_id = getpid(); // Get the current process ID
    std::cout << "Current Process ID: " << process_id << std::endl;
    
    Approach approach = getSolutionApproach(argv[1]);

    if (approach == Approach::SAME_PROCESS)
    {
        MG::Player *player1 = new MG::Player("Alex", Role::INITIATOR, approach);
        MG::Player *player2 = new MG::Player("Bob",  Role::ACTOR,     approach);
        player1->startGame();
        player2->startGame();

        // wait until both player1 and player2 finish playing
        while (player1->isActive() || player2->isActive())
        {
            std::this_thread::sleep_for(500ms);
        }
    }
    else
    {
        Role role = getPlayerRole(argv[2]);
        std::string playerName(argv[3]);
        MG::Player *player = new MG::Player(playerName, role, approach);
        player->startGame();
        while (player->isActive())
        {
            std::this_thread::sleep_for(500ms);
        }
    }

    std::cout << "\n\nMessage Game is Finished" << std::endl;
    return 0;
    
}