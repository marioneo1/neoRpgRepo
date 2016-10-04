// RPG Game.cpp : Defines the entry point for the console application.
//
// this is a comment
// Neo Marcos
// 09.12.2016

#include <cmath>
#include <iostream>		// input/output library
#include <iomanip>
#include <string>


//class definition for enemies
class Monster {
public:
	Monster();
	Monster(std::string name, int hp, int evasion, int dmg, int dmgvariation, int experience);
	void print();
	std::string getName();

private:
	std::string monsterName;
	int maxMonsterHealth;
	int monsterLevel;
	int currentMonsterHealth;
	int monsterEvasion;
	int monsterDamage;
	int expReward;

};

//default const(monster)
Monster::Monster()
{
	monsterName = "DefaultMName";
	maxMonsterHealth = 50;
	currentMonsterHealth = maxMonsterHealth;
	monsterEvasion = 5;
	monsterDamage = 40;
	expReward = 20;
}

Monster::Monster(std::string monsName, int monsLevel, int monsHP, int monsEva, int reliableDmg, int expRew)
{
	monsterName = monsName;
	maxMonsterHealth = monsHP;
	currentMonsterHealth = maxMonsterHealth;
	monsterEvasion = monsEva;
	monsterDamage = (rand() % monsLevel + reliableDmg);
	expReward = expRew;
}

void Monster::print()
{
	std::cout << "\nMonster Name : " << monsterName << "\nMonster HP : " << maxMonsterHealth << "/" << currentMonsterHealth << "\nEvasion Chance : " << monsterEvasion
		<< "\n" << "\nMonster EXP : " << expReward << std::endl;
}

std::string Monster::getName()
{
	return monsterName;
}



//class definition for user
class Player {
public:
	Player();
	Player(std::string, std::string);
	void showStats();
	double getAmount(double temporaryAmount);
	void levelUp(int charaterLevel);
	int getLevel();
	friend class Monster;

private:
	std::string playerFirstName;	// done
	std::string playerLastName;	// done
	int playerLevel; // done
	static int levelPoints;	// done
	int levelupEXP;
	int currentEXP;
	int damage;
	int strength;	// done
	int vitality;	// done
	int intelligence;	// done
	int stamina;	// done
	int agility;	// done
	int dexterity;	// done
	int maxPlayerHealth;	// done
	int currentPlayerHealth;	// done
	int maxPlayerMagicka;	// done
	int currentPlayerMagicka;	// done
};
int Player::levelPoints = 0;

//Function defs
//default const(player)
Player::Player() {
	playerFirstName = "Default";
	playerLastName = "Default";
	playerLevel = 0;
	strength = 5;
	vitality = 5;
	intelligence = 5;
	stamina = 5;
	agility = 5;
	dexterity = 5;


}
//overloaded const
Player::Player(std::string mainFirstName, std::string mainLastName) {
	int statChoice;
	playerFirstName = mainFirstName;
		playerLastName = mainLastName;
		std::cout << "Your name is " << playerFirstName << " " << playerLastName << ".";
		std::cout << "\nPlease distribute your stat points : ";
		strength = 5;
		vitality = 5;
		intelligence = 5;
		stamina = 5;
		agility = 5;
		dexterity = 5;
		playerLevel = 0;
		levelUp(getLevel());
}

/*Level Up*/
void Player::levelUp(int characterLevel)
{
	playerLevel = characterLevel+1;
	levelPoints += 7;
	std::cout << "			**********\\Level Up!/**********" << std::endl;
	int statChoice;

	for (; levelPoints > 0; levelPoints -= 1)
	{
		std::cout << "\n			Total points left : =" << levelPoints
			<< "\n			1. Str = " << strength
			<< "\n			2. Vit = " << vitality
			<< "\n			3. Intl = " << intelligence
			<< "\n			4. Stam = " << stamina
			<< "\n			5. Agi = " << agility
			<< "\n			6. Dex = " << dexterity;
			maxPlayerHealth = 50 * (vitality + 5);
			currentPlayerHealth = maxPlayerHealth;
			maxPlayerMagicka = 50 * (intelligence + 5);
			currentPlayerMagicka = currentPlayerMagicka;
			std::cout << "\n			MaxHP = " << maxPlayerHealth
			<< "\n			MaxMAG = " << maxPlayerMagicka
			<< "\n\nChoose using the number beside the stat you wish to increase (1-6)\n";
		while (!(std::cin >> statChoice) || statChoice <= 0 || statChoice > 6)
		{
			std::cout << "\nPlease input a number between 1-6\n";
			std::cin.clear(); /*cure for endless loop when inputting char on int*/
			std::cin.ignore();
		}
		if (statChoice == 1)
		{
			strength += 1;
		}
		else if (statChoice == 2)
		{
			vitality += 1;
		}
		else if (statChoice == 3)
		{
			intelligence += 1;
		}
		else if (statChoice == 4)
		{
			stamina += 1;
		}
		else if (statChoice == 5)
		{
			agility += 1;
		}
		else if (statChoice == 6)
		{
			dexterity += 1;
		}
		system("CLS");
	}
}

/*Stats*/
void Player::showStats()
{
	getLevel();
	std::cout << "			**********\\Current Stats/**********"
		<< "\n			Str = " << strength
		<< "\n			Vit = " << vitality
		<< "\n			Intl = " << intelligence
		<< "\n			Stam = " << stamina
		<< "\n			Agi = " << agility
		<< "\n			Dex = " << dexterity;
		maxPlayerHealth = 50 * (vitality + 5);
		currentPlayerHealth = maxPlayerHealth;
		maxPlayerMagicka = 50 * (intelligence + 5);
		currentPlayerMagicka = currentPlayerMagicka;
		std::cout << "\n			MaxHP = " << maxPlayerHealth
		<< "\n			MaxMAG = " << maxPlayerMagicka << std::endl;
	system("pause");
	system("CLS");
}

/*Get current level*/
int Player::getLevel()
{
	std::cout << "\n			" << playerFirstName << " " << playerLastName << "'s current level is " << playerLevel << std::endl;
	return playerLevel;
}

/*Functions*/
Player battle(Player playerCharacter);


int main()
{
	/*Setting Character Name*/
	std::string mainFirstName, mainLastName;
	std::cout << "You are a wanderer from a far away land... \nand this is the start of your journey...\n"
			<< "\What's your first name?\n";
	std::cin >> mainFirstName;
	std::cout << "What's your last name?\n";
	std::cin >> mainLastName;
	Player playerCharacter(mainFirstName, mainLastName);
	playerCharacter = battle(playerCharacter);
	Monster chimera("Chimera", 99, 500, 10, 150, 200);
	/*playerCharacter.showStats(); 
	playerCharacter.levelUp(playerCharacter.getLevel()); 
	playerCharacter.getLevel(); */
	chimera.getName();
	


	system("pause");
	return 0;
}

Player battle(Player playerCharacter)
{
	std::cout << "\nYou get into a fight with ";
	return playerCharacter;
}
