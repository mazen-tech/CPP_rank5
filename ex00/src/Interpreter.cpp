#include "../header/Interpreter.hpp"

Interpreter::Interpreter(std::string const &value) : str(value), type(TypeINVALID)
{
    for (int i = 0; i < 4; i++)
        this->status[i] = 0;
    this->parse();
    if (this->type != TypeINVALID)
    {
        this->convert();
        if (this->hasFlag(TypeINT, this->isImpossible) || this->ivalue > 127 || this->ivalue < 0)
            this->setFlag(TypeCHAR, this->isImpossible);
        
        if (!std::isprint(this->cvalue))
            this->setFlag(TypeCHAR, this->nonDisplayable);
    }

    else
    {
        this->setFlag(TypeINT, this->isImpossible);
        this->setFlag(TypeFLOAT, this->isImpossible);
        this->setFlag(TypeDOUBLE, this->isImpossible);
        this->setFlag(TypeCHAR, this->isImpossible);
    }
}

Interpreter::Interpreter(Interpreter const &copy) : 
str(copy.str), type(copy.type), ivalue(copy.ivalue),
fvalue(copy.fvalue), dvalue(copy.dvalue), cvalue(copy.cvalue)
{
    for (int i = 0; i < 4; i++)
        this->status[i]  = copy.status[i];
}

Interpreter::~Interpreter()
{
}


/*
void parse(void);
void convert(void);
void fromInt(void);
void fromFloat(void);
void fromDouble(void);
void fromChar(void);
*/

/*here we are interorets the string input and determine it's type, such as 
int float double etc.. */
void Interpreter::parse(void)
{
    std::stringstream ss;
    size_t len = this->str.length();
    size_t i = 0;

    //if str consist of 1 element and this element is not digit so asign the type char
    if (len == 1 && !std::isdigit(this->str[0]))
    {
        this->type = TypeCHAR;
        this->cvalue = this->str[0];
        return ;
    }

    if (this->str[0] == '+' || this->str[0] == '-')
        ss << str[i++];
    this->type = TypeINT;

    /*scanning the string input and detecting invalied chars and updating type*/
    for ( ; i < len; i++)
    {
        if (this->str[i] == '.' && this->type != TypeDOUBLE)
        {
            this->type = TypeDOUBLE;
            ss << str[i];
        }

        else if (this->str[i] == 'e' && i < len - 1 
        && (this->str[i + 1] == '-' || this->str[i + 1] == '+' || std::isdigit(this->str[i + 1])))
        {
            ss << str[i] << str[i + 1];
            i++;
            this->type = TypeDOUBLE;
        }

        else if (this->str[i] == 'f' && i == len - 1 && this->type == TypeDOUBLE)
            this->type = TypeFLOAT;

        else if (!std::isdigit(this->str[i]))
        {
            this->type = TypeINVALID;
            i = len;
        }

        else 
            ss << str[i];
    }

    if (this->type == TypeFLOAT)
        ss >> this->fvalue;
    else if (this->type == TypeDOUBLE)
        ss >> this->dvalue;
    else if (this->type == TypeINT)
    {
        long Ivalue;
        ss >> Ivalue;
        this->ivalue = Ivalue;
        if (ss.fail()
            || Ivalue > std::numeric_limits<int>::max()
            || Ivalue < std::numeric_limits<int>::min())
            this->type = TypeINVALID;
    }
    /*
    inff, +inff, -inff appreviation for infinity in the float data type
    nanf not_a_Number i.g 0/0
    */
    else if (this->type == TypeINVALID)
    {
        if (this->str == "inff" || this->str == "-inff" || this->str == "+inff"
            || this->str == "nanf")
        {
            /*converting string to floar using atof() and converting the string to c_style "Null termenator"*/
            this->fvalue = atof(this->str.c_str());
            this->type = TypeFLOAT;
        }
        else if (this->str == "inf" || this->str == "-inf" || this->str == "+inf" || this->str == "nan")
        {
            this->dvalue = atof(this->str.c_str());
            this->type = TypeDOUBLE;
        }
    }

}

void Interpreter::convert(void)
{
    switch (this->type)
    {
    case TypeINT:
        this->fromInt();
        break;
    
    case TypeCHAR:
        this->fromChar();
        break;
    
    case TypeDOUBLE:
        this->fromDouble();
        break;
    
    case TypeFLOAT:
        this->fromFloat();
        break;
    }
}

void Interpreter::fromInt(void)
{
    this->fvalue = static_cast<float>(this->ivalue);
    this->dvalue = static_cast<double>(this->ivalue);
    this->cvalue = static_cast<char>(this->ivalue);
}

bool Interpreter::FloatIsValue(void) const
{
    return (!(std::isnan(this->fvalue) || std::isinf(this->fvalue)));
    /*isnan -> checks if is number isinf -> checks if is infinty*/
}

bool Interpreter::doubleIsValue(void) const
{
    return (!(std::isnan(this->dvalue) || std::isinf(this->dvalue)));
}

void Interpreter::fromFloat(void)
{
    this->ivalue = static_cast<int>(this->fvalue);
    this->dvalue = static_cast<double>(this->fvalue);
    this->cvalue = static_cast<char>(this->fvalue);
    if (!this->FloatIsValue() || this->fvalue > std::numeric_limits<int>::max()
    || this->fvalue < std::numeric_limits<int>::min())
    this->setFlag(TypeINT, this->isImpossible);
}

void Interpreter::fromDouble(void)
{
    this->ivalue = static_cast<int>(this->dvalue);
    this->cvalue = static_cast<char>(this->dvalue);
    this->fvalue = static_cast<float>(this->dvalue);
    if (!this->doubleIsValue()
        || this->dvalue > std::numeric_limits<int>::max()
        || this->dvalue < std::numeric_limits<int>::min())
        this->setFlag(TypeINT, this->isImpossible);
}

void Interpreter::fromChar(void)
{
    this->ivalue = static_cast<int>(this->cvalue);
    this->dvalue = static_cast<double>(this->cvalue);
    this->fvalue = static_cast<float>(this->cvalue);
}

void Interpreter::setFlag(int status, int flag)
{
    this->status[status] |= flag;
    //0000 00001 (1) |= 0000 0010 (2) = 0000 0011 (3)
}

bool Interpreter::hasFlag(int status, int flag) const
{
    return (this->status[status] & flag);
}

/*assignation operator*/
Interpreter &Interpreter::operator=(Interpreter const &copy)
{
    this->str = copy.str;
    this->type = copy.type;
    for (int i = 0; i < 4; i++)
        this->status[i] = copy.status[i];
    this->ivalue = copy.ivalue;
    this->dvalue = copy.dvalue;
    this->cvalue = copy.cvalue;
    this->fvalue = copy.fvalue;
    return (*this);
}

/*getters*/
int Interpreter::getAsInt(void) const
{
    return (this->ivalue);
}
float Interpreter::getAsFloat(void) const
{
    return (this->fvalue);
}
double Interpreter::getAsDouble(void) const
{
    return (this->dvalue);
}
char Interpreter::getAsChar(void) const
{
    return (this->cvalue);
}
std::string const &Interpreter::getRaw(void) const
{
    return (this->str);
}

/*seting the overload operator*/
std::ostream &operator<<(std::ostream &out, Interpreter const &b)
{
    std::stringstream ss;
    std::string tmp;

    //status zero "char"
    if (b.hasFlag(0, Interpreter::isImpossible))
        ss << "char: impossible\n";

    else if (b.hasFlag(0, Interpreter::nonDisplayable))
        ss << "char: non displayable\n";

    else 
        ss << "char: '" << b.getAsChar() << "' \n";

    //status one "int"
    if (b.hasFlag(1, Interpreter::isImpossible))
        ss << "int: impossible \n";
    
    else
        ss << "int: '" << b.getAsInt() << "\n";
    out << ss.str();
    ss.str(std::string());
    ss.clear();

    //status three "float"
    if (b.hasFlag(2, Interpreter::isImpossible))
        ss << "float: impossible\n";
    
    else 
    {
        ss << "float: '" << b.getAsFloat(); 
        tmp = ss.str();
        if (b.FloatIsValue() && tmp.find('.') == std::string::npos)
            ss << ".0";
        ss << "f\n";
    }
    out << ss.str();
    ss.str(std::string());
    ss.clear();

    //status four "double"
    if (b.hasFlag(3, Interpreter::isImpossible))
        ss << "double: imposible";

    else 
    {
        ss << "double: " << b.getAsDouble();
        tmp = ss.str();
        if (b.doubleIsValue() && tmp.find('.') == std::string::npos)
            ss << ".0";
    }
    out << ss.str() << std::endl;
    return (out);
}