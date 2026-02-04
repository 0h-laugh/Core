#include "Contact.hpp"

void Contact::setContact(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds)
{
    firstName = fn;
    lastName = ln;
    nickname = nn;
    phoneNumber = pn;
    darkestSecret = ds;
}

void Contact::displayShort(int index) const {
    auto format = [](std::string str)
    {
        if (str.length() > 10)
            return (str.substr(0, 9) + ".");
        return str;
    };

    std::cout << std::setw(10) << index << "|"
              << std::setw(10) << format(firstName) << "|"
              << std::setw(10) << format(lastName) << "|"
              << std::setw(10) << format(nickname) << std::endl;
}

void Contact::displayFull() const {
    std::cout << "First name: " << firstName << std::endl;
    std::cout << "Last name: " << lastName << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Phone number: " << phoneNumber << std::endl;
    std::cout << "Darkest secret: " << darkestSecret << std::endl;
}

bool Contact::isEmpty() const {
    return firstName.empty();
}
