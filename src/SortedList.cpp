/*
 * SortedList.cpp
 *
 *  Created on: Sep 17, 2023
 *      Author: edel
 */

#include "SortedList.h"
#include <iostream>

using namespace std;

SortedList::SortedList() {
    root = NULL;
}

SortedList::~SortedList() {
    Node *reco = root;
    Node *bor;
    while (reco != NULL) {
        bor = reco;
        reco = reco->next;
        delete bor;
    }
}

void SortedList::insert(double x) {
    Node*nuevo = new Node();
    nuevo->data = x;
    if (root == NULL) {
        root = nuevo;
    } else {
        if (x < root->data) {
            nuevo->next = root;
            root = nuevo;
        } else {
            Node *reco = root;
            Node *atras = root;
            while (x >= reco->data && reco->next != NULL) {
                atras = reco;
                reco = reco->next;
            }
            if (x >= reco->data) {
                reco->next = nuevo;
            } else {
                nuevo->next = reco;
                atras->next = nuevo;
            }
        }
    }
}

void SortedList::print() {
    Node *reco = root;
    cout << "Listado completo.\n";
    while (reco != NULL) {
        cout << reco->data << "; ";
        reco = reco->next;
    }
    cout << "\n";
}

