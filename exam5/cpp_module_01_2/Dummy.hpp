#ifndef DUMMY_HPP
#define DUMMY_HPP

#include "ATarget.hpp"

class Dummy: public ATarget{
public:
	Dummy():ATarget("Dummy Practice"){}
	virtual ~Dummy(){}
	ATarget *clone(void) const{ return (new Dummy(*this)); }
};

#endif
