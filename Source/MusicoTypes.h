
/*
  ==============================================================================

	MusicoTypes.h
	Created: 3 Dec 2025 3:24:26am
	Author:  r3dda

  ==============================================================================
*/

#pragma once

#include <bitset>
#include <string>
#include <vector>

namespace musico::core
{
	/******************************************************************************
	 * Mask Types
	 ******************************************************************************/
	using MidiNoteMask = std::bitset<128>;
	using PitchClassMask = std::bitset<12>;

	constexpr PitchClassMask pcmMajor = { (1 << 0) | (1 << 4) | (1 << 7) };
	constexpr PitchClassMask pcmMinor = { (1 << 0) | (1 << 3) | (1 << 7) };
	constexpr PitchClassMask pcmAugmented = { (1 << 0) | (1 << 4) | (1 << 8) };
	constexpr PitchClassMask pcmDiminished = { (1 << 0) | (1 << 3) | (1 << 6) };
	constexpr PitchClassMask pcmSuspended2 = { (1 << 0) | (1 << 2) | (1 << 7) };
	constexpr PitchClassMask pcmSuspended4 = { (1 << 0) | (1 << 5) | (1 << 7) };
	constexpr PitchClassMask pcmPower = { (1 << 0) | (1 << 7) };

	PitchClassMask rotate(const musico::core::PitchClassMask&, int);
	bool contain(const PitchClassMask&, const PitchClassMask&);

	/******************************************************************************
	 * Enum Types
	 ******************************************************************************/
	enum class NamingStyle
	{
		Jazz,
		Classical,
		Quartal,
		Cluster,
		Generic
	};

	enum class ChordQuality
	{
		Major,
		Minor,
		Augmented,
		Diminished,
		Suspended2,
		Suspended4,
		Power,
		Cluster,
		Unknown
	};

	/******************************************************************************
	 * Chord Types
	 ******************************************************************************/
	struct ChordInterpretation
	{
		musico::core::PitchClassMask mask;
		ChordQuality quality;
		int root;
		bool omit3 = false;
		bool omit5 = false;
		bool inverted = false;

		float confidence;
	};

	std::string toString(const ChordInterpretation&);
	std::string toString(const std::vector<ChordInterpretation>&);
}