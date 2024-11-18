#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <string>

std::unordered_map<std::string, std::unordered_set<std::string>> map;
std::unordered_map<std::string, int> counter;

int main()
{
    int request_count;
    std::cin >> request_count;

    for (size_t i = 0; i < request_count; i++)
    {
        std::string operation;
        std::cin >> operation;

        std::string param1;
        std::cin >> param1;

        if (operation == "ADD")
        {
            std::string param2;
            std::cin >> param2;

            map[param1].insert(param2);

            if (map.count(param2) == 0 ||
                (map.count(param2) > 0 && map[param2].count(param1) == 0))
            {
                ++counter[param1];
                ++counter[param2];
            }

            continue;
        }
        else if (operation == "CHECK")
        {
            std::string param2;
            std::cin >> param2;

            if ((map.count(param1) > 0 && map[param1].count(param2) > 0) ||
                (map.count(param2) > 0 && map[param2].count(param1) > 0))
            {
                std::cout << "YES" << std::endl;
            }
            else
            {
                std::cout << "NO" << std::endl;
            }
        }
        else // if (operation == "COUNT")
        {
            if (counter.count(param1) > 0)
            {
                std::cout << counter[param1] << std::endl;
            }
            else
            {
                std::cout << 0 << std::endl;
            }
        }
    }
}