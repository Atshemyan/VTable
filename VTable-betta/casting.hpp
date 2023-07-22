template<typename T1 , typename T2>
T2* my_dynamic_cast(T1* base, T2* derived)
{
    if (base->GetVPtr()->GetTypeInfo().CurrentClassName == derived->GetVPtr()->GetTypeInfo().BaseClassName)
    {
        return static_cast<T2*>(base);
    }
    

    return nullptr;
    
}