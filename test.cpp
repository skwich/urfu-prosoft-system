#include <unordered_map>
#include <vector>
#include <iostream>
#include <string>

void print_vector(std::vector<std::string> vec)
{
    for (const auto& it : vec)
    {
        std::cout << it << ", ";
    }
}

void print_map(const std::unordered_map<std::string, std::vector<std::string>>& map)
{
    for (const auto& [key, value] : map)
    {
        std::cout << "first: " << key
                  << " second: ";
        print_vector(value);
        std::cout << std::endl;
    }
}

void print_map(const std::unordered_map<std::string, std::string>& map)
{
    for (const auto& it : map)
    {
        std::cout << "first: " << it.first
                  << " second: " << it.second
                  << std::endl;
    }
}

int main()
{
    // std::unordered_map<std::string, std::vector<std::string>> map;
    // map["code"].push_back("cpp");
    // map["code"].push_back("java");
    // map["code"].push_back("python");

    std::unordered_map<std::string, std::string> map;
    // std::cout << map["code"].size() << std::endl;
    map["program"] += "code,";
    map["program"] += "ded,";
    std::cout << map["program"] << std::endl;
    // std::cout << map["program"].append("dad") << std::endl;
    // map["program"].append(",dad");
    // map["program"].append(",dad");
    // std::cout << map.at("program") << std::endl;
    print_map(map);
}