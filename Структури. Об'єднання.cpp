

//3
//#include <iostream>
//#include <cstring>
//using namespace std;
//
//struct Book {
//    char name[30];
//    char author[30];
//    char pub[30];
//    char type[20];
//};
//
//void show(Book b) {
//    cout << b.name << " - " << b.author << " (" << b.pub << ", " << b.type << ")\n";
//}
//
//int main() {
//    Book books[3] = {
//        {"Harry Potter", "Rowling", "Bloomsbury", "Fantasy"},
//        {"Dune", "Herbert", "Chilton", "Sci-Fi"},
//        {"It", "King", "Viking", "Horror"}
//    };
//
//    for (int i = 0; i < 3; i++) show(books[i]);
//    return 0;
//}

//5
#include <iostream>
#include <cstring>
using namespace std;

struct Life {
    double speed;
    char type[20];
    char color[20];
    double fly;
    bool hoof;
    int iq;
};

void show(Life l) {
    cout << "Type: " << l.type << ", Color: " << l.color << ", Speed: " << l.speed;
    if (strcmp(l.type, "bird") == 0) cout << ", Fly: " << l.fly;
    if (strcmp(l.type, "cow") == 0) cout << ", Hoof: " << l.hoof;
    if (strcmp(l.type, "man") == 0) cout << ", IQ: " << l.iq;
    cout << endl;
}

int main() {
    Life a = { 20, "bird", "white", 45, 0, 0 };
    Life b = { 10, "cow", "brown", 0, 1, 0 };
    Life c = { 5, "man", "black", 0, 0, 120 };
    show(a);
    show(b);
    show(c);
    return 0;
}


//6
//#include <iostream>
//#include <cstring>
//using namespace std;
//
//struct Student {
//    char name[20];
//    char group[10];
//    int marks[5];
//};
//
//bool isGood(Student s) {
//    int good = 0;
//    for (int i = 0; i < 5; i++) if (s.marks[i] >= 4) good++;
//    return good >= 4;
//}
//
//int main() {
//    Student s[3] = {
//        {"Ivan", "A1", {5,4,5,5,4}},
//        {"Petro", "A2", {3,2,3,2,2}},
//        {"Oleg", "A1", {4,4,4,3,5}}
//    };
//
//    cout << "Good students:\n";
//    for (int i = 0; i < 3; i++)
//        if (isGood(s[i])) cout << s[i].name << endl;
//    return 0;
//}
