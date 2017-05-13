#ifndef DLLIST_H
#define DLLIST_H

using namespace std;

class DLList
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

        DLList() :
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

        const int deleteMin() {
            if (this->_size == 0) return -1;

            int returnVal = this->head->x;

            // we need to find the next lowest in the list and update our head, then relink the list.
            // first update our head to the next of the current head
            this->head = this->head->next;

            // iterate through our nodes searching for a smaller value
            Node* currentNode       = this->head;
            Node* lowestNode        = NULL;

            for(int i = 0; i < this->_size - 2; i++) {
                if (currentNode->next->x < this->head->x) {
                    lowestNode      = currentNode->next;

                    // if lowestNode is adjacent to this->head
                    if (lowestNode->last == this->head) { 
                        this->head->last                = lowestNode;
                        
                        if (lowestNode->next != NULL) {
                            // if lowestNode is not the tail, update the link before and after lowest
                            lowestNode->next->last   = this->head;
                            this->head->next        = currentNode->next->next;
                        } else {
                            // update the tail if the tail was removed
                            this->tail              = this->head; 
                        }

                        lowestNode->next        = this->head;
                        lowestNode->last        = NULL;

                        // goto next node
                        currentNode             = this->head;
                        // update head
                        this->head              = lowestNode;
                    } else {
                        // lowestNode is not adjacent to this->head
                        Node* nextToLowest  = currentNode->next->next;
                        Node* prevToLowest  = currentNode;
                        Node* nextHead      = this->head->next;
                        
                        // if lowestNode is not the tail, update the `last` link of the node after lowest
                        if (lowestNode->next != NULL) {
                            lowestNode->next->last   = this->head;
                        }
                        
                        // adjust links
                        currentNode->next               = this->head;
                        currentNode->next->next         = nextToLowest;
                        currentNode->next->last         = prevToLowest;

                        this->head          = lowestNode;
                        this->head->next    = nextHead;
                        this->head->last    = NULL;
                        
                        prevToLowest->last  = this->head;
                        // goto next node
                        currentNode         = currentNode->next;
                    }
                } else {
                    // goto next node
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

#endif  // DLLIST_H