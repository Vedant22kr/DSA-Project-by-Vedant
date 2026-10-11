#include <iostream>
using namespace std;

struct Coach
{
    int coachNumber;
    string coachType;
    Coach *next;
};

Coach *head = NULL;

// Add a new coach
void addCoach()
{
    Coach *newCoach = new Coach;

    cout << "\nEnter Coach Number: ";
    cin >> newCoach->coachNumber;

    cout << "Enter Coach Type (AC/SL/GEN): ";
    cin >> newCoach->coachType;

    newCoach->next = NULL;

    if (head == NULL)
    {
        head = newCoach;
    }
    else
    {
        Coach *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newCoach;
    }

    cout << "\nCoach added successfully!\n";
}

// Remove a coach
void removeCoach()
{
    int number;

    if (head == NULL)
    {
        cout << "\nNo coaches available!\n";
        return;
    }

    cout << "\nEnter Coach Number to remove: ";
    cin >> number;

    // Delete first node
    if (head->coachNumber == number)
    {
        Coach *temp = head;
        head = head->next;
        delete temp;

        cout << "\nCoach removed successfully!\n";
        return;
    }

    Coach *temp = head;

    while (temp->next != NULL &&
           temp->next->coachNumber != number)
    {
        temp = temp->next;
    }

    if (temp->next == NULL)
    {
        cout << "\nCoach not found!\n";
        return;
    }

    Coach *deleteNode = temp->next;
    temp->next = temp->next->next;

    delete deleteNode;

    cout << "\nCoach removed successfully!\n";
}

// Display all coaches
void displayCoaches()
{
    if (head == NULL)
    {
        cout << "\nNo coaches available!\n";
        return;
    }

    Coach *temp = head;

    cout << "\n===== TRAIN COACHES =====\n";

    while (temp != NULL)
    {
        cout << "Coach Number : " << temp->coachNumber << endl;
        cout << "Coach Type   : " << temp->coachType << endl;
        cout << "------------------------\n";

        temp = temp->next;
    }
}

// Search for a coach
void searchCoach()
{
    int number;

    if (head == NULL)
    {
        cout << "\nNo coaches available!\n";
        return;
    }

    cout << "\nEnter Coach Number to search: ";
    cin >> number;

    Coach *temp = head;

    while (temp != NULL)
    {
        if (temp->coachNumber == number)
        {
            cout << "\nCoach Found!\n";
            cout << "Coach Number : " << temp->coachNumber << endl;
            cout << "Coach Type   : " << temp->coachType << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "\nCoach not found!\n";
}

// Main function
int main()
{
    int choice;

    do
    {
        cout << "\n===== TRAIN COACH MANAGEMENT SYSTEM =====";
        cout << "\n1. Add Coach";
        cout << "\n2. Remove Coach";
        cout << "\n3. Display Coaches";
        cout << "\n4. Search Coach";
        cout << "\n5. Exit";

        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addCoach();
                break;

            case 2:
                removeCoach();
                break;

            case 3:
                displayCoaches();
                break;

            case 4:
                searchCoach();
                break;

            case 5:
                cout << "\nProgram ended.\n";
                break;

            default:
                cout << "\nInvalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
