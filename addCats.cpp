///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-lab-08d-animal-farm-1-to-clion - EE 205 - Spr 2022
///
/// @file addCats.cpp
/// @version 1.0
///
/// @author Joshua Galeria <jgaleria@hawaii.edu>
/// @date   20_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include "catDatabase.h"
#include <stdio.h>
#include <string.h>
#include "addCats.h"


bool addCat ( const char name[], const enum Gender gender, const enum Breed breed, bool isFixed, Weight weight, enum Color collar1, enum Color collar2, unsigned long long license ) {

    //Error Checks from catDatabase.c
    if ( enoughSpace() ) {
        return false;
    }

    if ( nameIsEmpty(name) ) {
        return false;
    }

    if ( nameIsOver(name) ) {
        return false;
    }

    if ( isNameUnique(name) ) {
        return false;
    }

    if ( weightValid (weight) ) {
        return false;
    }

    //Insert
    strcpy(Database[numberOfCats].name, name);
    Database[numberOfCats].gender  = gender;
    Database[numberOfCats].breed   = breed;
    Database[numberOfCats].isFixed = isFixed;
    Database[numberOfCats].weight  = weight;
    Database[numberOfCats].collar1 = collar1;
    Database[numberOfCats].collar2 = collar2;
    Database[numberOfCats].license = license;

    //Add to number of cats
    numberOfCats += 1;
    printf("Added a new cat!\n");

    return true;

}
