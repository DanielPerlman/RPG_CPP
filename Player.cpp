// Player.cpp

#include <iostream>
#include "Player.h"
#include "Random.h"
#include <string>
#include <fstream>
using namespace std;

Player::Player()
{
	mName         = "Default";
	mClassName    = "Default";
	mRaceName     = "Default";
	mAccuracy     = 0;
	mHitPoints    = 0;
	mMaxHitPoints = 0;
	mExpPoints    = 0;
	mNextLevelExp = 0;
	mLevel        = 0;
	mArmor        = 0;
	mWeapon.mName = "Default Weapon Name";
	mWeapon.mDamageRange.mLow  = 0;
	mWeapon.mDamageRange.mHigh = 0;
	mGold		  = 0;
	mPlayerPos.x      = 0;
	mPlayerPos.y	  = 0;
}
void Player::move(int x, int y){
	mPlayerPos.x += x;
	mPlayerPos.y += y;
}
void Player::save(std::ofstream& outFile){
	outFile << "Player Name : " << mName << endl;
	outFile << "Player Class: " << mClassName << endl;
	outFile << "Player Race : " << mRaceName << endl;
	outFile << "Player Acc  : " << mAccuracy << endl;
	outFile << "Current HP  : " << mHitPoints << endl;
	outFile << "Max HP	: " << mMaxHitPoints << endl;
	outFile << "Current Exp : " << mExpPoints << endl;
	outFile << "Next Lvl HP : " << mNextLevelExp << endl;
	outFile << "Player lvl	: " << mLevel << endl;
	outFile << "Player Armor: " << mArmor << endl;
	outFile << "Weapon	: " << mWeapon.mName << endl;
	outFile << "Weapon R Low: " << mWeapon.mDamageRange.mLow << endl;
	outFile << "Weapon R H  : " << mWeapon.mDamageRange.mHigh << endl;
	outFile << "Gold	: " << mGold << endl;
	outFile << "Position X  : " << mPlayerPos.x << endl;
	outFile << "Position Y  : " << mPlayerPos.y << endl;
}
bool Player::isDead()
{
	return mHitPoints <= 0;
}
int Player::getArmor()
{
	return mArmor;
}
void Player::takeDamage(int damage)
{
	mHitPoints -= damage;
}
void Player::gainGold(int goldReward){
	mGold += goldReward;
}
void Player::createClass()
{
	cout << "\nCHARACTER CLASS GENERATION\n";
	cout << "==========================\n";

	// Input character's name.
	cout << "Enter your character's name: ";
	getline(cin, mName);

	// Character selection.
	cout << "\nPlease select a character class number...\n";	
	cout << "1)Fighter 2)Mage 3)Cleric 4)Thief : ";	

	int characterNum = 1;	
	cin >> characterNum;

	switch( characterNum )
	{
	case 1:  // Fighter
		mClassName    = "Fighter";
		mAccuracy     = 10;
		mHitPoints    = 20;
		mMaxHitPoints = 20;
		mExpPoints    = 0;
		mNextLevelExp = 1000;
		mLevel        = 1;
		mArmor        = 4;
		mWeapon.mName = "Long Sword";
		mWeapon.mDamageRange.mLow  = 4;
		mWeapon.mDamageRange.mHigh = 10;
		break;
	case 2:  // Wizard
		mClassName    = "Mage";
		mAccuracy     = 5;
		mHitPoints    = 10;
		mMaxHitPoints = 10;
		mExpPoints    = 0;
		mNextLevelExp = 1000;
		mLevel        = 1;
		mArmor        = 1;
		mWeapon.mName = "Staff";
		mWeapon.mDamageRange.mLow  = 1;
		mWeapon.mDamageRange.mHigh = 4;
		break;
	case 3:  // Cleric
		mClassName    = "Cleric";
		mAccuracy     = 8;
		mHitPoints    = 15;
		mMaxHitPoints = 15;
		mExpPoints    = 0;
		mNextLevelExp = 1000;
		mLevel        = 1;
		mArmor        = 3;
		mWeapon.mName = "Flail";
		mWeapon.mDamageRange.mLow  = 3;
		mWeapon.mDamageRange.mHigh = 9;
		break;
	default: // Thief
		mClassName    = "Thief";
		mAccuracy     = 7;
		mHitPoints    = 12;
		mMaxHitPoints = 12;
		mExpPoints    = 0;
		mNextLevelExp = 1000;
		mLevel        = 1;
		mArmor        = 2;
		mWeapon.mName = "Short Sword";
		mWeapon.mDamageRange.mLow  = 4;
		mWeapon.mDamageRange.mHigh = 6;
		break;
	}
}
void Player::createRace(){
	cout << "\nRACE GENERATION\n";
	cout << "===============\n";

	cout << "Pick a race! : \n";
	cout << " 1) Human 2) Elf 3) Dwarf 4) Minotaur 5) Undead 6) Goblin 7) Random : ";
	int choice = 0;
	cin >> choice;
	if(choice == 7){
		choice = Random(1,7);
	}
	switch(choice){
	case 1:
		mRaceName	   = "Human";
		mHitPoints    += 1;
		mMaxHitPoints += 1;
		mAccuracy	  += 1;
		mArmor		  += 1;
		mWeapon.mDamageRange.mLow += 1;
		mWeapon.mDamageRange.mHigh+= 1;
        cout << "\nYou are a Human\n";
		break;
	case 2:
		mRaceName      = "Elf";
		mHitPoints	  -= 2;
		mMaxHitPoints -= 2;
		mAccuracy	  += 3;
		mArmor		  += 1;
        cout << "\nYou are an Elf\n";
		break;
	case 3:
		mRaceName	   = "Dwarf";
		mHitPoints	  += 4;
		mMaxHitPoints += 4;
		mAccuracy	  -= 4;
		mArmor		  += 2;
        cout << "\nYou are a Dwarf\n";
		break;
	case 4: 
		mRaceName	   = "Minotaur";
		mHitPoints	  += 5;
		mMaxHitPoints += 5;
		mArmor		  += 2;
		mAccuracy	  -= 4;
		mWeapon.mDamageRange.mLow -= 2;
		mWeapon.mDamageRange.mHigh-= 2;
        cout << "\nYou are a Minotaur\n";
		break;
	case 5:
		mRaceName	   = "Undead";
		mHitPoints    -= 4;
		mMaxHitPoints -= 4;
		mArmor		  -= 4;
		mAccuracy	  -= 2;
		mWeapon.mDamageRange.mLow += 4;
		mWeapon.mDamageRange.mHigh+= 4;
        cout << "\nYou are Undead\n";
		break;
	case 6:
		mRaceName	   = "Goblin";
		mArmor		  += 4;
		mAccuracy	  -= 2;
        cout << "\nYou are a Goblin\n";
		break;
	case 7:
		break;
	default:
		cout << "Error: wrong number chosen, try again : ";
		createRace();
		break;
	}
}
bool Player::attack(Monster& monster)
{
	// Combat is turned based: display an options menu.  You can,
	// of course, extend this to let the player use an item,
	// cast a spell, and so on.
	int selection = 1;
	cout << "1) Attack, 2) Run: ";
	cin >> selection;
	cout << endl;

	switch( selection )
	{
	case 1:
		cout << "You attack an " << monster.getName() 
			<< " with a " << mWeapon.mName << endl;

		if( Random(0, 20) < mAccuracy )
		{
			int damage = Random(mWeapon.mDamageRange);

			int totalDamage = damage - monster.getArmor();

			if( totalDamage <= 0 )
			{
				cout << "Your attack failed to penetrate "
					<< "the armor." << endl;
			}
			else
			{
				cout << "You attack for " << totalDamage 
					<< " damage!" << endl;

				// Subtract from monster's hitpoints.
				monster.takeDamage(totalDamage);
			}
		}
		else
		{
			cout << "You miss!" << endl;
		}
		cout << endl;
		break;
	case 2:
		// 25 % chance of being able to run.
		int roll = Random(1, 4);

		if( roll == 1 )
		{
			cout << "You run away!" << endl;
			return true;//<--Return out of the function.
		}
		else
		{
			cout << "You could not escape!" << endl;
			break;
		}
	}

	return false;
}
 
void Player::levelUp()
{
	if( mExpPoints >= mNextLevelExp )
	{
		cout << "You gained a level!" << endl;

		// Increment level.
		mLevel++;

		// Set experience points required for next level.
		mNextLevelExp = mLevel * mLevel * 1000;

		// Increase stats randomly.
		mAccuracy     += Random(1, 3);
		mMaxHitPoints += Random(2, 6);
		mArmor        += Random(1, 2);

		// Give player full hitpoints when they level up.
		mLevel = mMaxHitPoints;
	}
}

void Player::rest()
{
	cout << "Resting..." << endl;

	mHitPoints = mMaxHitPoints;

	// TODO: Modify function so that random enemy encounters
	// are possible when resting.
}

void Player::viewStats()
{
	cout << "\nPLAYER STATS\n";
	cout << "============\n";
	cout << endl;

	cout << "Name            = " << mName         << endl;
	cout << "Class           = " << mClassName    << endl;
	cout << "Race            = " << mRaceName     << endl;
	cout << "Accuracy        = " << mAccuracy     << endl;
	cout << "Hitpoints       = " << mHitPoints    << endl;
	cout << "MaxHitpoints    = " << mMaxHitPoints << endl;
	cout << "XP              = " << mExpPoints    << endl;
	cout << "XP for Next Lvl = " << mNextLevelExp << endl;
	cout << "Level           = " << mLevel        << endl;
	cout << "Armor           = " << mArmor        << endl;
	cout << "Weapon Name     = " << mWeapon.mName << endl;
	cout << "Weapon Damage   = " << mWeapon.mDamageRange.mLow << "-" <<
		mWeapon.mDamageRange.mHigh << endl;
	cout << "Gold            = " << mGold         << endl;

	cout << endl;
	cout << "END PLAYER STATS" << endl;
	cout << "================" << endl;
	cout << endl;
}

void Player::victory(int xp)
{
	cout << "You won the battle!" << endl;
	cout << "You win " << xp 
		<< " experience points!" << endl << endl;

	mExpPoints += xp;
}

bool Player::gameover()
{
	cout << "You died in battle..." << endl;
	cout << endl;
	cout << "================================" << endl;
	cout << "GAME OVER!" << endl;
	cout << "================================" << endl;
	cout << "Press 'r' to restart or any key to quit: ";
	char q = 'r';
	cin >> q;
    if (q == 'r') {
        mGold = (int)(mGold / 2);
	mHitPoints = mMaxHitPoints;
        return false;
    } else {
        return true;
    }

	cout << endl;
}

void Player::displayHitPoints()
{
	cout << mName << "'s hitpoints = " << mHitPoints << endl;
}
