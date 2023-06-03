class Derived : public Base {
public:
    Derived()
    {
        m_vtable->AddFunction(1, [this](){ Function1Impl(); }); // second argument creates function object with labda functon, 
        m_vtable->AddFunction(2, [this](){ Function2Impl(); }); // labda function calls this->FunctionImpl()
    }

    void Function1Impl()
    {
        std::cout << "Derived::Function1Impl()" << std::endl;
    }

    void Function2Impl()
    {
        std::cout << "Derived::Function2Impl()" << std::endl;
    }
};
