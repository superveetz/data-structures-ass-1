#ifndef SLLIST_H
#define SLLIST_H

#include "Node.cpp"

using namespace std;

class Node;
class SLList
{
    private:
        unsigned int _size = 0;

    public:
        Node* head; // used to store minimum value x
        Node* tail; 

        SLList() {

        }

        const int add (int x) {
            // create new node
            Node* newNode = new Node();
            newNode->x = x;

            if (this->_size == 0) {
                this->head = newNode;
            } else {
                if (newNode->x < this->head->x) {
                    // update head to new lowest and relink nodes
                }
                newNode->next = this->tail;
            }

            this->tail = newNode;

            // update list size
            _size++;
            return x;
        }


};

#endif  // SLLIST_H