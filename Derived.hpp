class Derived : public Base
{
    private:
        VTable* m_copy_of_base_ptr = GetVTablePointer();
        void Function1Impl()
        {
            std::cout << "Derived::Function1Impl()" << std::endl;
        }

        void Function2Impl()
        {
            std::cout << "Derived::Function2Impl()" << std::endl;
        }
    public:
        Derived()
        {
            
            SetVTablePointer(new VTable);
            TypeInfo tobjD;
            tobjD.CurrentClassName = "Derived";
            tobjD.BaseClassName = "Base";
            GetVTablePointer()->AddFunction(0, [tobjD](){ TypeInfo();});
            GetVTablePointer()->AddFunction(1, [this](){ Function1Impl(); }); // second argument creates function object with labda functon, 
            GetVTablePointer()->AddFunction(2, [this](){ Function2Impl(); }); // labda function calls this->FunctionImpl()
        }

        ~Derived()
        {
            delete m_copy_of_base_ptr;
            m_copy_of_base_ptr = nullptr;
        }

};
