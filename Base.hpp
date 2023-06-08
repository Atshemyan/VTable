class Base
{
    private:
        VTable* m_vtable_p;
        /*virtual*/ void Function1Impl()
        {
            std::cout << "Base::Function1Impl()" << std::endl;
        }

        /*virtual*/ void Function2Impl()
        {
            std::cout << "Base::Function2Impl()" << std::endl;
        }

    protected:
        VTable* GetVTablePointer()
        {
            return m_vtable_p;
        }

        void SetVTablePointer(VTable* vtable)
        {
            m_vtable_p = vtable;
        }
    public:
        Base() : m_vtable_p(new VTable)
        {
            TypeInfo tobj;
            tobj.CurrentClassName = "Base";
            tobj.BaseClassName = "";
            std::vector<std::pair<int, std::string>> fvfcopy = find_virtual_functions("Base.hpp");
            
            m_vtable_p->AddFunction(0, [tobj](){ TypeInfo();});

            for (int i = 0; i < fvfcopy.size(); i++)
            {
                if (fvfcopy[i].second == "Function1Impl")  //ibr compillern a anum
                {
                    m_vtable_p->AddFunction(fvfcopy[i].first, [this](){ Function1Impl(); });        
                }

                else  if (fvfcopy[i].second == "Function2Impl")  //ibr compillern a anum
                {
                    m_vtable_p->AddFunction(fvfcopy[i].first, [this](){ Function2Impl(); });                                                      
                }
                

            }

        }

        void Function1()
        {
            m_vtable_p->CallFunction(1);
        }

        void Function2()
        {
            m_vtable_p->CallFunction(2);
        }
        
        virtual ~Base()
        {
            if (m_vtable_p != nullptr)
            {
                delete m_vtable_p; 
            }
            
        }
    
};