/*
  ==============================================================================

	NoteTracker.h
	Created: 16 Dec 2025 9:18:09pm
	Author:  r3dda

  ==============================================================================
*/

#pragma once

#include <cstdint>
#include <atomic>
#include <bitset>
#include <vector>

namespace musico::core
{
	//==============================================================================
	/**
	*/
	class NoteTracker
	{
	public:
		explicit NoteTracker();
		~NoteTracker();

		//==============================================================================
		void noteOn(int);
		void noteOff(int);

		std::vector<int> getActiveNotes() const;
		std::bitset<12> getPitchClassMask() const;

	private:
		std::bitset<128> notes_;
		std::atomic<uint16_t> pitchClassMask_{ 0 };

		void updatePitchClassMask();
	};
}