/*
  ==============================================================================

	This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "MidiInputAdapter.h"
#include "JazzInterpreter.h"
#include "NoteTracker.h"

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

	musico::core::MidiNoteMask getMidiNoteMask() const;
	musico::core::PitchClassMask getPitchClassMask() const;

	std::vector<musico::core::ChordInterpretation> interpretChord(const musico::core::PitchClassMask&)const;

private:
	/*********************************************************************************
	* Add functions and variables here
	*********************************************************************************/
	juce::MidiKeyboardState midiKeyboardState_;

	musico::utils::NoteTracker noteTracker_;
	musico::io::MidiInputAdapter midiInputAdapter_{ noteTracker_ };
	musico::middleware::JazzInterpreter jazzInterpreter_;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MusicoAudioProcessor)

};