///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file catDatabase.cpp
/// @version 1.0
///
/// @author Joshua Galeria <jgaleria@hawaii.edu>
/// @date   20_Mar_2022
///////////////////////////////////////////////////////////////////////////////

//Include
#include <iostream>
#include <cassert>
#include <stdexcept>

#include "Cat.h"
#include "reportCats.h"

using namespace std;

//Declare what we're going to need
//struct Cat Database[MAX_CATS];
//NumCats    numberOfCats;

//Head pointer
Cat* catDatabaseHeadPointer = nullptr;
NumCats numberOfCats = 0;

//Initizaling database
void initializeDatabase() {
    //Check if there's existing database
    if(catDatabaseHeadPointer != nullptr ) {
        throw logic_error(PROGRAM_NAME ": You need to delete the old database");
    }

    //Validate database
    assert( validateDatabase());

//    #ifdef DEBUG
//        cout << PROGRAM_NAME << ": Database initialized" << endl;
//    #endif
}

//Check to validate database
extern bool validateDatabase() {
    int numValidCats = 0;

    for (Cat* iCat = catDatabaseHeadPointer; iCat != nullptr; iCat = iCat->next) {
        if( !iCat-> validate() ) {
            return false;
        }

//        Cat* foundCat = findCatByName( iCat-> getName() );
//        if( foundCat != iCat ) {
//            cout << PROGRAM_NAME ": There was a duplicate cat name [" << iCat->getName() << "]" << endl ;
//        }

        numValidCats++;
    }

    if (numValidCats != numberOfCats ) {
        cout << PROGRAM_NAME << ": The number of cats: " << numberOfCats
            << "] does not equal [" << numValidCats << "]" << endl;
        return false;
    }

//    #ifdef DEBUG
//        cout << PROGRAM_NAME << "The database is valid." << endl;
//    #endif

    return true;
}

//Check if there's a cat in the database
bool isCatInDatabase( const Cat* aCat ) {
    assert ( aCat != nullptr );

    assert( validateDatabase() );

    //Check to find the cat
    for(Cat* iCat = catDatabaseHeadPointer; iCat != nullptr; iCat = iCat->next ){
        if(iCat == aCat) {
            return true;
        }
    }

    assert ( validateDatabase() );

    return false;
}



