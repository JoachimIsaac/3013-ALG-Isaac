///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Joachim Isaac
// Email:            joachimvivian3@gmail.com
// Label:            A02
// Title:            Linked List Class
// Course:           CMPS 3013
// Semester:         Spring 2020
//
// Description:
//       This is a program that creates a Linked list class and it's methods
//       and demonstrates the uses of them and how they are used. i.e pushing,
//       popping, printing and combining linked list together.  
//
// Usage:
//       - run main_commented.cpp either through terminal or through IDE
//       - no input is needed and the results are printed to the screen.
//
// Files: 
//       main_commented.cpp
/////////////////////////////////////////////////////////////////////////////////



#include <iostream>

using namespace std;


int A[100];     //Declared and array of size 100.


/**
 * Node
 * 
 * Description:
 *      A Struct which holds the data and properties of
 *      a node in a linked list which has a pointer
 *      to point to another node called (next) and (x) 
 *      which is the what holds the data that is inserted
 *      into the node.
 * 
 * Public Methods:
 *       - Constructor ( Node() ) 
 *       - Parameterized Constructor ( Node(int n) )
 * 
 * Private Methods:
 *       - None
 * 
 * Usage: 
 *           int val = 3;
 *           Node *Temp = new Node(val);
 *           Node *Temp2 = new Node();
 *           Temp->x = 5;
 *           Temp2->x = 6;
 *           Temp->next = Temp2;
 *      
 *      
 *      ************************************
 */

struct Node {
    int x;        //int value of Node
    Node *next;   //Pointer that points to next Node

    /**
     * Public: Node()
     * 
     * Description:
     *      This is a default constructor that sets defaults for the node's 
     *      value and pointer.
     * 
     * Params:
     *      None
     * 
     * Returns:
     *      None
     */
    Node() {
        x = -1;            // by default, x is set to -1
        next = NULL;       // next points to NULL.
    }

    
    /**
     * Public: Node(int n)
     * 
     * Description:
     *      This is a parameterized constructor you can set the value of the node
     *      to a specific int value (n).
     * 
     * Params:
     *      int : value to store in Node.
     * 
     * Returns:
     *      None
     */
    Node(int n) { 
        x = n;         // x is equal to the current value of n 
        next = NULL;  // next is equal to NULL.
    }
};



/**
 * Class List
 * 
 * Description:
 *      A list class made up of Head, Tail and Size member data.
 *      It uses this combined with the struct called Node to construct
 *      a linked list.
 * 
 * Public Methods:
 *      - Constructor List()
 *      - void: Push(int val)
 *      - void: Insert(int val)
 *      - void: PrintTail()
 *      - string: Print()
 *      - int:  Pop()
 *      - List: operator+(const List &Rhs)
 *      - int: operator[](int index)
 *      - ostream: &operator<<(ostream &os, List L)
 * 
 * Private Methods:
 *      - None
 * 
 * Usage:
 *          List L1;
 *          List L2;
 *          List L3;
 *          L1.push(10);
 *          L1.push(20);
 *          L1.push(30);
 *          L2.push(40);
 *          L2.push(50);
 *          L2.push(60);
 *          L3 = L1 + L2;
 *          L3.print();
 *          L3.pop();
 *          L3.insert(14);
 *          cout << L3[2];
 *
 * ************************   
 */

class List {
private:
    Node *Head;     //Pointer which points to a Node and represents the head of the list.
    Node *Tail;     //Pointer which points to a Node and represents the tail or end of the list.
    int Size;       //An integer value that represents the size of the list currently.

public:


     /**
     * Public: List()
     * 
     * Description:
     *      This is a Default constructor for the List class which sets the 
     *      Head, Tail and Size to their default values.
     * 
     * Params:
     *      int : value to store in Node.
     * 
     * Returns:
     *      None
     */
    List() {
        Head = Tail = NULL;  // head and tail are set to NULL
        Size = 0;            // Size is set to zero.
    }



    /**
     * Public: Push(int val)
     * 
     * Description:
     *      Adds a new node to the list from the end/Tail, sets the Head and Tail 
     *      pointers to their appropriate positions and then increments the size of the list.
     * 
     * Params:
     *     - int :  value to store in the Node that will be constructed
     *              and added to the list.
     * 
     * Returns:
     *      - Doesn't return anything.
     */
    void Push(int val) {
        // allocate new memory and init node
        Node *Temp = new Node(val);     // Create a new node.

        if (!Head && !Tail) {           //If head and tail point to nothing, set both of them to the new Node
            Head = Tail = Temp;
        } else {                        //else let the current tail point to the new Node.
            Tail->next = Temp;
            Tail = Temp;
        }

        Size++;                         // Increase the size of the Linked list.
    }



    /**
     * Public: Insert(int val)
     * 
     * Description:
     *      Inserts a Node at the Front/Head of the list rather than from the Tail/End.
     * 
     * Params:
     *        - int :  value to store in the Node that will be constructed
     *                 and added to the list.
     * 
     * Returns:
     *      - Doesn't return anything.
     */
    void Insert(int val) {
        // allocate new memory and init node
        Node *Temp = new Node(val);

        // figure out where it goes in the list

        Temp->next = Head;       // makes the new Node point to the current head.
        Head = Temp;            // makes head the new node that was inserted at head.
        if (!Tail) {           // if tail doesn't point to anything then make tail point to head.
            Tail = Head;
        }
        Size++;                // Increase the size of the linked list.
    }


    /**
     * Public : PrintTail()
     * 
     * Description:
     *      This function prints the value of the tail of the linked list.
     * 
     * Params:
     *      - None
     * 
     * Returns:
     *      - Doesn't return anything.
     */
    void PrintTail() {
        cout << Tail->x << endl; //Prints the value of the Node that tail points to.
    }


    /**
     * Public : Print()
     * 
     * Description:
     *      Creates a string of the entire list values using '->' to make it readable
     *      then it returns that string. 
     * 
     * Params:
     *      - None
     * 
     * Returns:
     *      - returns a string of list values connected by "->"
     */
    
    string Print() {
        Node *Temp = Head;
        string list;

        while (Temp != NULL) { // loads the value of each node into the string list with this "-->"
            list += to_string(Temp->x) + "->";
            Temp = Temp->next;
        }

        return list; // Then it returns the string of the list. 
    }


    /**
     * Public: Pop()
     * 
     * Description:
     *      Remove the Node at the tail of the list and decreases the Size of the list.
     * 
     * Params:
     *      - None
     *      
     * 
     * Returns:
     *      - Currently Zero, otherwise the value of the removed Node.
     */
    
    // not implemented
    int Pop() {
        Size--;
        return 0; //
    }


    /**
     * Public : operator+(const List &Rhs)
     * 
     * Description:
     *      Concatenates two lists together(essenstial connects two lists together)
     * 
     * Params:
     *      - const List : The other list which gets added on 
     * 
     * Returns:
     *      - It returns a new concatenated version of the lists.
     */
    List operator+(const List &Rhs) {
        // Create a new list that will contain both when done
        List NewList;

        // Get a reference to beginning of local list
        Node *Temp = Head;

        // Loop through local list and Push values onto new list
        while (Temp != NULL) {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        // Get a reference to head of Rhs
        Temp = Rhs.Head;

        // Same as above, loop and push
        while (Temp != NULL) {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        // Return new concatenated version of lists
        return NewList;
    }


    /**
     * Public: operator[](int index)
     * 
     * Description:
     *      Overloads the '[]' operator to allow indexing for a linked list.
     * 
     * Params:
     *      -int: an integer number which represents the postion of a specific Node.
     * 
     * Returns:
     *      - Returns the value of the data in the Node that is in the current position 
     *      - as indicated by the overloaded '[]'.
     */
    // Implementation of [] operator.  This function returns an
    // int value as if the list were an array.
    int operator[](int index) {

        Node *Temp = Head;    //Creates a pointer that points to the head of the list.

        if (index >= Size) {  //Handles when an index is entered that is greater 
                              //than or equeal to the current size.
            cout << "Index out of bounds, exiting";
            exit(0);

        } else {

            for (int i = 0; i < index; i++) { //Gets to the correct postion and makes temp point to that Node.
                Temp = Temp->next;
            }

            return Temp->x; //Returns the value of the current temp.
        }
    }


    /**
     * Public : &operator<<(ostream &os, List L)
     * 
     * Description:
     *      This overloads the "<<" operator and makes it change a list into a string when followed by it.
     * 
     * Params:
     *      - ostream: Part of class ostream
     *      - List:  A list so that we can use .print to turn it into a string.
     *      
     * 
     * Returns:
     *      - It returns a string which is made up of the values of the Nodes in a list.
     */
    friend ostream &operator<<(ostream &os, List L) {

        os << L.Print(); // Allows what ever ostream object act on the list as a String
                         // i.e cout << l1 (where l1 is a list)

        return os;

    }
};

int main(int argc, char **argv) {

    List L1;    //Create a list name L1
    List L2;    //Create a list name L2

    for (int i = 0; i < 25; i++) {  //Loads list 'L1' with numbers 0-24.
        L1.Push(i);
    }

    for (int i = 50; i < 100; i++) { //Loads list 'L2' with numbers 50-99.
        L2.Push(i);
    }

    //cout << L1 << endl;
    L1.PrintTail(); //Prints the tail of list 'L1'
    L2.PrintTail(); //Prints the tail of list 'L2'

    List L3 = L1 + L2; // Adds list 'L1' and list 'L2' together 
    cout << L3 << endl; // Prints out list 'l3'

    cout << L3[5] << endl; // Prints out the value at position 5 of list 'L3'


    return 0;
}
