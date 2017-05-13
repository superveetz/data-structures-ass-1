#ifndef STACK_H
#define STACK_H

#include <vector>

using namespace std;

class Stack
{
    private:
        vector<int> inbox;
        vector<int> outbox;
    public:
        Stack() {

        }

        const int push(int x) {
            this->inbox.push_back(x);
            return x;
        }

        const int pop() {
            if (this->outbox.empty() && this->inbox.empty()) return -1;

            if (this->outbox.empty()) {
                while (!this->inbox.empty()) {
                    this->outbox.push_back(this->inbox[this->inbox.size() - 1]);
                    this->inbox.pop_back();
                }
            }

            int returnVal = this->outbox[this->outbox.size() - 1];
            this->outbox.pop_back();
            return returnVal;
        }

};

#endif  // STACK_H