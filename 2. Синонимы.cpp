#include <unordered_map>
#include <iostream>
#include <string>

std::unordered_map<std::string, std::string> map;

void execute_operation(const std::string& operation)
{
    std::string param1;
    std::cin >> param1;

    if (operation == "ADD")
    {
        std::string param2;
        std::cin >> param2;

        map[param1] += param2 + ',';
        map[param2] += param1 + ',';
    }
    else if (operation == "COUNT")
    {
        size_t counter = 0;
        size_t finder = map[param1].find(',');
        while (finder != std::string::npos)
        {
            ++counter;
            finder = map[param1].find(',', finder+1);
        }
        std::cout << counter << std::endl;
    }
    else if (operation == "CHECK")
    {
        std::string param2;
        std::cin >> param2;

        if (map[param1].find(param2) != std::string::npos)
            std::cout << "YES" << std::endl;
        else
            std::cout << "NO" << std::endl;
    }
}

int main()
{
    int requests_count;
    std::cin >> requests_count;
    for (size_t i = 0; i < requests_count; ++i)
    {
        std::string operation;
        std::cin >> operation;

        execute_operation(operation);
    }
}