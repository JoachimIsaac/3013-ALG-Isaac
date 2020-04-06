

///////////////////////////////////////////////////////////////////////////////
//
// Author:           Joachim Isaac 
// Email:            joachimvivian3@gmail.com
// Label:            UVA Problem 484(The Department of Redundancy Department)
// Title:            484(The Department of Redundancy Department)
// Course:           3013
// Semester:         Spring 2020
//
// Description: Problem asks to take in an input of which contains a list of integers
//              (positive, negative, and/or zero) and to keep track of the number of occurances
//              of each number. Print out the numbers in the order it was presented 
//              within the input but without duplicates and with the number of occurences 
//              on the side of the number seprated by a space character.
//              
/////////////////////////////////////////////////////////////////////////////////
#include <iostream> 
#include <iterator>
#include <vector> 
#include <map> 
using namespace std; 

int main() {
    
    typedef map<int,int> hashmap;
    typedef vector<int> vi;


    int num;
    hashmap container;
    vi numbers;
    vi results;

    //Load in all the input.
    while(cin >> num) numbers.push_back(num);

    
    //Load hashmap with the occurences and 
    //load the results array with the single numbers
    //in order.
    for(int i = 0; i < numbers.size(); i++){
        
        if(container.find(numbers[i])== container.end()){

          container.insert(pair<int, int>(numbers[i],1));

          results.push_back(numbers[i]);

        }
        else{
          container[numbers[i]] += 1;
        }
    }

    //Print the results
    for(int i = 0; i < results.size();i++){
    
      cout<< results[i]<<" "<< container[results[i]]<<"\n";

    }
   
// cout<<"\n";//Need last line to be accepted 
              //as per UVA (Udebug) standard.
              //Removed it so it can be accepted via 
              //UVA site submit


}