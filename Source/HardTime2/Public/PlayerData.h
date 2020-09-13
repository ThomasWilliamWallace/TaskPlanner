#pragma once

#include <iostream>
#include "PStats.h"
#include "Missions.h"
#include "BasicAI.h"
#include "ActorItem.h"
#include "AbstractAction.h"
#include "Constants.h"
#include "Object.h"
#include "PlatformSpecific.h"
#include "Relationship.h"
#include "Runtime/Core/Public/UObject/NameTypes.h"
#include "AbstractPlayerData.h"
#include "PlayerData.generated.h"

class USimWorld;
class AActorItem;
class AHardTime2Character;

UCLASS(BlueprintType, Blueprintable)
class UPlayerData : public UObject
{
	GENERATED_BODY()

public:
    PStats pStats;

	int m_key; //players PlayerRegistry index
    int cash = 0; //cash, in dollars, no bounds.
    int sentence = 5; //days left in prison sentence, only bound is above -1.
    FName m_playerName; //name of the character, used in speech.
    AIController aiController; //controlling AI for this character
    std::shared_ptr<MissionClass> missionOffer; // a mission being offered to 'playerTarget'

	UPROPERTY()
		AActorItem* itemPtr = nullptr; //pointer to an item carried by the player

	UPROPERTY()
		UPlayerData* playerTargetPtr = nullptr; //index of the character being targetted. You must set this when attacking or assigning a mission to another player!

	UPROPERTY()
		AActorItem* itemFocusPtr = nullptr; //pointer to an item the player is trying to interact with

	UPROPERTY()
		AHardTime2Character* physicalCharacter = nullptr;

	void UpdateMissions(USimWorld &world);
    void PrintPlayer();
	bool IsRequestedRecently(UPlayerData* requestedPlayer, EItemType m_itemType);
	void SetRequested(UPlayerData* requestedPlayer);
	UPlayerData();
	UPlayerData(const FObjectInitializer& ObjectInitializer);

	UPROPERTY()
		TMap<int, URelationship*> relMap; //Relationships have manual memory management, as they are kept in a TMap without UProperty(). TODO Change to unreal memory management

	virtual class UWorld* GetWorld() const override;

	std::string CharacterName();
	AbstractPlayerData abstractPlayerData = AbstractPlayerData();
};


bool OtherInReach(AbstractPlayerData& playerPtr, AbstractPlayerData& otherPlayerPtr, PlayerMap& playerMap);