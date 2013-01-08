// Monster.h

#ifndef MONSTER_H
#define MONSTER_H

#include "Weapon.h"
#include <string>

// "Forward class declaration" so that we can use the Player
// class without having defined it yet.  This idea is 
// similar to a function declaration.

class Player;

class Monster
{
public:
	Monster(const std::string& name, int hp, int acc,
		int xpReward,int lowGoldReward,int highGoldReward, int armor, const std::string& weaponName,
		int lowDamage, int highDamage);

	bool isDead();

	int         getXPReward();
	int			getGoldReward();
	std::string getName();
	int         getArmor();

	void attack(Player& player);
	void takeDamage(int damage);
	void displayHitPoints();

private:
	std::string mName;
	int         mHitPoints;
	int         mAccuracy;
	int         mExpReward;
	int         mArmor;
	int			mLowGoldReward;
	int			mHighGoldReward;
	Weapon      mWeapon;
};

#endif //MONSTER_H