///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file List.h
/// @version 1.0
///
/// @author Joshua Galeria <jgaleria@hawaii.edu>
/// @date   21_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include "Node.h"

class List {

    ///Protected members
protected:
    //Head pointer for collection
    Node* head = nullptr ;

    //Count for number of node objects
    unsigned int count = 0;

    ///Public Methods
public:
    //Check if list is empty
    bool empty() const noexcept;

    //Check size of list
    unsigned int size() const noexcept;

    //Check if node is in list
    bool isIn( Node* aNode ) const;

    //Check if sorted
    bool isSorted() const noexcept;

    //Return first node in list
    Node* get_first() const noexcept;

    //Delete all
    void deleteAllNodes() noexcept;

    ///Static Methods
public:
    static Node* get_next( const Node* currentNode );

    ///Abstract Methods
public:
    //Remove and return first node in List
    virtual Node* pop_front() noexcept = 0;

    //Output contents of container
    virtual void dump() const noexcept = 0;

    //Validate the container
    virtual bool validate() const noexcept = 0;




};


