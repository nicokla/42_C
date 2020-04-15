#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP

#include <vector>
#include "ATarget.hpp"

class TargetGenerator {
private:
std::vector<ATarget*> types;

TargetGenerator(TargetGenerator const &other);
TargetGenerator &operator=(TargetGenerator const &other);

public:

TargetGenerator(){}

virtual ~TargetGenerator(){
	std::vector<ATarget*>::iterator ite = this->types.end();
	for (std::vector<ATarget*>::iterator it = this->types.begin(); it != ite; ++it)
		delete *it;
	this->types.clear();
}

void learnTargetType(ATarget *type){
	if (type) {
		std::vector<ATarget*>::iterator ite = this->types.end();
		for (std::vector<ATarget*>::iterator it = this->types.begin(); it != ite; ++it)
			if ((*it)->getName() == type->getName())
				return ;
		this->types.push_back(type->clone());
	}
}

void forgetTargetType(std::string const &typeName) {
	std::vector<ATarget*>::iterator ite = this->types.end();
	for (std::vector<ATarget*>::iterator it = this->types.begin(); it != ite; ++it) {
		if ((*it)->getName() == typeName) {
			delete *it;
			it = this->types.erase(it);
		}
	}
}

ATarget *createTarget(std::string const &typeName){
	std::vector<ATarget*>::iterator ite = this->types.end();
	for (std::vector<ATarget*>::iterator it = this->types.begin(); it != ite; ++it) {
		if ((*it)->getName() == typeName) {
			return (*it);
		}
	}
	return (nullptr);
}


};

#endif
