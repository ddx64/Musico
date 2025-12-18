/*
  ==============================================================================

	MidiInputAdapter.cpp
	Created: 3 Dec 2025 3:23:03am
	Author:  r3dda

  ==============================================================================
*/

#include "MidiInputAdapter.h"

namespace musico::io
{
	using musico::core::NoteTracker;

	//==============================================================================
	MidiInputAdapter::MidiInputAdapter(NoteTracker& noteTracker) : noteTracker_(noteTracker)
	{
	}

	MidiInputAdapter::~MidiInputAdapter()
	{
	}

	//==============================================================================
	void MidiInputAdapter::processBlock(const juce::MidiBuffer& midiBuffer, double sampleRate, int blockStartSample)
	{
		for (const auto mididata : midiBuffer)
		{
			const juce::MidiMessage msg = mididata.getMessage();

			if (msg.isNoteOn())
			{
				noteTracker_.noteOn(msg.getNoteNumber());
			}
			else if (msg.isNoteOff())
			{
				noteTracker_.noteOff(msg.getNoteNumber());
			}
		}
	}

}