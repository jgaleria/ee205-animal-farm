///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file Animal.cpp
/// @version 1.0
///
/// @author Joshua Galeria <jgaleria@hawaii.edu>
/// @date   21_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include "Animal.h"
#include <cassert>
#include <iostream>
#include <stdexcept>
#include <iomanip>

#include "programName.h"

using namespace std;

//Constant
const std::string Animal::KINGDOM_NAME = "Animalia";

//Constructor with least required fields
Animal::Animal(const Weight::t_weight newMaxWeight,
               const std::string &newClassification,
               const std::string &newSpecies) : Node(), weight(Weight::POUND, newMaxWeight) {
    classification = newClassification;
    species        = newSpecies;
}

//Constructor with all fields
Animal::Animal(const Gender newGender,
               const Weight::t_weight newWeight,
               const Weight::t_weight newMaxWeight,
               const std::string &newClassification,
               const std::string &newSpecies) : Node(), weight( newWeight, newMaxWeight) {

    classification = newClassification;
    species        = newSpecies;
    setGender( newGender );

}

//Getters

std::string Animal::getKingdom() const noexcept {
    return KINGDOM_NAME;
}

std::string Animal::getClassification() const noexcept {
    return classification;
}

std::string Animal::getSpecies() const noexcept {
    return species;
}

Gender Animal::getGender() const noexcept {
    return gender;
}

Weight::t_weight Animal::getWeight() const noexcept {
    return weight.getWeight();
}

//Setters

void Animal::setWeight(const Weight::t_weight newWeight) {
    validate();
    weight.setWeight( newWeight);
    validate();
}

void Animal::setGender(const Gender newGender) {
    //Validation check
    if( gender != Gender::UNKNOWN_GENDER ) {
        throw logic_error( PROGRAM_NAME ": You can not change an existing gender.") ;
    }

    validate();
    gender = newGender;
    validate();
}

//Validate checks
bool Animal::validateClassification(const std::string &checkClassification) noexcept {
    if( checkClassification.empty() ) {
        cout << PROGRAM_NAME << ": classification must not be empty" << endl;
        return false;
    }

    return true;
}

bool Animal::validateSpecies(const std::string &checkSpecies) noexcept {
    if( checkSpecies.empty() ) {
        cout << PROGRAM_NAME << ": species must not be empty." << endl;
        return false;
    }

    return true;
}

//Print meow
std::string Animal::speak() const noexcept {
    return "Meow";
}

void Animal::dump() const noexcept {
    PRINT_HEADING_FOR_DUMP ;

    Node::dump();

    FORMAT_LINE_FOR_DUMP( "Animal", "this" ) << this << endl ;
    FORMAT_LINE_FOR_DUMP( "Animal", "kingdom" ) << getKingdom() << endl ;
    FORMAT_LINE_FOR_DUMP( "Animal", "classification" ) << getClassification() << endl ;
    FORMAT_LINE_FOR_DUMP( "Animal", "species" ) << getSpecies() << endl ;
    FORMAT_LINE_FOR_DUMP( "Animal", "gender" ) << getGender() << endl ;
    //FORMAT_LINE_FOR_DUMP( "Animal", "weight" ) << weight << endl ;
}

bool Animal::validate() const noexcept {
    assert( Node::validate() );

    assert( !getKingdom().empty() );
    assert(validateClassification(getClassification()));
    assert(validateSpecies(getSpecies()));
    assert( weight.validate());
    return true;
}