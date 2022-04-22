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

#include <iomanip>

#define PROGRAM_NAME "AnimalFarm3"

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

/// Format the heading for dumping members of a class to the console
///
/// Print =====================
#define PRINT_HEADING_FOR_DUMP                                                \
    /* Print =========================================================== */   \
    std::cout << std::setw(80) << std::setfill( '=' ) << "" << std::endl


/// Format a line for dumping the members of a class to the console.
/// Setup the fields for printing (space pad, left justify, etc.)
#define FORMAT_LINE_FOR_DUMP( className, member ) \
    std::cout << std::setfill( ' ' )  /* Space pad    */ \
              << std::left            /* Left justify */ \
              << std::boolalpha  /* Print `true` or `false` for `bool`s */ \
              << std::setw( 8) << (className)     \
              << std::setw(20) << (member)        \
              << std::setw(52)  /* (data) */
