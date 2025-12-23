/*
  ==============================================================================

	PitchInterpreter.h
	Created: 7 Dec 2025 5:36:30pm
	Author:  r3dda

  ==============================================================================
*/

#pragma once

#include "MusicoTypes.h"

namespace musico::core
{
	//==============================================================================
	/**
	*/
	class PitchInterpreter
	{
	public:
		PitchInterpreter() = default;
		virtual ~PitchInterpreter() = default;

		//============================================================================
		virtual const std::string domain()const = 0;
		virtual std::vector<ChordInterpretation> interpret(const PitchClassMask&)const = 0;

	private:

	};
}