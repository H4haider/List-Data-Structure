#include <iostream>
#include "CustomList.h" 

using namespace std;

int main() {
    int size;
    cout << "Enter the maximum size of the list: ";
    cin >> size;

    CustomList<int> myList(size); 

    int choice, value, rotations;

    do {
        cout << "\n--- CustomList Menu ---\n";
        cout << "1. Add element at first index\n";
        cout << "2. Add element at last index\n";
        cout << "3. Display list\n";
        cout << "4. Find sum of prime numbers\n";
        cout << "5. Find second maximum even number\n";
        cout << "6. Find second minimum odd number\n";
        cout << "7. Print duplicate numbers\n";
        cout << "8. Rotate list clockwise\n";
        cout << "9. Rotate list anti-clockwise\n";
        cout << "10. Exit\n";
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
            cout << "List contents: ";
            myList.display();
            cout << endl;
            break;

        case 4:
            cout << "Sum of prime numbers: " << myList.sumofPrime() << endl;
            break;

        case 5:
            cout << "Second maximum even number: " << myList.secondmaxeven() << endl;
            break;

        case 6:
            cout << "Second minimum odd number: " << myList.secondminodd() << endl;
            break;

        case 7:
            cout << "Duplicate numbers: ";
            myList.printduplicates();
            break;

        case 8:
            cout << "Enter number of times to rotate clockwise: ";
            cin >> rotations;
            myList.rotateclockwise(rotations);
            cout << "List rotated clockwise " << rotations << " times.\n";
            break;

        case 9:
            cout << "Enter number of times to rotate anti-clockwise: ";
            cin >> rotations;
            myList.rotateAntiClockwise(rotations);
            cout << "List rotated anti-clockwise " << rotations << " times.\n";
            break;

        case 10:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice! Please enter a number between 1-10.\n";
        }
    } while (choice != 10);

    return 0;
}
