// Player.h

#ifndef PLAYER_H
#define PLAYER_H

#include "Weapon.h"
#include "Monster.h"
#include <string>

class Player
{
public:
	// Constructor.
	Player();

	// Methods
	bool isDead();

	int  getArmor();

	void takeDamage(int damage);
	void gainGold(int goldReward);
	void createClass();
	void createRace();
	bool attack(Monster& monster);
	void levelUp();
	void rest();
	void viewStats();
	void victory(int xp);
	void gameover();
	void displayHitPoints();
 
private:
	// Data members.
	std::string mName;
	std::string mClassName;
	std::string mRaceName;
	int         mAccuracy;
	int         mHitPoints;
	int         mMaxHitPoints;
	int         mExpPoints;
	int         mNextLevelExp;
	int         mLevel;
	int         mArmor;
	int			mGold;
	Weapon      mWeapon;
};

#endif //PLAYER_H