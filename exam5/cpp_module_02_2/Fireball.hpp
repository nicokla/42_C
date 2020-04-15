#ifndef FIREBALL_HPP
#define FIREBALL_HPP

#include "ASpell.hpp"

class Fireball: public ASpell {
public:

Fireball():ASpell("Fireball", "burnt to a crisp"){}
virtual ~Fireball(){}
ASpell *clone(void) const{ return (new Fireball(*this)); }

};

#endif
