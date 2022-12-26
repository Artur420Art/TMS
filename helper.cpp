#include "helper.h"
bool Helper::check_opeation(const std::string& op)
{
    return ((op == "name") || (op == "surname") || (op == "email"));
}
void Helper::line_cutter(std::string& line)
{

   auto li = line.find(':');
   auto beg = line.begin();
   line.erase(beg + line.find(' '));
   line.erase(beg + line.find(' '));
   line.erase (beg, beg + li);

}
std::string Helper::toUpperCase(std::string  s)
{
    std::string str;
    int size = s.size();
    for (int i = 0; i < size; ++i) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] += 32;
        }
    }
    str = s;
    return str;
}
std::vector<std::string> Helper::parser(const std::string& str, std::string& spliter)
{
    std::vector<std::string> nstr = {};
    std::string tstr = {};
    int size = str.size();
    for (int i = 0; i < size; ++i)
    {
        if (spliter.find(str[i]) != std::string::npos)
        {
            if (tstr != "")
            {
                nstr.push_back(tstr);
                tstr.clear();
                continue;
            }
            continue;
        }
        tstr.push_back(str[i]);
    }
    nstr.push_back(tstr);
    return nstr;
}
void Helper::check_errors(const std::vector<std::string>& vec)
{
    int count = 0;
    int size = vec.size();
    for (int i = 0; i < size; ++i)
    {
       std::string str =  toUpperCase(vec[i]);

        if (str == "name" || str == "surname" || str == "email" )
        {
            ++count;
        }

    }
    if (count != 3)
    {
        throw std::invalid_argument("Please enter a Name, Surname and Email");
    }
}
void Helper::check_task_errors(const std::vector<std::string>& vec)
{
    int count = 0;
    int size = vec.size();
    for (int i = 0; i < size; ++i)
    {
        std::string str = toUpperCase(vec[i]);

        if (str == "name" || str == "user"  || str == "project")
        {
            ++count;
        }

        }
    if (count != 3)
    {
        throw std::invalid_argument("Please enter a Task name, User email and Project name");
    }
}

