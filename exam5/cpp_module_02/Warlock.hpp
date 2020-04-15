#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <string>
#include <vector>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"

class Warlock {
private:
	std::string name;
	std::string title;
	SpellBook spellBook;

	Warlock();
	Warlock(Warlock const &other);
	Warlock &operator=(Warlock const &other);
public:
	virtual ~Warlock(){
		std::cout << this->name << ": My job here is done!\n";
	}
	Warlock(std::string const &name, std::string const &title):
			name(name), title(title) {
		std::cout << this->name << ": What a boring day\n";
	}

	std::string const &getName(void) const{return name;}
	std::string const &getTitle(void) const{return title;}
	void setTitle(std::string const &title){this->title = title;}
	void introduce(void) const{
		std::cout << this->name << ": My name is " << 
			this->name << ", " << this->title << "!\n";
	}

	void learnSpell(ASpell *spell){
		this->spellBook.learnSpell(spell);
	}
	void forgetSpell(std::string const &spellName){
		this->spellBook.forgetSpell(spellName);
	}
	void launchSpell(std::string const &spellName, ATarget const &target){
		ASpell *spell = this->spellBook.generateSpell(spellName);
		if (spell)
			spell->launch(target);
	}
};

#endif
