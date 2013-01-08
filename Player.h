// Player.h

#ifndef PLAYER_H
#define PLAYER_H
#include "Point.h"
#include "Weapon.h"
#include "Monster.h"
#include <string>
#include <fstream>
class Player
{
public:
	// Constructor.
	Player();

	// Methods
	bool isDead();

	int  getArmor();//returns the players armor
	void move(int x,int y);
	void takeDamage(int damage);//used for taking damage in combat or regaining hp(will be added later)
	void gainGold(int goldReward);//used when a monster is killed or when using the store(will be added)
	void createClass();//starts the class generation
	void createRace();//starts the race generation
	bool attack(Monster& monster);//used in combat to damage monster
	void levelUp();
	void rest();//regains hp to max, later will also regain mana and have chance of encountering monster
	void viewStats();//prints out all stats
	void victory(int xp);//used for when monster is killed, gives xp
	bool gameover();//if player dies, gives option to restart or quit
	void displayHitPoints();//prints out hp, used for combat loop
 	void save(std::ofstream& outFile);//used for saving the game, not implemented yet
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
	int         mGold;
	Weapon      mWeapon;
	Point       mPlayerPos;
};

#endif //PLAYER_H
