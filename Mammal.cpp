///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file Mammal.cpp
/// @version 1.0
///
/// @author Joshua Galeria <jgaleria@hawaii.edu>
/// @date   21_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include "Mammal.h"
#include "programName.h"
#include <string>
#include <cassert>

using namespace std;

const std::string Mammal::MAMMAL_NAME = "Mammilian";

void Mammal::dump() const noexcept {
    assert( validate() );
    Animal::dump();

    FORMAT_LINE_FOR_DUMP( "Mammal", "color" ) << color << endl;
}

