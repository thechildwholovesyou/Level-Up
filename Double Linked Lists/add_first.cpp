// Add first in Doubly Linkedlist

#include <bits/stdc++.h>
using namespace std;

class DoublyLinkedList
{
  class Node
  {
  public:
    int data = 0;
    Node* prev = nullptr;
    Node* next = nullptr;

    Node(int data)
    {
      this->data = data;
    }
  };

  Node* head = nullptr;
  Node* tail = nullptr;
  int size = 0;

public:
  void display()
  {
    string str = "";
    Node* curr = this->head;
    str += "[";
    while (curr != nullptr)
    {
      str += to_string(curr->data);
      if (curr->next != nullptr)
        str += ", ";
      curr = curr->next;
    }
    str += "]";

    cout << str << endl;
  }
  // ye wala mene khud ka banaya function 

void addFirstNode(Node* node)
{
    if(size==0)
    {
        head=tail=node;
    }
    else
    {
        node->next=head;
        head->prev=node;
        head=node;
    }
    size++;
}

  void addFirst(int data)
  {
      Node* node=new Node(data);
      addFirstNode(node);
  }
};

int main()
{
  DoublyLinkedList dll;
  string s;
  while (getline(cin, s))
  {
    stringstream ss(s);
    string word;
    ss >> word;
    if (word == "stop")
      break;
    if (word == "addFirst")
    {
      int data;
      ss >> data;
      dll.addFirst(data);
    }
  }

  dll.display();

  return 0;
}