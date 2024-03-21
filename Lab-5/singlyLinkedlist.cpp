#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        this->data =0;
        this->next = NULL;
    }
};

class SinglyLinkedList
{
public:
    Node *head = NULL;

    void insertAtFront(int x)
    {
        Node *newNode = new Node;

        if (head == NULL)
        {
            head = newNode;
            newNode->data = x;
        }

        else
        {
            newNode->data = x;
            newNode->next = head;
            head = newNode;
        }
    }

    void insertAtBack(int x)
    {
        Node *newNode = new Node;

        if (head == NULL)
        {
            head = newNode;
            newNode->data = x;
        }

        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->data = x;
        }
    }

    void insertBetween(int x, int ind)
    {
        Node *newNode = new Node;

        Node *temp = head;
        int i = 0;

        while (i < ind - 1)
        {
            // cout << "i : " << i << ", temp points to : " << temp->data << endl;
            temp = temp->next;
            i++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        newNode->data = x;
    }

    void deleteFromList(int index)
    {
        Node *temp = head;
        if (index == 0)
        {
            head = head->next;
            delete temp;
        }
        else
        {
            int i = 1;
            while (i < index)
            {
                temp = temp->next;
                i++;
            }
            Node *deletedNode = temp->next;
            temp->next = temp->next->next;
            cout << deletedNode->data << " was deleted" << endl;
            delete deletedNode;
        }
    }

    void deleteFromFront()
    {
        if (head == NULL)
        {
            cout << "Void deletion" << endl;
        }
        else
        {
            cout << head->data << " was deleted" << endl;
            head = head->next;
        }
    }

    void deleteFromBack()
    {
        if (head == NULL)
        {
            cout << "Void deletion" << endl;
        }
        else
        {
            Node *temp = head;
            while (temp->next->next != NULL)
            {
                temp = temp->next;
            }
            cout << temp->next->data << " was deleted" << endl;
            temp->next = NULL;
        }
    }

    bool search(int x)
    {
        Node *temp = head;

        if (temp == NULL)
        {
            cout << "Can't search the list is empty." << endl;
            return 0;
        }

        int flag = 0;
        while (temp != NULL)
        {
            if (temp->data == x)
            {
                flag = 1;
                break;
            }
            else
            {
                flag = 0;
            }
            temp = temp->next;
        }
        if (flag == 1)
        {
            cout << x << " was found." << endl;
            return 1;
        }
        else
        {
            cout << x << " was not found." << endl;
            return 0;
        }
    }

    void traverse()
    {
        Node *temp = head;

        while (temp != NULL)
        {
            cout << temp->data
                 << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void mainProcess()
    {
        // insertAtFront(5);
        // insertAtBack(6);
        // insertAtBack(7);
        // insertAtBack(8);
        // insertAtBack(9);
        // insertAtBack(10);
        // traverse();
        // insertAtFront(4);
        // traverse();
        // deleteFromList(1);
        // traverse();
        // insertBetween(5,1);
        // traverse();

        int uInput;
        do
        {
            cout << "Choose an operation from below: " << endl;
            cout << "1 ) Insert at beginning" << endl
                 << "2 ) Insert at end" << endl
                 << "3 ) Insert in between" << endl
                 << "4 ) Traverse" << endl
                 << "5 ) Delete from beginning" << endl
                 << "6 ) Delete from end" << endl
                 << "7 ) Delete in between" << endl
                 << "8 ) Search"<<endl
                 << "9 ) Exit the program" << endl;
            cin >> uInput;
            switch (uInput)
            {
            case 1:
                int valuef;
                cout << "Enter a number to input: ";
                cin >> valuef;
                insertAtFront(valuef);
                cout<<valuef <<" is inserted."<<endl;
                break;

            case 2:
                int valuel;
                cout << "Enter a number to input: ";
                cin >> valuel;
                insertAtBack(valuel);
                 cout<<valuel <<" is inserted."<<endl;
                break;

            case 3:
                int valueb, pos;
                cout << "Enter a number to input: ";
                cin >> valueb;
                cout << "Enter a position : ";
                cin >> pos;
                insertBetween(valueb, pos);
                 cout<<valueb <<" is inserted."<<endl;
                break;

            case 4:
                traverse();
                break;

            case 5:
                deleteFromFront();
                break;

            case 6:
                deleteFromBack();
                break;

            case 7:
                int ui;
                cout << "Enter an index to delete: ";
                cin >> ui;
                deleteFromList(ui);
                break;
            case 8:
            	int vi;
            	cout<<"Enter the element to search:";
            	cin>>vi;
            	search(vi);
            	break;

            case 9:
                cout << "Program is exiting..." << endl;
                break;

            default:
                cout << "Invalid input" << endl;
                break;
            }
        } while (uInput != 8); 
    }
};

int main()
{
    SinglyLinkedList s1;
    s1.mainProcess();
}
