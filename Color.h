///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file Color.h
/// @version 1.0
///
/// @author Joshua Galeria <jgaleria@hawaii.edu>
/// @date   20_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once
#include <iostream>
#include <string>
#include "programName.h"


enum class Color {
    UNKNOWN_COLOR = 0,
    BLACK,
    BROWN,
    WHITE,
    RED ,
    BLUE,
    GREEN,
    GINGER,
    CREAM,
    CINNAMON,
    CALICO
};

/// Output Color as a formatted string
inline std::ostream& operator<<( std::ostream& lhs_stream, const Color& rhs_Color ){
    switch( rhs_Color ) {
        case Color::UNKNOWN_COLOR:
            lhs_stream << "Unknown Color";
            break;
        case Color::RED:
            lhs_stream << "Red";
            break;
        case Color::BLUE:
            lhs_stream << "Blue";
            break;
        case Color::GREEN:
            lhs_stream << "Green";
            break;
        case Color::WHITE:
            lhs_stream << "White";
            break;
        case Color::BLACK:
            lhs_stream << "Black";
            break;
        case Color::BROWN:
            lhs_stream << "Brown";
            break;
        case Color::GINGER:
            lhs_stream << "Ginger";
            break;
        case Color::CREAM:
            lhs_stream << "Cream";
            break;
        case Color::CINNAMON:
            lhs_stream << "Cinammon";
            break;
        case Color::CALICO:
            lhs_stream << "Calico";
            break;
        default:
            /// @throw out_of_range If the enum is not mapped to a string.
            throw std::out_of_range( PROGRAM_NAME ": Gender not mapped to a string" );
    }
    return lhs_stream;
}
