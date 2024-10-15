#include "../header/Bureaucrat.hpp"
#include "../header/Form.hpp"

int main()
{
    /*Bureaucrat b1("mazen", 1);
    Bureaucrat b2("john", 150);
    Bureaucrat b3("alex", 50);

    std::cout << "test creating bureaucrat opjects\n";
    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;
    std::cout << b3 << std::endl;

    //testing gradTooHigh and TooLow
    std::cout << "----------------TEST OF TooHigh----------------\n";
    try
    {
        Bureaucrat test("test", 0);
    }
    catch(const std::exception& e)
    {
        std::cout << "cannot creat test" << std::endl;
        std::cout << "Exception:" << e.what() << '\n';
    }

    std::cout << "----------------TEST OF TooLow----------------\n";
    try
    {
        Bureaucrat test1("test1", 160);
    }
    catch(const std::exception& e)
    {
        std::cout << "cannot creat test1" << std::endl;
        std::cout << "Exception:" << e.what() << '\n';
    }

    std::cout << "----------------TEST OF Increament----------------\n";
    try
    {
        b1.incrementGrad();
    }
    catch(const std::exception& e)
    {
        std::cout << "Cannot increment the grade of b1" << std::endl;
		std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "----------------TEST OF Derement----------------\n";
    try
    {
        b2.decrementGrad();
    }
    catch(const std::exception& e)
    {
        std::cout << "Cannot increment the grade of b2" << std::endl;
		std::cout << "Exception: " << e.what() << std::endl;
    }*/

   std::cout << GREEN << "we will test now by creating form with grad to sign 0\n" << RESET;

   try
   {
        Form f1("EB110", 0, 1);
   }
   catch(const std::exception& e)
   {
        std::cout << "Exception: " << e.what() << std::endl;
   }


    /*tcheck the implimentation of this part*/
   std::cout << GREEN << "we will test now by creating form with grad to excute 0\n" << RESET;
   try
   {
        Form f1("EB111", 1, 0);
   }
   catch(const std::exception& e)
   {
        std::cout << "Exception: " << e.what() << std::endl;
   }
   

    std::cout << GREEN << "we will test now by creating form with grad to sing 151\n" << RESET;
    try
    {
        Form f1("EB112", 151, 1);
    }
    catch(const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    

    std::cout << GREEN << "we will test now by creating form with grad to excute 151\n" << RESET;
    try
    {
        Form f1("EB112", 1, 151);
    }
    catch(const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    

    std::cout << GREEN << "#### GENRAL TEST ####\n" << RESET;
    try
    {
        Bureaucrat mazen("mazen", 1);
        Form f1("EB114", 150, 150);

        std::cout << f1 << std::endl;
        mazen.signForm(f1);
        std::cout << f1 << std::endl;
    }
    catch(const std::exception& e)
    {
            std::cout << e.what() << std::endl;
    }
    
    
    
    return (0);
}