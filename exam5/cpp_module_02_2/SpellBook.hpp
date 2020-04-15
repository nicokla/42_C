#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include <vector>
#include "ASpell.hpp"

class SpellBook {
private:
std::vector<ASpell*> spells;

SpellBook(SpellBook const &other);
SpellBook &operator=(SpellBook const &other);

public:

SpellBook(){}

virtual ~SpellBook(){
	std::vector<ASpell*>::iterator ite = this->spells.end();
	for (std::vector<ASpell*>::iterator it = this->spells.begin(); it != ite; ++it)
		delete *it;
	this->spells.clear();
}

void learnSpell(ASpell *spell){
	if (spell) {
		std::vector<ASpell*>::iterator ite = this->spells.end();
		for (std::vector<ASpell*>::iterator it = this->spells.begin(); it != ite; ++it)
			if ((*it)->getName() == spell->getName())
				return ;
		this->spells.push_back(spell->clone());
	}
}

void forgetSpell(std::string const &spellName) {
	std::vector<ASpell*>::iterator ite = this->spells.end();
	for (std::vector<ASpell*>::iterator it = this->spells.begin(); it != ite; ++it) {
		if ((*it)->getName() == spellName) {
			delete *it;
			it = this->spells.erase(it);
		}
	}
}

ASpell *generateSpell(std::string const &spellName){
	std::vector<ASpell*>::iterator ite = this->spells.end();
	for (std::vector<ASpell*>::iterator it = this->spells.begin(); it != ite; ++it) {
		if ((*it)->getName() == spellName) {
			return (*it);
		}
	}
	return (nullptr);
}


};

#endif
