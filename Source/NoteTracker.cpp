/*
  ==============================================================================

	NoteTracker.cpp
	Created: 16 Dec 2025 9:18:09pm
	Author:  r3dda

  ==============================================================================
*/

#include "NoteTracker.h"

namespace musico::utils
{
	using musico::core::MidiNoteMask;
	using musico::core::PitchClassMask;

	//==============================================================================
	MidiNoteMask NoteTracker::getMidiNoteMask() const
	{
		return midiNoteMask_;
	}

	PitchClassMask NoteTracker::getPitchClassMask() const
	{
		return pitchClassMask_;
	}
	//==============================================================================
	void NoteTracker::noteOn(int noteNumber)
	{
		midiNoteMask_.set(noteNumber);
		updatePitchClassMask_();
	}

	void NoteTracker::noteOff(int noteNumber)
	{
		midiNoteMask_.reset(noteNumber);
		updatePitchClassMask_();
	}
	//==============================================================================
	void NoteTracker::updatePitchClassMask_()
	{
		PitchClassMask mask{ 0 };

		for (int i = 0;i < 128;++i)
		{
			if (midiNoteMask_.test(i))
				mask.set(i % 12);
		}

		pitchClassMask_ = mask;
	}
}
