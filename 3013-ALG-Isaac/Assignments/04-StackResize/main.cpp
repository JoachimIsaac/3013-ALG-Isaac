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
//       Overview of a class implementing an array based stack. Resizing
//       was implemented into this class. If the array is too full it
//       increases by 1.75 and if it is half empty it decreases by 0.5.
//
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <string>

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
  int *A;        // pointer to array of int's.
  int top;      // current max stack size.
  int size;     // top of stack.
           

public:
  
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
  *      Returns top value and removes it from stack, 
  *      if the stack is half empty it resizes the array
  *      by 0.5 .
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
  *      Adds an item to top of stack and if the 
  *      stack is full it resizes by 1.75 times
  *      it current size.
  *
  * 
  * Params:
  *      [int] : item to be added
  * 
  * Returns:
  *      [bool] ; success = true
  */
  bool Push(int x){
    
    if(CheckResize() == "Grow"){
      ContainerGrow();
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
  *      Resizes the container for the stack by increasing
  *      it's capacity by 1.75 times.
  *      
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


/**
  * Public void: ContainerShrink
  * 
  * Description:
  *      Resizes the container for the stack when the stack
  *      top value of the stack is less than 0.5 the size of
  *      the stack.  
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      NULL
  */
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


  
 /**
  * Public strin: CheckResize
  * 
  * Description:
  *           Returns a string based on three conditions, 
  *           if when you should "Shrink" the array, "Grow"
  *           or just do nothing ("Pass"). This allows
  *           you to trigger when the array shrinks or grows.
  *           
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      String: either Shrink, Grow or Pass
  */
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



/**
  * Public int: getStackSize
  * 
  * Description:
  *         This returns the stack size as an integer.  
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      NULL
  */
  int getStackSize(){
    return size;
  }
};


/**
  * Public void: openFiles
  * 
  * Description:  Takes in name of files from user and 
  *               opens them.
  *        
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      NULL
  */
void openFiles(ifstream &infile, ofstream &outfile)
{
  string input_file;
  string output_file;
  cout << "Please enter the name of the input file. ";
  cin >> input_file;
  cout << "Please enter the name of the output file. ";
  cin >> output_file;
  infile.open(input_file);
  outfile.open(output_file);
}

/**
  * Public void: printHeading
  * 
  * Description:
  *       
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      NULL
  */
void printHeading(ofstream &outfile)
{
  outfile << "######################################################################\n\n";
  outfile << "Assignment 4 - Resizing the Stack\n";
  outfile << "CMPS 3013\n";
  outfile << "Name: Joachim Isaac \n";
}

/**
  * Public void: printResults
  * 
  * Description:
  *      Print the results of the Max Stack Size, End Stack Size, and
  *      Stack Resized count.  
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      NULL
  */
void printResults(ofstream &outfile,int currentStackSize,int maxStackSize,int timesResized){
  outfile << "Max Stack Size: " << maxStackSize << "\n";
  outfile << "End Stack Size: " << currentStackSize << "\n";
  outfile << "Stack Resized: " << timesResized << " times" << "\n\n"; 
  outfile << "######################################################################\n";
}



// MAIN DRIVER
// Simple Array Based Stack Usage:
int main() {
  
  ifstream infile;
  ofstream outfile;
  ArrayStack stack;

  openFiles(infile,outfile);
  printHeading(outfile);
  
    int value;
    int maxStackSize = -1;
    int currentStackSize = 0;
    int timesResized = 0; 
    string resized;

    while (infile >> value){

       if(value % 2 == 0){
         resized = stack.CheckResize();
        
        if(resized =="Grow"){
           timesResized++;
         } 
         stack.Push(value);
      }
      else{
        resized = stack.CheckResize(); 
        if(resized =="Shrink"){
          timesResized++;
        }
        stack.Pop();
      }
      
        currentStackSize = stack.getStackSize();

        if(currentStackSize > maxStackSize){
          maxStackSize = currentStackSize;
        }
    }

    printResults(outfile,currentStackSize,maxStackSize,timesResized);

}


