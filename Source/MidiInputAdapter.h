/*
  ==============================================================================

	MidiInputAdapter.h
	Created: 3 Dec 2025 3:23:03am
	Author:  r3dda

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "NoteTracker.h"

namespace musico::io
{
	//==============================================================================
	/**
	*/
	class MidiInputAdapter
	{
	public:
		explicit MidiInputAdapter(musico::core::NoteTracker&);
		~MidiInputAdapter();

		//==============================================================================
		void processBlock(const juce::MidiBuffer&, double, int);

	private:
		musico::core::NoteTracker& noteTracker_;
	};
}