#include <iostream>
using namespace std;

void test(int a, double b) {
    cout << "version 1 is used" << endl;
    cout << "a = " << a << ", b = " << b << endl;
    return;
}

void test(double a, int b) {
    cout << "version 2 is used" << endl;
    cout << "a = " << a << ", b = " << b << endl;
    return;
}

int main() {
    test(3, 4.6);   // resolution -> version 1
    test('a', 4.6); // 'a' can be promoted to 97 (int) -> version 1
    // test(3.2, 4.6);     // can match to either versions (by narrowing conversion to int)
                            // therefore compilation error (neither one is more preferable)

    return 0;
}