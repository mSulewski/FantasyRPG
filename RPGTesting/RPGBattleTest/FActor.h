 #pragma once
#include <string>

using FString = std::string;
using int32 = int;

enum EActorType {Hero, Enemy, None};

class FActor {
private:
	FString ActorName;
	int32 ActorMaxHealth;
	int32 ActorCurrentHealth;
	int32 ActorTurn;
	int32 ActorDamage;
	EActorType ActorType;

public:
	FActor();
	FActor(FString Name, int32 MaxHealth, EActorType Type);

	//Getters
	FString GetName() const;
	int32 GetMaxHealth() const;
	int32 GetCurrentHealth() const;
	int32 GetDamage() const;
	EActorType GetType() const;

	//Setters
	void SetName(FString);
	void SetMaxHealth(int32);
	void SetCurrentHealth(int32);
	void SetDamage();
	void SetType(EActorType);
};
