#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <string>
#include <vector>
#include "ASpell.hpp"
#include "ATarget.hpp"

class Warlock {
private:
	std::string name;
	std::string title;
	std::vector<ASpell*> spells;

	Warlock();
	Warlock(Warlock const &other);
	Warlock &operator=(Warlock const &other);

public:

Warlock(std::string const &name, std::string const &title):
		name(name), title(title) {
	std::cout << this->name << ": What a boring day\n";
}

virtual ~Warlock(){
	std::cout << this->name << ": My job here is done!\n";
	std::vector<ASpell*>::iterator ite = this->spells.end();
	for (std::vector<ASpell*>::iterator it = this->spells.begin(); it != ite; ++it)
		delete *it;
	this->spells.clear();
}

std::string const &getName(void) const{ return name; }
std::string const &getTitle(void) const{ return title; }
void setTitle(std::string const &title){ this->title = title; }

void introduce(void) const{
	std::cout << this->name << ": My name is " 
		<< this->name << ", " << this->title << "!\n";
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

void forgetSpell(std::string const &spellName){
	std::vector<ASpell*>::iterator ite = this->spells.end();
	for (std::vector<ASpell*>::iterator it = this->spells.begin(); it != ite; ++it) {
		if ((*it)->getName() == spellName) {
			delete *it;
			it = this->spells.erase(it);
		}
	}
}

void launchSpell(std::string const &spellName, ATarget const &target){
	std::vector<ASpell*>::iterator ite = this->spells.end();
	for (std::vector<ASpell*>::iterator it = this->spells.begin(); it != ite; ++it) {
		if ((*it)->getName() == spellName) {
			(*it)->launch(target);
			return ;
		}
	}
}

};

#endif
