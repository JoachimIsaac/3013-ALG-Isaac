#include <iostream>
#include <cmath>
using namespace std;

/**
 * Class Heap
 * 
 * @methods:
 *      constructors:
 *          Heap        : Default constructor
 *
 *          Heap(int)   : Overloaded constructor with heap size
 *
 *      private:
 *          BubbleUp    : This puts one value into its proper 
 *                        place in the heap by bubbling it up 
 *                        to it's proper location.
 *
 *          Left        : Returns the index of the 
 *                        left child, of the current index.
 *
 *          OnHeap      : Checks if an index is on the 
 *                        array (past the end).
 *
 *          Parent      : Calculates parent of a given index.
 *
 *          Right       : Returns the index of the 
 *                        right child, of the current index.
 *
 *          Swap        : Swaps to values in the heap
 *
 *          /// Fix These:
 *          SinkDown    : Places one heap item into its proper place in the heap
 *                        by bubbling it down to it's proper location.
 *
 *          PickChild   : If one child exists, return it.
 *                        Otherwise, return the smaller of the two.
 *
 *          Heapify     : Copies an array and heapifies it.
 *                        Makes it meet the conditions of a min heap ADT.
 *      public:
 *          Insert      : Add a value to the heap.
 *
 *          Print       : Prints ths values in the heap in a nicely
 *                        formatted manner.
 *
 *          Remove      : Removes item from top of heap
 */
class Heap {
private:
    int size; // size of the array
    int *H;   // array pointer
    int end;  // 1 past last item in array

    /**
   * BubbleUp
   * 
   * @description: 
   *    This puts one value into its proper 
   *    place in the heap by bubbling it up 
   *    to it's proper location.
   * 
   * @param  {int} index : index to start bubbling at
   * @return             : void
   */
    void BubbleUp(int index) {
        // check parent is not of beginning of array
        if (Parent(index) >= 1) {
            // index is on array and value is less than parent
            while (index > 1 && H[index] < H[Parent(index)]) {
                // do a swap
                Swap(index, Parent(index));

                // update index to values new position
                index = Parent(index);
            }
        }
    }

    /**
     * Left
     * @description:
     *      Calculates index of left child.
     * 
     * @param  {int} index : index of parent
     * @return {int}       : index of left child
     */
    int Left(int index) {
        return 2 * index;
    }

    /**
     * OnHeap
     * @description:
     *      Checks if an index is on the array (past the end).
     * 
     * @param  {int} index : index to check
     * @return {bool}      : 0 = off heap / 1 = on heap
     */
    bool OnHeap(int index) {
        return index < end;
    }

    /**
     * Parent
     * @description:
     *      Calculates parent of a given index.
     * 
     * @param  {int} index : index to check
     * @return {int}       : parent index
     */
    int Parent(int index) {
        return index / 2;
    }

    /**
     * Right
     * @description:
     *      Calculates index of right child.
     * 
     * @param  {int} index : index of parent
     * @return {int}       : index of right child
     */
    int Right(int index) {
        return 2 * index + 1;
    }

    /**
     * Swap
     * 
     * @description: 
     *      Swaps to values in the heap
     * 
     * @param  {int} i  : index in array
     * @param  {int} j  : index in array
     * @return          : void
     */
    void Swap(int i, int j) {
        int temp = H[i];
        H[i] = H[j];
        H[j] = temp;
    }

    ////////////////////////////
    //Fix These Methods
    ////////////////////////////
public :
    /** Heapify
     * @description: Copies an array and heapifies it.
     *               makes it meet the conditions of a min heap ADT.
     * 
     * @param  {int*} A   :  array pointer with unsorted values to make into a heap
     * @param  {int} size :  size of new heap
     */
    void Heapify(int *A , int size) {
        H = A;// Copy array contents.

        end = size;//Change where end is located.

        this->size = end;//Change size of heap.

        //Sinks down all values starting from 
        //the last parent to ensure the values
        //meet the requirements for a heap.
        for (int i = end/2; i > 0; i--) {
            SinkDown(i);
        }  

    }
    
   
  
    /**
     * SinkDown
     * @description:
     *      Places one heap item into its proper place in the heap
     *      by bubbling it down to it's proper location.
     * 
     * @param  {int} index  : index to start from in the array
     * @return              : void 
     */
    void SinkDown(int index) {

       
    int l = Left(index); 

    int r = Right(index); 

    int smallest = index; 

    // Updates smallest to be left child index.
    // If left index is less than current index.
    if (l < end && H[l] < H[index]) 
        smallest = l; 

    // Update smallest to be right child index.
    // If right index is smaller than the current smallest.    
    if (r < end && H[r] < H[smallest]) 
        smallest = r; 

    //Swaps and does it again.
    if (smallest != index) { 
        Swap(index, smallest); 
        SinkDown(smallest); 
    } 

    }

    

    /**
     * PickChild
     * @description:
     *      If one child exists, return it.
     *      Otherwise, return the smaller of the two.
     * 
     * @param  {int} index  : index of parent in the array
     * @return              : index to child 
     */
    int PickChild(int index) {
        int childIndexOne = Left(index);
        int childIndexTwo = -1;
        
        // Look for children if index doesn't  
        // point pass the final parent Node.
        if(index < end/2+1){
        
        //If there is a left child 
        //Check for the right and set it.
        if (childIndexOne <= end - 1){
            if(Right(index) <= end - 1){
             childIndexTwo = Right(index);
            }
        }
            //If the left child is less than the right,
            //return the left
            if (H[childIndexOne] < H[childIndexTwo]){
                return childIndexOne;
            }
            //else return the right if we did have a right child (not '-1')
            else if(H[childIndexOne] > H[childIndexTwo] && childIndexTwo != -1){
                return childIndexTwo;
            }
        }
            return -1; // we failed to get a child. 
                      // leaf node or null.

        }

        
    

public:
    /**
   * Heap constructor
   */
    Heap() {
        size = 100;
        H = new int[size];
        end = 1;
    }

    /**
   * Heap constructor
   * 
   * @param  {int} s : heap size 
   */
    Heap(int s) {
        size = s;
        H = new int[s];
        end = 1;
    }

    /**
   * Insert
   * 
   * @description:
   *        Add a value to the heap.
   * 
   * @param  {int} x : value to Insert
   * @return         : void
   */
    void Insert(int x) {
        H[end] = x;
        BubbleUp(end);
        end++;
    }

    /**
   * Print
   * 
   * @description:
   *        Prints ths values in the heap in a nicely
   *        formatted manner.
   * 
   * @param  //       None 
   * @return         : void
   */
    void Print() {
        for (int i = 1; i <= end - 1; i++) {
            cout << H[i];
            if (i < end - 1) {
                cout << "->";
            }
        }
    }

    /**
     * Remove
     * @description:
     *      Removes item from top of heap
     * 
     * @return {int}  : top of heap
     */
    int Remove() {
        int temp = H[1];
        H[1] = H[end];
        --end;

        return temp;
    }
};

int main() {
    
    cout<<"\n";
    cout << "########################################\n";
    cout << "H02 - Compelte Heap Methods\n";
    cout  << "CMPS 3013\n";
    cout << "Name: Joachim Isaac \n";
    cout << "########################################\n\n";

    Heap H;

    H.Insert(17);
    H.Insert(11);

    for (int i = 1; i <= 10; i++) {
        H.Insert(i);
    }
    
    cout << "Here is the Heap loaded using insert:\n\n";
    H.Print();
    cout<<"\n\n\n";

    //Created my test arr to test if ShiftDown and Heapify.
    int test_arr [18] = {0,31,30,29,28,27,26,24,23,22,21,20,19,44,22,1,2,3};
    int * A = test_arr;
    int test_arr_size = (sizeof(test_arr)/sizeof(*test_arr));

    cout << "Here is the test_arr prior to being heapified:\n\n";
    
    for (int i = 1; i < test_arr_size; i++) {
            cout << test_arr[i];
            if (i < test_arr_size- 1) {
                cout << "->";
            }
        }

    cout << "\n\n\n";

    H.Heapify(A,18);

    cout << "Here is the Heapified array: \n\n";
    H.Print();
    cout << "\n\n";
    
}