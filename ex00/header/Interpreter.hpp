#pragma once

#include <iostream>
#include <iomanip>
#include <sstream>
#include <cctype>
#include <string>
#include <cmath>
#include <limits>

class Interpreter
{
private:
    /* data */
    Interpreter(/* args */);
    std::string str;
    int type;

    int status[4];
    int ivalue;
    float fvalue;
    double dvalue;
    char cvalue;

    void parse(void);
    void convert(void);
    void fromInt(void);
    void fromFloat(void);
    void fromDouble(void);
    void fromChar(void);

    void setFlag(int status, int flag);

    enum Type
    {
        TypeINT,
        TypeCHAR,
        TypeFLOAT,
        TypeDOUBLE,
        TypeLONG,
        TypeINVALID
    };

    public:
        Interpreter(std::string const &value);
        Interpreter(Interpreter const &copy);
        virtual ~Interpreter();

        static const int isImpossible = 0x00000001;
        static const int nonDisplayable = 0x00000010;

        Interpreter &operator=(Interpreter const &copy);

        bool FloatIsValue(void) const;
        bool doubleIsValue(void) const;
        bool hasFlag(int status, int flag) const;

        int getAsInt(void) const;
        float getAsFloat(void) const;
        double getAsDouble(void) const;
        char getAsChar(void) const;
        std::string const &getRaw(void) const;
};

std::ostream &operator<<(std::ostream &out, Interpreter const &b); 