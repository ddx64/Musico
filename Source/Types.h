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
	//=============================================================================
	// Constants & Names
	//=============================================================================
	using TimeRQP = double;					// DAW Relation Quantization Point in seconds
	using TimeSeconds = double;				// Absolute time in seconds

	using MidiNoteNumber = std::uint8_t;	// 0-127
	using MidiVelocity = std::uint8_t;		// 0-127
	using MidiChannel = std::uint8_t;		// 0-15

	enum  class InputSourceKind :std::uint8_t { Ara, Audio, Midi };

	enum class MidiEventType : std::uint8_t
	{
		NoteOn,
		NoteOff,
		ControlChange,
		ProgramChange,
		PitchBend
	};

	enum class ChordStructureType : std::uint8_t
	{
		Unknown,

		Triad,
		Seventh,
		// TODO: Add more structures
	};

	enum class ChordQualityType : std::uint8_t
	{
		Major,
		Minor,
		Diminished,
		Augmented,
		// TODO: Add more qualities
	};

	//=============================================================================
	// Data Structures
	//=============================================================================
	struct MusicalTime
	{
	};

	struct MidiEvent {
		MidiEventType type;
		int channel;		// MIDI channel
		double timestamp;	// Time in seconds
		int note;			// 0-127, For NoteOn and NoteOff
		int velocity;		// 0-127, For NoteOn
		int value;			// For ControlChange and PitchBend
	};

	struct PitchClassFrame
	{

	};

	struct ChordFrame
	{
		std::string symbol;
		float confidence;
	};

	struct HarmonyAxis
	{
		std::vector<ChordFrame> chords;
	};
}
