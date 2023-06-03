class Base
{
    public:
        Base() : m_vtable(new VTable())
        {
            m_vtable->AddFunction(1, [this](){ Function1Impl(); }); // second argument creates function object with labda functon,                                                        
            m_vtable->AddFunction(2, [this](){ Function2Impl(); }); // labda function calls this->FunctionImpl()
        }

        /*virtual*/ void Function1()
        {
            m_vtable->CallFunction(1);
        }

        /*virtual*/ void Function2()
        {
            m_vtable->CallFunction(2);
        }

        void Function1Impl()
        {
            std::cout << "Base::Function1Impl()" << std::endl;
        }

        void Function2Impl()
        {
            std::cout << "Base::Function2Impl()" << std::endl;
        }

        virtual ~Base()
        {
            delete m_vtable;
        }
    protected:
        VTable* m_vtable;
};