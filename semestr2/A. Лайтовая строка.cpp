#include <iostream>
#include <cstring>
#include <algorithm>

class LightString
{
public:
    LightString() = default;
    LightString(const char *tmp)
    {
        size = strlen(tmp);
        str = new char[size + 1];
        strcpy(str, tmp);
    }

    ~LightString()
    {
        delete[] str;
    }

    char &operator[](size_t pos)
    {
        return str[pos];
    }

    const char &operator[](size_t pos) const
    {
        return str[pos];
    }

    char &at(size_t pos)
    {
        if (pos >= size)
        {
            throw std::out_of_range("index out of range");
        }

        return str[pos];
    }

    const char &at(size_t pos) const
    {
        if (pos >= size)
        {
            throw std::out_of_range("index out of range");
        }

        return str[pos];
    }

    LightString(const LightString &other)
    {
        size = other.size;
        str = new char[size + 1];
        strcpy(str, other.str);
    }

    LightString &operator=(const LightString &other)
    {
        if (this != &other)
        {
            swap(other);
        }

        return *this;
    }

    bool operator==(const LightString &other) const noexcept
    {
        return size == other.size && std::equal(str, str + size, other.str);
    }

    bool operator!=(const LightString &other) const noexcept
    {
        return !(*this == other);
    }

    bool operator<(const LightString &other) const noexcept
    {
        return std::lexicographical_compare(str, str + size, other.str, other.str + other.size);
    }

    bool operator>(const LightString &other) const noexcept
    {
        return !(*this < other) && *this != other;
    }

    size_t Size() const noexcept
    {
        return size;
    }

    void Clear() noexcept
    {
        delete[] str;
        str = nullptr;
        size = 0;
    }

    const char *C_str() const noexcept
    {
        return str;
    }

private:
    void swap(LightString copy)
    {
        std::swap(str, copy.str);
        std::swap(size, copy.size);
    }

private:
    size_t size = 0;
    char *str = nullptr;
};