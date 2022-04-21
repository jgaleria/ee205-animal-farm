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

//Include
#include <cassert>
#include <iostream>

#include "catDatabase.h"
#include "addCats.h"
#include "programName.h"

using namespace std;

bool addCat(Cat* newCat) {
    //Check that newCat has a value
    assert( newCat != nullptr );
    newCat->validate() ;

    //Error check
    if (isCatInDatabase( newCat )) {
        throw logic_error(PROGRAM_NAME ": That cat already exists");
    }

    //Make sure database is healthy
    assert( validateDatabase() );

    //Inserting cat
    newCat->next = catDatabaseHeadPointer;
    catDatabaseHeadPointer = newCat;
    numberOfCats++;

    assert( validateDatabase());

    //#ifdef DEBUG
    //    cout << PROGRAM_NAME << ": Added cat [" << newCat->getName() << "]" << endl;
    //#endif

    return true;
}


