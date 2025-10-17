#include <iostream>
#include <cstring>
using namespace std;

class String {
private:
    char* data;
    int size;

public:
    String() {
        data = nullptr;
        size = 0;
    }

    String(const char* str) {
        size = strlen(str);
        data = new char[size + 1];
        strcpy(data, str);
    }

    String(const String& other) {
        size = other.size;
        data = new char[size + 1];
        strcpy(data, other.data);
    }

    ~String() {
        delete[] data;
    }

    int length() const {
        return size;
    }

    char* get() const {
        return data;
    }

    const char* c_str() const {
        return data;
    }

    String operator+(const String& other) {
        int newSize = size + other.size;
        char* newData = new char[newSize + 1];
        strcpy(newData, data);
        strcat(newData, other.data);
        String temp(newData);
        delete[] newData;
        return temp;
    }

    void show() const {
        cout << data << endl;
    }
};

int main() {
    String a("Hello");
    String b(" World");
    String c = a + b;
    a.show();
    b.show();
    c.show();
    cout << c.length() << endl;
    cout << c.c_str() << endl;
    return 0;
}
