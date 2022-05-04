///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file List.cpp
/// @version 1.0
///
/// @author Joshua Galeria <jgaleria@hawaii.edu>
/// @date   21_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include <cassert>
#include "List.h"

///Public Methods

//Check if List is empty
bool List::empty() const noexcept {
    if( head == nullptr)
        return true;
    return false;
}

//Check size of list
unsigned int List::size() const noexcept {
    return count;
}

//Check if node is in List
bool List::isIn(Node *aNode) const {
    //Early validation check
    if( aNode == nullptr )
        throw std::invalid_argument("You can't search for a nullptr");

    Node* currentNode = head;

    //Check to see if the node was found
    while( currentNode!= nullptr ) {
        if( currentNode == aNode ) {
            return true;
        }
        //Go to the next node
        currentNode = currentNode -> next;
    }

    return false;
}

//Check if list is sorted
bool List::isSorted() const noexcept {
    //Edge case
    if( count < 1 ) {
        return true;
    }

    //Loop through each node in the list
    //If the check is less than the next, return false
    for(Node* checkNode = head; checkNode->next != nullptr; checkNode = checkNode-> next ) {
        if (*checkNode > *checkNode-> next ) {
            return false;
        }
        return true;
    }

    return false;
}

//Return first node in list
Node* List::get_first() const noexcept {
    return head;
}

//Delete all
void List::deleteAllNodes() noexcept {
    assert( validate() );

    //While head not null
    while( head!=nullptr ){

        //Keep on setting head = the next value
        pop_front();
    }

#ifdef DEBUG
    cout << PROGRAM_NAME << ": All Nodes have been deleted" << endl ;
#endif

    assert( validate() );
}

///Static Methods
//Gets next node in list
Node* List::get_next(const Node *currentNode) {
    //Edge case
    if(currentNode == nullptr) {
        throw std::invalid_argument("There's no next node after the nullptr");
    }

    return currentNode-> next;
}

///Abstract Methods
//Remove and return first node in list
Node* List::pop_front() noexcept {

    //Set variable = first node
    Node* front = head;

    //Set head = next node
    head = head-> next;

    //Return the variable
    return front;

}

//Output contents of container
void List::dump() const noexcept {

    //Loop through the list
//    for(Node* checkNode = head; checkNode->next != nullptr; checkNode = checkNode-> next ) {
//        std::cout << checkNode& << endl;
//    }
    //Print out each node
}

bool List::validate() const noexcept {

    if( count == 0 ){
        return false;
    }
    return true;
}
