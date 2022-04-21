///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file programName.h
/// @version 1.0
///
/// @author Joshua Galeria <jgaleria@hawaii.edu>
/// @date   20_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once
#define PROGRAM_NAME "AnimalFarm1"

// Define max numbers
//#define MAX_CATS (1024)

//Enums Gender, Breed
//enum Gender {UNKNOWN_GENDER=0, MALE, FEMALE};
enum Breed  {UNKNOWN_BREED=0, MAINE_COON, MANX, SHORTHAIR, PERSIAN, SPHYNX};
//enum Color  {RED, BLUE, GREEN, WHITE, BLACK, PINK};

//typedefs
typedef int   NumCats;
//typedef float Weight;

//Not valid weight
//const Weight UNKNOWN_WEIGHT = -1;