#pragma once
#include <string>
#include <vector>
#include "FActor.h"

using FString = std::string;
using int32 = int; 

enum EBattleEventType { ATTACK, HEAL, INVALID };

class FBattleGame {
public:

	void ResetGame();
	void CreateParty();
	void CreateEnemy();
	void CreateTurnOrder();

	void PrintTurnOrder();
	void Encounter(EBattleEventType, int32);
	bool IsGameWon();

	std::vector<FActor> GetTurnOrderVector() const;
	void SetTurnOrderVector(std::vector<FActor> TurnOrder); //sets new turn order
	FString GetCurrentActor() const; // gets current actor at top of turn order


private:
	bool bGameWon;
	
	FActor MainCharacter;
	FActor Chemist;
	FActor ShrineMaiden;
	FActor Barbarian;

	FActor Orc;

	std::vector <FActor> VectorActorTurn; // vector of actors stored in current turn order
	
};
