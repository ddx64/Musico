/*
  ==============================================================================

	NoteTracker.cpp
	Created: 16 Dec 2025 9:18:09pm
	Author:  r3dda

  ==============================================================================
*/

#include "NoteTracker.h"

namespace musico::core
{
	//==============================================================================
	NoteTracker::NoteTracker()
	{
	}

	NoteTracker::~NoteTracker()
	{
	}

	//==============================================================================
	void NoteTracker::noteOn(int noteNumber)
	{
		notes_.set(noteNumber);
		updatePitchClassMask();
	}

	void NoteTracker::noteOff(int noteNumber)
	{
		notes_.reset(noteNumber);
		updatePitchClassMask();
	}

	std::vector<int> NoteTracker::getActiveNotes() const
	{
		std::vector<int> out;
		out.reserve(8);
		for (int i = 0; i < 128; ++i)
			if (notes_.test(i))
				out.push_back(i);
		return out;
	}

	std::bitset<12> NoteTracker::getPitchClassMask() const
	{
		return std::bitset<12>(pitchClassMask_.load(std::memory_order_relaxed));
	}

	void NoteTracker::updatePitchClassMask()
	{
		uint16_t mask = 0;
		for (int i = 0; i < 128; ++i)
			if (notes_.test(i))
				mask |= (1u << (i % 12));
		pitchClassMask_.store(mask, std::memory_order_relaxed);
	}
}
