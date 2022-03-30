///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file updateCats.h
/// @version 1.0
///
/// @author Joshua Galeria <jgaleria@hawaii.edu>
/// @date   20_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once
#include "catDatabase.h"

bool updateCatName( int index, char newName[] );

bool fixCat( int index );

bool updateCatWeight( int index, Weight newWeight );

bool updateCollar1 ( int index, enum Color newColor );

bool updateCollar2 ( int index, enum Color newColor );

bool updateLicense ( int index, unsigned long long newLicense );
