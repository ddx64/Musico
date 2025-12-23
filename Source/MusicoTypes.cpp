/*
  ==============================================================================

	MusicoTypes.cpp
	Created: 21 Dec 2025 6:07:54pm
	Author:  r3dda

  ==============================================================================
*/

#include "MusicoTypes.h"

namespace musico::core
{
	bool contain(const PitchClassMask& child, const PitchClassMask& parent)
	{
		return (child & parent) == parent;
	}

	PitchClassMask rotate(const PitchClassMask& mask, int offset)
	{
		PitchClassMask rotated;
		for (int i = 0;i < 12;++i)
		{
			if (mask.test((i + offset) % 12))
				rotated.set(i);
		}
		return rotated;
	}
	//==============================================================================
	std::string toString(const ChordInterpretation& chord)
	{
		switch (chord.quality)
		{
		case ChordQuality::Major:
			return "Major";
		case ChordQuality::Minor:
			return "Minor";
		case ChordQuality::Augmented:
			return "Augmented";
		case ChordQuality::Diminished:
			return "Diminished";
		case ChordQuality::Suspended2:
			return "Suspended2";
		case ChordQuality::Suspended4:
			return "Suspended4";
		case ChordQuality::Power:
			return "Power";
		case ChordQuality::Cluster:
			return "Cluster";
		default:
			return "Unknown";
		}

		return "Unknown";
	}

	std::string toString(const std::vector<ChordInterpretation>& chords)
	{
		std::string result;
		for (const auto& chord : chords)
		{
			result += toString(chord) + ",";
		}
		return result;
	}
}