/*
  ==============================================================================

	PianoKeyboardView.cpp
	Created: 3 Dec 2025 3:24:50am
	Author:  r3dda

  ==============================================================================
*/

#include "PianoKeyboardView.h"

//==============================================================================
PianoKeyboardView::PianoKeyboardView(juce::MidiKeyboardState& state)
	: keyboard(state, juce::MidiKeyboardComponent::horizontalKeyboard)
{
	// Key range A0-C8
	keyboard.setAvailableRange(21, 108);

	addAndMakeVisible(keyboard);
}

//==============================================================================
void PianoKeyboardView::resized()
{
	keyboard.setBounds(getLocalBounds());
}
