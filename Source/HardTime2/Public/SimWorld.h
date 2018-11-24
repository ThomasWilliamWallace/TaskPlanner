#pragma once

#include <vector>
#include "PlayerData.h"
#include "Object.h"
#include "SimWorld.generated.h"

class AActorItem;

UCLASS(BlueprintType, Blueprintable)
class USimWorld : public UObject //represents the simulated world
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintCallable, Category = USimWorld)
		void AddItem(AActorItem* item);

	UFUNCTION(BlueprintCallable, Category = USimWorld)
		void AddPlayer(AAICharacterC* aiCharacterC);

	UFUNCTION(BlueprintCallable, Category = USimWorld)
		void UpdateItemLocation(AActorItem* item, ELocations location);

	UFUNCTION(BlueprintCallable, Category = USimWorld)
		void UpdateCarriedItemC(AActorItem* item, ACharacter* character);

    UPlayerData* weightsOccupied;
    UPlayerData* circuitsOccupied;
    UPlayerData* studyOccupied;
    UPlayerData* bedOccupied;
    void WorldEffects(UPlayerData player[], int frame);
    void PrintWorld(UPlayerData player[]);
    void FullDisplay(UPlayerData player[]);
    void Clean();
    USimWorld();
    std::vector< AActorItem* > items;
	std::vector< UPlayerData* > m_players;
};