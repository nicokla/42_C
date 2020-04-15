#ifndef ATARGET_HPP
#define ATARGET_HPP

#include <iostream>
#include <string>

class ASpell;

class ATarget {
private:
	std::string type;
public:

	ATarget():type(){};
	ATarget(ATarget const &other):type(other.type){}
	ATarget &operator=(ATarget const &other){
		type = other.type;
		return (*this);
	}


ATarget(std::string const &type):
		type(type) {
}

virtual ~ATarget(){
}

std::string const &getType(void) const{ return type; }

virtual ATarget *clone() const = 0;
void getHitBySpell(ASpell const &spell) const{
	std::cout << type << " has been " << spell.getEffects() << "!\n";
}

};

#include "ASpell.hpp"


#endif
