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

//Make char* to print out
//const char* genders[] = {"UNKNOWN_GENDER", "MALE", "FEMALE"};
//const char* breeds[]  = {"UNKNOWN_BREED", "MAINE_COON", "MANX", "SHORTHAIR", "PERSIAN", "SPHYNX"};
//const char* colors[]  = {"RED", "BLUE", "GREEN", "WHITE", "BLACK", "PINK"};
//

////Print name of all of the cats in database
//void printAllCats() {
//    printf("These are all the cats:\n");
//
//    for ( int x = 0; x < numberOfCats; x++ ) {
//        printf("[%s]\n", Database[x].name);
//    }
//    printf("\n");
//}

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
////Print cat at location in database
//bool printCat( int index ) {
//
//    //Error check:
//    if ( isValidIndex(index) ) {
//        return false;
//    }
//
//    //View cat
//    printf("You have found the cat:\n");
//    printf("cat index = [%d]\nname    = [%s]\ngender  = [%s]\n", index, Database[index].name, genders[Database[index].gender]);
//    printf("breed   = [%s]\nisFixed = [%d]\nweight  = [%f]\n", breeds[Database[index].breed], Database[index].isFixed, Database[index].weight);
//    printf("collar1 = [%s]\ncollar2 = [%s]\nlicense = [%lld]\n\n", colors[Database[index].collar1], colors[Database[index].collar2], Database[index].license);
//    return true;
//}

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
const char* genderName( const enum Gender gender ) {
    switch( gender ) {
        case UNKNOWN_GENDER: return "Unknown" ;
        case MALE:           return "Male"    ;
        case FEMALE:         return "Female"  ;
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

