/*
  ==============================================================================

	NoteTracker.h
	Created: 16 Dec 2025 9:18:09pm
	Author:  r3dda

  ==============================================================================
*/

#pragma once

#include "MusicoTypes.h"

namespace musico::utils
{
	//==============================================================================
	/**
	*/
	class NoteTracker
	{
	public:
		NoteTracker() = default;
		~NoteTracker() = default;

		// ===== Read =====
		musico::core::MidiNoteMask getMidiNoteMask() const;
		musico::core::PitchClassMask getPitchClassMask() const;

		// ===== Write =====
		void noteOn(int);
		void noteOff(int);

	private:
		// ===== Data =====
		musico::core::MidiNoteMask midiNoteMask_;
		musico::core::PitchClassMask pitchClassMask_;

		// ===== Internal Methods =====
		void updatePitchClassMask_();
	};
}