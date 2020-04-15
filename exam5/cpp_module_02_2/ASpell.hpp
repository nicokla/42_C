#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <iostream>
#include <string>

class ATarget;

class ASpell
{
private:
	std::string name;
	std::string effects;
public:
	ASpell():name(), effects(){}

	ASpell(std::string const &name, std::string const &effects):
		name(name), effects(effects){}
	
	ASpell(ASpell const &other):
		name(other.name), effects(other.effects){}
	
	virtual ~ASpell(){}

	ASpell &operator=(ASpell const &other){
		this->name = other.name;
		this->effects = other.effects;
		return (*this);
	}

	std::string const &getName(void) const { return name; }
	std::string const &getEffects(void) const { return effects; }

	void launch(ATarget const &target) const;

	virtual ASpell *clone(void) const = 0;
};

#include "ATarget.hpp"

#endif
