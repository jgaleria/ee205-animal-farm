///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file Mammal.h
/// @version 1.0
///
/// @author Joshua Galeria <jgaleria@hawaii.edu>
/// @date   21_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once
#include "Color.h"
#include "Animal.h"

class Mammal : public Animal {
    //Constants
public:
    static const std::string MAMMAL_NAME;

    //Member variables
protected:
    Color color = Color::UNKNOWN_COLOR;

    //Constructors
public:
    //Least amount of fields
    Mammal( const Weight::t_weight newMaxWeight,
            const std::string&     newSpecies
            ) : Animal( newMaxWeight, MAMMAL_NAME, newSpecies ) {};

    //All member variables
    Mammal( const Color newColor,
            const Gender newGender,
            const Weight::t_weight newWeight,
            const Weight::t_weight newMaxWeight,
            const std::string& newSpecies) : Animal( newGender, newWeight, newMaxWeight, MAMMAL_NAME, newSpecies) {
        setColor( newColor );
    }

    //Getters and setters
public:
    Color getColor() const noexcept { return color; }
    void setColor( const Color newColor ) noexcept { color = newColor; }

    //Public Methods
public:
    void dump() const noexcept override;
};

