#include <iostream>
#include <string>

bool ParseFile(const std::string& input, size_t& index);
bool ParsePath(const std::string& input, size_t& index);
bool ParseDir(const std::string& input, size_t& index);
bool ParseExtension(const std::string& input, size_t& index);

bool ParseFile(const std::string& input) {
    size_t index = 0;
    if (!ParsePath(input, index)) return false;
    if (index < input.length() && input[index] == '.') {
        index++;
        if (!ParseExtension(input, index)) return false;
    }
    return index == input.length();
}

bool ParsePath(const std::string& input, size_t& index) {
    if (!ParseDir(input, index)) return false;
    while (index < input.length() && input[index] == '/') {
        index++;
        if (!ParseDir(input, index)) return false;
    }
    return true;
}

bool ParseDir(const std::string& input, size_t& index) {
    std::string dirs[] = { "home", "var","user","documents"};
    for (const auto& dir : dirs) {
        if (input.substr(index, dir.length()) == dir) {
            index += dir.length();
            return true;
        }
    }
    return false;
}

bool ParseExtension(const std::string& input, size_t& index) {
    std::string extensions[] = { "txt", "docx"  };
    for (const auto& ext : extensions) {
        if (input.substr(index, ext.length()) == ext) {
            index += ext.length();
            return true;
        }
    }
    return false;
}

int main() {
    std::string input;
    std::cout << "Introduce una cadena: ";
    std::cin >> input;

    if (ParseFile(input)) {
        std::cout << "Cadena aceptada.\n";
    } else {
        std::cout << "Cadena rechazada.\n";
    }

    return 0;
}
