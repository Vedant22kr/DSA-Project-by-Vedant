#include <iostream>
#include <string>
using namespace std;

struct Coach {
    int coachNo;
    string coachType;
    Coach* prev;
    Coach* next;
};

Coach* head = NULL;
Coach* tail = NULL;

void addCoach() {
    Coach* newCoach = new Coach;

    cout << "Enter coach number: ";
    cin >> newCoach->coachNo;

    Coach* temp = head;
    while (temp != NULL) {
        if (temp->coachNo == newCoach->coachNo) {
            cout << "Coach number already exists!\n";
            delete newCoach;
            return;
        }
        temp = temp->next;
    }

    cout << "Enter coach type (AC/SL/GEN): ";
    cin >> newCoach->coachType;

    newCoach->prev = NULL;
    newCoach->next = NULL;

    if (head == NULL) {
        head = tail = newCoach;
    } else {
        tail->next = newCoach;
        newCoach->prev = tail;
        tail = newCoach;
    }

    cout << "Coach added successfully!\n";
}

void deleteCoach() {
    if (head == NULL) {
        cout << "No coaches available!\n";
        return;
    }

    int number;
    cout << "Enter coach number to delete: ";
    cin >> number;

    Coach* temp = head;
    while (temp != NULL && temp->coachNo != number)
        temp = temp->next;

    if (temp == NULL) {
        cout << "Coach not found!\n";
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    else
        tail = temp->prev;

    delete temp;
    cout << "Coach deleted successfully!\n";
}

void searchCoach() {
    int number;
    cout << "Enter coach number to search: ";
    cin >> number;

    Coach* temp = head;
    while (temp != NULL) {
        if (temp->coachNo == number) {
            cout << "Coach found: " << temp->coachNo
                 << " - " << temp->coachType << '\n';
            return;
        }
        temp = temp->next;
    }

    cout << "Coach not found!\n";
}

void displayForward() {
    if (head == NULL) {
        cout << "No coaches available!\n";
        return;
    }

    Coach* temp = head;
    cout << "\nForward Train: ";

    while (temp != NULL) {
        cout << "[" << temp->coachNo << " "
             << temp->coachType << "] <-> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

void displayBackward() {
    if (tail == NULL) {
        cout << "No coaches available!\n";
        return;
    }

    Coach* temp = tail;
    cout << "\nBackward Train: ";

    while (temp != NULL) {
        cout << "[" << temp->coachNo << " "
             << temp->coachType << "] <-> ";
        temp = temp->prev;
    }

    cout << "NULL\n";
}

void countCoaches() {
    int count = 0;
    Coach* temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    cout << "Total coaches: " << count << '\n';
}

void freeMemory() {
    while (head != NULL) {
        Coach* temp = head;
        head = head->next;
        delete temp;
    }

    tail = NULL;
}

int main() {
    int choice;

    do {
        cout << "\n--- TRAIN COACH MANAGEMENT (DLL) ---\n";
        cout << "1. Add Coach\n";
        cout << "2. Delete Coach\n";
        cout << "3. Search Coach\n";
        cout << "4. Display Forward\n";
        cout << "5. Display Backward\n";
        cout << "6. Count Coaches\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addCoach();
                break;

            case 2:
                deleteCoach();
                break;

            case 3:
                searchCoach();
                break;

            case 4:
                displayForward();
                break;

            case 5:
                displayBackward();
                break;

            case 6:
                countCoaches();
                break;

            case 0:
                freeMemory();
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}
0
