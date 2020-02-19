
//File: List.cpp

//Default templated constructor.
/**
     * Public : List()
     * 
     * Description:
     *      Creates an instance of a templated linked list.
     * 
     * Params:
     *      None
     * 
     * Returns:
     *      Nothing
     */
template <class ItemType>
List<ItemType>::List()
{
    wordNode *dummy;
    dummy = new wordNode;
    dummy->next = nullptr;
    this->head = dummy;
    this->cursor = dummy;
    this->count = 0;
}


//Templated copy constructor.
/**
     * Public : List(List &other)
     * 
     * Description:
     *      Makes a copy of a linked list using another
     *      linked list.
     * 
     * Params:
     *      
     *      List &other   :  another linked list
     * 
     * Returns:
     *      Nothing
     */
template <class ItemType>
List<ItemType>::List(List &other)
{
    ItemType Item;
    wordNode *temp;

    //construct empty list - same code
    //as in default constructor goes here
    wordNode *dummy;
    dummy = new wordNode;
    dummy->next = nullptr;
    this->head = dummy;
    this->cursor = dummy;
    this->count = 0;

    //copy items in other to this list
    other.cursor = other.head;
    while (other.cursor->next != NULL)
    {
        Item = other.cursor->next->word;

        temp = new wordNode();
        temp->word = Item;
        temp->next = cursor->next;
        cursor->next = temp;
        count++;

        other.cursor = other.cursor->next;
        cursor = cursor->next;
    }
}


// Destructor
/**
     * Public : ~List()
     * 
     * Description:
     *      Clears all the memory the linked list used.
     * 
     * Params:
     *      None
     * 
     * Returns:
     *      None
     */
template <class ItemType>
List<ItemType>::~List()
{
  
    wordNode *temp;
    ResetCursor();
    temp = cursor;
    //starting at head of list, delete all nodes
    while (temp != nullptr)
    {
        cursor = cursor->next;
        delete temp;
        temp = cursor;
    }
    // dispose of dummy node
    head = cursor = nullptr;
}




/**
     * Public : SwapLists(List &other)
     * 
     * Description:
     *      //Swaps the values between two link lists.
     * 
     * Params:
     *      List &other   :  another linked list.
     *      
     * 
     * Returns:
     *     void
     */
template <class ItemType>
void List<ItemType>::SwapLists(List &other)
{
    wordNode *temp;
    int tempCount;

    //swap cursors
    temp = cursor;
    cursor = other.cursor;
    other.cursor = temp;

    //swap heads
    temp = head;
    head = other.head;
    other.head = temp;

    //swap counts
    tempCount = count;
    count = other.count;
    other.count = count;
}



/**
     * Public : ClearList()
     * 
     * Description:
     *     Clears every node in the list
     *     besides the dummy node.
     * 
     * Params:
     *      None
     * 
     * Returns:
     *      None
     */
template <class ItemType>
void List<ItemType>::ClearList()
{
    ResetCursor();
    while (!CursorAtEnd())
        DeleteItem();
}




/**
     * Public : ResetCursor()
     * 
     * Description:
     *      //Resets the cursor(sets it back to head)
     * 
     * Params:
     *      None 
     * 
     * Returns:
     *      None
     */
template <class ItemType>
void List<ItemType>::ResetCursor()
{
    this->cursor = head;
}




/**
     * Public : CursorAtEnd()
     * 
     * Description:
     *      Returns a boolean value wether
     *      the cursor is at the end or not.
     * 
     * Params:
     *      None
     * 
     * Returns:
     *      None
     */
template <class ItemType>
bool List<ItemType>::CursorAtEnd()
{
    if (cursor->next == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}



/**
     * Public : GetCurrentItem(ItemType &Item)
     * 
     * Description:
     *      
     *    Loads a Item with a value(obj,int,string,etc.)
     *    and passes it by reference.
     * 
     * Params:
     *      ItemType &Item:  value(obj,int,string,etc.)
     *      
     * 
     * Returns:
     *      void
     */
template <class ItemType>
void List<ItemType>::GetCurrentItem(ItemType &Item)
{
    if (cursor->next != nullptr)
        Item = cursor->next->word;
    else
        cout << "ERROR : cursor at end cannot get current item" << endl;
}



/**
     * Public : GetCurrentItem()
     * 
     * Description:
     *      Acesses the node and returns the string value
     *      contained in it's 'word' member data.
     * 
     * Params:
     *      None
     * 
     * Returns:
     *      string: returns the string
     */
template <class ItemType>
string List<ItemType>::GetCurrentItem()
{
    if (cursor->next != nullptr)
      return cursor->next->word;
    else
        cout << "ERROR : cursor at end cannot get current item" << endl;
        return "";
}




/**
     * Public : UpdateCurrentItem(const ItemType &Item)
     * 
     * Description:
     *    //Sets a new item into a node.
     * 
     * Params:
     *      const ItemType &Item:  value(obj,int,string,etc.)
     *    
     * 
     * Returns:
     *      void
     */
template <class ItemType>
void List<ItemType>::UpdateCurrentItem(const ItemType &Item)
{
    if (cursor->next == NULL)
        cout << "ERROR : cursor at end cannot get current item" << endl;
    else
        cursor->next->word = Item;
}




/**
     * Public : AdvanceCursor()
     * 
     * Description:
     *     Advances the cursor to the next node in the list.
     * 
     * Params:
     *      None
     * 
     * Returns:
     *      void
     */
template <class ItemType>
void List<ItemType>::AdvanceCursor()
{
    if (cursor->next == NULL)
        cout << "ERROR : cursor at end cannot advance cursor" << endl;
    else
        cursor = cursor->next;
}




/**
     * Public : InsertItem(const ItemType &Item)
     * 
     * Description:
     *      Inserts and Item into the list.
     * 
     * Params:
     *      const ItemType &Item:  value(obj,int,string,etc.)
     *      
     * 
     * Returns:
     *      void
     */
template <class ItemType>
void List<ItemType>::InsertItem(const ItemType &Item)
{
    wordNode *temp;

    if (count == 0)
    {
        temp = new wordNode();
        temp->word = Item;
        temp->next = nullptr;
        cursor->next = temp;
    }
    else
    {
        temp = new wordNode();
        temp->word = Item;
        temp->next = cursor->next;
        cursor->next = temp;
    }
    count++;
}



/**
     * Public : InsertItem(const ItemType &Item, const ItemType &Def)
     * 
     * Description:
     *     //Inserts and two pieces of data int into one node.
     *     //and inserts it into the
     * 
     * Params:
     *      const ItemType &Item: value(obj,int,string,etc.)
     *      const ItemType &Def:  value(obj,int,string,etc.)
     * 
     * Returns:
     *      void
     */
template <class ItemType>
void List<ItemType>::InsertItem(const ItemType &Item, const ItemType &Def)
{
    wordNode *temp;

    if (count == 0)
    {
        temp = new wordNode();
        temp->word = Item;
        temp->definition = Def;
        temp->next = nullptr;
        cursor->next = temp;
    }
    else
    {
        temp = new wordNode();
        temp->word = Item;
        temp->definition = Def;
        temp->next = cursor->next;
        cursor->next = temp;
    }
    count++;
}



/**
     * Public : DeleteItem()
     * 
     * Description:
     *     //Deletes an item in the list.
     * 
     * Params:
     *      None
     * Returns:
     *     Void
     */
template <class ItemType>
void List<ItemType>::DeleteItem()
{

    wordNode *temp;

    if (cursor->next == NULL)
        cout << "ERROR : cursor at end cannot delete item" << endl;
    else
    {
        temp = cursor->next;
        cursor->next = temp->next;
        delete temp;
        count--;
    }
}




/**
     * Public : getCount()
     * 
     * Description:
     *      //Gets the current size of the list.
     * 
     * Params:
     *      None
     * 
     * Returns:
     *     int  : integer
     */
template <class ItemType>
int List<ItemType>::getCount()
{
    return this->count;
}
