#include <iostream>
#include <cstring>
using namespace std;

class People {
    char* name;
public:
    People() {
        name = new char[1];
        name[0] = '\0';
    }

    People(const char* n) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }

    People(const People& other) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
    }

    ~People() {
        delete[] name;
    }

    void show() const {
        cout << name;
    }
};

class Flat {
    People* arr;
    int count;
public:
    Flat() {
        arr = nullptr;
        count = 0;
    }

    Flat(People* p, int c) {
        count = c;
        arr = new People[count];
        for (int i = 0; i < count; i++) {
            arr[i] = p[i];
        }
    }

    Flat(const Flat& other) {
        count = other.count;
        arr = new People[count];
        for (int i = 0; i < count; i++) {
            arr[i] = other.arr[i];
        }
    }

    ~Flat() {
        delete[] arr;
    }

    void show() const {
        for (int i = 0; i < count; i++) {
            arr[i].show();
            cout << " ";
        }
    }
};

class House {
    Flat* flats;
    int count;
public:
    House() {
        flats = nullptr;
        count = 0;
    }

    House(Flat* f, int c) {
        count = c;
        flats = new Flat[count];
        for (int i = 0; i < count; i++) {
            flats[i] = f[i];
        }
    }

    House(const House& other) {
        count = other.count;
        flats = new Flat[count];
        for (int i = 0; i < count; i++) {
            flats[i] = other.flats[i];
        }
    }

    ~House() {
        delete[] flats;
    }

    void show() const {
        for (int i = 0; i < count; i++) {
            cout << "Flat " << i + 1 << ": ";
            flats[i].show();
            cout << endl;
        }
    }
};

int main() {
    People p1("Ivanov");
    People p2("Petrov");
    People p3("Sidorov");
    People p4("Kozlov");

    People arr1[] = { p1, p2 };
    People arr2[] = { p3, p4 };

    Flat f1(arr1, 2);
    Flat f2(arr2, 2);

    Flat flats[] = { f1, f2 };

    House h(flats, 2);

    h.show();

    return 0;
}
