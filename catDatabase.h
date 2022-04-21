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

//Head pointer
extern Cat* catDatabaseHeadPointer;

// extern
extern NumCats numberOfCats;

//Initialize cat database
extern void initializeDatabase();

//Validate database
extern bool validateDatabase();

//Check if cat is in database
extern bool isCatInDatabase( const Cat* aCat );

