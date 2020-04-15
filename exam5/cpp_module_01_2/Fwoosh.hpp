#ifndef FWOOSH_HPP
#define FWOOSH_HPP

#include "ASpell.hpp"

class Fwoosh: public ASpell{
public:
	Fwoosh():ASpell("Fwoosh Practice"){}
	virtual ~Fwoosh(){}
	ASpell *clone(void) const{ return (new Fwoosh(*this)); }
};

#endif
