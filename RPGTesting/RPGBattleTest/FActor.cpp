#include "FActor.h"

FActor::FActor()
	: FActor("", 0, Hero)
{
}

//NOTE: May get rid of Turn Order, it will be in its own vector
FActor::FActor(FString Name, int32 MaxHealth, EActorType Type)
{
	SetName(Name);
	SetMaxHealth(MaxHealth);
	SetCurrentHealth(MaxHealth);
	SetDamage();
	SetType(Type);
}

//Getters
FString FActor::GetName() const { return ActorName; }
int32 FActor::GetMaxHealth() const { return ActorMaxHealth; }
int32 FActor::GetCurrentHealth() const { return ActorCurrentHealth; }
int32 FActor::GetDamage() const { return ActorDamage; }
EActorType FActor::GetType() const { return ActorType; }

//Setters
void FActor::SetName(FString Name)
{
	ActorName = Name;
}

void FActor::SetMaxHealth(int32 MaxHealth)
{
	ActorMaxHealth = MaxHealth;
}

void FActor::SetCurrentHealth(int32 Health)// TODO I believe this needs fixed, this shows only initial health
{
	ActorCurrentHealth = Health;
}

void FActor::SetDamage()
{
	ActorDamage = ActorMaxHealth / 10;
}

void FActor::SetType(EActorType Type)
{
	ActorType = Type;
}
 
