#include "../header/A.hpp"

A::A(void) {}

A::A(const A &copy) { *this = copy; }

A::~A() {}

A &A::operator=(const A&) {return (*this); }