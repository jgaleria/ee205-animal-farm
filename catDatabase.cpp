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
//Header
#include <string.h>
#include "catDatabase.h"
#include <stdio.h>
#include "programName.h"

//Include
#include <iostream>
#include <cassert>
#include <stdexcept>

#include "programName.h"
#include "catDatabase.h"
#include "Cat.h"
#include "reportCats.h"

using namespace std;

//Declare what we're going to need
//struct Cat Database[MAX_CATS];
//NumCats    numberOfCats;

//Head pointer
Cat* catDatabaseHeadPointer = nullptr;
int numberOfCats = 0;

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

//Check if there's a cat in the database

//
////Check if there's enough space in the database
//bool enoughSpace() {
//    if ( numberOfCats > MAX_CATS ) {
//        fprintf( stderr, "%s: You have exceeded the max number of cats\n", PROGRAM_NAME );
//        return true;
//    }
//    return false;
//}
//
////Check if string name is empty
//bool nameIsEmpty( const char name[] ) {
//    if ( strlen(name) == 0 ) {
//        fprintf( stderr, "%s: Your name must not be empty\n", PROGRAM_NAME );
//        return true;
//    }
//    return false;
//}
//
////Check if name length is over max name length
//bool nameIsOver( const char name[] ) {
//    if ( strlen(name) > MAX_NAME ) {
//        fprintf( stderr, "%s: Your name must be less than or equal to [%d] characters\n", PROGRAM_NAME, MAX_NAME);
//        return true;
//    }
//    return false;
//}
//
////Check if name is unique
//bool isNameUnique( const char name[] ) {
//    if ( strlen(name) > 0 ) {
//        for(int x = 0; x < MAX_CATS; x++ ) {
//            if( strcmp(Database[x].name, name) == 0 ) {
//                fprintf( stderr, "%s: Your cat must have a unique name\n", PROGRAM_NAME );
//                return true;
//            }
//        }
//    }
//    return false;
//}
//
////Check if weight is valid
//bool weightValid( const Weight weight ) {
//    if ( weight < 0 ) {
//        fprintf( stderr, "%s: The weight needs to be greater than 0\n", PROGRAM_NAME );
//        return true;
//    }
//    return false;
//}
//
////Check if valid index
//bool isValidIndex ( const int index ) {
//    if ( index < 0 || index > MAX_CATS ) {
//        fprintf( stderr, "%s: Invalid index!\n", PROGRAM_NAME );
//        return true;
//    }
//    return false;
//}


