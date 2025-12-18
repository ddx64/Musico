/*
  ==============================================================================

	This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "Chord.h"
#include "NoteTracker.h"
#include "MidiInputAdapter.h"

//==============================================================================
/**
*/
class MusicoAudioProcessor : public juce::AudioProcessor
#if JucePlugin_Enable_ARA
	, public juce::AudioProcessorARAExtension
#endif
{
public:
	//==============================================================================
	MusicoAudioProcessor();
	~MusicoAudioProcessor() override;

	//==============================================================================
	void prepareToPlay(double sampleRate, int samplesPerBlock) override;
	void releaseResources() override;

#ifndef JucePlugin_PreferredChannelConfigurations
	bool isBusesLayoutSupported(const BusesLayout& layouts) const override;
#endif

	void processBlock(juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

	//==============================================================================
	juce::AudioProcessorEditor* createEditor() override;
	bool hasEditor() const override;

	//==============================================================================
	const juce::String getName() const override;

	bool acceptsMidi() const override;
	bool producesMidi() const override;
	bool isMidiEffect() const override;
	double getTailLengthSeconds() const override;

	//==============================================================================
	int getNumPrograms() override;
	int getCurrentProgram() override;
	void setCurrentProgram(int index) override;
	const juce::String getProgramName(int index) override;
	void changeProgramName(int index, const juce::String& newName) override;

	//==============================================================================
	void getStateInformation(juce::MemoryBlock& destData) override;
	void setStateInformation(const void* data, int sizeInBytes) override;
	/*********************************************************************************
	* Add functions and variables here
	*********************************************************************************/
	juce::MidiKeyboardState& getKeyboardState();

	std::vector<int> getActiveNotes() const;
	std::bitset<12> getPitchClassMask() const;
	musico::core::ChordType matchChordMask(const std::bitset<12>&)const;

private:
	/*********************************************************************************
	* Add functions and variables here
	*********************************************************************************/
	juce::MidiKeyboardState midiKeyboardState_;

	musico::core::Chord chord_;
	musico::core::NoteTracker noteTracker_;
	musico::io::MidiInputAdapter midiInputAdapter_{ noteTracker_ };

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MusicoAudioProcessor)

};
