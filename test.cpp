#include <unordered_map>
#include <iostream>
#include <string>

int main()
{
    std::unordered_multimap<std::string, std::string> map = {
        {"1", "1"},
        {"1", "2"},
        {"1", "3"},
        {"2", "1"},
    };

    auto range = map.equal_range("2");
    for (auto it = range.first; it != range.second; ++it)
    {
        if (it->second == "1")
        {
            std::cout << "found!" << std::endl;
        }
    }
}