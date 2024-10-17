#include "../header/Data.hpp"

/*serialize, converts a pointer of type
 Data* to an unsigned integer type (uintptr_t) 
 using reinterpret_cast*/
uintptr_t serialize(t_Data *ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
    //converting from pointer to unsigned int using "reinterpret_cast"
    /*NOTE## we were using static_cast<data type>(variable)
    to convert from flout to double to int to char etc*/
}

/*now doing the same but reversed from uintptr -> pointer*/
t_Data *deserialize(uintptr_t rev)
{
    return (reinterpret_cast<t_Data *>(rev));
}

int main()
{
    
    t_Data *ptr;
    t_Data *test_ptr;
    uintptr_t rev;

    ptr = new t_Data;
    ptr->Data = "trolling on pointers";

    rev = serialize(ptr);
    test_ptr = deserialize(rev);

    std::cout << "Data of ptr: " << ptr->Data << std::endl;
    std::cout << "Data of test_ptr: " << test_ptr->Data << std::endl;
    return (0);
}