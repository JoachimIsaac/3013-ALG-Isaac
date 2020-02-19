
//File: List.cpp

//Default templated constructor.
/**
     * Public : LoadList
     * 
     * Description:
     *      Loads an array of integerts into a linked list.
     * 
     * Params:
     *      [int*]    :  array of integers
     *      [int]     :  array size
     * 
     * Returns:
     *      [type] List*   : a pointer to a linked list of integers.
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

/**
     * Public : LoadList
     * 
     * Description:
     *      Loads an array of integerts into a linked list.
     * 
     * Params:
     *      [int*]    :  array of integers
     *      [int]     :  array size
     * 
     * Returns:
     *      [type] List*   : a pointer to a linked list of integers.
     */
//Templated copy constructor.
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


/**
     * Public : LoadList
     * 
     * Description:
     *      Loads an array of integerts into a linked list.
     * 
     * Params:
     *      [int*]    :  array of integers
     *      [int]     :  array size
     * 
     * Returns:
     *      [type] List*   : a pointer to a linked list of integers.
     */
// Destructor
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



//Swaps the values between two link lists.
/**
     * Public : LoadList
     * 
     * Description:
     *      Loads an array of integerts into a linked list.
     * 
     * Params:
     *      [int*]    :  array of integers
     *      [int]     :  array size
     * 
     * Returns:
     *      [type] List*   : a pointer to a linked list of integers.
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

//Clears every node in the list
//besides the dummy node.
/**
     * Public : LoadList
     * 
     * Description:
     *      Loads an array of integerts into a linked list.
     * 
     * Params:
     *      [int*]    :  array of integers
     *      [int]     :  array size
     * 
     * Returns:
     *      [type] List*   : a pointer to a linked list of integers.
     */
template <class ItemType>
void List<ItemType>::ClearList()
{
    ResetCursor();
    while (!CursorAtEnd())
        DeleteItem();
}



//Resets the cursor(sets it back to head)
/**
     * Public : LoadList
     * 
     * Description:
     *      Loads an array of integerts into a linked list.
     * 
     * Params:
     *      [int*]    :  array of integers
     *      [int]     :  array size
     * 
     * Returns:
     *      [type] List*   : a pointer to a linked list of integers.
     */
template <class ItemType>
void List<ItemType>::ResetCursor()
{
    this->cursor = head;
}



//Returns a boolean value wether
//the cursor is at the end or not.
/**
     * Public : LoadList
     * 
     * Description:
     *      Loads an array of integerts into a linked list.
     * 
     * Params:
     *      [int*]    :  array of integers
     *      [int]     :  array size
     * 
     * Returns:
     *      [type] List*   : a pointer to a linked list of integers.
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



//Loads a Item with a value(obj,int,string,etc.)
//and passes it by reference.
/**
     * Public : LoadList
     * 
     * Description:
     *      Loads an array of integerts into a linked list.
     * 
     * Params:
     *      [int*]    :  array of integers
     *      [int]     :  array size
     * 
     * Returns:
     *      [type] List*   : a pointer to a linked list of integers.
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
     * Public : LoadList
     * 
     * Description:
     *      Loads an array of integerts into a linked list.
     * 
     * Params:
     *      [int*]    :  array of integers
     *      [int]     :  array size
     * 
     * Returns:
     *      [type] List*   : a pointer to a linked list of integers.
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



//Sets a new item into a node.
/**
     * Public : LoadList
     * 
     * Description:
     *      Loads an array of integerts into a linked list.
     * 
     * Params:
     *      [int*]    :  array of integers
     *      [int]     :  array size
     * 
     * Returns:
     *      [type] List*   : a pointer to a linked list of integers.
     */
template <class ItemType>
void List<ItemType>::UpdateCurrentItem(const ItemType &Item)
{
    if (cursor->next == NULL)
        cout << "ERROR : cursor at end cannot get current item" << endl;
    else
        cursor->next->word = Item;
}



//Advances the cursor to the next node in the list.
/**
     * Public : LoadList
     * 
     * Description:
     *      Loads an array of integerts into a linked list.
     * 
     * Params:
     *      [int*]    :  array of integers
     *      [int]     :  array size
     * 
     * Returns:
     *      [type] List*   : a pointer to a linked list of integers.
     */
template <class ItemType>
void List<ItemType>::AdvanceCursor()
{
    if (cursor->next == NULL)
        cout << "ERROR : cursor at end cannot advance cursor" << endl;
    else
        cursor = cursor->next;
}



//Inserts and Item into the list.
/**
     * Public : LoadList
     * 
     * Description:
     *      Loads an array of integerts into a linked list.
     * 
     * Params:
     *      [int*]    :  array of integers
     *      [int]     :  array size
     * 
     * Returns:
     *      [type] List*   : a pointer to a linked list of integers.
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


//Inserts and two pieces of data int into one node.
//and inserts it into the
/**
     * Public : LoadList
     * 
     * Description:
     *      Loads an array of integerts into a linked list.
     * 
     * Params:
     *      [int*]    :  array of integers
     *      [int]     :  array size
     * 
     * Returns:
     *      [type] List*   : a pointer to a linked list of integers.
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


//Deletes an item in the list.
/**
     * Public : LoadList
     * 
     * Description:
     *      Loads an array of integerts into a linked list.
     * 
     * Params:
     *      [int*]    :  array of integers
     *      [int]     :  array size
     * 
     * Returns:
     *      [type] List*   : a pointer to a linked list of integers.
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



//Gets the current size of the list.
/**
     * Public : LoadList
     * 
     * Description:
     *      Loads an array of integerts into a linked list.
     * 
     * Params:
     *      [int*]    :  array of integers
     *      [int]     :  array size
     * 
     * Returns:
     *      [type] List*   : a pointer to a linked list of integers.
     */
template <class ItemType>
int List<ItemType>::getCount()
{
    return this->count;
}
