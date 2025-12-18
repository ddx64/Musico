/*
  ==============================================================================

	Chord.cpp
	Created: 7 Dec 2025 8:36:39pm
	Author:  r3dda

  ==============================================================================
*/

#pragma once

#include "Chord.h"

namespace musico::core
{
	//==============================================================================
	const std::bitset<12> Chord::Major = std::bitset<12>("000010010001");
	const std::bitset<12> Chord::Minor = std::bitset<12>("000010001001");
	const std::bitset<12> Chord::Augmented = std::bitset<12>("000100010001");
	const std::bitset<12> Chord::Diminished = std::bitset<12>("000001001001");

	//==============================================================================
	Chord::Chord()
	{
	}

	Chord::~Chord()
	{
	}

	//==============================================================================
	bool Chord::contain(const std::bitset<12>& child, const std::bitset<12>& parent)
	{
		return (child & parent) == parent;
	}

	ChordType Chord::match(const std::bitset<12>& input)
	{
		// ===== Major Class =====
		if (contain(input, Chord::Major))
		{
			return ChordType::Major;
		}

		// ===== Minor Class =====
		if (contain(input, Chord::Minor))
		{
			return ChordType::Minor;
		}

		// ===== Augmented Class =====
		if (contain(input, Chord::Augmented))
		{
			return ChordType::Augmented;
		}

		// ===== Diminished Class =====
		if (contain(input, Chord::Diminished))
		{
			return ChordType::Diminished;
		}

		return ChordType::Unknown;
	}
}