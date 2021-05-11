/* Write C++ program for storing binary number using doubly linked lists. Write functions- 
a) To compute 1‘s and 2‘s complement  
b) Add two binary numbers 
*/

#include <iostream>
#include <math.h>
using namespace std;
class Node
{
private:
    int bit;
    Node *prev;
    Node *next;

public:
    Node(int data)
    {

        this->bit = data;
        prev = NULL;
        next = NULL;
    }

    friend class DLinkedList;
    friend class Operations;
};

class DLinkedList
{
private:
    Node *head;

public:
    DLinkedList()
    {
        head = NULL;
    }

    void insert1Node(int data)
    {

        // binary bit will be taken as input and a node is created

        Node *newnode = new Node(data);

        if (head == NULL)
        {
            head = newnode;
        }
        else
        {

            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
    }

    void insertdecnumber(int decnum)
    {
        // converts dec num to binary and adds bin to list

        int n = decnum;

        while (n / 2 != 0)
        {

            insert1Node(n % 2);
            n = n / 2;
        }
        insert1Node(1);
    }

    void printLinkedList()
    {

        // in linked list msb is at start and lsb is at end

        if (head == NULL)
        {
            cout << "Empty List.\n";
            return;
        }

        Node *temp = head;

        while (temp)
        {

            cout << temp->bit;
            temp = temp->next;
        }
        cout << "\n";
    }

    int revconvertbintodec()
    {

        // here lsb is aat start and  msb is at end

        Node *temp = head;
        int sum = 0;
        int i = 0;
        while (temp)
        {

            sum += ((temp->bit) * pow(2, i));

            i += 1;
            temp = temp->next;
        }

        return sum;
    }

    int convertbintodec()
    {
        // here msb is at start and  lsb is at end

        Node *temp = head;
        int sum = 0;
        int i = 0;

        // first go to last node means lsb
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        // now temp is pointing to last node

        while (temp != NULL)
        {

            sum += ((temp->bit) * pow(2, i));

            i += 1;
            temp = temp->prev;
        }

        return sum;
    }

    friend class Operations;
};

class Operations
{
private:
    DLinkedList numbers;
    int res;
    int sum;
    int carry;

public:
    Operations()
    {
        sum = 0;
        carry = 0;
    }
    void getInput()
    {
        int decnumber;
        cout << "Enter the number : \n";
        cin >> decnumber;
        numbers.insertdecnumber(decnumber);
    }

    void printList()
    {
        numbers.printLinkedList();
    }

    void onescomplement()
    {
        Node *temp = numbers.head;

        Operations onescompobj;

        while (temp)
        {

            // here list will now be in reversed order
            // lsb is at start
            // msb at end

            if (temp->bit == 0)
            {
                onescompobj.numbers.insert1Node(1);
            }
            else
            {
                onescompobj.numbers.insert1Node(0);
            }

            temp = temp->next;
        }

        res = onescompobj.numbers.revconvertbintodec();
    }

    void printres()
    {
        cout << "\n"
             << res << endl;
    }

    void twoscomplement()
    {

        Node *temp = numbers.head;
        Operations twoscompobj;

        // step 1 : taking ones complement
        while (temp)
        {

            // here list will now be in reversed order lsb is at start  msb at end

            if (temp->bit == 0)
            {
                twoscompobj.numbers.insert1Node(1);
            }
            else
            {
                twoscompobj.numbers.insert1Node(0);
            }

            temp = temp->next;
        }

        Node *temp2 = twoscompobj.numbers.head;

        if (twoscompobj.numbers.head->bit == 0)
        {
            twoscompobj.numbers.head->bit = 1;
            this->res = twoscompobj.numbers.revconvertbintodec();
            return;
        }
        int carry = 0;

        while (temp2->bit != 0 && temp2)
        {

            temp2->bit = 0;
            carry = 1;

            temp2 = temp2->next;
        }

        if (temp2)
        {
            // condition when there exists 0 in the list
            temp2->bit = 1;
        }
        else
        {
            // when there is no 0 (all are 1 in the list), then temp will be null now

            // now insert one node at end  ( which is carry )
            // now value of temp2 is null

            Node *lastnewnode = new Node(1);

            Node *temptrav = twoscompobj.numbers.head;

            while (temptrav->next)
            {
                temptrav = temptrav->next;
            }
            // now temptrav is pointing to existing last node

            temptrav->next = lastnewnode;
            lastnewnode->prev = temptrav;
        }

        res = twoscompobj.numbers.revconvertbintodec();
    }

    int length()
    {

        Node *temp = this->numbers.head;
        int mycount = 0;
        while (temp->next == NULL)
        {
            mycount += 1;
            temp = temp->next;
        }
        cout << mycount << "count ----";
        return mycount;
    }

    void addeachbit(int a, int b)
    {

        // start of ifelse
        if (a == 1)
        {
            if (b == 1)
            {
                sum = 0;
                carry = 1;
            }
            else
            {
                sum = 1;
                carry = 0;
            }
        }
        else
        {
            if (b == 1)
            {
                sum = 1;
                carry = 0;
            }
            else
            {
                sum = 0;
                carry = 0;
            }
        } // end of ifelse
    }

    void adding2binnos(Operations obj2)
    {

        Operations finalsummation;

        Node *head1 = numbers.head;
        Node *head2 = obj2.numbers.head;

        // going to last node  (lsb)  of both lists
        while (head1->next != NULL)
        {
            head1 = head1->next;
        }

        while (head2->next != NULL)
        {
            head2 = head2->next;
        }

        // we have to loop till any node's prev value is NULL
        while (head1 != NULL && head2 != NULL)
        {

            cout << "\n inside first loop \n ";

            // first adding the two bits
            addeachbit(head1->bit, head2->bit);

            // storing their carry in nextcarry

            // store their sum in thissum

            // now add the prevcarry and thissum
            addeachbit(sum, carry);

            // final carry is prevcarry ... bcuz in next loop the nextcarry will be the prevcarry

            // final carry is prevcarry and final sum is thissum

            // now add the final sum to the finalsummation list

            finalsummation.numbers.insert1Node(sum);

            finalsummation.printList();

            // change values for looping (value of current pointing node)
            head1 = head1->prev;
            head2 = head2->prev;

        } // end of while loop

        while (head1 != NULL)
        {

            cout << "\n inside 2nd loop \n";

            // actually there is no use of nextcarry here

            addeachbit(carry, head1->bit);

            // add new node of thisum value in the finalsummation list
            finalsummation.numbers.insert1Node(sum);

            head1 = head1->prev;
        }

        while (head2 != NULL)
        {

            cout << "\n inside 3rd loop \n";

            // actually there is no use of nextcarry here

            addeachbit(carry, head2->bit);

            // add new node of thisum value in the finalsummation list
            finalsummation.numbers.insert1Node(sum);

            head2 = head2->prev;
        }

        if (carry != 0)
            finalsummation.numbers.insert1Node(carry);

        res = finalsummation.numbers.convertbintodec();
        cout << "\nres : " << res << endl;
        return;
    }

    void binaddition(Operations obj2)
    {

        Operations L5;

        Operations finalsummation;

        Node *temp = numbers.head;
        Node *temp2 = obj2.numbers.head;

        // going to last node  (lsb)  of both lists
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        while (temp2->next != NULL)
        {
            temp2 = temp2->next;
        }

        int carry = 0;
        int sum;

        while (temp != NULL && temp2 != NULL)
        {
            sum = temp->bit + temp2->bit + carry;
            carry = 0;
            if (sum == 2)
            {
                L5.numbers.insert1Node(0);
                carry = 1;
            }
            else if (sum == 3)
            {
                L5.numbers.insert1Node(1);
                carry = 1;
            }
            else
            {
                L5.numbers.insert1Node(sum);
            }

            temp = temp->prev;
            temp2 = temp2->prev;
        }

        if (temp2 == NULL && temp != NULL)
        {

            while (temp != NULL)
            {
                sum = temp->bit + carry;
                carry = 0;
                if (sum > 1)
                {
                    L5.numbers.insert1Node(0);
                    carry = 1;
                }
                else
                {
                    L5.numbers.insert1Node(sum);
                }
                temp = temp->prev;
            }
        }

        if (temp == NULL && temp2 != NULL)
        {
            while (temp2 != NULL)
            {
                sum = temp2->bit + carry;
                carry = 0;
                if (sum > 1)
                {
                    L5.numbers.insert1Node(0);
                    carry = 1;
                }
                else
                {
                    L5.numbers.insert1Node(sum);
                }
                temp2 = temp2->prev;
            }
        }

        if (temp2 == NULL && temp == NULL)
        {

            if (carry == 1)
            {
                L5.numbers.insert1Node(1);
            }
        }

        L5.printList();
        res = L5.numbers.convertbintodec();
    }
};

int main()
{

    Operations opobj;

    opobj.getInput();

    opobj.printList();

    cout << " 0. End program \n 1. Ones complement \n 2.Twos complement \n 3.Binary Addition \n";

    while (1)
    {

        int choice;
        cout << "\n Enter choice : \n";
        cin >> choice;

        if (choice == 0)
        {
            cout << "program Ended";
            break;
        }
        else if (choice == 1)
        {
            cout << "\n ones complement \n ";
            opobj.onescomplement();
            opobj.printres();
        }
        else if (choice == 2)
        {
            cout << "\n twos complement \n ";
            opobj.twoscomplement();
            opobj.printres();
        }
        else if (choice == 3)
        {

            Operations opobj2;
            opobj2.getInput();
            opobj2.printList();

            cout << "\n \n BiNARY ADDITION \n \n";

            opobj.binaddition(opobj2);
            opobj.printres();
        }
        else
        {
            cout << "Wrong choice";
        }
    }

    return 0;
}
