#include <iostream>
using namespace std;

struct Node
{
    string name;
    string birthday;
    Node *next;
};

class StudentList
{
public:
    Node *head = nullptr;

    void insertStudent(string name, string birthday)
    {
        cout << "Attempting to insert student: " << name << " - " << birthday << endl;

        Node *newNode = new Node{name, birthday, nullptr};
        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void deleteStudent(string name)
    {
        cout << "Attempting to delete student: " << name << endl;

        if (head == nullptr)
        {
            cout << "List is empty. No students to delete." << endl;
            return;
        }

        if (head->name == name)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node *temp = head;
        while (temp->next != nullptr && temp->next->name != name)
        {
            temp = temp->next;
        }

        if (temp->next == nullptr)
        {
            cout << "Student not found." << endl;
            return;
        }

        Node *toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    void displayBirthdayMessage(string currentDate)
    {
        if (head == nullptr)
        {
            cout << "List is empty. No students to wish." << endl;
            return;
        }

        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->birthday == currentDate)
            {
                cout << "Happy Birthday, " << temp->name << "!" << endl;
            }
            temp = temp->next;
        }
    }

    int searchindex(string nm)
    {
        Node *temp = head;
        int index = 0;
        while (temp != nullptr)
        {
            if (temp->name == nm)
            {
                return index;
            }
            temp = temp->next;
            index++;
        }
        return -1;
    }

    void search(string nm)
    {
        if (head == nullptr)
        {
            cout << "List is empty. No students to search." << endl;
            return;
        }

        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->name == nm)
            {
                cout << "The " << temp->name << " is present in the list "
                     << " ,And his birthdate is " << temp->birthday << " At index " << searchindex(nm) << endl;
            }
            temp = temp->next;
        }
    }

    void displayStudents()
    {
        if (head == nullptr)
        {
            cout << "List is empty." << endl;
            return;
        }

        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->name << " - " << temp->birthday << endl;
            temp = temp->next;
        }
    }

    void length()
    {
        Node *temp = head;
        int count = 0;
        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }
        cout << "The no of students in the linked list are :" << count << endl;
    }
};

int main()
{
    StudentList list;
    int choice;
    int index;
    string nm;
    string name, birthday;
    string currentDate;

    do
    {
        cout << "Menu:" << endl;
        cout << "1. Insert new student" << endl;
        cout << "2. Delete student" << endl;
        cout << "3. Display birthday messages" << endl;
        cout << "4. Display student list" << endl;
        cout << "5. Search a student in the list " << endl;
        cout << "6. No of students in the list  " << endl;
        cout << "7. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter birthday (DD/MM/YYYY): ";
            cin >> birthday;
            list.insertStudent(name, birthday);
            cout << "Entered Successfully" << endl;
            cout << "---------------------------------------------------------------------------------------------------------------------------" << endl;
            break;

        case 2:
            cout << "Enter name to delete: ";
            cin >> name;
            list.deleteStudent(name);
            cout << "Deleted Successfully" << endl;
            cout << "---------------------------------------------------------------------------------------------------------------------------" << endl;
            break;

        case 3:
            cout << "Enter current date (DD/MM/YYYY): ";
            cin >> currentDate;
            list.displayBirthdayMessage(currentDate);
            cout << "---------------------------------------------------------------------------------------------------------------------------" << endl;
            break;

        case 4:
            list.displayStudents();
            cout << "---------------------------------------------------------------------------------------------------------------------------" << endl;
            break;

        case 5:
            cout << "Enter the student name whom you want to search :" << endl;
            cin >> nm;
            list.search(nm);
            cout << "---------------------------------------------------------------------------------------------------------------------------" << endl;
            break;

        case 6:
            list.length();
            cout << "---------------------------------------------------------------------------------------------------------------------------" << endl;
            break;

        case 7:
            cout << "Goodbye! Thankyou for using me :)" << endl;
            cout << "---------------------------------------------------------------------------------------------------------------------------" << endl;
            break;

        default:
            cout << "Invalid choice. Try again." << endl;
            cout << "---------------------------------------------------------------------------------------------------------------------------" << endl;
            break;
        }

    } while (choice != 7);

    return 0;
}
