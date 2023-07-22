class Derived : public Base
{
    private:
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
            std::vector<std::pair<int, std::string>> fvfcopy = find_virtual_functions("Base.hpp");
            
            GetVTablePointer()->SetTypeInfo(tobjD);//like index 0

            for (int i = 0; i < fvfcopy.size(); i++)
            {
                if (fvfcopy[i].second == "Function1Impl")  //ibr compillern a anum
                {
                    GetVTablePointer()->AddFunction(1, [this](){ Function1Impl(); }); // second argument creates function object with labda functon, 
                }

                else  if (fvfcopy[i].second == "Function2Impl")  //ibr compillern a anum
                {
                    GetVTablePointer()->AddFunction(2, [this](){ Function2Impl(); }); // labda function calls this->FunctionImpl()
                }
                

            }
        }

};
