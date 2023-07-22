#include "VTable.hpp"
#include "Base.hpp"
#include "Derived.hpp"
#include "casting.hpp"
int main()
{
    Base* obj = new Derived();
    
    try
    {
        //Client code start

        obj->Function1();
        obj->Function2();

        //Client code end
    }

    catch(const std::exception& e)
    {
        obj = new Base();
        obj->Function1();
        obj->Function2();
    }
    
    delete obj;
    return 0;
}
