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
    char name[MAX_NAME];
    enum Gender gender;
    enum Breed breed;
    bool isCatFixed;
    Weight weight;

//Public members
public:
    Cat* next;

//Private methods
private:
    void zeroOutMemberData();

//Constructors
public:
    //Create cat with default values
    Cat();

    //Create cat with all the fields

    //Zero out member data

//Getters and Setters - Public
public:
//For name

//For gender

//For breed

//For weight

//Protected methods
protected:
public:





};

