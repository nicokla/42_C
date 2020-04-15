for file in BrickWall Fireball Polymorph TargetGenerator; do
	printf '' > $file.cpp
done

prepare(){
	local old=$1
	local new=$2
	local oldCap=$(echo $old | tr a-z A-Z)
	local newCap=$(echo $new | tr a-z A-Z)
	cp $old.hpp $new.hpp
	./replace.sh $new.hpp $old $new
	./replace.sh $new.hpp $oldCap $newCap
}

prepare Dummy BrickWall

prepare Fwoosh Fireball
./replace.sh Fireball.hpp "fwooshed" "burnt to a crisp"

prepare Fwoosh Polymorph
./replace.sh Polymorph.hpp "fwooshed" "turned to a sheep"

# copier coller les fonctions de Warlock dans Spellbook, sauf la derniere
# changer les fonctions dans Warlock en faisant reference a SpellBook

prepare SpellBook TargetGenerator
file=TargetGenerator.hpp
./exchange.sh $file ASpell ATarget
./replace.sh $file spell type
./replace.sh $file Spell Type
./replace.sh $file learnType learnTargetType
./replace.sh $file forgetType forgetTargetType
./replace.sh $file generateType createTarget
./replace.sh $file getName getType