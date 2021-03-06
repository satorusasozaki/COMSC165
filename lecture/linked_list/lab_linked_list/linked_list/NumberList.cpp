#include <iostream>  
#include "NumberList.h"
using namespace std;



// copy constructor
NumberList::NumberList(const NumberList& original) {
    ListNode *originalNode;
    ListNode *currentNode;
    if (!original.head) {
        head = nullptr;
    } else {
        originalNode = original.head;
        currentNode = new ListNode;
        head = currentNode;
        
        while (originalNode) {
                currentNode->value = originalNode->value;
                currentNode->next = new ListNode;
            if (originalNode->next) {
                currentNode = currentNode->next;
            }
                originalNode = originalNode->next;
        }
        
        currentNode->next = nullptr;
    }
}


void NumberList::reverse() {
    ListNode *prev;
    ListNode *current;
    ListNode *next;
    
    current = head;
    prev = nullptr;
    while (current) {
        next = current->next;
        // make the link to point to the previous node
        current->next = prev;
        
        // move to next node
        prev = current;
        current = next;
    }
    
    head = prev;
}

void NumberList::appendNode(double num) {
   ListNode *newNode;
   ListNode *nodePtr;

   newNode = new ListNode;
   (*newNode).value = num;
   (*newNode).next = nullptr;

    if (!head) {
      head = newNode;
    } else {
      nodePtr = head;

       while ((*nodePtr).next) {
         nodePtr = (*nodePtr).next;
       }
       (*nodePtr).next = newNode;
   }
}

void NumberList::displayList() const
{
   ListNode *nodePtr;  // To move through the list

   // Position nodePtr at the head of the list.
   nodePtr = head;

   // While nodePtr points to a node, traverse
   // the list.
   while (nodePtr)
   {
      // Display the value in this node.
      cout << (*nodePtr).value << endl;

      // Move to the next node.
      nodePtr = (*nodePtr).next;
   }
}

//**************************************************
// The insertNode function inserts a node with     *
// num copied to its value member.                 *
//**************************************************

void NumberList::insertNode(double num) {
   ListNode *newNode;					// A new node
   ListNode *nodePtr;					// To traverse the list
   ListNode *previousNode = nullptr;	// The previous node

   // Allocate a new node and store num there.
   newNode = new ListNode;
   (*newNode).value = num;
    

    if (!head || ((*head).value > num)) {

        (*newNode).next = head; // head is nullptr
        head = newNode;
   } else { // Otherwise, insert newNode
       
      // Position nodePtr at the head of list.
      nodePtr = head;

      // Initialize previousNode to nullptr.
      previousNode = nullptr;

      // Skip all nodes whose value is less than num.
      while (nodePtr != nullptr && (*nodePtr).value < num) {
         previousNode = nodePtr;
         nodePtr = (*nodePtr).next;
      }
    // insert newNode after previousNode
    (*previousNode).next = newNode;
    // newNodeの次のnode = nodePtr
    (*newNode).next = nodePtr;
   }
}



//**************************************************
// The deleteNode function searches for a node     *
// with num as its value. The node, if found, is   *
// deleted from the list and from memory.          *
//**************************************************

void NumberList::deleteNode(double num)
{
   ListNode *nodePtr;       // To traverse the list
   ListNode *previousNode = nullptr;  // To point to the previous node

   // If the list is empty, do nothing.
   if (!head)
      return;
   
   // Determine if the first node is the one.
   if ((*head).value == num) {
      // nodePtrに次のnodeを設定
      nodePtr = (*head).next;
      // 削除
      delete head;
      // headにnodePtrをアサイン
      head = nodePtr;
   }
   else {
      // Initialize nodePtr to head of list
      nodePtr = head;

      // Skip all nodes whose value member is 
      // not equal to num.
      while (nodePtr != nullptr && (*nodePtr).value != num) {
         previousNode = nodePtr;
         nodePtr = (*nodePtr).next;
      }

      // If nodePtr is not at the end of the list, 
      // link the previous node to the node after
      // nodePtr, then delete nodePtr.
      if (nodePtr)
      {
         (*previousNode).next = (*nodePtr).next;
         delete nodePtr;
      }
   }
}

//**************************************************
// Destructor                                      *
// This function deletes every node in the list.   *
//**************************************************

NumberList::~NumberList()
{
   ListNode *nodePtr;   // To traverse the list
   ListNode *nextNode;  // To point to the next node

   // Position nodePtr at the head of the list.
   nodePtr = head;

   // While nodePtr is not at the end of the list...
   while (nodePtr != nullptr) {
      // Save a pointer to the next node.
      nextNode = (*nodePtr).next;

      // Delete the current node.
      delete nodePtr;

      // Position nodePtr at the next node.
      nodePtr = nextNode;
   }
}