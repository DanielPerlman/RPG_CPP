#!/bin/sh

#compile.sh is a shell script that we can run to compile the RPG_CPP game.
#just run ./compile.sh to compile
#if we add more files just use `echo "NEWFILE" >> compile.sh`
#to add the new files.

g++ game.cpp Map.cpp Map.h Monster.cpp Monster.h Player.cpp Player.h Random.cpp Random.h Range.h Spell.h Weapon.h -o game
