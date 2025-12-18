/*
  ==============================================================================

	Chord.h
	Created: 7 Dec 2025 5:36:30pm
	Author:  r3dda

  ==============================================================================
*/

#pragma once

#include <bitset>
#include <string>
#include <vector>

namespace musico::core
{
	//==============================================================================
	/**
	*/
	enum class ChordType
	{
		Major,
		Minor,
		Augmented,
		Diminished,
		Unknown
	};

	static constexpr std::string toString(ChordType type)
	{
		switch (type)
		{
		case ChordType::Major:
			return "Major";
		case ChordType::Minor:
			return "Minor";
		case ChordType::Augmented:
			return "Augmented";
		case ChordType::Diminished:
			return "Diminished";
		default:
			return "Unknown";
		}
	}

	//==============================================================================
	/**
	*/
	class Chord
	{
	public:
		static const std::bitset<12> Major;
		static const std::bitset<12> Minor;
		static const std::bitset<12> Augmented;
		static const std::bitset<12> Diminished;
		static constexpr int Seventh = 11;
		static constexpr int Ninth = 2;
		static constexpr int Eleventh = 5;
		static constexpr int Thirteenth = 9;

		static ChordType match(const std::bitset<12>&);

		//============================================================================
		explicit Chord();
		~Chord();

	private:
		static bool contain(const std::bitset<12>&, const std::bitset<12>&);

		//============================================================================
		std::bitset<12> pcm;
		std::string name;
		int rootNote;
		bool inverted;
		float confidence;
	};
}