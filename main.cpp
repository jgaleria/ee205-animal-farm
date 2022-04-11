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
//#include <stdio.h>
//#include <assert.h>
//#include "catDatabase.h"
//#include "addCats.h"
//#include "deleteCats.h"
//#include "reportCats.h"
//#include "updateCats.h"
//#include "programName.h"
//#include <iostream>
//
//using namespace std;
//#define MAX_NAME1 "12376342578634872234789632"
#define MAX_NAME2 "32487932904782958434569854"
#define WRONG_NAME "2345897895347985748374957865734"
//#define DEBUG


//main
//int main() {
    //Starting
//    cout << "Starting" << PROGRAM_NAME << endl;
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
//    cout << "Done with " << PROGRAM_NAME << endl;
//    printf("Ending %s\n", PROGRAM_NAME);
//    return(1);
//}

#include <cstdlib>  // For EXIT_SUCCESS / EXIT_FAILURE
#include <cassert>  // For assert()
#include <cstring>  // For strcmp()
#include <exception>  // For try/catch blocks
#include <iostream>

#include "programName.h"
#include "Cat.h"
#include "catDatabase.h"
#include "addCats.h"
#include "reportCats.h"
#include "deleteCats.h"

using namespace std ;

/// @internal Used to test the largest possible name
#define MAX_NAME1    "1234567890123456789012345678901234567890123456789"

/// @internal Used to test an illegal name (because it's too large by
///           one character)
#define ILLEGAL_NAME "12345678901234567890123456789012345678901234567890"


/// The entry point for Animal Farm
int main() {
    cout << "Starting " << PROGRAM_NAME << endl ;

    initializeDatabase() ;

#ifdef DEBUG
    {
      // Verify that a cat's default values are set
      Cat testCat = Cat();
      assert(testCat.getName() != nullptr );
      assert(strcmp(testCat.getName(), "") == 0);
      assert(testCat.getGender() == UNKNOWN_GENDER);
      assert(testCat.getBreed() == UNKNOWN_BREED);
      assert(testCat.isFixed() == false);
      assert(testCat.getWeight() == UNKNOWN_WEIGHT);
      assert(!testCat.isFixed());
      assert(!testCat.validate());  // The default cat is invalid

      // Test for NULL name
      try {
         testCat.setName(nullptr);
         assert(false); // We should never get here
      } catch (exception const &e) {}

      // Test for empty name
      try {
         testCat.setName("");
         assert(false); // We should never get here
      } catch (exception const &e) {}

      // Test valid names
      testCat.setName("A");       // A 1 character name is valid
      testCat.setName(MAX_NAME1); // A MAX_NAME1 name is valid

      // Test for name too large
      try {
         testCat.setName(ILLEGAL_NAME);
         assert(false); // We should never get here
      } catch (exception const &e) {}

      testCat.setGender(FEMALE);

      try {
         testCat.setGender(MALE);
         assert(false); // We should never get here
      } catch (exception const &e) {}

      testCat.setBreed(MAINE_COON);

      try {
         testCat.setBreed(MANX);
         assert(false); // We should never get here
      } catch (exception const &e) {}

      testCat.fixCat();
      assert(testCat.isFixed());

      // Test for Weight <= 0
      try {
         testCat.setWeight(0);
         assert(false); // We should never get here
      } catch (exception const &e) {}

      testCat.setWeight(1.0 / 1024);
      assert(testCat.getWeight() == 1.0 / 1024);

      assert(testCat.validate());  // The cat should now be valid
      testCat.print() ;

      assert(!isCatInDatabase(&testCat)) ;
   }
#endif

    bool result ;
    result = addCat( new Cat( "Loki", MALE, PERSIAN, 1.0 )) ;
    assert( result ) ;
    if( !result ) throw logic_error (PROGRAM_NAME ": addCat() failed" ) ;
    result = addCat( new Cat( "Milo", MALE, MANX , 1.1 )) ;
    assert( result ) ;
    result = addCat( new Cat( "Bella", FEMALE, MAINE_COON, 1.2 )) ;
    assert( result ) ;
    result = addCat( new Cat( "Kali", FEMALE, SHORTHAIR, 1.3 )) ;
    assert( result ) ;
    result = addCat( new Cat( "Trin", FEMALE, MANX, 1.4 )) ;
    assert( result ) ;
    result = addCat( new Cat( "Chili", MALE, SHORTHAIR, 1.5 )) ;
    assert( result ) ;

#ifdef DEBUG
    {
      // Test finding a cat...
      Cat *bella = findCatByName("Bella");
      assert(bella != nullptr);
      // Test not finding a cat
      assert(findCatByName("Bella's not here") == nullptr);

      // Test deleting a cat...
      assert(deleteCat(bella) == true);
      try {
         deleteCat(bella); // Verify that Bella's not there
      } catch (exception const &e) {}

      bella = nullptr;
   }
#endif

    printAllCats() ;

    deleteAllCats() ;

    printAllCats() ;

    cout << "Done with " << PROGRAM_NAME ;

    return( EXIT_SUCCESS ) ;
}