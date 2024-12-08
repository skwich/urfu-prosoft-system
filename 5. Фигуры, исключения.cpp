#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>
#include <cmath>

class Figure {
public:
    virtual std::string Name() const = 0;
    virtual double Perimeter() const = 0;
    virtual double Area() const = 0;
    virtual ~Figure() = default;
};

class Rect : public Figure
{
public:
    Rect(double width, double height)
        : width(width), height(height) {}

    std::string Name() const override
    {
        return "RECT";
    }

    double Perimeter() const override
    {
        return 2 * (width + height);
    }

    double Area() const override
    {
        return width * height;
    }

private:
    double width;
    double height;
};

class Triangle : public Figure
{
public:
    Triangle(double a, double b, double c)
        : a(a), b(b), c(c) {}

    std::string Name() const override
    {
        return "TRIANGLE";
    }

    double Perimeter() const override
    {
        return a + b + c;
    }

    double Area() const override
    {
        double s = (a + b + c) / 2;
        return std::sqrt(s * (s-a) * (s-b) * (s-c));
    }

private:
    double a;
    double b;
    double c;
};

class Circle : public Figure
{
public:
    Circle(double r)
        : r(r) {}

    std::string Name() const override
    {
        return "CIRCLE";
    }

    double Perimeter() const override
    {
        return 2 * PI * r;
    }

    double Area() const override
    {
        return PI * r * r;
    }

private:
    double r;
    double PI = 3.14;
};

std::shared_ptr<Figure> CreateFigure(std::istringstream& is)
{
    std::string figure;
    is >> figure;

    if (figure == "RECT")
    {
        double width;
        double height;
        is >> width >> height;

        return std::make_shared<Rect>(width, height);
    }
    else if (figure == "TRIANGLE")
    {
        double a;
        double b;
        double c;
        is >> a >> b >> c;

        return std::make_shared<Triangle>(a, b, c);
    }
    else if (figure == "CIRCLE")
    {
        double r;
        is >> r;

        return std::make_shared<Circle>(r);
    }

    throw std::runtime_error("Wrong figure name");
}

int main()
{
    std::vector<std::shared_ptr<Figure>> figures;
    for (std::string line; std::getline(std::cin, line);)
    {
        std::istringstream is(line);

        std::string command;
        is >> command;
        if (command == "ADD")
        {
            // Файловый манипулятор для пропуска ведущих пробелов
            // https://en.cppreference.com/w/cpp/io/manip/ws
            is >> std::ws;
            try
            {
                figures.push_back(CreateFigure(is));
            }
            catch (const std::runtime_error &e)
            {
                std::cout << e.what() << std::endl;
            }
        }
        else if (command == "PRINT")
        {
            for (const auto &current_figure : figures)
            {
                std::cout << std::fixed << std::setprecision(3)
                          << current_figure->Name() << " "
                          << current_figure->Perimeter() << " "
                          << current_figure->Area() << std::endl;
            }
        }
    }
    return 0;
}