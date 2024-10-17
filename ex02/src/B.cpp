#include "../header/B.hpp"

B::B(void) {}

B::B(const B &copy) { *this = copy; }

B::~B() {}

B &B::operator=(const B&) {return (*this); }