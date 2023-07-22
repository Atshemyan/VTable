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
            
            m_vtable_p->SetTypeInfo(tobj); //like 0 index
            m_vtable_p->AddFunction(1, [this](){ Function1Impl(); });        
            m_vtable_p->AddFunction(2, [this](){ Function2Impl(); });                                                      
                

        }
        VTable* GetVPtr() const
        {
            return m_vtable_p;
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