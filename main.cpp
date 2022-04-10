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

//Header
#include <stdio.h>
#include <assert.h>
#include "catDatabase.h"
#include "addCats.h"
#include "deleteCats.h"
#include "reportCats.h"
#include "updateCats.h"
#include "programName.h"
#include <iostream>

using namespace std;
#define MAX_NAME1 "12376342578634872234789632"
#define MAX_NAME2 "32487932904782958434569854"
#define WRONG_NAME "2345897895347985748374957865734"
//#define DEBUG


//main
int main() {
    //Starting
    cout << "Starting" << PROGRAM_NAME << endl;
//    printf("Starting %s\n\n", PROGRAM_NAME);

    //Insert
//    addCat( "Loki", MALE, PERSIAN, true, 8.5, BLACK, WHITE, 101 ) ;
//    addCat( "Milo", MALE, MANX, true, 7.0, BLACK, RED, 102 ) ;
//    addCat( "Bella", FEMALE, MAINE_COON, true, 18.2, BLACK, BLUE, 103 ) ;
//    addCat( "Kali", FEMALE, SHORTHAIR, false, 9.2, BLACK, GREEN, 104 ) ;
//    addCat( "Trin", FEMALE, MANX, true, 12.2, BLACK, PINK, 105 ) ;
//    addCat( "Chili", UNKNOWN_GENDER, SHORTHAIR, false, 19.0, WHITE, BLACK, 106 ) ;
//
//#ifdef DEBUG
//    // Test for empty name
//    assert( addCat( "", UNKNOWN_GENDER, SHORTHAIR, false, 19.0, BLACK, WHITE, 101 ) == false ) ;
//    // Test for max name
//    assert( addCat( MAX_NAME1, UNKNOWN_GENDER, SHORTHAIR, false, 19.0, WHITE, RED, 107 ) == true ) ;
//    // Test for name too long
//    assert( addCat( WRONG_NAME, UNKNOWN_GENDER, SHORTHAIR, false, 19.0, WHITE, BLUE, 108 ) == false ) ;
//    // Test for duplicate cat name
//    assert( addCat( "Chili", UNKNOWN_GENDER, SHORTHAIR, false, 0, WHITE, GREEN, 109 ) == false ) ;
//    // Test for weight <= 0
//    assert( addCat( "Neo", UNKNOWN_GENDER, SHORTHAIR, false, 0, WHITE, PINK, 110 ) == false ) ;
//    // Test for printCat( -1 ) ;
//    assert( printCat( -1 ) == false );
//    // Test for out of bounds
//    assert ( printCat( 2000 ) == false );
//    // Test finding a cat...
//    assert( findCat( "Bella" ) == 2 ) ;
//    // Test not finding a cat
//    assert( findCat( "Bella's not here" ) == -1 ) ;
//#endif
//
//    //Test addCat
//    //addCat( "", FEMALE, MANX, false, 0 );
//    //addCat( "Henry", MALE, SHORTHAIR, true, 10000.0 );
//    //addCat( "BEN", UNKNOWN_GENDER, MAINE_COON, false, -1.0 );
//
//    //View
//    printf("\n");
//    printAllCats();
//
//    //Test view
//    //printCat ( hi );
//
//    //Update
//    int kali = findCat( "Kali" ) ;
//    updateCatName( kali, "Chili" ) ; // this should fail
//    printCat( kali );
//    updateCatName( kali, "Capulet" ) ;
//    updateCatWeight( kali, 9.9 ) ;
//    fixCat( kali ) ;
//    printCat( kali );
//
//    //View
//    printAllCats();
//
//    //Delete
//    printf("Deleting all cats\n");
//    deleteAllCats();
//    printAllCats();

    //Ending
    cout << "Done with " << PROGRAM_NAME << endl;
//    printf("Ending %s\n", PROGRAM_NAME);
//    return(1);
}
