///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file Cat.h
/// @version 1.0
///
/// @author Joshua Galeria <jgaleria@hawaii.edu>
/// @date   09_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include "programName.h"
#include "Mammal.h"

#define MAX_NAME (50)

//Cat class
class Cat : public Mammal {
    //Constants
public:
    static const std::string SPECIES_NAME;
    static const Weight::t_weight MAX_WEIGHT;

    //Member variables
protected:
    std::string name;
    bool isCatFixed;

    //Constructors
public:
    explicit Cat( const std::string& newName ) : Mammal( MAX_WEIGHT, SPECIES_NAME ) {
        if( !validateName( newName )) {
            throw std::out_of_range("Cats must have a name");
        }
        name = newName;
        isCatFixed = false;

        Cat::validate();
    }

    //All member variables
    Cat( const std::string newName,
         const Color       newColor,
         const bool        newIsFixed,
         const Gender      newGender,
         const Weight::t_weight newWeight
         ) : Mammal( newColor, newGender, newWeight, MAX_WEIGHT, SPECIES_NAME ) {
        if( !validateName( newName) ) {
            throw std::out_of_range( "Cats must have a name" );
        }
        name = newName;
        isCatFixed = newIsFixed;

        Cat::validate();
    }

    //Getters and setters
public:
    std::string getName() const noexcept;
    void setName( const std::string& newName );

    bool isFixed() const noexcept;
    void fixCat() noexcept;

    //Public methods
public:
    std::string speak() const noexcept override;
    void dump() const noexcept override;
    bool validate() const noexcept override;

    //Static public methods
public:
    static bool validateName(const std::string& newName) ;
};
