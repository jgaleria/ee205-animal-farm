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

//Print all cats
extern bool printAllCats();

//Find cat
extern Cat* findCatByName( const std::string name );

//Return string for gender name
extern const char* genderName( Gender gender );

//Return string for breed name
extern const char* breedName( enum Breed breed );

//Return string for color name
extern const char* colorName( Color color );
