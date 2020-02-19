///////////////////////////////////////////////////////////////////////////////
//
// Author:           Joachim Isaac 
// Email:            joachimvivian3@gmail.com
// Label:            05-P02
// Title:            Assignment 5 -  Processing in Linear Time 
// Course:           3013
// Semester:         Spring 2020
//
// Description:
//       This program reads a JSON file and runs through it to generate 
//       search suggestions using the getch function. 
//       This is timed so that we can compare if search in a different
//       manner (O(log(n))) will have a large impact on the time taken.
//
// Usage:
//       cd  05-Processing-in-Linear-Time
//       g++ -std=c++17 read_dict.cpp -o run
//       ./run
//       Then type words to get suggestions.
//       You can hit back space to remove a character
//       or enter to clear and entire word.
//       pressing '/' this stops the program.
//
// Files:  -->dict_w_defs.json
//         -->json.hpp
//         -->JsonFacade.hpp
//         -->List.cpp
//         -->List.h
//         -->mygetch.hpp
//         -->read_dict.cpp (main)
//         -->Timer.hpp
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

    Timer T;                            //Timer object.
    
    JsonFacade J("dict_w_defs.json");  //create instance of json class
  

    string key;                      //key variable to access json object

   
    //Loads the vector with keys form Json file.
    vector<string> keys = J.getKeys(); 
    
    //Load the words into linked list.
    for(int i = 0; i < keys.size(); i++)
     wordNodeList.InsertItem(keys[i],J.getValue(keys[i]));

  

    char k;                 //holder for character being typed

    string word = "";      //variable to concatenate letters to

    cout<<"Type keys and watch what happens. Type '/' to quit."<<endl;

    // While capital '/' is not typed keep looping
    while ((k = getch()) != '/') {
        
        //Ensures that we start from the start of the list.
        //Resets the cursor at the start of the list.
        wordNodeList.ResetCursor();

        if((int)k != 127){//Type a character and it adds to the word variable.
            word += k; 
        }
        else{//Press backspace and it removes one letter.
            word = word.erase(word.length()-1,word.length());
        }     


    vector<string> listOfWords;     //Vector which contains all matching words. 


    vector<string> top_ten_words;  //vector which contains the top 10 results.
    

    T.Start();                   //Timing, loading the results.
    
    //Loops through all the words that were read into the linked list.
    for (int i = 0; i < wordNodeList.getCount(); i++){
    //Searches for the substring in the current word.
    size_t found = wordNodeList.GetCurrentItem().find(word); 
    
    //If a valid substring postion was found.
    //Store it in the list of words.
    if(found != string::npos){
        listOfWords.push_back(wordNodeList.GetCurrentItem()); 

        //If a higher priority substring was found
        //Store it in the list of top ten words.
        if(found <= word.length()){
        top_ten_words.push_back(wordNodeList.GetCurrentItem()); 
        }
    }
    wordNodeList.AdvanceCursor();
  }
    

    T.End();                 //The timing of loading the results ends.


    string results = "";    //String to store the top 10 words.


    int iterator = 0;       //counts up to the top 10 relevant words.


    int limit = 0;          // Stores the limit of valid words
                            // Since we could get less than 10.

    
    // If size is greater than 9 limit to 10.
    if(top_ten_words.size() > 9){
        limit = 10;
    }
    else{
    //If it is less than, set the size of the 
    //limit to the top_ten array's size.
        limit = top_ten_words.size();
    }

    //Load the results into the results string.
    while(iterator < limit){
            results += top_ten_words[iterator] + " ";
            iterator++;     
    }


    double timeTaken = T.Seconds();   // Store the time it took in a variable.

    
        if((int)k != 10){           //If character hit is not equal to 10.
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