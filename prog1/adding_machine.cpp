#include <iostream>

using std::cin;
using std::cout;
using std::endl;


int main(int argc, char *argv[]) {
    int total = 0, subtotal = 0, temp;
    bool flag = false;
    while (!cin.eof()) {
        cin >> temp;
        if (temp == 0) {
            if (flag) {
                cout << total << endl;
                break;
            } else {
                cout << subtotal << endl;
                subtotal = 0;
                flag = true;
            }
        } else {
            subtotal += temp;
            total += temp;
            flag = false;
        }
    }
    return 0;
}

            
            
