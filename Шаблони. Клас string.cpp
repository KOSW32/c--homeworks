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

    char& operator[](int index) {
        return data[index];
    }

    const char& operator[](int index) const {
        return data[index];
    }

    bool empty() const {
        return size == 0;
    }

    String substr(int start, int end) const {
        if (start < 0) start = 0;
        if (end > size) end = size;
        if (start >= end) return String("");

        int newLen = end - start;
        char* buf = new char[newLen + 1];
        strncpy(buf, data + start, newLen);
        buf[newLen] = '\0';
        String res(buf);
        delete[] buf;
        return res;
    }

    void replace(int index, int count, const String& str) {
        if (index < 0 || index >= size) return;

        int newSize = size - count + str.size;
        char* buf = new char[newSize + 1];

        strncpy(buf, data, index);
        buf[index] = '\0';
        strcat(buf, str.data);
        strcat(buf, data + index + count);

        delete[] data;
        data = buf;
        size = newSize;
    }

    void insert(int index, const String& str) {
        if (index < 0) index = 0;
        if (index > size) index = size;

        int newSize = size + str.size;
        char* buf = new char[newSize + 1];

        strncpy(buf, data, index);
        buf[index] = '\0';
        strcat(buf, str.data);
        strcat(buf, data + index);

        delete[] data;
        data = buf;
        size = newSize;
    }
};

int main() {
    String s("Hello World");

    cout << "substr(0,5): " << s.substr(0, 5).c_str() << endl;

    s.replace(6, 5, String("ChatGPT"));
    cout << "replace: " << s.c_str() << endl;

    s.insert(5, String(" AMAZING"));
    cout << "insert: " << s.c_str() << endl;

    cout << "empty: " << (s.empty() ? "yes" : "no") << endl;

    return 0;
}
