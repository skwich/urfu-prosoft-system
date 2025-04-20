template <int N>
struct factorial_calc
{
    static constexpr unsigned long long value()
    {
        return factorial_calc<N - 1>::value() * N;
    }
};

template <>
struct factorial_calc<1>
{
    static constexpr unsigned long long value()
    {
        return 1;
    }
};

template <>
struct factorial_calc<0>
{
    static constexpr unsigned long long value()
    {
        return 1;
    }
};