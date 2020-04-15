for file in ATarget Dummy Fwoosh Warlock; do
	printf '' > $file.cpp
done

prepare(){
	cap1=$(echo $1 | tr a-z A-Z)
	cap2=$(echo $2 | tr a-z A-Z)
	cp $1.hpp $2.hpp
	./replace.sh $2.hpp $1 $2
	./replace.sh $2.hpp $cap1 $cap2
}

prepare Warlock ASpell
./replace.sh ASpell.hpp title effects 
./replace.sh ASpell.hpp Title Effects 
read -p "modify as needed"
# deplacer public
# enlever setEffects et introduce et effetsDeBordCreationDestruction
# ajouter launch        void launch(ATarget const &target) const; 
# ajouter clone     virtual ASpell *clone(void) const = 0;
# changer les include

cp ASpell.hpp ATarget.hpp
./exchange.sh ATarget.hpp ATarget ASpell
./replace.sh ATarget.hpp ASPELL ATARGET 
./replace.sh ATarget.hpp name type
./replace.sh ATarget.hpp effects type
./replace.sh ATarget.hpp Name Type
./replace.sh ATarget.hpp Effects Type
./replace.sh ATarget.hpp launch getHitBySpell
./replace.sh ATarget.hpp target spell
# remove double stuff
# define getHitBySpell

cp Dummy.hpp Fwoosh.hpp
./exchange.sh Fwoosh.hpp ATarget ASpell
./replace.sh Fwoosh.hpp Dummy Fwoosh
./replace.sh Fwoosh.hpp DUMMY FWOOSH

# coder fonctions de Warlock (ajouter 3 includes et 3 fonctions, completer destructor)
