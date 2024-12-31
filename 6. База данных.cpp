#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#include <iomanip>
#include <vector>
#include <set>
#include <map>

class Date;
Date get_date(std::string &date);
void check_valid_date(const Date &date);

class Date
{
public:
    Date(int year, int month, int day)
        : m_year(year), m_month(month), m_day(day)
    {
    }

    int GetYear() const
    {
        return m_year;
    }

    int GetMonth() const
    {
        return m_month;
    }

    int GetDay() const
    {
        return m_day;
    }

private:
    int m_year;
    int m_month;
    int m_day;
};

bool operator<(const Date &lhs, const Date &rhs)
{
    return std::vector<int>({lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()}) < std::vector<int>({rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()});
}

class Database
{
public:
    void AddEvent(const Date &date, const std::string &event)
    {
        map[date].insert(event);
    }

    bool DeleteEvent(const Date &date, const std::string &event)
    {
        if (map.count(date) == 0 || map[date].count(event) == 0)
        {
            return false;
        }

        map[date].erase(event);
        return true;
    }

    int DeleteDate(const Date &date)
    {
        int event_count = 0;
        if (map.count(date) > 0)
        {
            event_count = map[date].size();
            map.erase(date);
        }

        return event_count;
    }

    std::set<std::string> Find(const Date &date) const
    {
        std::set<std::string> set;
        if (map.count(date) > 0)
        {
            set = map.at(date);
        }

        return set;
    }

    void Print() const
    {
        for (const auto &[date, set] : map)
        {
            for (const auto &event : set)
            {
                std::cout << std::setfill('0')
                          << std::setw(4) << date.GetYear() << '-'
                          << std::setw(2) << date.GetMonth() << '-'
                          << std::setw(2) << date.GetDay() << ' '
                          << event << std::endl;
            }
        }
    }

private:
    std::map<Date, std::set<std::string>> map;
};

int main()
{
    Database db;

    std::string commandLine;
    try
    {
        while (std::getline(std::cin, commandLine))
        {
            if (commandLine.empty())
            {
                continue;
            }

            std::stringstream stream(commandLine);
            std::string command;
            std::string str_date;
            std::string event;

            stream >> command;

            if (stream >> str_date)
            {
                Date date = get_date(str_date);
                check_valid_date(date);

                if (command == "Add")
                {
                    stream >> event;
                    db.AddEvent(date, event);
                }
                else if (command == "Del")
                {
                    if (stream >> event)
                    {
                        if (db.DeleteEvent(date, event))
                        {
                            std::cout << "Deleted successfully" << std::endl;
                        }
                        else
                        {
                            std::cout << "Event not found" << std::endl;
                        }
                    }
                    else
                    {
                        int count = db.DeleteDate(date);
                        std::cout << "Deleted " << count << " events" << std::endl;
                    }
                }
                else if (command == "Find")
                {
                    std::set<std::string> set = db.Find(date);
                    for (const auto &elem : set)
                    {
                        std::cout << elem << std::endl;
                    }
                }
            }
            else if (command == "Print")
            {
                db.Print();
            }
            else
            {
                std::cout << "Unknown command: " << command << std::endl;
            }
        }
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    

    return 0;
}

Date get_date(std::string &date)
{
    std::stringstream stream(date);
    int year;
    int month;
    int day;
    char delim;
    if (!(stream >> year >> delim >> month >> delim >> day) || delim != '-' || stream.peek() != EOF)
    {
        throw std::invalid_argument("Wrong date format: " + date);
    }
    return Date(year, month, day);
}

void check_valid_date(const Date &date)
{
    if (date.GetMonth() < 1 || date.GetMonth() > 12)
    {
        throw std::invalid_argument("Month value is invalid: " + std::to_string(date.GetMonth()));
    }

    if (date.GetDay() < 1 || date.GetDay() > 31)
    {
        throw std::invalid_argument("Day value is invalid: " + std::to_string(date.GetDay()));
    }
}