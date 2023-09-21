/*
 * SortedList.h
 *
 *  Created on: Sep 17, 2023
 *      Author: edel
 */

#ifndef SORTEDLIST_H_
#define SORTEDLIST_H_

class SortedList {
public:
    SortedList();
    SortedList(const SortedList& orig);
    virtual ~SortedList();

    void insert(double x);
    void print();

private:
    class Node {
    public:
        double data;
        Node *next;
    };

    Node *root;
};

#endif /* SORTEDLIST_H_ */
