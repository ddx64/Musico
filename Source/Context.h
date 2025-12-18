/*
  ==============================================================================

	Context.h
	Created: 7 Dec 2025 5:38:52pm
	Author:  r3dda

  ==============================================================================
*/

#pragma once

namespace musico::core
{
	struct MidiNoteEvent
	{

	};

	class IMidiContext
	{
	public:
		virtual ~IMidiContext() = default;
		virtual void processMidiEvent(const MidiNoteEvent& event) = 0;
	};

	//==============================================================================
	/**
	*/
	class Context : public IMidiContext
	{
	public:
		Context();
		void processMidiNote(const MidiNoteEvent& event);

	private:

	};
}