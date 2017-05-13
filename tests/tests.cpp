#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <catch/include/catch.hpp>

#include "DLList.hpp"
#include "SLList.hpp"
#include "Stack.hpp"
#include "RandQueue.hpp"
#include "MinStack.hpp"

using namespace std;

TEST_CASE( "MinStack Class", "[minstack]" ) {
    MinStack* minStack      = new MinStack();
    REQUIRE(minStack->push(5)   == 5);
    REQUIRE(minStack->min()     == 5);
    REQUIRE(minStack->size()    == 1);
    REQUIRE(minStack->push(4)   == 4);
    REQUIRE(minStack->min()     == 4);
    REQUIRE(minStack->size()    == 2);

    REQUIRE(minStack->push(1)   == 1);
    REQUIRE(minStack->push(3)   == 3);
    REQUIRE(minStack->push(2)   == 2);
    REQUIRE(minStack->min()     == 1);

    REQUIRE(minStack->pop()     == 2);
    REQUIRE(minStack->pop()     == 3);
    REQUIRE(minStack->pop()     == 5);
    REQUIRE(minStack->pop()     == 4);
}

TEST_CASE( "RandQueue Class", "[randqueue]" ) {
    RandQueue* randQueue    = new RandQueue();
    REQUIRE( randQueue->add(1) == 1);
    REQUIRE( randQueue->add(2) == 2);
    REQUIRE ( randQueue->add(3) == 3);
    REQUIRE ( randQueue->add(4) == 4);
    REQUIRE ( randQueue->add(5) == 5);
    REQUIRE ( randQueue->add(6) == 6);
    REQUIRE ( randQueue->size() == 6);

    randQueue->remove();
    REQUIRE ( randQueue->size() == 5);

    randQueue->remove();
    REQUIRE ( randQueue->size() == 4);
    
    randQueue->remove();
    REQUIRE ( randQueue->size() == 3);

    randQueue->remove();
    REQUIRE ( randQueue->size() == 2);
}

TEST_CASE( "DLList Class", "[dllist]" ) {
    SECTION("Removing elements from a doubly linked list priority queue") {
        DLList* TestDLList1     = new DLList();
        TestDLList1->add(14);
        TestDLList1->add(10);
        TestDLList1->add(22);
        TestDLList1->add(11);
        TestDLList1->add(13);
        TestDLList1->add(9);
        TestDLList1->add(20);
        REQUIRE( TestDLList1->size() == 7 );
        // TestDLList1->printList();

        REQUIRE( TestDLList1->deleteMin() == 9 );
        REQUIRE( TestDLList1->size() == 6 );
        // TestDLList1->printList();

        REQUIRE( TestDLList1->deleteMin() == 10 );
        REQUIRE( TestDLList1->size() == 5 );
        // TestDLList1->printList();

        REQUIRE( TestDLList1->deleteMin() == 11 );
        REQUIRE( TestDLList1->size() == 4 );
        // TestDLList1->printList();

        REQUIRE( TestDLList1->deleteMin() == 13 );
        REQUIRE( TestDLList1->size() == 3 );
        // TestDLList1->printList();

        REQUIRE( TestDLList1->deleteMin() == 14 );
        REQUIRE( TestDLList1->size() == 2 );
        // TestDLList1->printList();
    }

    SECTION("Adding elements to a doubly list priority queue") {
        DLList* TestDLList1     = new DLList();
        REQUIRE( TestDLList1->size() == 0 );

        WHEN("A node of 14 is added") {
            TestDLList1->add(14);

            THEN("List size = 1, head = 14, tail = 14") {
                REQUIRE( TestDLList1->size() == 1 );
                REQUIRE( TestDLList1->head->x == 14 );
                REQUIRE( TestDLList1->tail->x == 14 );
            }

            AND_WHEN("A second larger node of 22 is added") {
                TestDLList1->add(22);

                THEN("List size = 2, head = 14, tail = 22") {
                    REQUIRE( TestDLList1->size() == 2 );
                    REQUIRE( TestDLList1->head->x == 14 );
                    REQUIRE( TestDLList1->tail->x == 22 );
                    REQUIRE( TestDLList1->tail->last->x == TestDLList1->head->x );
                    REQUIRE( TestDLList1->head->next->x == TestDLList1->tail->x );
                }

                AND_WHEN("A third smaller node of 10 is added") {
                    TestDLList1->add(10);

                    THEN("List size = 3, head = 10, tail = 22") {
                        REQUIRE( TestDLList1->size() == 3 );
                        REQUIRE( TestDLList1->head->x == 10 );
                        REQUIRE( TestDLList1->head->next->x == 14);
                        REQUIRE( TestDLList1->head->next->last->x == 10);
                        REQUIRE( TestDLList1->tail->last->x == 14 );
                        REQUIRE( TestDLList1->tail->next == NULL );
                    }

                    AND_WHEN("A fourth arbitary node of 17 is added") {
                        TestDLList1->add(17);

                        THEN("List size = 4, head = 10, tail = 17") {
                            REQUIRE( TestDLList1->size() == 4 );
                            REQUIRE( TestDLList1->head->x == 10 );
                            REQUIRE( TestDLList1->tail->x == 17 );
                        }
                    }
                }
            }
        }
    }
}

TEST_CASE( "Stack Class", "[stack]" ) {
    Stack* TestStack        = new Stack();
    REQUIRE(TestStack->push(1) == 1);
    REQUIRE(TestStack->pop() == 1);
    REQUIRE(TestStack->push(2) == 2);
    REQUIRE(TestStack->push(3) == 3);
    REQUIRE(TestStack->pop() == 2);
    REQUIRE(TestStack->pop() == 3);
    REQUIRE(TestStack->push(4) == 4);
    REQUIRE(TestStack->push(5) == 5);
    REQUIRE(TestStack->pop() == 4);
    REQUIRE(TestStack->push(6) == 6);
    REQUIRE(TestStack->push(7) == 7);
    REQUIRE(TestStack->pop() == 5);
    REQUIRE(TestStack->pop() == 6);
}


TEST_CASE( "SLList Class", "[sllist]" ) {

    GIVEN("A Singly Linked Instance") {

        SECTION("Adding elements to a singly list priority queue") {
            SLList* SLList1     = new SLList();
            REQUIRE( SLList1->size() == 0 );

            WHEN("A node of 14 is added") {
                SLList1->add(14);

                THEN("List size = 1, head = 14, tail = 14") {
                    REQUIRE( SLList1->size() == 1 );
                    REQUIRE( SLList1->head->x == 14 );
                    REQUIRE( SLList1->tail->x == 14 );
                }

                AND_WHEN("A second larger node of 22 is added") {
                    SLList1->add(22);

                    THEN("List size = 2, head = 14, tail = 22") {
                        REQUIRE( SLList1->size() == 2 );
                        REQUIRE( SLList1->head->x == 14 );
                        REQUIRE( SLList1->tail->x == 22 );
                    }

                    AND_WHEN("A third smaller node of 10 is added") {
                        SLList1->add(10);

                        THEN("List size = 3, head = 10, tail = 22") {
                            REQUIRE( SLList1->size() == 3 );
                            REQUIRE( SLList1->head->x == 10 );
                            REQUIRE( SLList1->tail->x == 22 );
                        }

                        AND_WHEN("A fourth arbitary node of 17 is added") {
                            SLList1->add(17);

                            THEN("List size = 4, head = 10, tail = 17") {
                                REQUIRE( SLList1->size() == 4 );
                                REQUIRE( SLList1->head->x == 10 );
                                REQUIRE( SLList1->tail->x == 17 );
                            }
                        }
                    }
                }
            }
        }

        SECTION("Removing elements from a singly linked piority queue") {
            WHEN("adding 5 elements to the list in a random order") {
                SLList* SLList1     = new SLList();
                SLList1->add(1);
                SLList1->add(5);
                SLList1->add(3);
                SLList1->add(4);
                SLList1->add(2);

                THEN("the list size should be 5") {
                    REQUIRE( SLList1->size() == 5 );
                }

                AND_WHEN("we remove the first element") {
                    REQUIRE( SLList1->deleteMin() == 1);

                    THEN("the list size should be 4") {
                        REQUIRE (SLList1->size() == 4);
                    }

                    AND_WHEN("we remove another element") {
                        REQUIRE( SLList1->deleteMin() == 2);

                        THEN("the list size should be 3") {
                            REQUIRE (SLList1->size() == 3);
                        }

                        AND_WHEN("we remove another element") {
                            REQUIRE( SLList1->deleteMin() == 3);

                            THEN("the list size should be 2") {
                                REQUIRE (SLList1->size() == 2);
                            }

                            AND_WHEN("we remove another element") {
                                REQUIRE( SLList1->deleteMin() == 4);

                                THEN("the list size should be 1") {
                                    REQUIRE (SLList1->size() == 1);
                                }

                                AND_WHEN("we remove another element") {
                                    REQUIRE( SLList1->deleteMin() == 5);

                                    THEN("the list size should be 0") {
                                        REQUIRE (SLList1->size() == 0);
                                    }

                                    AND_WHEN("try to remove an element when the list size = 0") {
                                        REQUIRE( SLList1->deleteMin() == -1);

                                        THEN("the list size should still be 0") {
                                            REQUIRE (SLList1->size() == 0);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}