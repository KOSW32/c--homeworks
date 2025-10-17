#include <iostream>
using namespace std;

class DoublyLinkedList {
private:
    struct Node {
        int value;
        Node* prev;
        Node* next;
        Node(int v) : value(v), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int count;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), count(0) {}

    ~DoublyLinkedList() {
        clear();
    }

    void push_front(int value) {
        Node* n = new Node(value);
        if (!head) {
            head = tail = n;
        }
        else {
            n->next = head;
            head->prev = n;
            head = n;
        }
        count++;
    }

    void push_back(int value) {
        Node* n = new Node(value);
        if (!tail) {
            head = tail = n;
        }
        else {
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
        count++;
    }

    void pop_front() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete temp;
        count--;
    }

    void pop_back() {
        if (!tail) return;
        Node* temp = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete temp;
        count--;
    }

    void insert(int position, int value) {
        if (position <= 0) {
            push_front(value);
            return;
        }
        if (position >= count) {
            push_back(value);
            return;
        }

        Node* cur = head;
        for (int i = 0; i < position; i++) {
            cur = cur->next;
        }

        Node* n = new Node(value);
        n->prev = cur->prev;
        n->next = cur;
        cur->prev->next = n;
        cur->prev = n;
        count++;
    }

    void erase(int position) {
        if (position < 0 || position >= count) return;

        if (position == 0) {
            pop_front();
            return;
        }
        if (position == count - 1) {
            pop_back();
            return;
        }

        Node* cur = head;
        for (int i = 0; i < position; i++) {
            cur = cur->next;
        }
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        delete cur;
        count--;
    }

    int find(int value) {
        Node* cur = head;
        int pos = 0;
        while (cur) {
            if (cur->value == value) return pos;
            cur = cur->next;
            pos++;
        }
        return -1;
    }

    void clear() {
        while (head) {
            pop_front();
        }
    }

    int size() {
        return count;
    }

    bool empty() {
        return count == 0;
    }

    void print_forward() {
        Node* cur = head;
        while (cur) {
            cout << cur->value << " ";
            cur = cur->next;
        }
        cout << endl;
    }

    void print_backward() {
        Node* cur = tail;
        while (cur) {
            cout << cur->value << " ";
            cur = cur->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    list.push_back(10);
    list.push_back(20);
    list.push_front(5);
    list.insert(1, 15);

    list.print_forward();   
    list.print_backward();  

    cout << "Find 10: " << list.find(10) << endl;
    cout << "Size: " << list.size() << endl;

    list.erase(2);
    list.print_forward();   

    list.clear();
    cout << "Empty: " << list.empty() << endl;

    return 0;
}
