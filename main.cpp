#include "VTable.hpp"
#include "Base.hpp"
#include "Derived.hpp"
int main()
{
    Base* obj = new Derived();
    obj->Function1();
    obj->Function2();
    
   
    
    delete obj;

    return 0;
}
