///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file updateCats.cpp
/// @version 1.0
///
/// @author Joshua Galeria <jgaleria@hawaii.edu>
/// @date   20_Mar_2022
///////////////////////////////////////////////////////////////////////////////
//Header
#include "catDatabase.h"
#include "updateCats.h"
#include <stdio.h>
#include <string.h>

bool updateCatName( int index, char newName[] ) {

    //Error check from catDatabase.c
    if ( nameIsEmpty(newName) ) {
        return false;
    }

    if ( isNameUnique(newName) ) {
        return false;
    }

    //Update the cat name
    strcpy(Database[index].name, newName);
    return true;
}

bool fixCat( int index ) {
    Database[index].isFixed = true;
    return true;
}

bool updateCatWeight( int index, Weight newWeight ) {

    //Error check from catDatabase.c
    if ( weightValid(newWeight) ) {
        return false;
    }

    //Update cat weight
    Database[index].weight = newWeight;
    return true;
}


bool updateCollar1 ( int index, enum Color newColor ) {
    Database[index].collar1 = newColor;
    return true;
}

bool updateCollar2 ( int index, enum Color newColor ) {
    Database[index].collar2 = newColor;
    return true;
}

bool updateLicense ( int index, unsigned long long newLicense ) {
    Database[index].license = newLicense;
    return true;
}

