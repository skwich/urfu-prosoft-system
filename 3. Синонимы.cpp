#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <string>
#include <set>

std::unordered_map<std::string, std::set<std::string>> map;

enum ANSWER{
    YES = -1,
    NO = -2,
    ADD = -3
};

int func(const std::string& operation, const std::string& param1, const std::string& param2)
{
    // int request_count;
    // std::cin >> request_count;

    // for (size_t i = 0; i < request_count; ++i)
    {
        // std::string operation;
        // std::cin >> operation;

        // std::string param1;
        // std::cin >> param1;

        if (operation == "ADD")
        {
            // std::string param2;
            // std::cin >> param2;

            map[param1].(param2);
            map[param2].push_back(param1);
            return ANSWER::ADD;
        }
        else if (operation == "CHECK")
        {
            // std::string param2;
            // std::cin >> param2;

            if (std::find(map[param1].begin(), map[param1].end(), param2) != map[param1].end() ||
                std::find(map[param2].begin(), map[param2].end(), param1) != map[param2].end())
            {
                // std::cout << "YES" << std::endl;
                return ANSWER::YES;
            }
            else
            {
                // std::cout << "NO" << std::endl;
                return ANSWER::NO;
            }
        }
        else // if (operation == "COUNT")
        {
            // std::cout << map[param1].size() << std::endl;
            return map[param1].size();
        }
    }
}

std::string test(const std::string &operation, const std::string &param1, const std::string &param2, int answer = ANSWER::ADD)
{
    if (answer == func(operation, param1, param2))
    {
        return "ok!\n";
    }
    else
    {
        return "WRONG ANSWER!\n";
    }
}

int main()
{
    int i = 76;
    std::cout << "test " << ++i << ": " << test("ADD", "code", "cpp");
    std::cout << "test " << ++i << ": " << test("CHECK", "code", "cpp", ANSWER::YES);
    std::cout << "test " << ++i << ": " << test("CHECK", "cpp", "code", ANSWER::YES);
    std::cout << "test " << ++i << ": " << test("COUNT", "code", "", 1);
    std::cout << "test " << ++i << ": " << test("COUNT", "cpp", "", 1);
    std::cout << "test " << ++i << ": " << test("COUNT", "TRASH", "", 0);
    std::cout << "test " << ++i << ": " << test("CHECK", "cpp", "TRASH", ANSWER::NO);
    std::cout << "test " << ++i << ": " << test("CHECK", "code", "TRASH", ANSWER::NO);
    std::cout << "test " << ++i << ": " << test("CHECK", "TRASH", "code", ANSWER::NO);
    std::cout << "test " << ++i << ": " << test("CHECK", "TRASH", "cpp", ANSWER::NO);
    std::cout << "test " << ++i << ": " << test("ADD", "code", "java");
    std::cout << "test " << ++i << ": " << test("COUNT", "code", "", 2);
    std::cout << "test " << ++i << ": " << test("ADD", "code", "python");
    std::cout << "test " << ++i << ": " << test("COUNT", "code", "", 3);
    std::cout << "test " << ++i << ": " << test("CHECK", "python", "code", ANSWER::YES);
    std::cout << "test " << ++i << ": " << test("COUNT", "", "", 0);
    std::cout << "test " << ++i << ": " << test("ADD", "cpp", "code");
    std::cout << "test " << ++i << ": " << test("ADD", "cpp", "code");
    std::cout << "test " << ++i << ": " << test("CHECK", "cpp", "code", ANSWER::YES);
}