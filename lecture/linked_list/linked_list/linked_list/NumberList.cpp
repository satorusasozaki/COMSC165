// Implementation file for the NumberList class
#include <iostream>  // For cout
#include "NumberList.h"
using namespace std;

//**************************************************
// appendNode appends a node containing the        *
// value pased into num, to the end of the list.   *
//**************************************************

void NumberList::appendNode(double num)
{
   ListNode *newNode;  // To point to a new node. appendするための新しいnodeをポインタ変数で作成
   ListNode *nodePtr;  // To move through the list. 最後のnodeを探すためのポインタ変数

   // Allocate a new node and store num there.
   newNode = new ListNode;
   (*newNode).value = num;
   (*newNode).next = nullptr;

   // If there are no nodes in the list
   // make newNode the first node.
   if (!head)
      head = newNode;
   else  // Otherwise, insert newNode at end.
   {
      // Initialize nodePtr to head of list.
      // head nodeでスタート
      nodePtr = head;

       // Find the last node in the list.
       // 次を指すポインタがnullになったら（＝最後）外に出る
       while ((*nodePtr).next) {
         // *next はポインタ変数で、nextは次のnodeが入ってるメモリアドレス、*nextが次のnodeを示す
         // 次のnodeアドレスをnodePtrに入れる
         // nodePtr（アドレス）が次のnodeに移る
         nodePtr = (*nodePtr).next;
         // 繰り返すことでnodePtrが前に進み続ける
       }
       // nodePtrには最後のnodeのアドレスが入ってる
       
      // Insert newNode as the last node.
      // ListNode *newNodeで*newNodeはポインタ変数で、newNodeにはアドレスが入ってる
      // newNode（*newNodeのアドレス）をnext（アドレス）にassignする
      // つまり、*next = *newNode
       (*nodePtr).next = newNode;
   }
}

//**************************************************
// displayList shows the value                     *
// stored in each node of the linked list          *
// pointed to by head.                             *
//**************************************************

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
    
    // If the new node is to be the 1st in the list,
    // insert it before all other nodes.
   // If there are no nodes in the list
   // make newNode the first node
    
    // headがnullptrの場合（＝listが空）
    // あるいはnumがhead valueより小さい場合（先頭に来る場合）
    if (!head || ((*head).value > num)) {
        // headを1st nodeにする＝ひとつ後ろにずらす
        // listが空の場合はheadはnullptrで*nextはnullptrになる
        (*newNode).next = head; // head is nullptr
        head = newNode;
   } else { // Otherwise, insert newNode
      // listの途中にinsertする場合は、前のnodeと次のnodeが必要
       
      // Position nodePtr at the head of list.
      nodePtr = head;

      // Initialize previousNode to nullptr.
      previousNode = nullptr;

      // Skip all nodes whose value is less than num.
      // かつnodePtrが外に出てしまっていない時
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