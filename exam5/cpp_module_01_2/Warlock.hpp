#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <string>
#include "ASpell.hpp"
#include "ATarget.hpp"

class Warlock {
private:
	std::string name;
	std::string title;

	Warlock():name(), title(){};
	Warlock(Warlock const &other):name(other.name), title(other.title){}
	Warlock &operator=(Warlock const &other){
		name = other.name;
		title = other.title;
		return (*this);
	}

public:

Warlock(std::string const &name, std::string const &title):
		name(name), title(title) {
	std::cout << this->name << ": What a boring day\n";
}

virtual ~Warlock(){
	std::cout << this->name << ": My job here is done!\n";
}

std::string const &getName(void) const{ return name; }
std::string const &getTitle(void) const{ return title; }
void setTitle(std::string const &title){ this->title = title; }

void introduce(void) const{
	std::cout << this->name << ": My name is " 
		<< this->name << ", " << this->title << "!\n";
}

};

#endif
