#include <iostream>
#include <string>
#include <map>

std::map<int, std::string> readFromFile(std::string fileName)
{
    freopen(fileName.c_str(), "r", stdin);
    std::map<int, std::string> data; // initialize empty map
    int number;
    std::string word;
    while(std::cin >> number >> word)
    {
        data[number] = word;
    }

    return data;
}

std::string decodeMessage(std::map<int, std::string>& data)
{
    int step = 1;
    int i;
    std::string answer = "";
    for (i = 1; i <= data.size(); i+=step)
    {
        if (answer.empty())
            answer += data[i];
        else
            answer += (" " + data[i]);
        step += 1;
    }
    if ((i - step) == data.size())
        return answer;
    else
        return "";
}

int main()
{
    std::map<int, std::string> data = readFromFile("input.txt");
    std::string answer = decodeMessage(data);
    if (answer.empty())
        std::cout << "Could not decode message, because input file doesn't represent valid pyramid" << std::endl;
    else
        std::cout << "Answer is : " << answer << std::endl;

    return 0;
}




