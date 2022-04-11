///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file deleteCats.cpp
/// @version 1.0
///
/// @author Joshua Galeria <jgaleria@hawaii.edu>
/// @date   20_Mar_2022
///////////////////////////////////////////////////////////////////////////////

//Include
#include <iostream>
#include <stdexcept>
#include <cassert>

#include "programName.h"
#include "deleteCats.h"
#include "catDatabase.h"
#include "Cat.h"

using namespace std;
//Delete all cats
//void deleteAllCats() {
//    for( int x = 0; x < numberOfCats; x++ ) {
//        strcpy(Database[x].name, "");
//        Database[x].gender  = UNKNOWN_GENDER;
//        Database[x].breed   = UNKNOWN_BREED;
//        Database[x].isFixed = false;
//        Database[x].weight  = 0.0;
//        Database[x].collar1 = RED;
//        Database[x].collar2 = RED;
//        Database[x].license = 0;
//    }
//    //Couldn't get this to work
//    //memset(Database, 0, MAX_CATS);
//}
//

//Delete specific cat
bool deleteCat( Cat* deleteThisCat ) {
    assert( deleteThisCat!= nullptr );

    assert( validateDatabase() );

    //Test case. Head pointer
    if(deleteThisCat == catDatabaseHeadPointer ) {
        catDatabaseHeadPointer = catDatabaseHeadPointer->next;
        delete deleteThisCat;
        numberOfCats--;

        assert (validateDatabase());
        return true;
    }

    //Finding cat
    Cat* iCat = catDatabaseHeadPointer;
    while( iCat!= nullptr ) {
        if( iCat->next == deleteThisCat ) {
            iCat-> next = deleteThisCat-> next;
            delete deleteThisCat;
            numberOfCats--;

            assert(validateDatabase());

            return true;
        }
        iCat = iCat->next;
    }

    assert(validateDatabase());

    throw invalid_argument(PROGRAM_NAME ": Unable to delete the cat. It wasn't found");
}


//Delete all cats
bool deleteAllCats() {
    //Deletes until there's no cats left
    while(catDatabaseHeadPointer != nullptr) {
        deleteCat(catDatabaseHeadPointer);
    }

    //numCats = 0;

//    #ifdef DEBUG
//        cout << PROGRAM_NAME << ": Deleted all cats" << endl;
//    #endif
}

////Delete specific cat
//bool deleteCat( int index ) {
//
//    //Error check
//    if ( isValidIndex(index) ) {
//        return false;
//    }
//
//    //Delete cat
//    strcpy(Database[index].name, "");
//    Database[index].gender  = UNKNOWN_GENDER;
//    Database[index].breed   = UNKNOWN_BREED;
//    Database[index].isFixed = false;
//    Database[index].weight  = 0.0;
//    Database[index].collar1 = RED;
//    Database[index].collar2 = RED;
//    Database[index].license = 0;
//    return true;
//}
