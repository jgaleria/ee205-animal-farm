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

////Include
//#include <iostream>
//#include <stdexcept>
//#include <cassert>
//
//#include "programName.h"
//#include "deleteCats.h"
//#include "catDatabase.h"
//#include "Cat.h"
//
//using namespace std;
//
//
////Delete specific cat
//bool deleteCat( Cat* deleteThisCat ) {
//    //Check that conditions are satisfied
//    assert( deleteThisCat!= nullptr );
//    assert( validateDatabase() );
//
//    //Test case. Head pointer
//    if(deleteThisCat == catDatabaseHeadPointer ) {
//        catDatabaseHeadPointer = catDatabaseHeadPointer->next;
//        delete deleteThisCat;
//        numberOfCats--;
//
//        assert (validateDatabase());
//        return true;
//    }
//
//    //Finding cat
//    Cat* iCat = catDatabaseHeadPointer;
//    while( iCat!= nullptr ) {
//        //Reset headpointer first to make the delete
//        if( iCat->next == deleteThisCat ) {
//            iCat-> next = deleteThisCat-> next;
//            delete deleteThisCat;
//            numberOfCats--;
//
//            assert(validateDatabase());
//
//            return true;
//        }
//        iCat = iCat->next;
//    }
//
//    //Check if database is healthy
//    assert(validateDatabase());
//
//    throw invalid_argument(PROGRAM_NAME ": Unable to delete the cat. It wasn't found");
//}
//
////Delete all cats
//bool deleteAllCats() {
//    //Deletes until there's no cats left
//    while(catDatabaseHeadPointer != nullptr) {
//        deleteCat(catDatabaseHeadPointer);
//    }
//
//    //numCats = 0;
//
////    #ifdef DEBUG
////        cout << PROGRAM_NAME << ": Deleted all cats" << endl;
////    #endif
//
//    return true;
//}
