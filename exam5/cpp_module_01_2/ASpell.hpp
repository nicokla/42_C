#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <iostream>
#include <string>

class ATarget;

class ASpell {
private:
	std::string name;
	std::string effects;
public:

	ASpell():name(), effects(){};
	ASpell(ASpell const &other):name(other.name), effects(other.effects){}
	ASpell &operator=(ASpell const &other){
		name = other.name;
		effects = other.effects;
		return (*this);
	}


ASpell(std::string const &name, std::string const &effects):
		name(name), effects(effects) {
}

virtual ~ASpell(){
}

std::string const &getName(void) const{ return name; }
std::string const &getEffects(void) const{ return effects; }

virtual ASpell *clone() const = 0;
void launch(ATarget const &target) const;

};

#include "ATarget.hpp"


#endif
