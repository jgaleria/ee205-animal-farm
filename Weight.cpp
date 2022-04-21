///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file Weight.cpp
/// @version 1.0
///
/// @author Joshua Galeria <jgaleria@hawaii.edu>
/// @date   20_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include "Weight.h"
#include <iostream>
#include <cassert>

//Weight conversions
const t_weight Weight::UNKNOWN_WEIGHT   = -1;
const t_weight Weight::KILOS_IN_A_POUND = 0.453592;
const t_weight Weight::SLUGS_IN_A_POUND = 0.031081;

//Unit labels
const std::string Weight::POUND_LABEL = "Pound";
const std::string Weight::KILO_LABEL  = "Kilo" ;
const std::string Weight::SLUG_LABEL  = "Slug" ;

///////////////////
///Constructors
//////////////////

//First instance
Weight::Weight() noexcept {
    bIsKnown = false;
    bHasMax  = false;
    unitOfWeight = POUND;
    weight = UNKNOWN_WEIGHT;
    MaxWeight = UNKNOWN_WEIGHT;
};

// Only adding weight
Weight::Weight( t_weight newWeight ) {
    bIsKnown = false;
    bHasMax  = false;
    unitOfWeight = POUND;
    weight = newWeight;
    MaxWeight = UNKNOWN_WEIGHT;
}

// Defaulting the unit of weight
Weight::Weight( Weight::UnitOfWeight newUnitOfWeight ) noexcept {
    bIsKnown = true;
    bHasMax  = false;
    unitOfWeight = newUnitOfWeight;
    weight = UNKNOWN_WEIGHT;
    MaxWeight = UNKNOWN_WEIGHT;
}

// Defaulting weight and unit
Weight::Weight( t_weight newWeight, Weight::UnitOfWeight newUnitOfWeight ) {
    bIsKnown = true;
    bHasMax  = false;
    unitOfWeight = newUnitOfWeight;
    weight = newWeight;
    MaxWeight = UNKNOWN_WEIGHT;
}

// Defaulting weight and max weight
Weight::Weight( t_weight newWeight, t_weight newMaxWeight ) {
    bIsKnown = true;
    bHasMax  = true;
    unitOfWeight = POUND;
    weight = newWeight;
    MaxWeight = newMaxWeight;
}

//Defaulting unit and max weight
Weight::Weight( Weight::UnitOfWeight newUnitOfWeight, t_weight newMaxWeight ) {
    bIsKnown = false;
    bHasMax  = true;
    unitOfWeight = newUnitOfWeight;
    weight = UNKNOWN_WEIGHT;
    MaxWeight = newMaxWeight;
}

//Defaulting weight, unit, and max
Weight::Weight( t_weight newWeight, Weight::UnitOfWeight newUnitOfWeight, t_weight newMaxWeight ) {
    bIsKnown = true;
    bHasMax  = true;
    unitOfWeight = newUnitOfWeight;
    weight = newWeight;
    MaxWeight = newMaxWeight;
}

///////////////////////////
/// Getters and setters
//////////////////////////
bool Weight::isWeightKnown() const noexcept {
    return bIsKnown;
}

bool Weight::hasMaxWeight() const noexcept {
    return bHasMax;
}

t_weight Weight::getWeight() const noexcept {
    assert( isWeightValid( weight ));
    return weight;
}

t_weight Weight::getWeight( Weight::UnitOfWeight weightUnits ) const noexcept {
    assert( isWeightValid( weight ));
    t_weight fullWeight = convertWeight( weight, unitOfWeight, weightUnits );
    return fullWeight;
}

t_weight Weight::getMaxWeight() const noexcept {
    return MaxWeight;
}

Weight::UnitOfWeight Weight::getWeightUnit() const noexcept {
    return unitOfWeight;
}

void Weight::setWeight( t_weight newWeight ) {
    weight = newWeight;
}

void Weight::setWeight( t_weight newWeight, Weight::UnitOfWeight weightUnits ) {
    weight = newWeight;
    unitOfWeight = weightUnits;
}

///////////////////////
/// Checks and methods
///////////////////////
bool Weight::isWeightValid( t_weight checkWeight ) const noexcept {
    assert( (checkWeight > 0 ) || checkWeight == Weight::UNKNOWN_WEIGHT );
    if( bHasMax ) {
        assert(checkWeight <= MaxWeight);
    }
    return true;
}

bool Weight::validate() const noexcept {
    assert(isWeightValid(weight));
    assert(isWeightValid(MaxWeight));
    return true;
}

//Dump
void Weight::dump() const noexcept {
    std::cout << "===================================" << std::endl;
    std::cout << "bIsKnown:   " << bIsKnown << std::endl;
    std::cout << "bHasMax:    " << bHasMax  << std::endl;
    std::cout << "Unit:       " << unitOfWeight << std::endl;
    std::cout << "Weight:     " << weight    << std::endl;
    std::cout << "Max Weight: " << MaxWeight << std::endl;
}

//Operators
std::ostream& operator<<( std::ostream& lhs_stream,Weight::UnitOfWeight rhs_UnitOfWeight );
std::ostream& operator<<( std::ostream& lhs_stream
        ,const Weight::UnitOfWeight rhs_UnitOfWeight ) {
    switch( rhs_UnitOfWeight ) {
        case Weight::POUND: return lhs_stream << Weight::POUND_LABEL ;
        case Weight::KILO: return lhs_stream << Weight::KILO_LABEL ;
        case Weight::SLUG: return lhs_stream << Weight::SLUG_LABEL ;
    }
    return lhs_stream << Weight::POUND_LABEL ;
}

//Override equals to
bool Weight::operator==(const Weight &rhs_Weight) const {
    t_weight leftWeight = convertWeight( weight, unitOfWeight, POUND );
    t_weight rightWeight = convertWeight( rhs_Weight.weight, rhs_Weight.unitOfWeight, POUND);
    if( leftWeight == rightWeight ) {
        return true;
    }
    return false;
};

//Override less than
bool Weight::operator<( const Weight &rhs_Weight) const {
    t_weight leftWeight = convertWeight( weight, unitOfWeight, POUND);
    t_weight rightWeight = convertWeight( rhs_Weight.weight, rhs_Weight.unitOfWeight, POUND );
    if( leftWeight < rightWeight ) {
        return true;
    }
    return false;
}

Weight &Weight::operator+=(t_weight rhs_addToWeight) {
    weight += rhs_addToWeight;
    return *this;
}

//Conversions
t_weight Weight::fromKilogramToPound(t_weight kilogram) noexcept {
    t_weight pound = kilogram / KILOS_IN_A_POUND;
    return pound;
}

t_weight Weight::fromPoundToKilogram(t_weight pound) noexcept {
    t_weight kilogram = pound * KILOS_IN_A_POUND;
    return kilogram;
}

t_weight Weight::fromSlugToPound(t_weight slug) noexcept {
    t_weight pound = slug / SLUGS_IN_A_POUND;
    return pound;
}

t_weight Weight::fromPoundToSlug(t_weight pound) noexcept {
    t_weight slugs = pound * SLUGS_IN_A_POUND;
    return slugs;
}

t_weight Weight::convertWeight(t_weight fromWeight, Weight::UnitOfWeight fromUnit, Weight::UnitOfWeight toUnit) noexcept {
    switch( fromUnit ){
        case POUND:
            switch( toUnit ){
                case POUND:
                    return fromWeight;
                case KILO:
                    return fromPoundToKilogram( fromWeight );
                case SLUG:
                    return fromPoundToSlug( fromWeight );
            }
        case KILO:
            switch( toUnit ){
                case POUND:
                    return fromKilogramToPound( fromWeight );
                case KILO:
                    return fromWeight;
                case SLUG:
                    t_weight pound = fromKilogramToPound( fromWeight );
                    return fromPoundToSlug( pound );
            }
        case SLUG:
            switch( toUnit ){
                case SLUG:
                    return fromWeight;
                case POUND:
                    return fromSlugToPound( fromWeight );
                case KILO:
                    t_weight pound = fromSlugToPound( fromWeight );
                    return fromPoundToKilogram( pound );
            }
    }
    return 0;
}


