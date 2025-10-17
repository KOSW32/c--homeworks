#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Reservoir {
    char* name;
    char* type; // море, річка, ставок і т.д.
    double width;
    double length;
    double depth;
public:
    Reservoir() {
        name = new char[1]; name[0] = '\0';
        type = new char[1]; type[0] = '\0';
        width = length = depth = 0;
    }

    explicit Reservoir(const char* n, const char* t, double w, double l, double d) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);

        type = new char[strlen(t) + 1];
        strcpy(type, t);

        width = w;
        length = l;
        depth = d;
    }

    Reservoir(const Reservoir& other) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);

        type = new char[strlen(other.type) + 1];
        strcpy(type, other.type);

        width = other.width;
        length = other.length;
        depth = other.depth;
    }

    Reservoir& operator=(const Reservoir& other) {
        if (this == &other) return *this;

        delete[] name;
        delete[] type;

        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);

        type = new char[strlen(other.type) + 1];
        strcpy(type, other.type);

        width = other.width;
        length = other.length;
        depth = other.depth;

        return *this;
    }

    ~Reservoir() {
        delete[] name;
        delete[] type;
    }

    double volume() const {
        return width * length * depth;
    }

    double area() const {
        return width * length;
    }

    bool sameType(const Reservoir& r) const {
        return strcmp(type, r.type) == 0;
    }

    int compareArea(const Reservoir& r) const {
        if (!sameType(r)) return 0; // не можна порівняти різні типи
        if (area() > r.area()) return 1;
        if (area() < r.area()) return -1;
        return 0;
    }

    void setName(const char* n) {
        delete[] name;
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }

    void setType(const char* t) {
        delete[] type;
        type = new char[strlen(t) + 1];
        strcpy(type, t);
    }

    void setSize(double w, double l, double d) {
        width = w; length = l; depth = d;
    }

    const char* getName() const { return name; }
    const char* getType() const { return type; }
    double getWidth() const { return width; }
    double getLength() const { return length; }
    double getDepth() const { return depth; }

    void show() const {
        cout << "Назва: " << name
            << ", Тип: " << type
            << ", Площа: " << area()
            << ", Обсяг: " << volume()
            << endl;
    }

    void saveTxt(ofstream& fout) const {
        fout << name << " " << type << " " << width << " " << length << " " << depth << endl;
    }

    void saveBin(ofstream& fout) const {
        size_t len = strlen(name) + 1;
        fout.write((char*)&len, sizeof(len));
        fout.write(name, len);

        len = strlen(type) + 1;
        fout.write((char*)&len, sizeof(len));
        fout.write(type, len);

        fout.write((char*)&width, sizeof(width));
        fout.write((char*)&length, sizeof(length));
        fout.write((char*)&depth, sizeof(depth));
    }
};

class ReservoirList {
    Reservoir* arr;
    int count;
public:
    ReservoirList() {
        arr = nullptr;
        count = 0;
    }

    ~ReservoirList() {
        delete[] arr;
    }

    void add(const Reservoir& r) {
        Reservoir* tmp = new Reservoir[count + 1];
        for (int i = 0; i < count; i++) tmp[i] = arr[i];
        tmp[count] = r;
        delete[] arr;
        arr = tmp;
        count++;
    }

    void remove(int index) {
        if (index < 0 || index >= count) return;
        Reservoir* tmp = new Reservoir[count - 1];
        for (int i = 0, j = 0; i < count; i++) {
            if (i == index) continue;
            tmp[j++] = arr[i];
        }
        delete[] arr;
        arr = tmp;
        count--;
    }

    void showAll() const {
        for (int i = 0; i < count; i++) {
            cout << i + 1 << ") ";
            arr[i].show();
        }
    }

    void saveTxt(const char* fname) const {
        ofstream fout(fname);
        for (int i = 0; i < count; i++) {
            arr[i].saveTxt(fout);
        }
        fout.close();
    }

    void saveBin(const char* fname) const {
        ofstream fout(fname, ios::binary);
        for (int i = 0; i < count; i++) {
            arr[i].saveBin(fout);
        }
        fout.close();
    }
};

int main() {
    Reservoir r1("Чорне", "море", 500, 700, 2000);
    Reservoir r2("Азовське", "море", 300, 400, 1000);
    Reservoir r3("Дніпро", "річка", 100, 200, 50);

    ReservoirList list;
    list.add(r1);
    list.add(r2);
    list.add(r3);

    cout << "Усі водойми:" << endl;
    list.showAll();

    cout << endl << "Збереження у файл..." << endl;
    list.saveTxt("water.txt");
    list.saveBin("water.bin");

    return 0;
}
