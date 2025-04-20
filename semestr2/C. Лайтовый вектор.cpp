#include <iostream>
#include <stdexcept>

template <typename T, size_t N>
class LightVector
{
public:
    explicit LightVector(size_t a_size = 0)
    {
        if (a_size > m_capacity)
        {
            throw std::invalid_argument("std::invalid_argument");
        }
        
        m_size = a_size;
    }

    T &operator[](size_t index)
    {
        return m_data[index];
    }
    
    const T &operator[](size_t index) const
    {
        return m_data[index];
    }

    T* begin()
    {
        return m_data;
    }
    
    T* end()
    {
        return m_data + m_size;
    }
    
    const T* begin() const
    {
        return m_data;
    }
    
    const T* end() const
    {
        return m_data + m_size;
    }

    size_t Size() const
    {
        return m_size;
    }
    
    size_t Capacity() const
    {
        return m_capacity;
    }

    void PushBack(const T &value)
    {
        if (m_size == m_capacity)
        {
            throw std::overflow_error("std::overflow_error");
        }
        
        *end() = value;
        m_size++;
    }
    
    T PopBack()
    {
        if (m_size == 0)
        {
            throw std::underflow_error("std::underflow_error");
        }
        
        m_size--;
        return *end();
    }
    
private:
    size_t m_size = 0;
    size_t m_capacity = N;
    T m_data[N];
};

int main()
{
    LightVector<int, 3> vec(0);
    vec.PushBack(1);
    vec.PushBack(2);
    vec.PushBack(3);
    
    std::cout << vec.PopBack() << std::endl;
    std::cout << vec.PopBack() << std::endl;
    std::cout << vec.PopBack() << std::endl;
}