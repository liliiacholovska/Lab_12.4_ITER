#include <iostream>

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
    if (L == NULL) return;
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
    int N, increaseBy;
    cout << "Enter the number of elements: ";
    cin >> N;
    cout << "Enter the values:" << endl;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        insert(L, a);
    }

    cout << "Original list: ";
    printList(L);

    cout << "Enter the increase value: ";
    cin >> increaseBy;
    increaseListValues(L, increaseBy);

    cout << "Modified list: ";
    printList(L);

    return 0;
}