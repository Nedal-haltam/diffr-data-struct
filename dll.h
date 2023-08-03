#pragma once

/*
this class is a doubly linked list class and a bunch of extra function with good ideas

Find and Replace
Implement the nonmember function int replaceVal(DLList<T> &list, T v1, T v2) 
which replaces every occurrence of the value v1 in the list with the value v2. 
The function should also return the total number of replacements.

Example:

If mylist = [7, 3, 5, 7, 7, 3, 8, 3] then after calling replaceVal(myList, 7, 5) :

mylist = [5, 3, 5, 5, 5, 3, 8, 3] and the function returns 3.

-----------------------------------------------

Return What's Before val
Write the member function prior_v(T v, int count), 
which searches for a node with the value v (first occurrence), 
and then returns a list with all the nodes (up to count nodes) right before that node. 

If the value v is not found or the first occurrence of v is at the head node, the function should return an empty list. 

------------------------------------------------------------------------

Remove Negatives
Implement the member function DLList rmv_ret_negative()
which removes nodes with negative values from the original list, 
adds them to another temporary list, and returns that list.

Example: 

If mylist = [10, -5, -2, 20, 90, -25, 50], then after calling mylist.rmv_ret_negative() :

mylist = [10, 20, 90, 50]and the function returns the list [-5, -2, -25]

-------------------------------------------------------------------

Rearrange Negative & Non-negative 
Implement the member function rearrange_neg_pos(), 
which rearranges the list such that all negative values are to the left of non-negative values (i.e., values ≥ 0). 

Example: 

if the list L1 has [10, -5, -2, 20, 90, -25, 50, 0]

then after calling your function L1.rearrange_neg_pos()

L1 should contain [-25, -5, -2, 20, 90, 10, 50, 0]

--------------------------------------------------------

Insert Before & After
Implement the member function insert_before_after(T val, T insertVal, int count), 
which looks for the first occurrence of the value val in the list, 
if it is found it inserts insertVal by the amount of count before and after val in the list.

Example: 

If the list list1 has [8, 6, 10, 25, 20, 90, 25, 55] then:

list1.insert_before_after(50, 4, 3) does not cause any change to the original list since the value 50 is not in the list.

insert_before_after(25, 4, 3) changes the list to: [8, 6, 10, 4, 4, 4, 25, 4, 4, 4, 20, 90, 25, 55]

---------------------------------------------------------------

Collapse m nodes into one
Write the member function collapse_m_nodes(int m), 
which collapses the first m nodes into one node that contains the average of their values.
The function does the same with the next m nodes and so on with the remaining nodes in the list. 
You must remove the nodes that are no longer needed. 
If there are less than m nodes, then all of them should be collapsed into one node.  

Example: 

If List1 = [ 5.1 6.3 10.5 7.1 3.8 5.4 7.1 7.0 3.2 8.9 3.3 ] Then:

 List1.collapse_m_nodes(3) makes List1 = [ 7.3 5.43333 5.76667 6.1 ]

 List1.collapse_m_nodes(5) makes List1 = [ 6.56 6.32 3.3 ]

List1.collapse_m_nodes(15) makes List1 = [ 6.15455 ]

  */





#include <iostream>
using namespace std;


template <class T>
class DLList;

template <class T>
class DLLNode {
public:
    DLLNode(const T& val, DLLNode* next, DLLNode* prev);

    T get_val() const { return val; }
    void set_val(const T& val) { this->val = val; }
    DLLNode* get_next() const { return next; }
    DLLNode* get_prev() const { return prev; }

private:
    T val;
    DLLNode* next;
    DLLNode* prev;

    friend class DLList<T>;
};

template <class T>
DLLNode<T>::DLLNode(const T& val, DLLNode* next, DLLNode* prev)
{
    this->val = val;
    this->next = next;
    this->prev = prev;
}

// A doubly-linked list class to store elements of a generic type T
template <class T>
class DLList {
public:
    DLList();
    DLList(const DLList& other);
    ~DLList();

    bool is_empty() const;

    DLLNode<T>* head_node() const;
    DLLNode<T>* tail_node() const;
    T head_val() const;
    T tail_val() const;

    void add_to_head(const T& val);
    void add_to_tail(const T& val);
    void append(const DLList& otherList);

    void remove_head();
    void remove_tail();
    bool remove(const T& val);
    void clear();

    bool contains(const T& val) const;
    DLList& operator=(const DLList& other);

    DLList<T> prior_v(T v, int count)
    {
        DLLNode<T>* curr = head;
        DLList<T> list;
        if ( !curr or count <= 0 or curr->get_val() == v or !contains(v)) return list;

        while (curr)
        {
            if (curr->get_val() == v)
            {
                while (curr->get_prev() and count--)
                {
                    list.add_to_head(curr->get_prev()->get_val());
                    curr = curr->get_prev();
                }
                return list;
            }
            curr = curr->get_next();
        }
        
    }


    void removenode(DLLNode<T>* node)
    {
        if (is_empty()) return;

        if (node == head) remove_head();

        else if (node == tail) remove_tail();

        else
        {
            node->next->prev = node->prev;
            node->prev->next = node->next;
            delete node;
        }
    }

    DLList<T> rmv_ret_negative()
    {
        DLLNode<T>* curr = head;
        DLList<T> list;
        DLLNode<T>* delnode = nullptr;
        while (curr)
        {
            if (curr->get_val() < 0)
            {
                list.add_to_tail(curr->get_val());
                delnode = curr;
                curr = curr->get_next();
                removenode(delnode);
            }
            else
            curr = curr->get_next();
        }

        return list;
    }

    void rearrange_neg_pos()
    {
        DLLNode<T>* temp = head;
        DLLNode<T>* curr = temp;

        while(curr)
        {
            if(curr->get_val() < 0)
            {
                swap(curr->val , temp->val);
                temp = temp->get_next();
            }
            curr = curr->get_next();
        }
    }


    void insert_after(DLLNode<T>* node , T val)
    {
        if (!node) return;


        if (node == tail) add_to_tail(val);
        
        
        else
        {
            DLLNode<T>* newnode = new DLLNode<T>(val, node->next, node);

            node->next->prev = newnode;
            node->next = newnode;
        }
    }

    void insert_before(DLLNode<T>* node, T val)
    {
        if (!node) return;

        if (node == head) add_to_head(val);


        else
        {
            DLLNode<T>* newnode = new DLLNode<T>(val, node, node->prev);

            node->prev->next = newnode;
            node->prev = newnode;
        }
    }


    void insert_before_after(T val, T insertval, int count)
    {
        DLLNode<T>* curr = head;

        while (curr)
        {
            if (curr->get_val() == val)
            {
                while (count--)
                {
                    insert_after(curr, insertval);
                    insert_before(curr, insertval);
                }
                return;
            }
            curr = curr->get_next();
        }
    }

    void collapse_m_nodes(int m)
    {
        T* avg = new T(0); int mm = m;

        DLLNode<T>* delnode = nullptr;
        
        DLLNode<T>* curr = head;
        while (curr and mm-- )
        {
            *avg += curr->get_val();

            delnode = curr;
            curr = curr->get_next();
            removenode(delnode);

            if (!mm or !curr)
            {
                if (!curr) {
                    add_to_tail(*avg/((!mm) ? m : m-mm));
                }

                else if (!mm)
                {
                    insert_before(curr, *avg/m);
                    delete avg; avg = new T(0);
                    mm = m;
                }
            }
        }
    }




private:
    DLLNode<T>* head;
    DLLNode<T>* tail;

    
};


template<class T>
int replaceVal(DLList<T>& list, T v1, T v2)
{
    int c = 0;

    DLLNode<T>* curr = list.head_node();

    while (curr)
    {
        if (curr->get_val() == v1)
        {
            c++;
            curr->set_val(v2);
        }
        curr = curr->get_next();

    }

    return c;
}


template <class T>
DLList<T>::DLList()
{
    head = nullptr;
    tail = nullptr;
}

template <class T>
DLList<T>::DLList(const DLList<T>& other) {
    head = nullptr;
    tail = nullptr;
    append(other);
}

template <class T>
DLList<T>::~DLList()
{
    clear();
}

template <class T>
void DLList<T>::clear()
{
    DLLNode<T>* tmp = head;
    DLLNode<T>* del_node;

    while (tmp != nullptr) {
        del_node = tmp;
        tmp = tmp->next;
        delete del_node;
    }

    head = nullptr;
    tail = nullptr;
}

template <class T>
bool DLList<T>::is_empty() const
{
    return head == nullptr;
}

template <class T>
void DLList<T>::add_to_head(const T& val)
{
    DLLNode<T>* new_node = new DLLNode<T>(val, head, nullptr);

    if (head != nullptr)
        head->prev = new_node;

    head = new_node;
    if (tail == nullptr)
        tail = new_node;
}

template <class T>
void DLList<T>::add_to_tail(const T& val)
{
    DLLNode<T>* new_node = new DLLNode<T>(val, nullptr, tail);

    if (tail != nullptr) //If list is non-empty
        tail->next = new_node;

    tail = new_node;
    if (head == nullptr)
        head = new_node;
}

template <class T>
void DLList<T>::remove_head()
{
    DLLNode<T>* del_node = head;

    if (is_empty())
        return;

    if (head == tail) // if only one node in list
        head = tail = nullptr;
    else {
        head = del_node->next;
        head->prev = nullptr;
    }
    delete del_node;
}

template <class T>
void DLList<T>::remove_tail()
{
    if (is_empty())
        return;

    DLLNode<T>* del_node = tail;

    if (head == tail) // if only one node in list
        head = tail = nullptr;
    else {
        tail = del_node->prev;
        tail->next = nullptr;
    }

    delete del_node;
}

template <class T>
bool DLList<T>::remove(const T& val)
{
    if (is_empty())
        return false;

    if (val == head->val) {
        remove_head();
        return true;
    }

    if (val == tail->val) {
        remove_tail();
        return true;
    }

    // traverse list to find the node to be deleted
    for (DLLNode<T>* curr = head->next; curr != nullptr; curr = curr->next) {
        if (curr->val == val) {
            DLLNode<T>* pred = curr->prev;
            DLLNode<T>* succ = curr->next;
            pred->next = succ;
            succ->prev = pred;
            delete curr;
            return true;
        }
    }

    return false;
}

template <class T>
bool DLList<T>::contains(const T& val) const
{
    DLLNode<T>* curr;

    for (curr = head; curr != nullptr; curr = curr->next) {
        if (curr->val == val)
            return true;
    }

    return false;
}

template <class T>
DLLNode<T>* DLList<T>::head_node() const
{
    return head;
}

template <class T>
DLLNode<T>* DLList<T>::tail_node() const
{
    return tail;
}

template <class T>
T DLList<T>::head_val() const
{
    if (is_empty())
        throw string("ERROR: Attempting to retrieve a value of the head from an empty list.");

    return head->val;
}

template <class T>
T DLList<T>::tail_val() const
{
    if (is_empty())
        throw string("ERROR: Attempting to retrieve a value of the tail from an empty list.");

    return tail->val;
}

template <class T>
void DLList<T>::append(const DLList& other)
{
    if (this == &other)
        throw string("ERROR: Can't append list to itself");

    for (DLLNode<T>* curr = other.head; curr != nullptr; curr = curr->next)
        add_to_tail(curr->val);
}

// copy assignment
template <class T>
DLList<T>& DLList<T>::operator=(const DLList<T>& other)
{
    if (this == &other)
        return *this;

    clear();
    append(other);

    return *this;
}

template<class T>
ostream& operator<<(ostream& out, const DLList<T>& list) {
    out << "[";

    DLLNode<T>* curr = list.head_node();
    while (curr != nullptr) {
        out << curr->get_val();
        if (curr->get_next() != nullptr)
            out << ", ";
        curr = curr->get_next();
    }
    out << "]";

    return out;
}


