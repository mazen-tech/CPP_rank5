#include "../header/C.hpp"


C::C(void) {}

C::C(const C &copy) { *this = copy; }

C::~C() {}

C &C::operator=(const C&) {return (*this); }