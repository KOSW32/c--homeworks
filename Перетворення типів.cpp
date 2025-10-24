//1

//#include <iostream>
//#include <typeinfo>
//#include <windows.h>
//using namespace std;
//
//template <typename T>
//void showType(T value) {
//    cout << "Тип: " << typeid(value).name() << endl;
//}
//
//int main() {
//    SetConsoleOutputCP(1251);
//
//    int a = 10;
//    double b = 3.14;
//    char c = 'A';
//    string s = "Hello";
//
//    showType(a);
//    showType(b);
//    showType(c);
//    showType(s);
//
//    return 0;
//}


//2
#include <iostream>
#include <windows.h>
using namespace std;

void showChar(int number) {
    char* ch = reinterpret_cast<char*>(&number);
    cout << "Символ: " << *ch << endl;
}

int main() {
    SetConsoleOutputCP(1251);

    int num;
    cout << "Введіть число: ";
    cin >> num;
    showChar(num);
    return 0;
}

