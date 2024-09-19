#include "player.h"
#include "global.h"

namespace MG
{
    Player::Player(std::string name, Role r, Approach a)
    {
        playerName = name;
        playerRole = r;
        solutionApproach = a;
        active = false;

        std::cout << playerName << " is an " << playerRole << std::endl;
    }

    void Player::startGame()
    {
        active = true;
        if (solutionApproach == Approach::SAME_PROCESS)
            new std::thread(&Player::play_SameProcess, this);
        else
            new std::thread(&Player::play_DifferentProcess, this);
    }

    bool Player::isActive()
    {
        return active;
    }

    void Player::play_SameProcess()
    {
        int msgCounter = 0;
        std::thread::id currentThreadId = std::this_thread::get_id();

        while (msgCounter < numberOfIteration)
        {
            std::unique_lock<std::mutex> lock(mtx);
            std::this_thread::sleep_for(100ms);

            int randomIndex = distribute(gen) % messages.size();

            if (playerRole == Role::INITIATOR)
            {
                messageQueue.push(std::make_pair(currentThreadId, messages[randomIndex]));
                cv.notify_one();
            }

            cv.wait(lock, [currentThreadId]{
                        return !messageQueue.empty() &&  messageQueue.front().first != currentThreadId;
                    });

            // Get the message from the queue
            std::string receivedMessage = messageQueue.front().second;
            msgCounter++;
            messageQueue.pop();

            if (playerRole == Role::ACTOR)
                std::cout << "\n                              ";
            else
                std::cout << "\n";

            std::cout << "[" << playerName << " received]: " << receivedMessage << std::endl;

            if (playerRole == Role::ACTOR)
            {
                messageQueue.push(std::make_pair(currentThreadId, receivedMessage + " " + std::to_string(msgCounter)));
                cv.notify_one();
            }
        }

        active = false;
    }

    void Player::play_DifferentProcess()
    {
        int msgCounter = 0;

        // create the FIFO if the player is an Initiator
        if (playerRole == Role::INITIATOR)
            mkfifo(fifoPath.c_str(), mode);

        while (msgCounter < numberOfIteration)
        {
            std::this_thread::sleep_for(100ms);
            int randomIndex = distribute(gen) % messages.size();

            if (playerRole == Role::INITIATOR)
            {
                // Open FIFO for writing
                int fifo = open(fifoPath.c_str(), O_WRONLY);
                write(fifo, messages[randomIndex].c_str(), messages[randomIndex].size() + 1);
                close(fifo);
            }

            // Wait for reply
            char buffer[bufferSize];
            int fifo = open(fifoPath.c_str(), O_RDONLY);
            read(fifo, buffer, sizeof(buffer));
            close(fifo);

            msgCounter++;
            std::cout << "[" << playerName << " received]: " << buffer << std::endl;

            if (playerRole == Role::ACTOR)
            {
                std::string response(buffer);
                response += (" " + std::to_string(msgCounter));

                // Open FIFO for writing
                int fifo = open(fifoPath.c_str(), O_WRONLY);
                write(fifo, response.c_str(), response.size() + 1);
                close(fifo);
            }

        }

        active = false;
    }

}