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

    String(String&& other) noexcept {
        data = other.data;
        size = other.size;
        other.data = nullptr;
        other.size = 0;
    }

    ~String() {
        delete[] data;
    }

    String& operator=(const String& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new char[size + 1];
            strcpy(data, other.data);
        }
        return *this;
    }

    String& operator=(String&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            size = other.size;
            other.data = nullptr;
            other.size = 0;
        }
        return *this;
    }

    int length() const {
        return size;
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
};

int main() {
    String a("Hello");
    String b(" World");
    String c = a + b;

    cout << a.c_str() << endl;
    cout << b.c_str() << endl;
    cout << c.c_str() << endl;

    String d = move(c);
    cout << d.c_str() << endl;

    String e;
    e = a;
    cout << e.c_str() << endl;

    String f;
    f = move(b);
    cout << f.c_str() << endl;

    return 0;
}
