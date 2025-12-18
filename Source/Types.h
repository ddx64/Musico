
/*
  ==============================================================================

	Types.h
	Created: 3 Dec 2025 3:24:26am
	Author:  r3dda

  ==============================================================================
*/

#pragma once

#include <string>
#include <vector>

namespace musico::core
{
	//==============================================================================
	/**
	*/
	struct MidiNoteEvent
	{
		bool isNoteOn = false;
		int noteNumber = 0;
		int velocity = 0;
		double timestamp = 0.0;
	};

	class IMidiEventSink
	{
	public:
		virtual ~IMidiEventSink() = default;
		virtual void handleMidiNote(const MidiNoteEvent& e) = 0;
	};

	//==============================================================================
	/**
	*/
	struct ChordModelInput
	{
		std::vector<int> midiNotes;
	};

	struct ChordModelOutput
	{
		std::string chordName;
		int rootNote = -1;
		double condidence = 0.0;
	};

	class IChordModel
	{
	public:
		virtual ~IChordModel() = default;
		virtual ChordModelOutput analyze(const ChordModelInput& input) = 0;
	};
}
