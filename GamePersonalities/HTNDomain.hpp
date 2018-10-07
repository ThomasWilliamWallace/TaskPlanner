//
//  HTNDomain.hpp
//  GamePersonalities
//
//  Created by VITALIJA STEPUSAITYTE on 25/08/2018.
//  Copyright © 2018 Thomas. All rights reserved.
//

#ifndef HTNDomain_hpp
#define HTNDomain_hpp
#include <vector>
#include <iostream>
#include "HTN.hpp"
#include "HTNWorldState.hpp"

class Item;
class World;

//***********************************************************
class Study : public HTNPrimitive
{
public:
    Study();
    bool Preconditions(HTNWorldState &htnWorldState);
    void Effect(HTNWorldState &htnWorldState);
    Actions Operator(int playerIndex, Player player[], World &world);
};

//***********************************************************
class Sleep : public HTNPrimitive
{
public:
    Sleep();
    bool Preconditions(HTNWorldState &htnWorldState);
    void Effect(HTNWorldState &htnWorldState);
    Actions Operator(int playerIndex, Player player[], World &world);
};

//***********************************************************
class UseGym : public HTNPrimitive
{
public:
    UseGym();
    bool Preconditions(HTNWorldState &htnWorldState);
    void Effect(HTNWorldState &htnWorldState);
    Actions Operator(int playerIndex, Player player[], World &world);
};

//***********************************************************
class RunCircuits : public HTNPrimitive
{
public:
    RunCircuits();
    bool Preconditions(HTNWorldState &htnWorldState);
    void Effect(HTNWorldState &htnWorldState);
    Actions Operator(int playerIndex, Player player[], World &world);
};

//***********************************************************
class GoToGym : public HTNPrimitive
{
public:
    GoToGym();
    bool Preconditions(HTNWorldState &htnWorldState);
    void Effect(HTNWorldState &htnWorldState);
    Actions Operator(int playerIndex, Player player[], World &world);
};

//***********************************************************
class GoToLibrary : public HTNPrimitive
{
public:
    GoToLibrary();
    bool Preconditions(HTNWorldState &htnWorldState);
    void Effect(HTNWorldState &htnWorldState);
    Actions Operator(int playerIndex, Player player[], World &world);
};

//***********************************************************
class GoToCircuitTrack : public HTNPrimitive
{
public:
    GoToCircuitTrack();
    bool Preconditions(HTNWorldState &htnWorldState);
    void Effect(HTNWorldState &htnWorldState);
    Actions Operator(int playerIndex, Player player[], World &world);
};

//***********************************************************
class GoToBedroom : public HTNPrimitive
{
public:
    GoToBedroom();
    bool Preconditions(HTNWorldState &htnWorldState);
    void Effect(HTNWorldState &htnWorldState);
    Actions Operator(int playerIndex, Player player[], World &world);
};

//***********************************************************
class GoToMainHall : public HTNPrimitive
{
public:
    GoToMainHall();
    bool Preconditions(HTNWorldState &htnWorldState);
    void Effect(HTNWorldState &htnWorldState);
    Actions Operator(int playerIndex, Player player[], World &world);
};

//***********************************************************
class Drink : public HTNPrimitive
{
public:
    Drink();
    bool Preconditions(HTNWorldState &htnWorldState);
    void Effect(HTNWorldState &htnWorldState);
    Actions Operator(int playerIndex, Player player[], World &world);
};

//***********************************************************
class Punch : public HTNPrimitive
{
    int m_targetPlayerIndex;
public:
    Punch(int playerIndex);
    bool Preconditions(HTNWorldState &htnWorldState);
    void Effect(HTNWorldState &htnWorldState);
    Actions Operator(int playerIndex, Player player[], World &world);
};

//***********************************************************
class Evade : public HTNPrimitive
{
public:
    Evade();
    bool Preconditions(HTNWorldState &htnWorldState);
    void Effect(HTNWorldState &htnWorldState);
    Actions Operator(int playerIndex, Player player[], World &world);
};

//***********************************************************
class PickUpItem : public HTNPrimitive
{
public:
    PickUpItem(Item* itemFocusPtr);
    Item* m_itemFocusPtr;
    bool Preconditions(HTNWorldState &htnWorldState);
    void Effect(HTNWorldState &htnWorldState);
    Actions Operator(int playerIndex, Player player[], World &world);
    void PointToRealItems();
};

//***********************************************************
class DropItem : public HTNPrimitive
{
public:
    DropItem(Item* itemFocusPtr);
    Item* m_itemFocusPtr;
    bool Preconditions(HTNWorldState &htnWorldState);
    void Effect(HTNWorldState &htnWorldState);
    Actions Operator(int playerIndex, Player player[], World &world);
    void PointToRealItems();
};

//***********************************************************
class GoToLibraryMethod1 : public HTNMethod
{
public:
    GoToLibraryMethod1();
    bool Preconditions(HTNWorldState &htnWorldState);
};

class GoToLibraryMethod2 : public HTNMethod
{
public:
    GoToLibraryMethod2();
    bool Preconditions(HTNWorldState &htnWorldState);
};

class GoToLibraryCompound : public HTNCompound
{
public:
    GoToLibraryCompound();
};

//***********************************************************
class GoToGymMethod1 : public HTNMethod
{
public:
    GoToGymMethod1();
    bool Preconditions(HTNWorldState &htnWorldState);
};

class GoToGymMethod2 : public HTNMethod
{
public:
    GoToGymMethod2();
    bool Preconditions(HTNWorldState &htnWorldState);
};

class GoToGymCompound : public HTNCompound
{
public:
    GoToGymCompound();
};

//***********************************************************
class GoToCircuitTrackMethod1 : public HTNMethod
{
public:
    GoToCircuitTrackMethod1();
    bool Preconditions(HTNWorldState &htnWorldState);
};

class GoToCircuitTrackMethod2 : public HTNMethod
{
public:
    GoToCircuitTrackMethod2();
    bool Preconditions(HTNWorldState &htnWorldState);
};

class GoToCircuitTrackCompound : public HTNCompound
{
public:
    GoToCircuitTrackCompound();
};

//***********************************************************
class GoToBedroomMethod1 : public HTNMethod
{
public:
    GoToBedroomMethod1();
    bool Preconditions(HTNWorldState &htnWorldState);
};

class GoToBedroomMethod2 : public HTNMethod
{
public:
    GoToBedroomMethod2();
    bool Preconditions(HTNWorldState &htnWorldState);
};

class GoToBedroomCompound : public HTNCompound
{
public:
    GoToBedroomCompound();
};

//***********************************************************
class IncreaseHealthMethod1 : public HTNMethod
{
public:
    IncreaseHealthMethod1();
    bool Preconditions(HTNWorldState &htnWorldState);
};

class IncreaseHealthMethod2 : public HTNMethod
{
public:
    IncreaseHealthMethod2();
    bool Preconditions(HTNWorldState &htnWorldState);
};

class IncreaseHealthCompound : public HTNCompound
{
public:
    IncreaseHealthCompound();
};

//***********************************************************
class IncreaseStrengthMethod1 : public HTNMethod
{
public:
    IncreaseStrengthMethod1();
    bool Preconditions(HTNWorldState &htnWorldState);
};

class IncreaseStrengthMethod2 : public HTNMethod
{
public:
    IncreaseStrengthMethod2();
    bool Preconditions(HTNWorldState &htnWorldState);
};

class IncreaseStrengthCompound : public HTNCompound
{
public:
    IncreaseStrengthCompound();
};

//***********************************************************
class IncreaseAgilityMethod1 : public HTNMethod
{
public:
    IncreaseAgilityMethod1();
    bool Preconditions(HTNWorldState &htnWorldState);
};

class IncreaseAgilityMethod2 : public HTNMethod
{
public:
    IncreaseAgilityMethod2();
    bool Preconditions(HTNWorldState &htnWorldState);
};

class IncreaseAgilityCompound : public HTNCompound
{
public:
    IncreaseAgilityCompound();
};

//***********************************************************
class IncreaseIntelligenceMethod1 : public HTNMethod
{
public:
    IncreaseIntelligenceMethod1();
    bool Preconditions(HTNWorldState &htnWorldState);
};

class IncreaseIntelligenceMethod2 : public HTNMethod
{
public:
    IncreaseIntelligenceMethod2();
    bool Preconditions(HTNWorldState &htnWorldState);
};

class IncreaseIntelligenceCompound : public HTNCompound
{
public:
    IncreaseIntelligenceCompound();
};

//***********************************************************
class AttackMethod1 : public HTNMethod
{
    Item* m_itemPtr;
public:
    AttackMethod1(Item* itemPtr, int opponentIndex);
    bool Preconditions(HTNWorldState &htnWorldState);
};

class AttackMethod2 : public HTNMethod
{
public:
    AttackMethod2(int opponentIndex);
    bool Preconditions(HTNWorldState &htnWorldState);
};

class AttackCompound : public HTNCompound
{
public:
    AttackCompound(HTNWorldState &htnWorldState, int opponentIndex);
};

class AttackCompoundMethod : public HTNMethod
{
public:
    AttackCompoundMethod(HTNWorldState &htnWorldState, int opponentIndex);
    bool Preconditions(HTNWorldState &htnWorldState);
};

//***********************************************************
class DoMissionMethod1 : public HTNMethod
{
public:
    DoMissionMethod1();
    bool Preconditions(HTNWorldState &htnWorldState);
};

class DoMissionMethod2 : public HTNMethod
{
public:
    DoMissionMethod2();
    bool Preconditions(HTNWorldState &htnWorldState);
};

class DoMissionMethod3 : public HTNMethod
{
public:
    DoMissionMethod3();
    bool Preconditions(HTNWorldState &htnWorldState);
};

class DoMissionCompound : public HTNCompound
{
public:
    DoMissionCompound();  //TODO add the bringItemToLocation mission
};

//***********************************************************
class EvadeMethod : public HTNMethod
{
public:
    EvadeMethod();
    bool Preconditions(HTNWorldState &htnWorldState);
};

class CombatCompound : public HTNCompound
{
public:
    CombatCompound(HTNWorldState &htnWorldState, int opponentIndex);
};

//***********************************************************
class CombatMethod : public HTNMethod
{
public:
    CombatMethod(HTNWorldState &htnWorldState, int opponentIndex);
    bool Preconditions(HTNWorldState &htnWorldState);
};

class DoMissionMethod : public HTNMethod
{
public:
    DoMissionMethod();
    bool Preconditions(HTNWorldState &htnWorldState);
};

class IncreaseIntelligenceMethod : public HTNMethod
{
public:
    IncreaseIntelligenceMethod();
    bool Preconditions(HTNWorldState &htnWorldState);
};

class PrisonerBehaviourCompound : public HTNCompound
{
public:
    PrisonerBehaviourCompound(HTNWorldState &htnWorldState);
};

//***********************************************************
class PickUpItemMethod1 : public HTNMethod
{
public:
    PickUpItemMethod1(Item* itemFocusPtr);
    bool Preconditions(HTNWorldState &htnWorldState);
};

//***********************************************************
class DropItemMethod1 : public HTNMethod
{
public:
    DropItemMethod1(Item* itemFocusPtr);
    bool Preconditions(HTNWorldState &htnWorldState);
};

#endif /* HTNDomain_hpp */