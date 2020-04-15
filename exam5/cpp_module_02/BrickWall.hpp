#ifndef BRICKWALL_HPP
#define BRICKWALL_HPP

#include "ATarget.hpp"

class BrickWall: public ATarget
{
public:
	BrickWall():ATarget("BrickWall Practice"){}
	virtual ~BrickWall(){}
	virtual ATarget *clone(void) const{ return (new BrickWall(*this)); }
};

#endif
