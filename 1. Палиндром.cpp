#include <string>

bool IsPalindrom(std::string str)
{
    int rIndex = str.size() - 1;
    for (int i = 0; i < str.size(); ++i, --rIndex)
        if(str[i] != str[rIndex])
            return false;
    
    return true;
}