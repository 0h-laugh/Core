#include "Sed.hpp"

Sed::Sed(const std::string& filename, const std::string& s1, const std::string& s2)
    : _filename(filename), _s1(s1), _s2(s2) {}

std::string Sed::replaceAll(const std::string& line) {
    std::string result;
    std::string temp = line;
    size_t pos = 0;

    while ((pos = temp.find(_s1)) != std::string::npos) {
        result += temp.substr(0, pos) + _s2;
        temp = temp.substr(pos + _s1.length());
    }
    result += temp;
    return result;
}

void Sed::replaceInFile() {
    std::ifstream input(_filename);
    if (!input) {
        std::cerr << "Error: cannot open file " << _filename << " for reading.\n";
        return;
    }

    std::ofstream output(_filename + ".replace");
    if (!output) {
        std::cerr << "Error: cannot open file " << _filename << ".replace for writing.\n";
        return;
    }

    std::string line;
    while (std::getline(input, line)) {
        output << replaceAll(line) << "\n";
    }
}
