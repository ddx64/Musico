/*
  ==============================================================================

	PianoKeyboardView.h
	Created: 3 Dec 2025 3:24:50am
	Author:  r3dda

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/**
*/
class PianoKeyboardView : public juce::Component
{
public:
	explicit PianoKeyboardView(juce::MidiKeyboardState& state);

	//==============================================================================
	void resized() override;

private:
	juce::MidiKeyboardComponent keyboard;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PianoKeyboardView)
};