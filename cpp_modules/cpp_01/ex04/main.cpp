#include <iostream>
#include "Sed.hpp"

int main(int argc, char* argv[])
{
    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[0] << " filename s1 s2\n";
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (s1.empty())
    {
        std::cerr << "Error: s1 must not be empty.\n";
        return 1;
    }

    Sed sed(filename, s1, s2);
    sed.replaceInFile();

    return 0;
}
