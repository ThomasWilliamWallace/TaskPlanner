//
//  HTNDomain.cpp
//  GamePersonalities
//
//  Created by VITALIJA STEPUSAITYTE on 25/08/2018.
//  Copyright © 2018 Thomas. All rights reserved.
//

#include "HTNWorldState.hpp"
#include "Player.hpp"
#include <cmath>
#include "World.hpp"

//***********************************************************
HTNWorldState::HTNWorldState(int playerIndex, Player player[], World &world):
    m_v(WorldE::last, 0),
    m_ptrToSelf(&(player[playerIndex])),
    m_missionClass(player[playerIndex].missionClass)
{
    m_v.at(WorldE::health) = round(player[playerIndex].stats.getHealth());
    m_v.at(WorldE::sanity) = round(player[playerIndex].stats.getSanity());
    m_v.at(WorldE::strength) = round(player[playerIndex].stats.getStrength());
    m_v.at(WorldE::agility) = round(player[playerIndex].stats.getAgility());
    m_v.at(WorldE::intelligence) = round(player[playerIndex].stats.getIntelligence());
    m_v.at(WorldE::punches) = 0;
    m_v.at(WorldE::evading) = player[playerIndex].lastAction == Actions::evade;
    m_v.at(WorldE::location) = static_cast<int>(player[playerIndex].locationClass.location);
    m_v.at(WorldE::inSameRoom) = player[playerIndex].locationClass.location == player[0].locationClass.location;
    
    //TODO reflect players sensors rather than being hardwired to the world
    for (auto &item : world.items)
    {
        m_items.push_back(new SimItem(*item, item->m_itemType, item->m_locationClass.location, item->m_carryingPlayer));
        if (&*(m_items.back()->m_carryingPlayer) == &player[playerIndex])
        {
            m_itemCarriedPtr = m_items.back();
        }
    }
    
    for (int i = 0; i < c_playerCount; i++)
    {
        m_attackers.push_back(player[playerIndex].rel[i].getAggro()>29 ? true : false);
        m_playerLocations.push_back(player[i].locationClass.location);
    }
    std::cout << "HTNWorldState constructor\n";
        for (auto &item : world.items)
        {
            std::cout << "Items: " << item << "\n";
        }
        for (auto &simItem : m_items)
        {
            std::cout << "SimItems: " << simItem << ", with link to real item " << &(simItem->m_realItem) << "\n";
        }
}

HTNWorldState::HTNWorldState(HTNWorldState &ws2):
    m_v(ws2.m_v),
    m_ptrToSelf(ws2.m_ptrToSelf),
    m_attackers(ws2.m_attackers),
    m_playerLocations(ws2.m_playerLocations),
    m_missionClass(ws2.m_missionClass)
{
    for (auto &item : ws2.m_items)
    {
        m_items.push_back(new SimItem(item->m_realItem, item->m_itemType, item->m_locationClass.location, item->m_carryingPlayer));
        if (ws2.m_itemCarriedPtr == item)
            
        {
            m_itemCarriedPtr = m_items.back();
        }
    }
    std::cout << "HTNWorldState copy constructor\n";
//        for (auto &simItem : m_items)
//        {;
            //std::cout << "SimItems: " << simItem << ", with link to real item " << &(simItem->m_realItem) << "\n";
//        }   
}

HTNWorldState::~HTNWorldState()
{
    for (SimItem* itemPtr : m_items)
    {
        delete itemPtr;
    }
}

void HTNWorldState::CopyFrom(HTNWorldState &ws2)
{
    m_v = ws2.m_v;
    m_ptrToSelf = ws2.m_ptrToSelf;
    m_attackers = ws2.m_attackers;
    m_playerLocations = ws2.m_playerLocations;
    
    m_items.clear();
    for (auto &item : ws2.m_items)
    {
        m_items.push_back(new SimItem(item->m_realItem, item->m_itemType, item->m_locationClass.location, item->m_carryingPlayer));
        if (ws2.m_itemCarriedPtr == item)
        {
            m_itemCarriedPtr = m_items.back();
        }
    }
    m_missionClass = ws2.m_missionClass;
    std::cout << "HTNWorldState copyFrom\n";
        for (auto &simItem : m_items)
        {
            std::cout << "SimItems: " << simItem << ", with link to real item " << &(simItem->m_realItem) << "\n";
        }
}

void HTNWorldState::Print()
{
    for (int i = 0; i < static_cast<int>(m_v.size()); i++)
    {
        std::cout << WorldEToString(static_cast<WorldE>(i)) << ":" << m_v.at(i) << "\n";
    }
    std::cout << "m_ptrToSelf:" << m_ptrToSelf << "\n";
    std::cout << "m_itemCarriedPtr:" << m_itemCarriedPtr << "\n";
    for (auto &item : m_items)
    {
        std::cout << "Item: " << item->ToString() << " in the " << item->m_locationClass.ToString() << "\n";
    }
    for (int i = 0; i < c_playerCount; i++)
    {
        std::cout << "Status of player " << i << " = " << (m_attackers.at(i) ? "fighting" : "peaceful") << " in the " << LocationToString(m_playerLocations.at(i)) << ".\n";
    }
}

std::string WorldEToString(WorldE worldE)
{
    switch(worldE)
    {
        case WorldE::health: return "health";
        case WorldE::sanity: return "sanity";
        case WorldE::strength: return "strength";
        case WorldE::agility: return "agility";
        case WorldE::intelligence: return "intelligence";
        case WorldE::punches: return "punches";
        case WorldE::evading: return "evading";
        case WorldE::location: return "location";
        case WorldE::inSameRoom: return "inSameRoom";
        case WorldE::last: return "LAST";
        default: return "ERROR_NO_WORLDE_STRING_FOUND";
    }
}