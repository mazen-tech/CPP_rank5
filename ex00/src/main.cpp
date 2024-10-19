#include "../header/whatever.hpp"
# include <string>

int main ()
{
    int a, b;
    char c, d;
    float x, y;
    std::string s, ss;

    a = 1;
	b = 2;
	c = 4.2f;
	d = 42.21f;
	x = 'x';
	y = 'y';
	s = "string1";
	ss = "string2";

    std::cout << "####test swap function#####\n";
    std::cout << "a: " << a << " and b: " << b << std::endl;
	std::cout << "c: " << c << " and d: " << d << std::endl;
	std::cout << "x: " << x << " and y: " << y << std::endl;
	std::cout << "s: " << s << " and s: " << ss << std::endl;

    std::cout << "####AFTER#####\n";
    ::swap(a, b);
	::swap(c, d);
	::swap(x, y);
	::swap(s, ss);
    std::cout << "a: " << a << " and b: " << b << std::endl;
	std::cout << "c: " << c << " and d: " << d << std::endl;
	std::cout << "x: " << x << " and y: " << y << std::endl;
	std::cout << "s: " << s << " and s: " << ss << std::endl;

    std::cout << "\nLet's find the mins and maxs...\n" << std::endl;
	std::cout << "min(a, b): " << ::min(a, b) << std::endl;
	std::cout << "max(a, b): " << ::max(a, b) << std::endl;
	std::cout << "min(c, d): " << ::min(c, d) << std::endl;
	std::cout << "max(c, d): " << ::max(c, d) << std::endl;
	std::cout << "min(x, y): " << ::min(x, y) << std::endl;
	std::cout << "max(x, y): " << ::max(x, y) << std::endl;
	std::cout << "min(s, ss): " << ::min(s, ss) << std::endl;
	std::cout << "max(s, ss): " << ::max(s, ss) << std::endl;



}