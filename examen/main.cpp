#include <iostream>
#include <string>

enum State {
    q0, q1, q2, q3
};

bool isAccepted(const std::string &input) {
    State currentState = q0;

    for (char ch : input) {
        switch (currentState) {
            case q0:
                if (ch == 'm') currentState = q1;
                else if (ch == 'h') currentState = q2;
                else return false;
                break;
            case q1:
                if (ch == 'h') currentState = q3;
                else if (ch == 'a') currentState = q2;
                else return false;
                break;
            case q2:
                if (ch == 'm') currentState = q1;
                else return false;
                break;
            case q3:
                if (ch == 'a') currentState = q3;
                else return false;
                break;
            default:
                return false;
        }
    }


    return currentState == q2 || currentState == q3;
}

int main() {
    std::string input;
    std::cout << "Introduce una cadena: ";
    std::cin >> input;

    if (isAccepted(input)) {
        std::cout << "Cadena aceptada.\n";
    } else {
        std::cout << "Cadena rechazada.\n";
    }

    return 0;
}
