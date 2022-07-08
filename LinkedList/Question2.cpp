#include <iostream>
using namespace std;

struct list1
{
    int data;
    list1 *next = NULL;
};
list1 *head1 = NULL;
list1 *tail1 = NULL;

struct list2
{
    int data;
    list2 *next = NULL;
};
list2 *head2 = NULL;
list2 *tail2 = NULL;

struct list3
{
    int data;
    list3 *next = NULL;
};
list3 *head3 = NULL;
list3 *tail3 = NULL;

void display1();
void display2();
void display3();
void insert_list1();
void insert_list2();
void insert_list3(int);
void merged_list();
void sortenning(list3 *);
void sortenning2();
void sortenning1();
int main()
{
    int exit = 1;
    do
    {
        cout << "Enter the command number you want to execute\n";
        cout << "1. Enter data in first list\n";
        cout << "2. Enter data in second list\n";
        cout << "3. Display First List\n";
        cout << "4. Display Second List\n";
        cout << "5. Display Third List\n";
        cout << "6. Display Merged List\n";
        cout << "0.Exit\n";
        cout << ">> ";
        cin >> exit;
        cout << "\n";

        switch (exit)
        {
        case 0:
            cout << "Exiting.....\n";
            break;
        case 1:
            insert_list1();
            break;
        case 2:
            insert_list2();
            break;
        case 3:
            display1();
            break;
        case 4:
            display2();
            break;
        case 5:
            display3();
            break;
        case 6:
            merged_list();
            break;
        // case 6:
        //     earning_Specific();
        //     break;
        // case 7:
        //     earning_all();
        //     break;
        default:
            cout << "Wrong Number Entered. Please try again.....\n";
            break;
        }
    } while (exit != 0);
    return 0;
}

void insert_list1()
{
    list1 *curr = new list1;
    cout << "Enter data>> ";
    int id;
    cin >> id;
    curr->data = id;
    if (head1 == NULL)
    {
        head1 = tail1 = curr;
        tail1->next = head1;
    }
    else
    {
        curr->next = head1;
        tail1->next = curr;
        tail1 = curr;
    }
}
// Display
void display1()
{
    list1 *p = head1;
    if (head1 == NULL)
    {
        cout << "No Record Found" << endl;
    }
    else
    {
        while (p->next != head1)
        {
            cout << "Id is >> " << p->data << endl;
            p = p->next;
        }
        cout << "Id is >> " << p->data << endl;
    }
}
void insert_list2()
{
    list2 *curr = new list2;
    cout << "Enter data>> ";
    int id;
    cin >> id;
    curr->data = id;
    if (head2 == NULL)
    {
        head2 = tail2 = curr;
        tail2->next = head2;
    }
    else
    {
        curr->next = head2;
        tail2->next = curr;
        tail2 = curr;
    }
}
// Display
void display2()
{
    list2 *p = head2;
    if (head2 == NULL)
    {
        cout << "No Record Found" << endl;
    }
    else
    {
        do
        {
            cout << "Id is >> " << p->data << endl;
            p = p->next;
        } while (p != head2);
    }
}

void merged_list()
{
    sortenning1();
    sortenning2();
    list1 *p = head1;
    list2 *k = head2;
    do
    {
        list3* curr = new list3;
        if (p->data > k ->data)
        {
            insert_list3(p->data);
            insert_list3(k->data);
        }else
        {
            insert_list3(k->data);
            insert_list3(p->data);
        }
        p = p->next;
        k = k->next;

    } while (p != head1 && k != head2);
}

void insert_list3(int d)
{
    list3 *curr = new list3;
    curr->data = d;
    if (head3 == NULL)
    {
        head3 = tail3 = curr;
        tail3->next = head3;
    }
    else
    {
        curr->next = head3;
        tail3->next = curr;
        tail3 = curr;
    }
}
// Display
void display3()
{
    list3 *p = head3;
    if (head3 == NULL)
    {
        cout << "No Record Found" << endl;
    }
    else
    {
        while (p->next != head3)
        {
            cout << "Id is >> " << p->data << endl;
            p = p->next;
        }
        cout << "Id is >> " << p->data << endl;
    }
}
void sortenning(list3 *head)
{
    list3 *p;
    list3 *k;
    p = head;
    do
    {
        list3 *k = p->next;
        do
        {
            if (p->data < k->data)
            {
                k = k->next;
            }
            else
            {
                int temp = k->data;
                k->data = p->data;
                p->data = temp;
                k = k->next;
            }
        } while (k->next != head3);
        p = p->next;
    } while (p->next != head3);
}

void sortenning2()
{
    list2 *p = head2;
    list2 *k = p->next;
    do
    {
        do
        {
            if (p->data >= k->data)
            {
                int temp = p->data;
                p->data = k->data;
                k->data = temp;
            }
            k = k->next;
        } while (k != head2);
        p = p->next;
    } while (p != head2);
}                   
void sortenning1()     
{ 
    list1 *p = head1;
    list1 *k = p->next;
    do
    {
        do
        {
            if (p->data >= k->data)
            {
                int temp = p->data;
                p->data = k->data;
                k->data = temp;
            }
            k = k->next;
        } while (k != head1);
        p = p->next;
    } while (p != head1);
}

