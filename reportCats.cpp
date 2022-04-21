///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file reportCats.cpp
/// @version 1.0
///
/// @author Joshua Galeria <jgaleria@hawaii.edu>
/// @date   20_Mar_2022
///////////////////////////////////////////////////////////////////////////////

//Include files
#include <iostream>
#include <stdexcept>
#include <cstring>
#include <cassert>

#include "catDatabase.h"
#include "reportCats.h"
#include "programName.h"
#include "Cat.h"

using namespace std;

//Print all cats
bool printAllCats() {
    int numCats = 0;

    assert( validateDatabase() );

    for(Cat* iCat = catDatabaseHeadPointer; iCat != nullptr ; iCat = iCat->next) {
        iCat->print();
        numCats++;
    }

//    #ifdef DEBUG
//        cout << "numCats = [" << numCats << "]" << endl;
//    #endif

    assert(validateDatabase());

    return true;
}

//Find a cat
Cat* findCatByName( const char* name) {
    assert( Cat().validateName(name));

    // assert( validateDatabase() ) ;

    for(Cat* iCat = catDatabaseHeadPointer; iCat!= nullptr; iCat = iCat-> next ) {
        if(strcmp(name, iCat->getName()) == 0) {
            return iCat;
        }
    }

    // assert( validateDatabase() ) ;

    return nullptr;
}

//To check that gender has designated value
const char* genderName( const Gender gender ) {
    switch( gender ) {
        case Gender::UNKNOWN_GENDER: return "Unknown" ;
        case Gender::MALE:           return "Male"    ;
        case Gender::FEMALE:         return "Female"  ;
    }

    throw logic_error(PROGRAM_NAME ": Gender needs to have a valid string value");
}

//To check breed has designated value
const char* breedName( const enum Breed breed ) {
    switch( breed ){
        case UNKNOWN_BREED: return "Unknown"    ;
        case MAINE_COON:    return "Maine Coon" ;
        case MANX:          return "Manx"       ;
        case SHORTHAIR:     return "Shorthair"  ;
        case PERSIAN:       return "Persian"    ;
        case SPHYNX:        return "Sphynx"     ;
    }

    throw logic_error(PROGRAM_NAME ": Breed needs to have a valid string value");
}

//To check breed has designated value
const char* colorName( Color color ) {
    switch( color ){
        case Color::UNKNOWN_COLOR: return "Unknown"    ;
        case Color::BLACK:    return "Unknown"    ;
        case Color::BROWN:    return "Unknown"    ;
        case Color::WHITE:    return "Unknown"    ;
        case Color::RED:      return "Unknown"    ;
        case Color::BLUE:     return "Unknown"    ;
        case Color::GREEN:    return "Unknown"    ;
        case Color::GINGER:   return "Unknown"    ;
        case Color::CREAM:    return "Unknown"    ;
        case Color::CINNAMON: return "Unknown"    ;
        case Color::CALICO:   return "Unknown"    ;

    }

    throw logic_error(PROGRAM_NAME ": Breed needs to have a valid string value");
}