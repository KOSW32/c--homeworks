#include <iostream>
#include <windows.h>
using namespace std;


class Audio {
public:
    virtual void Play() const = 0; 
    virtual ~Audio() {}
};


class Song : public Audio {
    char title[50];
    char artist[50];
public:
    Song(const char* t, const char* a) {
        int i = 0; while (t[i] && i < 49) { title[i] = t[i]; i++; } title[i] = '\0';
        i = 0; while (a[i] && i < 49) { artist[i] = a[i]; i++; } artist[i] = '\0';
    }
    void Play() const override {
        cout << "Playing song: " << title << " by " << artist << endl;
    }
};


class Podcast : public Audio {
    char host[50];
    char topic[50];
public:
    Podcast(const char* h, const char* t) {
        int i = 0; while (h[i] && i < 49) { host[i] = h[i]; i++; } host[i] = '\0';
        i = 0; while (t[i] && i < 49) { topic[i] = t[i]; i++; } topic[i] = '\0';
    }
    void Play() const override {
        cout << "Podcast on " << topic << " hosted by " << host << endl;
    }
};

class Audiobook : public Audio {
    char bookTitle[50];
    char author[50];
    char voice[50];
public:
    Audiobook(const char* b, const char* a, const char* v) {
        int i = 0; while (b[i] && i < 49) { bookTitle[i] = b[i]; i++; } bookTitle[i] = '\0';
        i = 0; while (a[i] && i < 49) { author[i] = a[i]; i++; } author[i] = '\0';
        i = 0; while (v[i] && i < 49) { voice[i] = v[i]; i++; } voice[i] = '\0';
    }
    void Play() const override {
        cout << "Listening to audiobook: " << bookTitle
            << " by " << author << ". Read by " << voice << "." << endl;
    }
};

int main() {

    SetConsoleOutputCP(1251);


    Audio* audio = nullptr;
    int choice;

    while (true) {
        cout << "\n=== МЕНЮ ===\n";
        cout << "1. Song\n";
        cout << "2. Podcast\n";
        cout << "3. Audiobook\n";
        cout << "0. Вихід\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        if (choice == 0) break;

        char a[50], b[50], c[50];

        if (choice == 1) {
            cout << "Введіть назву пісні: ";
            cin >> a;
            cout << "Введіть виконавця: ";
            cin >> b;
            audio = new Song(a, b);
        }
        else if (choice == 2) {
            cout << "Введіть ведучого: ";
            cin >> a;
            cout << "Введіть тему подкасту: ";
            cin >> b;
            audio = new Podcast(a, b);
        }
        else if (choice == 3) {
            cout << "Введіть назву книги: ";
            cin >> a;
            cout << "Введіть автора: ";
            cin >> b;
            cout << "Введіть читеця: ";
            cin >> c;
            audio = new Audiobook(a, b, c);
        }
        else {
            cout << "Невірний вибір.\n";
            continue;
        }

        audio->Play();
        delete audio;
        audio = nullptr;
    }

    cout << "Програму завершено.\n";
    return 0;
}
