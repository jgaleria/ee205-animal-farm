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

#pragma once

//Include
#include <iostream>
#include <cassert>
#include <stdexcept>
#include <cstring>
#include <iomanip>

#include "Cat.h"
#include "reportCats.h"

using namespace std;

//Protected Members of a Cat
void Cat::zeroOutMemberData() {
    memset( name, 0, MAX_NAME );
    gender =  UNKNOWN_GENDER ;
    breed  =  UNKNOWN_BREED  ;
    isCatFixed = false ;
    weight = UNKNOWN_WEIGHT ;
    next = nullptr ; //Public Member
}

//Creating a new cat
//Constructor with no parameters
Cat::Cat() {
    zeroOutMemberData() ;
}

//Constructor with all fields valid for cat
Cat::Cat(const char *newName, const Gender newGender, const Breed newBreed, const Weight newWeight) : Cat() {
    setName( newName );
    setGender( newGender );
    setBreed( newBreed );
    setWeight( newWeight );

    //assert(validate());
}

Cat::~Cat() {
    zeroOutMemberData();
}

//Name

//Getter
const char *Cat::getName() const noexcept {
    return name;
}