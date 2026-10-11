#include <iostream>
#include <string>
using namespace std;

struct Coach {
    int coachNo;
    string coachType;
    Coach* next;
};

Coach* head = NULL;

void addCoach() {
    Coach* newCoach = new Coach;

    cout << "Enter coach number: ";
    cin >> newCoach->coachNo;

    Coach* temp = head;

    if (head != NULL) {
        do {
            if (temp->coachNo == newCoach->coachNo) {
                cout << "Coach number already exists!\n";
                delete newCoach;
                return;
            }
            temp = temp->next;
        } while (temp != head);
    }

    cout << "Enter coach type (AC/SL/GEN): ";
    cin >> newCoach->coachType;

    if (head == NULL) {
        head = newCoach;
        newCoach->next = head;
    } else {
        temp = head;

        while (temp->next != head) {
            temp = temp->next;
        }

        temp->next = newCoach;
        newCoach->next = head;
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
    Coach* prev = NULL;

    do {
        if (temp->coachNo == number)
            break;

        prev = temp;
        temp = temp->next;
    } while (temp != head);

    if (temp->coachNo != number) {
        cout << "Coach not found!\n";
        return;
    }

    if (temp->next == head && temp == head) {
        head = NULL;
    } else {
        if (temp == head) {
            Coach* last = head;

            while (last->next != head) {
                last = last->next;
            }

            head = head->next;
            last->next = head;
        } else {
            prev->next = temp->next;
        }
    }

    delete temp;
    cout << "Coach deleted successfully!\n";
}

void searchCoach() {
    if (head == NULL) {
        cout << "No coaches available!\n";
        return;
    }

    int number;
    cout << "Enter coach number to search: ";
    cin >> number;

    Coach* temp = head;

    do {
        if (temp->coachNo == number) {
            cout << "Coach found: " << temp->coachNo
                 << " - " << temp->coachType << '\n';
            return;
        }

        temp = temp->next;
    } while (temp != head);

    cout << "Coach not found!\n";
}

void displayCoaches() {
    if (head == NULL) {
        cout << "No coaches available!\n";
        return;
    }

    Coach* temp = head;

    cout << "\nCircular Train: ";

    do {
        cout << "[" << temp->coachNo << " "
             << temp->coachType << "] -> ";
        temp = temp->next;
    } while (temp != head);

    cout << "(Back to Head)\n";
}

void countCoaches() {
    int count = 0;

    if (head != NULL) {
        Coach* temp = head;

        do {
            count++;
            temp = temp->next;
        } while (temp != head);
    }

    cout << "Total coaches: " << count << '\n';
}

void freeMemory() {
    if (head == NULL)
        return;

    Coach* temp = head->next;

    while (temp != head) {
        Coach* nextCoach = temp->next;
        delete temp;
        temp = nextCoach;
    }

    delete head;
    head = NULL;
}

int main() {
    int choice;

    do {
        cout << "\n--- TRAIN COACH MANAGEMENT (CLL) ---\n";
        cout << "1. Add Coach\n";
        cout << "2. Delete Coach\n";
        cout << "3. Search Coach\n";
        cout << "4. Display Coaches\n";
        cout << "5. Count Coaches\n";
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
                displayCoaches();
                break;

            case 5:
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

