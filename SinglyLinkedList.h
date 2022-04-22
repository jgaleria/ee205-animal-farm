///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file SinglyLinkedList.h
/// @version 1.0
///
/// @author Joshua Galeria <jgaleria@hawaii.edu>
/// @date   21_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once
#include "Node.h"
#include "List.h"

class SinglyLinkedList : public List{
    //Public Constructor
public:
    //New singly Linked list
    SinglyLinkedList();

    //Public Methods
public:
    //Insert new node at beginning of list
    void push_front( Node* newNode);

    //Remove and return the first node
    Node* pop_front() noexcept override;

    //Insert newNode after currentNode
    void insert_after( Node* currentNode, Node* newNode );

    //Output contents of container
    void dump() const noexcept override;

    //Validate
    bool validate() const noexcept override;
};



