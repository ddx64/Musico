/*
  ==============================================================================

	JazzInterpreter.h
	Created: 24 Dec 2025 12:41:32am
	Author:  r3dda

  ==============================================================================
*/

#pragma once

#include "MusicoTypes.h"
#include "PitchInterpreter.h"

namespace musico::middleware
{
	//==============================================================================
	/**
	*/
	class JazzInterpreter final : public musico::core::PitchInterpreter
	{
	public:
		JazzInterpreter() = default;
		~JazzInterpreter() = default;

		//============================================================================
		virtual const std::string domain()const;
		virtual std::vector<musico::core::ChordInterpretation> interpret(const musico::core::PitchClassMask&)const;
		musico::core::ChordInterpretation analyze(const musico::core::PitchClassMask&)const;

	private:

	};
}