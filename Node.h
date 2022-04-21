///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file Node.h
/// @version 1.0
///
/// @author Joshua Galeria <jgaleria@hawaii.edu>
/// @date   21_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include <iostream>
#include <iomanip>
#include "programName.h"

/// Format the heading for dumping members of a class to the console
///
/// Print =====================
#define PRINT_HEADING_FOR_DUMP \
 /* Print =========================================================== */ \
 std::cout << std::setw(80) << std::setfill( '=' ) << "" << std::endl
/// Format a line for dumping the members of a class to the console.
/// Setup the fields for printing (space pad, left justify, etc.)
#define FORMAT_LINE_FOR_DUMP( className, member ) \
 std::cout << std::setfill( ' ' ) /* Space pad */ \
 << std::left /* Left justify */ \
 << std::boolalpha /* Print `true` or `false` for `bool`s */ \
 << std::setw(8) << (className) \
 << std::setw(20) << (member) \
 << std::setw(52) /* (data) */

class Node {
    //So that other classes can access protected members
    friend class List;
    friend class SinglyLinkedList;

    //Protected Members
protected:
    //Point to next node in the list
    Node* next = nullptr;


    //Public Methods
    virtual void dump() const {
        FORMAT_LINE_FOR_DUMP( "Node", "this") << this << std::endl;
        FORMAT_LINE_FOR_DUMP( "Node", "next") << next << std::endl;
    }

    //Static Methods
protected:
    //Compare node1 greater than node 2
    static bool compareAddress (const Node* node1, const Node* node2 ) {
        if( node1 > node2 )
            return true;
        return false;
    }

    //Validate
    virtual bool validate() const noexcept {
        if( next == nullptr ) {
            return true;
        }
        if( next == next-> next ) {
            std::cout << PROGRAM_NAME << "There's a recursive loop, next is pointing to itself";
            return false;
        }
    }

    //Compare if left is greater than right
    virtual bool operator>( const Node& rightSide ) {
        return compareAddress( this, &(Node&)rightSide );
    }
};


