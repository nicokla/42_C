#ifndef ATARGET_HPP
#define ATARGET_HPP

#include <iostream>
#include <string>

class ASpell;

class ATarget
{
private:
	std::string type;
public:
	ATarget():type(){}
	ATarget(std::string const &type):type(type){}
	ATarget(ATarget const &other):type(other.type){}
	virtual ~ATarget(){}
	ATarget &operator=(ATarget const &other){
		this->type = other.type;
		return (*this);
	}

	std::string const &getType(void) const{ return type; }

	void getHitBySpell(ASpell const &spell) const{
		std::cout << this->type << " has been " << spell.getEffects() << "!\n";
	}

	virtual ATarget *clone(void) const = 0;
};

#include "ASpell.hpp"

#endif
