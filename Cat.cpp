///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file Cat.cpp
/// @version 1.0
///
/// @author Joshua Galeria <jgaleria@hawaii.edu>
/// @date   09_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include "Cat.h"

#include <stdexcept>
#include <iostream>
#include <cassert>

using namespace std;

const std::string Cat::SPECIES_NAME = "Felis Catus";
const Weight::t_weight Cat::MAX_WEIGHT = 40;

//Getters and setters
string Cat::getName() const noexcept {
    return name;
}

void Cat::setName(const std::string &newName) {
    name = newName;
}

bool Cat::isFixed() const noexcept {
    return isCatFixed;
}

void Cat::fixCat() noexcept {
    Cat::isCatFixed = true;
}

//Dump
void Cat::dump() const noexcept {
    assert( validate() );
    Mammal::dump();

    FORMAT_LINE_FOR_DUMP( "Cat", "name" )    << getName() << endl ;
    FORMAT_LINE_FOR_DUMP( "Cat", "isFixed" ) << isFixed() << endl ;
}

//Validate
bool Cat::validate() const noexcept {
    Mammal::validate();

    assert(validateName(getName()));
    return true;

}

//Check name
bool Cat::validateName( const std::string& newName ) {
    if( newName.empty() ) {
        cout << PROGRAM_NAME ": A cat should have a name" << endl;
        return false;
    }

    return true;
}

//Speak
std::string Cat::speak() const noexcept {
    return "Meow";
}

