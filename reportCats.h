///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file reportCats.h
/// @version 1.0
///
/// @author Joshua Galeria <jgaleria@hawaii.edu>
/// @date   20_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once
#include "catDatabase.h"
#include "Cat.h"

//bool printCat( int index );
//
//void printAllCats();
//
//int findCat( char name[] );

//Print all cats
extern bool printAllCats();

//Find cat
extern Cat* findCatByName( const char* name );

//Return string for gender name
extern const char* genderName( enum Gender gender );

//Return string for breed name
extern const char* breedName( enum Breed breed );