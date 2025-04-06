#include <iostream>
#include "Mylist.h" // Include Mylist class

using namespace std;

int main() {
    int size;
    cout << "Enter the maximum size of the list: ";
    cin >> size;

    Mylist<int> myList(size); // Creating an integer list

    int choice, index, value;

    do {
        cout << "\n--- MyList Menu ---\n";
        cout << "1. Add element at first index\n";
        cout << "2. Add element at last index\n";
        cout << "3. Remove element from start\n";
        cout << "4. Remove element from end\n";
        cout << "5. Check if list is empty\n";
        cout << "6. Check if list is full\n";
        cout << "7. Get current size of list\n";
        cout << "8. Insert at specific index\n";
        cout << "9. Get last element\n";
        cout << "10. Search for an element\n";
        cout << "11. Display list\n";
        cout << "12. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert at first index: ";
            cin >> value;
            myList.addElementatfirstindex(value);
            break;

        case 2:
            cout << "Enter value to insert at last index: ";
            cin >> value;
            myList.addElementatlastindex(value);
            break;

        case 3:
            myList.removeElementfromStart();
            cout << "First element removed.\n";
            break;

        case 4:
            myList.removeElementfromEnd();
            cout << "Last element removed.\n";
            break;

        case 5:
            cout << (myList.empty() ? "List is empty.\n" : "List is not empty.\n");
            break;

        case 6:
            cout << (myList.Full() ? "List is full.\n" : "List is not full.\n");
            break;

        case 7:
            cout << "Current size of the list: " << myList.size() << endl;
            break;

        case 8:
            cout << "Enter index to insert at: ";
            cin >> index;
            cout << "Enter value to insert: ";
            cin >> value;
            if (myList.insertAt(index, value))
                cout << "Inserted successfully.\n";
            else
                cout << "Failed to insert. Invalid index or list is full.\n";
            break;

        case 9:
            if (!myList.empty())
                cout << "Last element: " << myList.last() << endl;
            else
                cout << "List is empty.\n";
            break;

        case 10:
            cout << "Enter value to search: ";
            cin >> value;
            cout << (myList.search(value) ? "Value found in list.\n" : "Value not found.\n");
            break;

        case 11:
            cout << "List contents: ";
            myList.display();
            cout << endl;
            break;

        case 12:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice! Please enter a number between 1-12.\n";
        }
    } while (choice != 12);

    return 0;
}
