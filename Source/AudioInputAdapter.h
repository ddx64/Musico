/*
  ==============================================================================

	AudioInputAdapter.h
	Created: 3 Dec 2025 3:23:23am
	Author:  r3dda

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"

namespace musico::io
{
	//==============================================================================
	/**
	*/
	class AudioInputAdapter
	{
	public:
		explicit AudioInputAdapter();
		~AudioInputAdapter();

		//==============================================================================
		void processBlock(const juce::AudioBuffer<float>& audioBuffer, double sampleRate, int64_t blockStartSample);

	private:


	};
}