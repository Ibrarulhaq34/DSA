#include <iostream>
#include <cstring>
using namespace std;
#define V 7

//Struct of Passenger
struct passenger
{
    string passengerName;
    int passengerAge;
    string cnic_no;
    string departure_time;
    string landing_time;
    string seat_no;
    string phoneNum;
    string gender;
    passenger *passenger_next = NULL;
    passenger *passenger_prev = NULL;
};
passenger *passenger_last_ptn = NULL, *passenger_first_ptn = NULL;

// Admin Log in Details
string adminName = "Admin";
string adminPass = "123";

int routes[V][V];
void login();
void insertEnd();
int search(string);
void deleteSpecific(string);
void admin_menu();
passenger* searchPassenger();
void displaySpecificPassenger();
void displayPassenger();
void addPassenger();
void ticketBookingMenu();
void cancelPassengerTicket();
void cancelPassengerTicket();
void avalaiblePilots();
void addPilotToJourney();
void planAJourney();
    // Passengers and VIP Passengers structs implementing doubly linked list and priority queues respectively
    int startIndex = -1,
        lastIndex = -1;
string pilots[6] = {"Ibrar", "Ibrahim", "Faisal", "Deepak Khatri", "Ahmed", "Rashid"};
// Search from array
int search(string element)
{
    for (int i = startIndex; i < lastIndex; i++)
    {
        if (pilots[i] == element)
        {
            return i;
        }
    }
    return -1;
}
// Insert  into Array
void insertEnd()
{
    if (startIndex == 0 && lastIndex == 50)
    {
        cout << "No space\n";
    }
    else if (lastIndex == 50 && startIndex != 0)
    {
        int count = startIndex;
        while (count <= lastIndex)
        {
            pilots[count - 1] = pilots[count];
            count++;
        }
        cout << "Enter name at to insert: ";
        cin >> pilots[lastIndex];
        startIndex--;
    }
    else if (lastIndex == -1 && startIndex == -1)
    {
        startIndex++;
        cout << "Enter name at to insert: ";
        cin >> pilots[startIndex];
        lastIndex = 1;
    }
    else
    {
        cout << "Enter name at to insert: ";
        cin >> pilots[lastIndex];
        lastIndex++;
    }
}
// Delete From Array
void deleteSpecific(string element)
{
    if (startIndex == -1)
    {
        cout << "Empty-------\n";
    }
    else if (lastIndex == 0)
    {
        cout << "Only 1 element found and deleted\n";
        startIndex = lastIndex = -1;
    }
    else
    {
        cout << "\n";
        int index = search(element);
        if (index == -1)
        {
            cout << "Wrong element entered\n";
        }
        else
        {
            int count = index;
            while (count < lastIndex - 1)
            {
                pilots[count] = pilots[count + 1];
                count++;
            }
            lastIndex--;
        }
    }
}

class Queue
{
public:
    int size;
    int front;
    int rear;
    string *q;
    Queue(int s)
    {
        front = rear = -1;
        size = s;
        q = new string[size];
    }
    bool isFull()
    {
        if (rear == size - 1)
        {
            return true;
        }
        return false;
    }

    bool isEmpty()
    {
        if (front == -1)
        {
            return true;
        }
        return false;
    }
    void pilotadd(string x)
    {
        if (isFull())
        {
            cout << "No Space Available" << endl;
            return;
        }
        else
        {
            if (front == -1 && rear == -1)
            {
                rear++;
                front++;
            }
            else
            {
                rear++;
            }
            q[rear] = x;
        }
    }
    string pilotremove()
    {
        if (isEmpty())
        {
            cout << "Already empty" << endl;
        }
        else
        {
            string x = q[rear];
            if (rear == front)
            {
                rear = front = -1;
            }
            else
            {
                rear--;
            }
            return x;
        }
    }
    void pilotdisplay()
    {
        if (isEmpty())
        {
            cout << "No record to found..." << endl;
            return;
        }
        else
        {
            for (int i = 0; i < size; i++)
            {
                cout << q[i] << endl;
            }
        }
    }
};

// Search Method
passenger* searchPassenger()
{
    cout << "Enter the cnic of passenger: ";
    string key;
    cin >> key;
    passenger *p = passenger_first_ptn;
    while ((p->cnic_no != key) && (p != NULL))
    {
        p = p->passenger_next;
    }
    if (p == NULL)
    {
        return NULL;
    }
    else
    {
        return p;
    }
}

// Admin Menu
void admin_menu()
{
    string choice;
    while (true)
    {
        cout << "\n------------------------------------------------------------\n";
        cout << "Enter any choice to perform any of the below opertion:" << endl;
        cout << "1 . Ticket Booking" << endl;
        cout << "2 . Plan a journey" << endl;
        cout << "0 .To exit" << endl;
        cout << "\n------------------------------------------------------------\n";
        cin >> choice;
        if (choice == "1")
        {
            ticketBookingMenu();
        }
        else if (choice == "2")
        {
            planAJourney();
        }
        else if (choice == "0")
        {
            break;
        }
        else
        {
            continue;
        }
    }
}
// Ticket Booking Menu
void ticketBookingMenu()
{
    string choice;

    while (true)
    {
        cout << "\n------------------------------------------------------------\n";
        cout << "Enter any choice to perform any of the below opertion:" << endl;
        cout << "1 . Add Passenger Records" << endl;
        cout << "2 . Display All Passenger Records" << endl;
        cout << "3 . Display Specific Passenger Record" << endl;
        cout << "4 . Cancel Flight" << endl;
        cout << "0 . To exit" << endl;
        cout << "\n------------------------------------------------------------\n";
        cin >> choice;

        if (choice == "1")
        {
            addPassenger();
        }
        else if (choice == "2")
        {
            displayPassenger();
        }
        else if (choice == "3")
        {
            displaySpecificPassenger();
        }
        else if (choice == "4")
        {
            cancelPassengerTicket();
        }
        else if (choice == "0")
        {
            break;
        }
        else
        {
            continue;
        }
    }
}

// Add Passenger
void addPassenger()
{

    passenger *curr = new passenger;

    cout << "Enter the passenger name: ";

    cin >> curr->passengerName;

    cout << "Enter the passenger age: ";

    cin >> curr->passengerAge;

    cout << "Enter the cnic of passenger: ";

    cin >> curr->cnic_no;

    cout << "Enter the departure time: ";

    cin >> curr->departure_time;

    cout << "Enter the landing time: ";

    cin >> curr->landing_time;

    cout << "Enter the seat no: ";

    cin >> curr->seat_no;

    cout << "Enter the Gender: ";

    cin >> curr->gender;

    if (passenger_first_ptn == NULL)
    {
        passenger_first_ptn = passenger_last_ptn = curr;
    }
    else
    {
        if (passenger_first_ptn == passenger_last_ptn)
        {
            curr->passenger_next = NULL;
            passenger_first_ptn->passenger_next = curr;
            passenger_last_ptn = curr;
        }
        else
        {
            curr->passenger_next = NULL;
            passenger_last_ptn->passenger_next = curr;
            passenger_last_ptn = curr;
        }
    }
    cout << "**New Passenger added!\n";
}
void displayPassenger()
{
    passenger *p = passenger_first_ptn;
    bool found = false;
    while (p != NULL)
    {
        cout << "Passenger Details" << endl;

        cout << "Name: " << p->passengerName << endl;

        cout << "Age: " << p->passengerAge << endl;

        cout << "CNIC: " << p->cnic_no << endl;

        cout << "Gender: " << p->gender << endl;

        cout << "Arrival Time: " << p->landing_time << endl;

        cout << "Departure Time: " << p->departure_time << endl;

        cout << "Seat No: " << p->seat_no << endl;

        cout << endl;
        found = true;
        p = p->passenger_next;
    }
    if (!found)
    {
        cout << "Passengers not found..........." << endl;
    }
}
// Display Specific Passenger
void displaySpecificPassenger()
{
    passenger *p = searchPassenger();
    if (p == NULL)
    {
        cout << "No record found.........." << endl;
    }
    else
    {
        cout << "Passenger Details" << endl;

        cout << "Name: " << p->passengerName << endl;

        cout << "Age: " << p->passengerAge << endl;

        cout << "CNIC: " << p->cnic_no << endl;

        cout << "Gender: " << p->gender << endl;

        cout << "Arrival Time: " << p->landing_time << endl;

        cout << "Departure Time: " << p->departure_time << endl;

        cout << "Seat No: " << p->seat_no << endl;
    }
}
// Display Specific Passenger
void cancelPassengerTicket()
{
    passenger *p = searchPassenger();
    if (p == NULL)
    {
        cout << "No record found.........." << endl;
    }
    else
    {
        if (p == passenger_first_ptn)
        {
            p = NULL;
            passenger_first_ptn = passenger_last_ptn = NULL;
        }
        else if (p == passenger_last_ptn)
        {
            passenger_last_ptn->passenger_prev->passenger_next == NULL;
            passenger_last_ptn = passenger_last_ptn->passenger_prev;
        }
        else
        {
            p->passenger_prev->passenger_next = p->passenger_next;
        }
        delete p;
        cout << "**Passenger's Flight Cancel!\n";
    }
}
// Login Menu
void login()
{
    // Admin Log in Details
    string adminName = "Admin";
    string adminPass = "123";
    cout << "************************************************************************************\n";
    cout << " Welcome to Airline Management System \n";
    cout << "************************************************************************************\n\n";
    cout << "Do you want to login? yes/not: ";
    string opt;
    cin >> opt;
    if (opt == "yes")
    {

        int flag1 = 0;
        int flag2 = 0;

        cout << "Please Enter the log In details\n";

        do
        {

            cout << "Enter admin name: ";

            string guess_admin;

            cin >> guess_admin;

            if (guess_admin == adminName)
            {
                flag1 = 1;
            }

            else
            {

                cout << "Admin name is incorrect" << endl;
            }

        }

        while (flag1 != 1);

        do
        {

            string guess_pass;

            cout << "Enter admin passcode: ";

            cin >> guess_pass;

            if (guess_pass == adminPass)
            {
                flag2 = 1;
            }

            else
            {

                cout << "Incorrect Password. Kindly try again" << endl;
            }

        } while (flag2 != 1);
        admin_menu();
    }
    else
    {
        exit(0);
    }
}
//<<<<<<<<<<<<<<<<<<<<<<< Plan a Journey >>>>>>>>>>>>>>>>>>>>>>>>>>>>>//
void planAJourney(){
    string choice;

    while (true)
    {
        cout << "\n------------------------------------------------------------\n";
        cout << "Enter any choice to perform any of the below opertion:" << endl;
        cout << "1 . Add Pilot To Journey" << endl;
        cout << "2 . Plan Route" << endl;
        cout << "3 . Cancel Flight" << endl;
        cout << "0 . To exit" << endl;
        cout << "\n------------------------------------------------------------\n";
        cin >> choice;

        if (choice == "1")
        {
            addPilotToJourney();
        }
        else if (choice == "2")
        {
            displayPassenger();
        }
        else if (choice == "3")
        {
            displaySpecificPassenger();
        }
        else if (choice == "4")
        {
            cancelPassengerTicket();
        }
        else if (choice == "0")
        {
            break;
        }
        else
        {
            continue;
        }
    }
}
// Display Avaialable Pilots
void avalaiblePilots()
{
    for (int i = 0; i < (sizeof(pilots) / sizeof(string)); i++)
    {
        cout << (i + 1) << " " << pilots[i] << endl;
    }
    cout << endl;
}
//Add Pilots to Journey
void addPilotToJourney()
{
    cout<<"<<<<<<<<<<<<<<<<<< Available Pilots >>>>>>>>>>>>>>>";
    avalaiblePilots();
    string name;
    cout << "Enter name of Pilot: ";
    cin >> name;
    deleteSpecific(name);
    Queue obj(15);
    obj.pilotadd(name);
    cout<<"Pilot Added to a Journey"<<endl;
}
int main()
{
    login();
    return 0;
}
