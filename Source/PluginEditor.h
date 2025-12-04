/*
  ==============================================================================

	This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class MusicoAudioProcessorEditor :public juce::AudioProcessorEditor
#if JucePlugin_Enable_ARA
	, public juce::AudioProcessorEditorARAExtension
#endif
	, private juce::Timer
{
public:
	MusicoAudioProcessorEditor(MusicoAudioProcessor&);
	~MusicoAudioProcessorEditor() override;

	//==============================================================================
	void paint(juce::Graphics&) override;
	void resized() override;

private:
	// This reference is provided as a quick way for your editor to access the processor object that created it.
	MusicoAudioProcessor& audioProcessor;

	//==============================================================================
	juce::MidiKeyboardComponent midiKeyboard;
	juce::Label chordLabel;
	// TODO: Implement in feature
	juce::Component webViewPlaceHolder;

	void timerCallback() override;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MusicoAudioProcessorEditor)

};
