#include <iostream>
#include "JsonFacade.hpp"       // need to grab a copy from resources folder
#include <time.h>
#include <chrono> 
#include "List.h"  
#include "Timer.hpp"  // need to grab a copy from resources folder
       


using namespace std;

// struct wordNode 
// 	{
// 		ItemType word;
// 		ItemType definition;
// 		wordNode *next;
// 	};
// void load_linked_list(vector<string>arr,List<string>* test){
   
// }



int main(){
    // Templated linked list is working, need to make the
    // dictionary node to put into it. 

    List<string> test;
  
 
    
    Timer T;
    
    JsonFacade J("dict_w_defs.json");   // create instance of json class
  
    

    cout <<s << " seconds" <<endl;
    cout <<m << " milli" <<endl;
    int index = 0;                      // 
    string key;                         // key variable to access json object

    vector<string> keys = J.getKeys();
    T.Start();

     for(int i = 0; i < keys.size(); i++){
        test.InsertItem(keys[i],J.getValue(keys[i]));
    }

    T.End();
    
    double s = T.Seconds();
    long m = T.MilliSeconds();

    cout << "First Item: "<<keys[3]<<"\n";
    
    cout << "First item via list "<< test.GetCurrentItem()<<"\n";
    // cout<<keys.size()<<endl;
    
    // index = rand() % keys.size();
    // key = J.getKey(index);

    // cout<<key<<" = "<<J.getValue(key)<<endl;
}