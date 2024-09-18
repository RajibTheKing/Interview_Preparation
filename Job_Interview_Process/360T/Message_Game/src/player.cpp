#include "player.h"
#include "global.h"

namespace MG
{
    Player::Player(std::string name, Role r)
    {
        playerName = name;
        playerRole = r;
        active = false;

        if (playerRole == Role::INITIATOR)
            std::cout << playerName << " is an Initiator" << std::endl;
        else
            std::cout << playerName << " is an Actor" << std::endl;
    }

    void Player::startGame()
    {
        active = true;
        new std::thread(&Player::play, this);
    }

    bool Player::isActive()
    {
        return active;
    }

    void Player::play()
    {
        std::string fixedMsg = "this is just a msg";
        int msgCounter = 0;
        int numberOfIteration = 10;

        std::thread::id currentThreadId = std::this_thread::get_id();

        while(msgCounter < numberOfIteration)
        {
            std::unique_lock<std::mutex> lock(mtx);
            std::this_thread::sleep_for(1000ms);

            if (playerRole == Role::INITIATOR)
            {
                messageQueue.push(std::make_pair(currentThreadId, fixedMsg));
                cv.notify_one();
            }

            cv.wait(lock, [currentThreadId]{ 
                        return !messageQueue.empty() &&  messageQueue.front().first != currentThreadId;
                    });

            // Get the message from the queue
            std::string receivedMessage = messageQueue.front().second;
            msgCounter++;
            messageQueue.pop();
            std::cout<<"\n" << playerName << " received: " << receivedMessage << std::endl;

            if (playerRole == Role::ACTOR)
            {
                messageQueue.push(std::make_pair(currentThreadId, receivedMessage + " " + std::to_string(msgCounter)));
                cv.notify_one();
            }
        }

        active = false;
    }
}