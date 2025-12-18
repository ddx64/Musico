/*
  ==============================================================================

	This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
MusicoAudioProcessorEditor::MusicoAudioProcessorEditor(MusicoAudioProcessor& p)
	: AudioProcessorEditor(&p),
#if JucePlugin_Enable_ARA
	AudioProcessorEditorARAExtension(&p),
#endif
	audioProcessor(p),
	midiKeyboard(audioProcessor.getKeyboardState(), juce::MidiKeyboardComponent::horizontalKeyboard)
{
#if JucePlugin_Enable_ARA
	// ARA plugins must be resizable for proper view embedding
	setResizable(true, false);
	getConstrainer()->setMinimumSize(600, 400);
#endif
	// UI components setup
	midiKeyboard.setAvailableRange(21, 108); // A0 to C8

	chordMask.setFont(juce::Font(24.0f, juce::Font::bold));
	chordMask.setJustificationType(juce::Justification::centred);
	chordLabel.setFont(juce::Font(16.0f, juce::Font::bold));
	chordLabel.setJustificationType(juce::Justification::centred);

	// Mount components
	addAndMakeVisible(midiKeyboard);
	addAndMakeVisible(chordMask);
	addAndMakeVisible(chordLabel);
	//addAndMakeVisible(webViewPlaceHolder);

	// Global configurations
	setSize(800, 200);
	startTimerHz(20);
}

MusicoAudioProcessorEditor::~MusicoAudioProcessorEditor()
{
}

//==============================================================================
void MusicoAudioProcessorEditor::paint(juce::Graphics& g)
{
	// (Our component is opaque, so we must completely fill the background with a solid colour)
	g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));

	g.setColour(juce::Colours::white);
	g.setFont(juce::FontOptions(15.0f));
	g.drawFittedText("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void MusicoAudioProcessorEditor::resized()
{
	// This is generally where you'll want to lay out the positions of any subcomponents in your editor..
	auto area = getLocalBounds();

	const int keyboardHeight = 80;
	auto keyboardArea = area.removeFromBottom(keyboardHeight);
	// Calculate key width based on white keys, assuming 52 white keys on a 88 keyboard
	float keyWidth = keyboardArea.getWidth() / 52.0;
	midiKeyboard.setKeyWidth(keyWidth);
	midiKeyboard.setBounds(keyboardArea);

	const int chordMaskHeight = 40;
	const int chordLabelHeight = 20;
	auto maskArea = area.removeFromBottom(chordMaskHeight);
	auto labelArea = area.removeFromBottom(chordLabelHeight);
	chordMask.setBounds(maskArea);
	chordLabel.setBounds(labelArea);

}

void MusicoAudioProcessorEditor::timerCallback()
{
	std::bitset<12> pcm = audioProcessor.getPitchClassMask();
	auto chordType = audioProcessor.matchChordMask(pcm);
	chordMask.setText(pcm.to_string(), juce::dontSendNotification);
	chordLabel.setText(musico::core::toString(chordType), juce::dontSendNotification);
}