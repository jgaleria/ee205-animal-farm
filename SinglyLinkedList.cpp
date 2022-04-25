///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file SinglyLinkedList.cpp
/// @version 1.0
///
/// @author Joshua Galeria <jgaleria@hawaii.edu>
/// @date   21_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include "SinglyLinkedList.h"
#include "programName.h"
#include <cassert>
#include <iostream>

//#define TRACE


//Constructor
SinglyLinkedList::SinglyLinkedList() {
    assert( SinglyLinkedList::validate() );
}

//Insert new node at beginning of list
void SinglyLinkedList::push_front(Node *newNode) {

    //Do checks

    //List isn't empty
    if( head != nullptr ) {
        newNode->next = head;
        head = newNode;
    }
    else {
        newNode->next = nullptr;
        head = newNode;
    }

    //Increment count
    count++;
}

//Remove and return first node in list
Node* SinglyLinkedList::pop_front() noexcept {

    //Check special case
    if( head == nullptr )
        return nullptr;

    Node* returnNode = head;

    //Not last node
    if( head-> next != nullptr ) {
        head = head-> next;
    }
    else {
        head = nullptr;
    }

    //Remove the next pointer
    returnNode->next = nullptr;

    //Decrement count
    count--;
    assert( validate() );
    assert( returnNode->validate() );

    return returnNode;
}

//Insert newNode after currentNode
void SinglyLinkedList::insert_after(Node *currentNode, Node *newNode) {

    //Functionality:
    newNode->next = currentNode->next;
    currentNode->next = newNode;
}

//Output all contents of container
void SinglyLinkedList::dump() const noexcept {
    for( Node* currentNode = head ; currentNode != nullptr ; currentNode = currentNode->next ) {
        currentNode->dump();
    }
}

//Valdiate
bool SinglyLinkedList::validate() const noexcept {
    //Check empty list
    if( head == nullptr ) {
        assert( count == 0 );
        assert( empty() );
    } else {
        assert( count != 0 );
        assert( !empty() );
    }

    //Check there's something after
    if( head != nullptr ) {
        if( head->next == nullptr ) {
            assert( count == 1 );
        }
    }

    unsigned int numberOfNodes = 0;
    Node* currentNode = head;
    // Count forward through the List
    while( currentNode != nullptr ) {
        assert( currentNode->validate() ) ;
        numberOfNodes++;
        currentNode = currentNode->next;
    }
    assert( size() == numberOfNodes );

#ifdef DEBUG
    cout << PROGRAM_NAME ": List is valid" << endl;
#endif

    return true;
}

