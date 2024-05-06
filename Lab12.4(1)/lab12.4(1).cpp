#include <iostream>
#include <sstream>
#include <string>

using namespace std;

typedef int Info;
struct Elem {
    Elem* link;
    Info info;
};

void insert(Elem*& L, Info value) {
    Elem* tmp = new Elem;
    tmp->info = value;
    if (L != NULL) {
        Elem* T = L;
        while (T->link != L)
            T = T->link;
        T->link = tmp;
    }
    else {
        L = tmp;
    }
    tmp->link = L;
}

void printList(Elem* L) {
    if (L == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    Elem* start = L;
    do {
        cout << L->info << " ";
        L = L->link;
    } while (L != start);
    cout << endl;
}

void increaseListValues(Elem*& L, Info increaseBy) {
    if (L == NULL) return;
    Elem* start = L;
    do {
        L->info += increaseBy;
        L = L->link;
    } while (L != start);
}

int main() {
    Elem* L = NULL;
    int increaseBy;

    cout << "Enter the values (enter a blank line to finish):" << endl;
    string line;
    int a;
    while (getline(cin, line)) {
        if (line.empty()) {
            break; 
        }
        stringstream ss(line);
        while (ss >> a) {
            insert(L, a);
        }
    }

    cout << "Original list: ";
    printList(L);

    cout << "Enter the increase value: ";
    if (cin >> increaseBy) {
        increaseListValues(L, increaseBy);
        cout << "Modified list: ";
        printList(L);
    }
    else {
        cout << "Invalid input for increase value." << endl;
    }

    return 0;
}
