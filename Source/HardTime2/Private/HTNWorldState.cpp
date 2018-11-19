#include "HTNWorldState.hpp"
#include <cmath>
#include "ActorItem.h"
#include "Player.hpp"
#include "World.hpp"
#include "HTNDomain.hpp"
#include "pLog.hpp"
#include <sstream>

//***********************************************************
HTNWorldState::HTNWorldState(Player* playerPtr, World &world):
	m_v(WorldE::last, 0),
	m_ptrToSelf(playerPtr),
    m_itemCarriedPtr(nullptr),
	m_missionClass(playerPtr->missionClass)
{
	m_v.at(WorldE::health) = round(m_ptrToSelf->pStats.getHealth());
	m_v.at(WorldE::sanity) = round(m_ptrToSelf->pStats.getSanity());
	m_v.at(WorldE::strength) = round(m_ptrToSelf->pStats.getStrength());
	m_v.at(WorldE::agility) = round(m_ptrToSelf->pStats.getAgility());
	m_v.at(WorldE::intelligence) = round(m_ptrToSelf->pStats.getIntelligence());
	m_v.at(WorldE::punches) = 0;
	m_v.at(WorldE::evading) = m_ptrToSelf->lastAction == Actions::evade;
	m_v.at(WorldE::location) = static_cast<int>(m_ptrToSelf->locationClass.location);

	//TODO reflect players sensors rather than being hardwired to the world
	for (auto &item : world.items)
	{
		m_items.push_back(new SimActorItem(item, item->m_itemType, Locations::mainHall, item->m_carryingPlayer));

		std::stringstream ss;
		ss << "item->m_carryingPlayer = " << item->m_carryingPlayer << "\n";
		ss << "m_items.back()->m_carryingPlayer = " << m_items.back()->m_carryingPlayer << "\n";
		ss << "m_ptrToSelf = " << m_ptrToSelf << "\n";
		ss << "constructor #1a m_itemCarriedPtr = " << m_itemCarriedPtr << "\n";

		if ((m_items.back()->m_carryingPlayer) == m_ptrToSelf)
		{
			m_itemCarriedPtr = m_items.back();
			ss << "constructor #1b m_itemCarriedPtr = " << m_itemCarriedPtr << "\n";
		}
		//pLog(ss.str());
	}
	pLog("HTNWorldState::default constructor:");
	Print();
}

HTNWorldState::HTNWorldState(HTNWorldState &ws2) :
	m_v(ws2.m_v),
	m_ptrToSelf(ws2.m_ptrToSelf),
    m_itemCarriedPtr(nullptr),
	m_attackers(ws2.m_attackers),
	m_playerLocations(ws2.m_playerLocations),
	m_missionClass(ws2.m_missionClass)
{
	m_itemCarriedPtr = nullptr;
	for (auto &item : ws2.m_items)
	{
		m_items.push_back(new SimActorItem(item->m_realItem, item->m_itemType, item->m_locationClass.location, item->m_carryingPlayer));
		if (ws2.m_itemCarriedPtr == item)
		{
			m_itemCarriedPtr = m_items.back();
		}
	}
	pLog("HTNWorldState::Copy constructor:");
	Print();
}

HTNWorldState::~HTNWorldState()
{
	for (SimActorItem* itemPtr : m_items)
	{
		delete itemPtr;
	}
}

void HTNWorldState::CopyFrom(HTNWorldState &ws2)
{
	m_v = ws2.m_v;
	m_ptrToSelf = ws2.m_ptrToSelf;
    	m_itemCarriedPtr = nullptr;
	m_attackers = ws2.m_attackers;
	m_playerLocations = ws2.m_playerLocations;

    m_items.clear();
	for (auto &item : ws2.m_items)
	{
		m_items.push_back(new SimActorItem(item->m_realItem, item->m_itemType, item->m_locationClass.location, item->m_carryingPlayer));
		if (ws2.m_itemCarriedPtr == item)
		{
			m_itemCarriedPtr = m_items.back();
		}
	}
	m_missionClass = ws2.m_missionClass;
	pLog("HTNWorldState::CopyFrom:");
	Print();
}

void HTNWorldState::Print()
{
	std::stringstream ss;
	ss << "HTNWorldState::Print\n";
    for (int i = 0; i < static_cast<int>(m_v.size()); i++)
    {
		ss << WorldEToString(static_cast<WorldE>(i)) << ":" << m_v.at(i) << "\n";
    }
	ss << "m_ptrToSelf:" << m_ptrToSelf << "\n";
	ss << "m_itemCarriedPtr:" << m_itemCarriedPtr << "\n";
    for (auto &simItem : m_items)
    {
		ss << "SimItem: " << simItem->ToString() << " carried by ";
		if (simItem->m_carryingPlayer != nullptr)
		{
			ss << simItem->m_carryingPlayer->name;
		}
		else
		{
			ss << "nullptr";
		}
		ss << " in the " << simItem->m_locationClass.ToString() << " with a link to real item " << simItem->m_realItem << "\n";
    }
	ss << "m_missionClass:" << m_missionClass.MissionName() << "\n";
	pLog(ss.str());
}

std::string WorldEToString(WorldE worldE)
{
	switch (worldE)
	{
	case WorldE::health: return "health";
	case WorldE::sanity: return "sanity";
	case WorldE::strength: return "strength";
	case WorldE::agility: return "agility";
	case WorldE::intelligence: return "intelligence";
	case WorldE::punches: return "punches";
	case WorldE::evading: return "evading";
	case WorldE::location: return "location";
	case WorldE::last: return "LAST";
	default: return "ERROR_NO_WORLDE_STRING_FOUND";
	}
}