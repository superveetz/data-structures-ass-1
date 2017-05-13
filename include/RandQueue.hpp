#ifndef RANDQUEUE_H
#define RANDQUEUE_H

#include <vector>
#include <stdlib.h>  
#include <stdio.h>  
#include <time.h> 

using namespace std;

class RandQueue
{
    private:
        vector<int> randQueue;

    public:
        RandQueue() {
            // Seed the random-number generator with the current time so that  
            // the numbers will be different every time we run.  
            srand( (unsigned)time( NULL ) );
        }

        int size() const {
            return this->randQueue.size();
        }

        const int add (const int x) {
            randQueue.push_back(x);
            return x;
        }

        const int remove() {
            if (this->randQueue.size() == 0) return -1;

            int randIndex  = rand() % randQueue.size();
            int returnVal   = this->randQueue[randIndex];

            // erase the random index from the queue
            this->randQueue.erase(this->randQueue.begin() + randIndex);
            // return the prev value
            return returnVal;
        }

        const void printList() const {
            if (this->randQueue.size() == 0) return;

            for(int i = 0; i < this->randQueue.size(); i++) {
                cout << this->randQueue[i] << endl;
            }
        }

};

#endif  // RANDQUEUE_H