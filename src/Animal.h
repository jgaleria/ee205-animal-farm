///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file Animal.h
/// @version 1.0
///
/// @author Joshua Galeria <jgaleria@hawaii.edu>
/// @date   21_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once
#include <string>

#include "programName.h"
#include "Node.h"
#include "Gender.h"
#include "Weight.h"

class Animal : public Node {
    //Constant
public:
    static const std::string KINGDOM_NAME;

    //Private members
    std::string species;
    std::string classification;
    Gender gender = Gender::UNKNOWN_GENDER;
    Weight weight;

    //Constructors
public:

    //Least required fields
    Animal( const Weight::t_weight newMaxWeight,
            const std::string& newClassification,
            const std::string& newSpecies
            );

    //All member variables
    Animal( const Gender newGender,
            const Weight::t_weight newWeight,
            const Weight::t_weight newMaxWeight,
            const std::string& newClassification,
            const std::string& newSpecies
            );

    //Getters and setters
public:
    std::string getKingdom() const noexcept;
    std::string getClassification() const noexcept;
    std::string getSpecies() const noexcept;

    Gender getGender() const noexcept;

    Weight::t_weight getWeight() const noexcept;

    //Setter for weight
    void setWeight( const Weight::t_weight newWeight );

public:
    //Static methods
    static bool validateClassification( const std::string& checkClassification ) noexcept;
    static bool validateSpecies( const std::string& checkSpecies ) noexcept;

    //Protected methods
protected:
    void setGender( const Gender newGender );

    //Abstract methods
public:
    virtual std::string speak() const noexcept = 0;

    //Methods
public:
    void dump() const noexcept override;
    bool validate() const noexcept override;
};



