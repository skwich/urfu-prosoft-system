#include <unordered_map>
#include <iostream>
#include <string>
#include <vector>

std::unordered_map<std::string, std::vector<std::string>> map;

void execute_operation(const std::string& operation, const std::string& param1, const std::string& param2)
{
    if (operation.starts_with("ADD"))
    {
        map[param1].push_back(param2);
        map[param2].push_back(param1);
    }
    else if (operation.starts_with("COUNT"))
    {
        std::cout << map[param1].size() << std::endl;
    }
    else if (operation.starts_with("CHECK"))
    {
        for (const auto& vec_elem : map[param1])
        {
            if (vec_elem == param2)
            {
                std::cout << "YES" << std::endl;
                return;
            }
        }
        std::cout << "NO" << std::endl;
    }
}

int main()
{
    int requests_count;
    std::cin >> requests_count;
    map.reserve(requests_count);
    for (size_t i = 0; i < requests_count; ++i)
    {
        std::string operation;
        std::cin >> operation;

        std::string param1;
        std::cin >> param1;

        std::string param2;
        if (operation != "COUNT")
            std::cin >> param2;

        execute_operation(operation, param1, param2);
    }
}