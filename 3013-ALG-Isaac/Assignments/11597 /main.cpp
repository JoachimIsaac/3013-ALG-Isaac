


///////////////////////////////////////////////////////////////////////////////
//
// Author:           Joachim Isaac 
// Email:            joachimvivian3@gmail.com
// Label:            UVA Problem 11597-(Spanning Subtrees)
// Title:            (Spanning Subtrees)
// Course:           3013
// Semester:         Spring 2020
//
// Description:  The question asks to find the maximum number of spanning trees
//               for a given input n , where (2<= n <= 400). 0 is used to denote
//                the end of the input.
//
//
//      
/////////////////////////////////////////////////////////////////////////////////


#include <iostream> 
using namespace std; 

int main() {
  int currentNumber; 
  int count = 1;
  
  while (cin >> currentNumber ){

      if(currentNumber == 0){ // it equal zero break from the loop.
        break;
      }
      cout<<"Case "<<count<<": "<<currentNumber/2<<"\n"; // print current max spanning tree.
      count++;//increment count
    
  }
  // cout<<"\n";//Need last line to be accepted 
              //as per UVA (Udebug) standard.
              //Removed it so it can be accepted via 
              //UVA site submit
            


}
//Ends here
//./main < input1
//./main < input2
