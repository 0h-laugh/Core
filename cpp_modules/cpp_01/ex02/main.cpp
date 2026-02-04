#include <iostream>
#include <string>

int main()
{
    
    std::string brain = "HI THIS IS BRAIN";

    
    std::string* stringPTR = &brain;

    
    std::string& stringREF = brain;

    
    std::cout << "Memory address of brain:     " << &brain << std::endl;
    std::cout << "Memory address in stringPTR: " << stringPTR << std::endl;
    std::cout << "Memory address in stringREF: " << &stringREF << std::endl;

    
    std::cout << "Value of brain:              " << brain << std::endl;
    std::cout << "Value pointed by stringPTR:  " << *stringPTR << std::endl;
    std::cout << "Value pointed by stringREF:  " << stringREF << std::endl;

    return 0;
}
