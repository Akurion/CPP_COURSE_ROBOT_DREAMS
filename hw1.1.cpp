#include <iostream>

using namespace std;
int main() {
    
    cout << "i love C++" << endl;
    int height;

    cout << "Enter triangle's height: "; 
    cin >> height;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}