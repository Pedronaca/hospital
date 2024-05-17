#include <iostream>

using namespace std;

int main() {
    // Text colors
    cout << "\033[31m" << "This text is red" << "\033[0m" << endl;
    cout << "\033[32m" << "This text is green" << "\033[0m" << endl;
    cout << "\033[33m" << "This text is yellow" << "\033[0m" << endl;
    cout << "\033[34m" << "This text is blue" << "\033[0m" << endl;
    cout << "\033[35m" << "This text is magenta" << "\033[0m" << endl;
    cout << "\033[36m" << "This text is cyan" << "\033[0m" << endl;
    cout << "\033[37m" << "This text is gray" << "\033[0m" << endl;

    // Background colors
    cout << "\033[41m" << "This background is red" << "\033[0m" << endl;
    cout << "\033[42m" << "This background is green" << "\033[0m" << endl;
    cout << "\033[43m" << "This background is yellow" << "\033[0m" << endl;
    cout << "\033[44m" << "This background is blue" << "\033[0m" << endl;
    cout << "\033[45m" << "This background is magenta" << "\033[0m" << endl;
    cout << "\033[46m" << "This background is cyan" << "\033[0m" << endl;
    cout << "\033[47m" << "This background is gray (bright white)" << "\033[0m" << endl;

    return 0;
}
