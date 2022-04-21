///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file Cat.cpp
/// @version 1.0
///
/// @author Joshua Galeria <jgaleria@hawaii.edu>
/// @date   09_Apr_2022
///////////////////////////////////////////////////////////////////////////////

//Include
#include <iostream>
#include <cassert>
#include <stdexcept>
#include <cstring>
#include <iomanip>

#include "Cat.h"
#include "reportCats.h"


using namespace std;

//Protected Members of a Cat
void Cat::zeroOutMemberData() {
    //memset( name, 0, MAX_NAME );
    name   = "null";
    gender =  Gender::UNKNOWN_GENDER ;
    breed  =  UNKNOWN_BREED  ;
    color  =  Color::UNKNOWN_COLOR ;
    isCatFixed = false ;
    weight =  Weight::UNKNOWN_WEIGHT ;
    next = nullptr ; //Public Member
}

//Creating a new cat
//Constructor with no parameters
Cat::Cat() {
    zeroOutMemberData() ;
}

//Constructor with all fields valid for cat
Cat::Cat( std::string newName, const Gender newGender, const Breed newBreed, const Color newColor, const Weight newWeight) : Cat() {
    setName( newName );
    setGender( newGender );
    setColor( newColor );
    setBreed( newBreed );
    setWeight( newWeight );

    assert(validate());
}

Cat::~Cat() {
    zeroOutMemberData();
}


//Getter for name
const std::string Cat::getName() const noexcept {
    return name;
}

//Setter for name
void Cat::setName( const std::string newName) {
    validateName( newName );
    //memset( name, 0, MAX_NAME )
    name = "Unknown name";
    name = newName;
}

//Getter for gender
Gender Cat::getGender() const noexcept {
    return gender;
}

//Getter for breed
Breed Cat::getBreed() const noexcept {
    return breed;
}

//Getter for color
Color Cat::getColor() const noexcept {
    return color;
}

//Get isFixed
bool Cat::isFixed() const noexcept {
    return isCatFixed;
}

//Get weight
Weight Cat::getWeight() const noexcept {
    return weight;
}

//Format line for printing out class
#define FORMAT_LINE( className, member ) cout << setw(8) << (className) << setw(20) << (member) << setw(52)

//Returning and printing Cat
bool Cat::print() const noexcept {
    assert( validate() );

    cout << setw(80) << setfill( '=' ) << "" << endl;
    cout << setfill( ' ' );
    cout << left ;
    cout << boolalpha;
    FORMAT_LINE( "Cat", "name" )        << getName()   << endl;
    FORMAT_LINE( "Cat", "gender" )      << genderName( getGender() ) << endl;
    FORMAT_LINE( "Cat", "breed" )       << breedName( getBreed() )   << endl;
    FORMAT_LINE( "Cat", "color" )       << colorName( getColor() )   << endl;
    FORMAT_LINE( "Cat", "isFixed" )     << isFixed()   << endl;
   //FORMAT_LINE( "Cat", "weight" )      << getWeight() << endl;

    return true;
}

//Validate functions

//Using try catch statement. Idea from Mark's source code.
bool Cat::validate() const noexcept {
    //Try to do this
    try {
        validateName( name );
        validateGender( gender );
        validateBreed( breed );
        validateWeight( weight );
    }
    //If any errors, it will catch and return false
    catch (exception const& x ) {
        cout << x.what() << endl;
        return false;
    }

    //If passes, return true
    return true;
}

//Check Name
bool Cat::validateName( const std::string newName ) {

    //Check if name length is valid
    if( newName.length() <= 0 || newName.length() >= MAX_NAME ){
        throw length_error( PROGRAM_NAME ": Input name length is invalid");
    }

    //Check if name is empty
    if( newName == "null" ) {
        throw invalid_argument( PROGRAM_NAME ": Input name must not be NULL");
    }

    return true;
}

//Check Gender
bool Cat::validateGender(const Gender newGender ) {
    if( newGender == Gender::UNKNOWN_GENDER ) {
        throw invalid_argument( PROGRAM_NAME ": Gender must be known");
    }
    return true;
}

//Check Breed
bool Cat::validateBreed(const Breed newBreed) {
    if( newBreed == UNKNOWN_BREED ) {
        throw invalid_argument(PROGRAM_NAME ": Breed must be known");
    }
    return true;
}

//Check Color
bool Cat::validateColor(const Color newColor) {
    if( newColor == Color::UNKNOWN_COLOR ) {
        throw invalid_argument(PROGRAM_NAME ": Color must be known");
    }
    return true;
}

//Check weight
bool Cat::validateWeight(Weight newWeight) {
    if( isWeightValid(newWeight) ){
        throw invalid_argument(PROGRAM_NAME ": Weight must be > 0");
    }
    return true;
}

//Check isFixed
bool Cat::fixCat() noexcept {
    Cat::isCatFixed = true;

    return true;
}

//Setting weight
void Cat::setWeight(Weight newWeight) {
    validateWeight( newWeight );
    Cat::weight = newWeight;
}

//Setting gender
void Cat::setGender(Gender newGender) {
    // Can't change male or female
    if( gender != Gender::UNKNOWN_GENDER ){
        throw logic_error(PROGRAM_NAME ": You are unable to change the gender");
    }

    //Validate
    validateGender( newGender );
    Cat::gender = newGender;
}

//Setting breed
void Cat::setBreed(Breed newBreed) {
    //Can't change the breed of a cat
    if( breed!= UNKNOWN_BREED ) {
        throw logic_error( PROGRAM_NAME ": You are unable to change the breed");
    }

    //Validate
    validateBreed( newBreed );
    Cat::breed = newBreed;
}

//Setting color
void Cat::setColor(Color newColor) {
    //Can't change the color of a cat
    if( color!= Color::UNKNOWN_COLOR ) {
        throw logic_error( PROGRAM_NAME ": You are unable to change the color");
    }

    //Validate
    validateColor( newColor );
    Cat::color = newColor;
}

bool Cat::isWeightValid(Weight weight) {
    return false;
}

