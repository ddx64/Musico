/*
  ==============================================================================

	AudioInputAdapter.cpp
	Created: 3 Dec 2025 3:23:23am
	Author:  r3dda

  ==============================================================================
*/

#include "AudioInputAdapter.h"

namespace musico::io
{
	//==============================================================================
	AudioInputAdapter::AudioInputAdapter()
	{
	}

	AudioInputAdapter::~AudioInputAdapter()
	{
	}

	//==============================================================================
	void AudioInputAdapter::processBlock(const juce::AudioBuffer<float>& audioBuffer, double sampleRate, int64_t blockStartSample)
	{
	}
}