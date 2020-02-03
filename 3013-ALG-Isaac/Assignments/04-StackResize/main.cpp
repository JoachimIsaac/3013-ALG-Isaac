///////////////////////////////////////////////////////////////////////////////
//
// Author:           Joachim Isaac 
// Email:            joachimvivian3@gmail.com
// Label:            L04
// Title:            Assignment 4 - Array Based Stack
// Course:           3013
// Semester:         Spring 2020
//
// Description:
//       Overview of a class implementing an array based stack
//
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

/**
 * ArrayStack
 * 
 * Description:
 *      Array based stack
 * 
 * Public Methods:
 *      - See class below
 * 
 * Usage: 
 *      - See main program
 *      
 */
class ArrayStack{
private:
  int *A;           // pointer to array of int's
           // current max stack size
           // top of stack 

public:
  int top; 
  int size;
 /**
  * ArrayStack
  * 
  * Description:
  *      Constructor no params
  * 
  * Params:
  *     - None
  * 
  * Returns:
  *     - NULL
  */
  ArrayStack(){
    size = 10;
    A = new int[size];
    top = -1;
  }

 /**
  * ArrayStack
  * 
  * Description:
  *      Constructor size param
  * 
  * Params:
  *     - int size
  * 
  * Returns:
  *     - NULL
  */
  ArrayStack(int s){
    size = s;
    A = new int[s];
    top = -1;
  }

 /**
  * Public bool: Empty
  * 
  * Description:
  *      Stack empty?
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      [bool] true = empty
  */
  bool Empty(){
    return (top <= -1);
  }
  
 /**
  * Public bool: Full
  * 
  * Description:
  *      Stack full?
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      [bool] true = full
  */
  bool Full(){
    return (top >= size-1);
  }

 /**
  * Public int: Peek
  * 
  * Description:
  *      Returns top value without altering the stack
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      [int] top value if any
  */
  int Peek(){
    if(!Empty()){
      return A[top];
    }
    
    return -99; // some sentinel value
                // not a good solution
  }

 /**
  * Public int: Pop
  * 
  * Description:
  *      Returns top value and removes it from stack
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      [int] top value if any
  */
  int Pop(){
    
    int half_array_size = 0 + (size - 1)/2;
    
    // if(top <= half_array_size){
    //   ContainerShrink();
    //   cout<< "It's half empty!\n";
    // }
    if(CheckResize() == "Shrink"){
      ContainerShrink();
      cout<< "It's half empty!\n";
    }
  
    if(!Empty()){
      return A[top--];
    }
    
    

    return -99; // some sentinel value
                // not a good solution
  }

 /**
  * Public void: Print
  * 
  * Description:
  *      Prints stack to standard out
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      NULL
  */
  void Print(){
    for(int i=0;i<=top;i++){
      cout<<A[i]<<" ";
    }
    cout<<endl;
  } 

 /**
  * Public bool: Push
  * 
  * Description:
  *      Adds an item to top of stack
  * 
  * Params:
  *      [int] : item to be added
  * 
  * Returns:
  *      [bool] ; success = true
  */
  bool Push(int x){
    // if(Full()){
    //   ContainerGrow();
    //   cout<<"Array grew at this point!!\n";
    //   cout<<"size is  "<< size;
    // }

    if(CheckResize() == "Grow"){
      ContainerGrow();
      cout<<"Array grew at this point!!\n";
      cout<<"size is  "<< size<<"\n";
    }
  
    if(!Full()){
      A[++top] = x;
      return true;
    }
    
    return false;
    
  }

 /**
  * Public void: ContainerGrow
  * 
  * Description:
  *      Resizes the container for the stack by doubling
  *      its capacity
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      NULL
  */
  void ContainerGrow(){
    int newSize = size*1.75;       // double size of original
    int *B = new int[newSize];  // allocate new memory

    for(int i=0;i<size;i++){    // copy values to new array
      B[i] = A[i];
    }

    delete [] A;                // delete old array

    size = newSize;             // save new size

    A = B;                      // reset array pointer

  }

  void ContainerShrink(){
      int half_array_size = 0 + (size - 1) / 2;
      // int newSize = half_array_size;
      int *tempArr = new int[half_array_size];
      
       for(int i=0;i<half_array_size;i++){    // copy values to new array
          tempArr[i] = A[i];
       }

       delete [] A; 
       size = half_array_size; 
       A = tempArr; 
    
  }

  void printSize(){
    cout<<"Here is the size: "<<size<<"\n";
  }
  
  // Figure this out !!
  string CheckResize(){
    int half_array_size = 0 + (size - 1)/2;
    
    if(top <= half_array_size) {
      return "Shrink";
      }

    if(Full()){
      return "Grow" ;
      }

    return "Pass";

  }

};

// MAIN DRIVER
// Simple Array Based Stack Usage:
int main() {
  ArrayStack stack;
  int r = 0;

  for(int i=0;i<10;i++){
    r = rand() % 100;
    r = i+1;
    if(!stack.Push(r)){
      cout<<"Push failed"<<endl;
    }
  }

  

  stack.Print();
  stack.printSize();

  stack.Pop();
  stack.Pop();
  stack.Pop();
  stack.Pop();
  stack.Pop();
  stack.Pop();

  cout<<"Top postion:"<<stack.top<<"\n";
  cout<<"Current size:"<<stack.size<<"\n";

  stack.Print();
  stack.printSize();

   for(int i=0;i<20;i++){
    r = rand() % 100;
    r = i+1;
    if(!stack.Push(r)){
      cout<<"Push failed"<<endl;
    }
  }

  stack.Print();
  stack.printSize();


}