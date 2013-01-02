// game.cpp

#include "Map.h"
#include "Player.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main()
{
	srand( time(0) );

	Map gameMap;

	Player mainPlayer;

	mainPlayer.createClass();
	mainPlayer.createRace();
	// Begin adventure.
	bool done = false;
	while( !done )
	{
		// Each loop cycly we output the player position and 
		// a selection menu.

		gameMap.printPlayerPos();
	
		int selection = 1;
		cout << "1) Move, 2) Rest, 3) View Stats, 4) Quit: ";
		cin >> selection;

		Monster* monster = 0;
		switch( selection )
		{
		case 1:
			gameMap.movePlayer();

			// Check for a random encounter.  This function
			// returns a null pointer if no monsters are
			// encountered.
			monster = gameMap.checkRandomEncounter();

			// 'monster' not null, run combat simulation.
			if( monster != 0 )
			{
				// Loop until a 'break' statement.
				while( true )
				{
					// Display hitpoints.
					mainPlayer.displayHitPoints();
					monster->displayHitPoints();
					cout << endl;

					// Player's turn to attack first.
					bool runAway = mainPlayer.attack(*monster);

					if( runAway )
						break;

					if( monster->isDead() )
					{
						mainPlayer.victory(monster->getXPReward());
						mainPlayer.gainGold(monster->getGoldReward());
						mainPlayer.levelUp();
						break;
					}

					monster->attack(mainPlayer);

					if( mainPlayer.isDead() )
					{
						mainPlayer.gameover();
						done = true;
						break;
					}
				}

				// The pointer to a monster returned from
				// checkRandomEncounter was allocated with
				// 'new', so we must delete it to avoid
				// memory leaks.
				delete monster;
				monster = 0;
			}

			break;
		case 2:
			mainPlayer.rest();
			break;
		case 3:
			mainPlayer.viewStats();
			break;
		case 4:
			done = true;
			break;
		}
	}	
}