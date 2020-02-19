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
//       describe program here thoroughly 
//
// Usage:
//       how to use the program if necessary
//
// Files:            (list of all source files used in this program)
/////////////////////////////////////////////////////////////////////////////////

#include "mygetch.hpp"
#include <iostream>
#include "JsonFacade.hpp"      
#include <time.h>
#include <chrono> 
#include "List.h"  
#include "Timer.hpp"  
#include <string>


using namespace std;



int main(){


    List<string> wordNodeList;

    Timer T;//Timer object.
    
    JsonFacade J("dict_w_defs.json");// create instance of json class
  

    string key;//key variable to access json object

    vector<string> keys = J.getKeys();
    
     //Load the words into linked list.
    for(int i = 0; i < keys.size(); i++)
     wordNodeList.InsertItem(keys[i],J.getValue(keys[i]));

  

    char k;//holder for character being typed
    string word = "";// var to concatenate letters to

    cout<<"Type keys and watch what happens. Type '/' to quit."<<endl;

    // While capital  '/' is not typed keep looping
    while ((k = getch()) != '/') {
        
        //Ensures that we start from the start of the list.
        //resets the cursor at the start of the list.
        wordNodeList.ResetCursor();

        if((int)k != 127){//Type a character and it adds to the word variable.
            word += k; 
        }
        else{//Press backspace and it removes one letter.
            word = word.erase(word.length()-1,word.length());
        }     


    vector<string> listOfWords;//Vector which contains all matching words. 
    vector<string> top_ten_words;//vector which contains the top 10 results.
    
    T.Start();//Timing, loading the results.
    
    for (int i = 0; i < wordNodeList.getCount(); i++){
    
    //Searches for the substring in the current word.
    size_t found = wordNodeList.GetCurrentItem().find(word); 
    
    //If a valid substring postion was found.
    //Store it in the list of words.
    if(found != string::npos){
        listOfWords.push_back(wordNodeList.GetCurrentItem()); 

        //If a higher priority substring was found
        //Store it in the list of top ten words.
        if(found < word.length()){
        top_ten_words.push_back(wordNodeList.GetCurrentItem()); 
        }
    }
    wordNodeList.AdvanceCursor();
  }
    

    T.End();//The timing of loading the results ends.


    string results = "";//String to store the top 10 words.

    int iterator = 0; //counts up to the top 10 relevant words.


    int limit = 0; // Stores the limit of valid words
                  // Since we could get less than 10.


    if(top_ten_words.size() > 9){// if size is greater than 9 limit to 10.
        limit = 10;
    }
    else{//if it is less than set the size of the limit to the top_ten array's size.
        limit = top_ten_words.size();
    }

    // Load the results into the results string.
    while(iterator < limit){
            results += top_ten_words[iterator] + " ";
            iterator++;     
    }


    double timeTaken = T.Seconds();// Store the time it took in a variable.

    
        if((int)k != 10){ // if character hit is not equal to 10.
                          //print this information.
            cout << "Word: " << word << "\n\n";
            cout << listOfWords.size() << " words found in "<<timeTaken<< " seconds\n\n";
            cout<<results<<"\n\n\n";

        }

        // Hitting enter sets word back to empty
        if((int)k == 10 ){
            cout<<"Enter pressed ... Word is empty\nWord: "<<endl;
            word = "";
        }
    }
}