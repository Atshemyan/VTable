#include <iostream>
#include "TypeInfo.hpp"
#include <map>
#include <functional>
#include <fstream>
#include <vector>
#include <utility>

std::vector<std::pair<int, std::string>> find_virtual_functions(const std::string& filename)
{
    std::ifstream file(filename);
    std::vector<std::pair<int, std::string>> functions;
    std::string line;
    int VirtualIndex = 0;
    while (std::getline(file, line))
    {
        if (line.find("/*virtual*/") != std::string::npos)
        {
            VirtualIndex++;
            size_t function_start = line.rfind(' ', line.find('('));
            std::string function_name = line.substr(function_start + 1, line.find('(') - function_start - 1);
            functions.push_back(std::make_pair(VirtualIndex, function_name));
        }
    }
    return functions;
}


class VTable
{
public:
    VTable()
    {
        
    }

    void AddFunction(int index, std::function<void()> func)
    {
        m_functions[index] = func;
    }

    void CallFunction(int index)
    {
        auto iter = m_functions.find(index);
        iter->second(); 
    }
    
private:
    std::map<int, std::function<void()>> m_functions;
};