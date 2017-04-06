#include <iostream>
#include <string>
#include <vector>
#include "FBattleGame.h"

using FText = std::string;
using int32 = int;

// Functions
void PrintGameIntro();
void PlayGame();
EBattleEventType GetPlayerAction();
int32 GetActionTarget(EBattleEventType Action);
bool PlayAgain();

FBattleGame Game; // instantiate a new game

int main()
{
	bool bPlayAgain = false;
	do {
		PrintGameIntro();
		PlayGame();
		bPlayAgain = PlayAgain();
	} while (bPlayAgain);

	return 0;
}

void PrintGameIntro()
{
	std::cout << "+-------------------------------------------------------------------------+\n";
	std::cout << "| Test code for RPG battle system in C++ to use in Unreal Engine.         |\n";
	std::cout << "| Play in order to see if you will live or die.                           |\n";
	std::cout << "+-------------------------------------------------------------------------+\n\n";
	return;
}

void PlayGame()
{ 
	Game.ResetGame();
	Game.CreateParty();
	Game.CreateEnemy();
	Game.CreateTurnOrder();

	// loop until enemy (or whole party) is dead
	while(!Game.IsGameWon()){  //TODO fix so it includes if whole party dies
		Game.PrintTurnOrder();

		//NOTE: this is only done if ally so may need type check here or somewhere else
		EBattleEventType Action = GetPlayerAction();
		int32 Target = GetActionTarget(Action);

		Game.Encounter(Action, Target);// TODO add Target
	}
	return;
}

EBattleEventType GetPlayerAction()
{
	FText Action = "";
	EBattleEventType Status = EBattleEventType::INVALID;
	bool IsValidAction = false;

	do { //loop until player provides a valid action
		std::cout << "What would you like the " << Game.GetCurrentActor() <<" to do, Attack[1] or Heal[2]?\n";
		std::getline(std::cin, Action);

		if (Action == "1") {
			IsValidAction = true;
			Status = EBattleEventType::ATTACK;
		}
		else if (Action == "2") {
			IsValidAction = true;
			Status = EBattleEventType::HEAL;
		}
		return Status;
	} while (!IsValidAction);
	
}

int32 GetActionTarget(EBattleEventType Event)
{
	FText Target = "";
	EBattleEventType Action = Event;
	EActorType Type = None;
	Type = Game.GetTurnOrderVector().at(0).GetType();
	bool IsValidTarget = true;
	int32 i_Target = 0;

	std::cout << std::endl;
	std::cout << "Who would you like " << Game.GetCurrentActor() << " to target? The choices are: \n";
	
	// TODO put possibilities in a vector?
	do { //TODO loop until player gives a valid target, foe for attack, ally for heal -> IsValidTarget
		if (Action == ATTACK) {
			for (int32 i = 0; i < Game.GetTurnOrderVector().size(); i++) {
				if (Type != Game.GetTurnOrderVector().at(i).GetType()) {
					std::cout << "* " << Game.GetTurnOrderVector().at(i).GetName() << "[" << i + 1 << "]\n";
				}
			}
		}
		else if (Action == HEAL) {
			for (int32 i = 0; i < Game.GetTurnOrderVector().size(); i++) {
				if (Type == Game.GetTurnOrderVector().at(i).GetType()) {
					std::cout << "* " << Game.GetTurnOrderVector().at(i).GetName() << "[" << i + 1 << "]\n";
				}
			}
		}
		std::getline(std::cin, Target);
		i_Target = std::stoi(Target) - 1;
		std::cout << "\n\nYou target the " << Game.GetTurnOrderVector().at(i_Target).GetName() << std::endl;
	} while (!IsValidTarget);
	return i_Target;
}

bool PlayAgain() 
{
	std::cout << "Do you want to play again? (y/n)";
	FText Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'y' || Response[0] == 'Y');
}