#ifndef HELPER_H
#define HELPER_H
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <map>
class Helper {
public:
    std::string get_info (std::vector<std::string>& vec, std::vector<std::string>::iterator it, const char*);
    bool check_file(const std::string& str, const std::string&);
    void check_errors(const std::vector<std::string>&);
    std::string toUpperCase(std::string );
    static bool check_opeation(const std::string&);
    void line_cutter(std::string&);
    std::vector<std::string> parser(const std::string& str, std::string& spliter);
    void check_task_errors(const std::vector<std::string>&);
};

#endif // HELPER_H
