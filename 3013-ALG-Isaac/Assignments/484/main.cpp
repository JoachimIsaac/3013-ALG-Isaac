#include <iostream> 
#include <iterator>
#include <vector> 
#include <map> 
using namespace std; 

int main() {
    
    typedef map<int, int> hashmap;
    typedef vector<int> vi;


    int num;
    hashmap container;
    vi numbers;
    vi results;

    while(cin>>num) numbers.push_back(num);

    for(int i = 0; i < numbers.size(); i++){
        
        if(container.find(numbers[i])== container.end()){

          container.insert(pair<int, int>(numbers[i],1));

          results.push_back(numbers[i]);

        }
        else{
          container[numbers[i]] += 1;
        }
    }


    for(int i=0; i < results.size();i++){
    
      cout<< results[i]<<" "<< container[results[i]]<<"\n";


    }
   
cout<<"\n";//Need last line to be accepted 
          //as per UAV (Udebug) standard.


}