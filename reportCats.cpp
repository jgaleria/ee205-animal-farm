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
#include "reportCats.h"
//Header
#include "catDatabase.h"
#include <stdio.h>
#include <string.h>

//Make char* to print out
//const char* genders[] = {"UNKNOWN_GENDER", "MALE", "FEMALE"};
//const char* breeds[]  = {"UNKNOWN_BREED", "MAINE_COON", "MANX", "SHORTHAIR", "PERSIAN", "SPHYNX"};
//const char* colors[]  = {"RED", "BLUE", "GREEN", "WHITE", "BLACK", "PINK"};
//
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
//
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
//
//// Print index of catname
//int findCat( char name[] ) {
//    for( int indexNum = 0; indexNum < numberOfCats; indexNum++ ) {
//        if(strcmp (Database[indexNum].name, name) == 0) {
//            printf("The index of [%s] is [%d]\n\n", Database[indexNum].name, indexNum);
//            return indexNum;
//        }
//    }
//    printf("\n");
//    return 0;
//
//}
