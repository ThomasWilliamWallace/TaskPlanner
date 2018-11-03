//
//  Item.hpp
//  GamePersonalities
//
//  Created by VITALIJA STEPUSAITYTE on 25/08/2018.
//  Copyright © 2018 Thomas. All rights reserved.
//

#ifndef Item_hpp
#define Item_hpp

#include "Locations.hpp"
#include <iostream>

class Player;

enum class ItemType
{
	assaultRifle,
	ball,
	bat,
	bottle,
	brick,
	broom,
	cigarette,
	cleaver,
	dumbbell,
	dynamite,
	extinguisher,
	hammer,
	knife,
	mirror,
	pistol,
	plank,
	poolCue,
	rock,
	scissors,
	sword,
	syringe
};

std::string ItemTypeToString(ItemType itemType);
ItemType GetRandomItemType();

class Item
{
public:
    ItemType m_itemType;
    LocationClass m_locationClass;
    Player* m_carryingPlayer;
    Item(ItemType itemE, Locations location, Player* carryingPlayer=nullptr): m_itemType(itemE), m_locationClass(location), m_carryingPlayer(carryingPlayer) {};
    std::string ToString();
    virtual ~Item() = default;
};

class SimItem : public Item
{
public:
    Item& m_realItem;
    SimItem(Item &realItem, ItemType itemType, Locations location, Player* carryingPlayer=nullptr):
        Item(itemType, location, carryingPlayer), m_realItem(realItem)
    {};
};

#endif /* Item_hpp */