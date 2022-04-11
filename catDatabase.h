///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file catDatabase.h
/// @version 1.0
///
/// @author Joshua Galeria <jgaleria@hawaii.edu>
/// @date   20_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

//Include
#include <cstddef>
#include "Cat.h"

// extern
extern NumCats numberOfCats;

//Head pointer
extern Cat* catDatabaseHeadPointer;

//Initialize cat database
extern void initializeDatabase();

//Validate database
extern bool validateDatabase();

//Check if cat is in database
extern bool isCatInDatabase( const Cat* aCat );

//// Array of structs
//struct Cat
//{
//    //Name
//    char          name[MAX_NAME];
//    //Gender
//    enum  Gender  gender;
//    //Breed
//    enum  Breed   breed;
//    //isFixed
//    bool          isFixed;
//    //Weight
//    Weight        weight;
//    //Color
//    enum  Color   collar1;
//    enum  Color   collar2;
//    //License
//    unsigned long long license;
//
//};

////extern
//extern struct Cat Database[MAX_CATS];

//
////checks
//extern bool enoughSpace();
//extern bool nameIsEmpty( const char name[] );
//extern bool nameIsOver( const char name[] );
//extern bool isNameUnique( const char name[] );
//extern bool weightValid( Weight weight );
//extern bool isValidIndex( const int index );

