#ifndef SLLIST_H
#define SLLIST_H

using namespace std;

class SLList
{
    struct Node {
        int x;
        Node *next;
    };

    private:
        int _size;

    public:
        Node* head; // used to store minimum value of a Node's x
        Node* tail; 

        SLList() :
        _size(0),
        head(NULL),
        tail(NULL) {

        }

        int size() const {
            return this->_size;
        }

        const int add (const int x) {
            // create new node
            Node* newNode = new Node();
            newNode->x = x;

            if (this->_size == 0) {
                this->head          = newNode;
                this->tail          = newNode;
            } else {
                if (newNode->x < this->head->x) {
                    // update head to new lowest and relink nodes
                    newNode->next       = this->head;
                    this->head          = newNode;
                } else {
                    this->tail->next    = newNode;
                    this->tail          = newNode;
                }
            }

            // update list size
            this->_size++;
            return x;
        }

        const int deleteMin() {
            if (this->_size == 0) return -1;

            int returnVal = this->head->x;

            // we need to find the next lowest in the list and update our head, then relink the list.
            // first update our head to the next of the current head
            this->head = this->head->next;

            // iterate through our nodes searching for a smaller value
            Node* currentNode       = this->head;
            Node* lowestNode        = NULL;

            for(int i = 0; i < this->_size - 1; i++) {
                if (currentNode->next->x < this->head->x) {
                    lowestNode      = currentNode->next;

                    // if lowestNode is adjacent to this->head
                    if (currentNode == this->head) { 
                        // only need to update 2 nodes
                        this->head->next = currentNode->next->next;
                        lowestNode->next = this->head;
                        this->head       = lowestNode;

                        currentNode = currentNode->next;
                    } else {
                        // update three nodes
                        lowestNode->next    = this->head->next;
                        currentNode->next   = this->head; 
                        this->head = lowestNode;

                        currentNode = currentNode->next;
                    }
                } else {
                    currentNode = currentNode->next;
                }
            }

            // decrement the size
            this->_size--;
            // return the minVal
            return returnVal;
        }

        const void printList() const {
            if (this->_size == 0) return;
            
            Node* tmp = this->head;
            for(int i = 0; i < this->_size; i++) {
                cout << tmp->x << endl;
                tmp = tmp->next;
            }
        }

};

#endif  // SLLIST_H