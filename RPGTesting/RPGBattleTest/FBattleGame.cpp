#include <iostream>
#include "FBattleGame.h"
#include "FActor.h"

using FString = std::string;
using int32 = int;
 

void FBattleGame::ResetGame()
{
	bGameWon = false;
	return;
}

void FBattleGame::CreateParty()
{	
	MainCharacter = FActor("Main Character", 100, Hero);
	Chemist = FActor("Chemist", 80, Hero);
	ShrineMaiden = FActor("Shrine Maiden", 60, Hero);
	Barbarian = FActor("Barbarian", 120, Hero);

	return;
}

void FBattleGame::CreateEnemy()
{
	Orc = FActor("Orc", 150, Enemy);
}

void FBattleGame::CreateTurnOrder()
{
	VectorActorTurn.push_back(MainCharacter);
	VectorActorTurn.push_back(Chemist);
	VectorActorTurn.push_back(ShrineMaiden);
	VectorActorTurn.push_back(Barbarian);

	// TODO add Orc to turn order, for now just party
	VectorActorTurn.push_back(Orc);
}

void FBattleGame::PrintTurnOrder()
{
	std::cout << "********************************************\n";
	std::cout << "TURN ORDER:\n";
	for (int32 i = 0; i < VectorActorTurn.size(); i++) {
		std::cout << i + 1 << ": " << VectorActorTurn[i].GetName()  << ",   HP: " << VectorActorTurn[i].GetCurrentHealth()
			<< " of " << VectorActorTurn[i].GetMaxHealth() << std::endl;
	}
	std::cout << "********************************************\n";
	std::cout << std::endl;
}

void FBattleGame::Encounter(EBattleEventType Action, int32 Target) // TODO adjust to have cases lead to action functions
{
	//int32 i_Action = std::stoi(Action);
	switch (Action)
	{
	case ATTACK: // TODO put statements into own function to keep case statement clear
	{
		//std::cout << "You said for " << VectorActorTurn[0].GetName() << " to attack\n\n"; 
		// TODO add actual damage
		int32 CurrentHealth = VectorActorTurn[Target].GetCurrentHealth();
		CurrentHealth = CurrentHealth - VectorActorTurn[0].GetDamage();
		VectorActorTurn[Target].SetCurrentHealth(CurrentHealth);
		std::cout << "The " << GetCurrentActor() << " does " << VectorActorTurn[0].GetDamage() << " points of damage to the " << VectorActorTurn[Target].GetName() << ". \n\n";
	}
		break;
	case HEAL: // heal
		//std::cout << "You said for " << VectorActorTurn[0].GetName() << " to heal.\n\n"; 
		// TODO add actual healing LATER
		break;
	}

	// rotates turn order (Own function?)
	std::rotate(VectorActorTurn.begin(), VectorActorTurn.begin() + 1, VectorActorTurn.end()); 
	return; 
}

std::vector<FActor> FBattleGame::GetTurnOrderVector() const { return VectorActorTurn; }

void FBattleGame::SetTurnOrderVector(std::vector<FActor> TurnOrder) // TODO fix so it is adjustable to create new turn order
{
	VectorActorTurn = TurnOrder;
}

FString FBattleGame::GetCurrentActor() const { return VectorActorTurn[0].GetName(); }

bool FBattleGame::IsGameWon()
{ 
	if (Orc.GetCurrentHealth() <= 0) { //orc died so end
		bGameWon = true;
	}
	return bGameWon; 
}
