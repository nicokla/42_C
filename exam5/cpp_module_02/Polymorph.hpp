#ifndef POLYMORPH_HPP
#define POLYMORPH_HPP

#include "ASpell.hpp"

class Polymorph: public ASpell {
public:

Polymorph(): ASpell("Polymorph", "turned to a sheep") {}
virtual ~Polymorph(){}
virtual ASpell *clone(void) const{ return (new Polymorph(*this)); }

};

#endif
