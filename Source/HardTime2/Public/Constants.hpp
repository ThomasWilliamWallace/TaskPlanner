#pragma once

constexpr int c_playerCount = 50;  //This MUST match the number of playerData registered in world. Or memory corruption occurs. Correct this.
constexpr double c_aggro_scale = 30;
constexpr double c_aggroCooldown = 0.15;
constexpr bool c_debug = false;

std::string FormatDouble(double input);
int RandPercent();
