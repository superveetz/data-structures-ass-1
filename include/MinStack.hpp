#ifndef MINSTACK_H
#define MINSTACK_H

using namespace std;

class MinStack
{
    struct Node {
        int x;
        Node* next;
        Node* last;
    };

    private:
        int _size;

    public:
        Node* head; // used to store minimum value of a Node's x
        Node* tail;

        MinStack() :
        _size(0),
        head(NULL),
        tail(NULL) {

        }

        int size() const {
            return this->_size;
        }

        int min() const {
            return this->head->x;
        }

        const int push (const int x) {
            // create new node
            Node* newNode       = new Node();
            newNode->x          = x;

            if (this->_size == 0) {
                this->head          = newNode;
                this->tail          = newNode;
            } else {
                if (newNode->x < this->head->x) {
                    newNode->next       = this->head;
                    this->head->last    = newNode;
                    this->head          = newNode;
                } else {
                    newNode->last       = this->tail;
                    this->tail->next    = newNode;
                    this->tail          = newNode;
                }
            }

            // update list size
            this->_size++;
            return x;
        }

        const int pop() {
            if (this->_size == 0) return -1;

            int returnVal = this->tail->x;

            // we just want to remove the tail and update with it with the this->tail->last
            this->tail->last->next  = NULL;
            this->tail              = this->tail->last;

            // decrement the size
            this->_size--;
            // return the minVal
            return returnVal;
        }

        const void printList() const {
            if (this->_size == 0) return;
            cout << "printing from head forwardly.." << endl;
            
            Node* tmp = this->head;
            for(int i = 0; i < this->_size; i++) {
                cout << tmp->x << endl;
                tmp = tmp->next;
            }

            cout << "printing from tail reversely.." << endl;
            tmp = this->tail;
            for(int i = this->_size; i != 0; i--) {
                cout << tmp->x << endl;
                tmp = tmp->last;
            }
        }

};

#endif  // MINSTACK_H