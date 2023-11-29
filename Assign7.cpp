#include <iostream>
using namespace std;

struct Node
{
    string name;
    int starttime;
    int endtime;
    Node *next;
};

class Appointment
{
public:
    Node *head = nullptr;
    int count = 0;

    void bookAppointment(string name, int startTime, int endTime)
    {
        Node *newNode = new Node{name, startTime, endTime, nullptr};
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        count++;
        cout << "Appointment booked successfully for " << newNode->name << " at time " << newNode->starttime << ":" << newNode->endtime << endl;
    }

    void displayFreeSlots()
    {
        if (head == nullptr)
        {
            cout << "No appointments scheduled for the day." << endl;
            return;
        }

        Node *temp = head;
        int last_end_time = 900;

        while (temp != nullptr)
        {
            if (temp->starttime > last_end_time)
            {
                cout << "Free slot from " << last_end_time << " to " << temp->starttime << endl;
            }

            last_end_time = max(last_end_time, temp->endtime);
            temp = temp->next;
        }

        if (last_end_time < 1700)
        {
            cout << "Free slot from " << last_end_time << " to 1700" << endl;
        }
        else{
            cout<<"Sorry,There are no free slots for today try tommorow"<<endl;
        }
    }

    void cancelling(string name)
    {
        cout << "Cancelling the appointment of " << name << endl;

        if (head == nullptr)
        {
            cout << "List is empty. No appointments to cancel." << endl;
            return;
        }

        if (head->name == name)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            count--;
            return;
        }

        Node *temp = head;
        while (temp->next != nullptr && temp->next->name != name)
        {
            temp = temp->next;
        }

        if (temp->next == nullptr)
        {
            cout << "Appointment not found." << endl;
            return;
        }

        Node *toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
        count--;
    }

    Node *swap(Node *ptr1, Node *ptr2)
    {
        Node *tmp = ptr2->next;
        ptr2->next = ptr1;
        ptr1->next = tmp;
        return ptr2;
    }

    void bubbleSort()
    {
        Node *h = head;
        int i, j, swapped;

        for (i = 0; i < count; i++)
        {
            h = head;
            swapped = 0;

            for (j = 0; j < count - i - 1; j++)
            {
                Node *p1 = h;
                Node *p2 = p1->next;

                if (p1->endtime > p2->endtime)
                {
                    head = swap(p1, p2);
                    swapped = 1;
                }

                h = h->next;
            }

            if (swapped == 0)
                break;
        }
    }

    void displayAppointments()
    {
        if (head == nullptr)
        {
            cout << "No appointments scheduled" << endl;
            return;
        }

        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->name << " scheduled at " << temp->starttime << ":" << temp->endtime << endl;
            temp = temp->next;
        }
    }

    void displayDeletedAppointments()
    {
    }
};

int main()
{
    Appointment ap;
    string name;
    int startTime, endTime, choice;

    cout << "---------------------------------------------------------------------------------------------------------------------------" << endl;

    do
    {
        cout << "\nMenu:" << endl;
        cout << "1. Book an Appointment " << endl;
        cout << "2. Display free slots " << endl;
        cout << "3. Cancel Appointments " << endl;
        cout << "4. Sort list based on time " << endl;
        cout << "5. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter the starting time for appointment (HHMM): ";
            cin >> startTime;
            cout << "Enter the ending time for appointment (HHMM): ";
            cin >> endTime;
            ap.bookAppointment(name, startTime, endTime);
            cout << "---------------------------------------------------------------------------------------------------------------------------" << endl;
            break;

        case 2:

            ap.displayFreeSlots();
            cout << "---------------------------------------------------------------------------------------------------------------------------" << endl;
            break;

        case 3:
            cout << "Enter the name which you used for booking: ";
            cin >> name;
            ap.cancelling(name);
            cout << "---------------------------------------------------------------------------------------------------------------------------" << endl;
            break;

        case 4:
            cout << "Sorting the list based on time..." << endl;
            ap.bubbleSort();
            ap.displayAppointments();
            cout << "---------------------------------------------------------------------------------------------------------------------------" << endl;
            break;

        case 5:
            cout << "Goodbye! Thank you for using me :)" << endl;
            cout << "---------------------------------------------------------------------------------------------------------------------------" << endl;
            break;

        default:
            cout << "Invalid choice. Try again." << endl;
            cout << "---------------------------------------------------------------------------------------------------------------------------" << endl;
            break;
        }

    } while (choice != 5);

    return 0;
}