class VTable {
public:
    VTable() {}

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