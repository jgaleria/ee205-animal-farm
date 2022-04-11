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
#include "catDatabase.h"

class Cat {
//protected members
protected:
    char        name[MAX_NAME];
    enum Gender gender;
    enum Breed  breed;
    bool        isCatFixed;
    Weight      weight;

//Public members
public:
    Cat*        next;

//Private methods
private:
    void zeroOutMemberData();

//Constructors
public:
    //Create cat with default values
    Cat();

    //Create cat with all the fields
    Cat( const char *newName, const Gender newGender, const Breed newBreed, const Weight newWeight );

    //Zero out member data
    virtual ~Cat();

//Getters and Setters - Public
public:
    //For name
    const char *getName() const noexcept;
    void setName ( const char* newName );

    //For gender
    Gender getGender() const noexcept;

    //For breed
    Breed getBreed() const noexcept;

    //For fixed
    bool isFixed() const noexcept;
    bool fixCat() noexcept;

    //For weight
    Weight getWeight() const noexcept;
    void setWeight(Weight newWeight);

//Protected methods
protected:
public:
    //Set gender
    void setGender(Gender newGender);

    //Set breed
    void setBreed(Breed newBreed);

//Public methods
public:
    //Print cat
    bool print() const noexcept;

    void setIsCatFixed(bool isCatFixed);

    //Validate cat
    bool validate() const noexcept;

//Static Public Methods
public:
    static bool validateName( const char* newName );
    static bool validateGender( const Gender newGender );
    static bool validateBreed( const Breed newBreed );
    static bool validateWeight( const Weight newWeight );

};

