/*
  ==============================================================================

	Types.h
	Created: 3 Dec 2025 3:24:26am
	Author:  r3dda

  ==============================================================================
*/

#pragma once

#include <string>
#include <vector>

struct PitchClassFrame
{

};

struct ChordFrame
{
	std::string symbol;
	float confidence;
};

struct HarmonyAxis
{
	std::vector<ChordFrame> chords;
};