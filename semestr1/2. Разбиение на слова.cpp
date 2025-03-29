#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::vector<std::string> SplitIntoWords(const std::string& str)
{
    std::vector<std::string> vec;

    if (str.length() == 0 || std::all_of(str.begin(), str.end(), isspace))
    {
        return vec;
    }

    if (std::none_of(str.begin(), str.end(), isspace))
    {
        vec.push_back(str);
    }
    else
    {
        size_t pos = 0;
        size_t space_index = str.find(' ');
        while (space_index != std::string::npos)
        {
            if (str[pos] != ' ')
            {
                vec.push_back(str.substr(pos, space_index - pos));
            }

            pos = space_index + 1;
            space_index = str.find(' ', pos);
        }

        if (str[pos] != ' ' && pos != str.length())
        {
            vec.push_back(str.substr(pos));
        }
    }

    return vec;
}

bool test(const std::string& input, std::vector<std::string> result)
{
    std::vector<std::string> vec = SplitIntoWords(input);

    if (vec.size() != result.size())
    {
        return false;
    }

    for (size_t i = 0; i < vec.size(); ++i)
    {
        if (vec[i] != result[i])
        {
            return false;
        }
    }

    return true;
}

void print(int n, const std::string& input, std::vector<std::string> result)
{
    std::cout << "Test " << n << ": ";
    if (test(input, result))
    {
        std::cout << "OK!" << std::endl;
    }
    else
    {
        std::cout << "Wrong Answer!" << std::endl;
    }
}

int main()
{
    print(
        1,
        "Hello world! Welcome to C++ programming.",
        {"Hello", "world!", "Welcome", "to", "C++", "programming."}
        );

    print(
        2,
        "",
        {}
        );

    print(
        3,
        " ",
        {}
        );

    print(
        4,
        "hello ",
        {"hello"}
        );

    print(
        5,
        " hello",
        {"hello"}
        );

    print(
        6,
        " hello ",
        {"hello"}
        );

    print(
        7,
        "   hello",
        {"hello"}
        );

    print(
        8,
        "hello   ",
        {"hello"}
        );

    print(
        9,
        "   hello   ",
        {"hello"}
        );

    print(
        10,
        "hello  world",
        {"hello", "world"}
        );

    print(
        11,
        "hello   world",
        {"hello", "world"}
        );

    print(
        12,
        "helloworld",
        {"helloworld"}
        );
}
