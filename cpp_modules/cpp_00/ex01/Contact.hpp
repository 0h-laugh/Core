#ifndef CONTACT_HPP
#define CONTACT_HPP

# include <string>
# include <iostream>
# include <iomanip>

class Contact {
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

public:
    void setContact(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds);
    void displayShort(int index) const;
    void displayFull() const;
    bool isEmpty() const;
};

#endif
