// Specification file for the NumberList class
#ifndef NUMBERLIST_H
#define NUMBERLIST_H

// このクラス自体がLinked List担ってて、複数のnodeを保持できる
class NumberList
{
private:
   // Declare a structure for the list
   // nodeのstruct
   struct ListNode
   {
      double value;           // The value in this node
      struct ListNode *next;  // To point to the next node, "self-referentiality"と呼ばれる
      // *nextは次のnodeのこと。nextは次のnodeがあるアドレスのこと
   }; 

   ListNode *head;            // List head pointer

public:
    // Constructor
    NumberList() {
       head = nullptr;
       // ガーベッジが入っててややこしいからnullptrをassignしとく
    }

    // copy constructor
    NumberList(const NumberList& list);
      
    // Destructor
    ~NumberList();
      
    // Linked list operations
    void appendNode(double);
    void insertNode(double);
    void deleteNode(double);
    void reverse();
    void displayList() const;
};
#endif