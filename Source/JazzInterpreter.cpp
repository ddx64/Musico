/*
  ==============================================================================

	JazzInterpreter.cpp
	Created: 24 Dec 2025 12:41:32am
	Author:  r3dda

  ==============================================================================
*/

#include "JazzInterpreter.h"


namespace musico::middleware
{
	using musico::core::PitchClassMask;
	using musico::core::ChordInterpretation;
	using musico::core::ChordQuality;
	using musico::core::contain;
	using musico::core::rotate;
	//==============================================================================
	const std::string JazzInterpreter::domain()const
	{
		return "Jazz";
	}

	std::vector<ChordInterpretation> JazzInterpreter::interpret(const PitchClassMask& mask)const
	{
		std::vector<ChordInterpretation> results;
		for (int root = 0;root < 12;++root)
		{
			if (!mask.test(root))continue;
			PitchClassMask norm = rotate(mask, root);
			ChordQuality base =
				contain(norm, musico::core::pcmMajor) ? ChordQuality::Major :
				contain(norm, musico::core::pcmMinor) ? ChordQuality::Minor :
				contain(norm, musico::core::pcmAugmented) ? ChordQuality::Augmented :
				contain(norm, musico::core::pcmDiminished) ? ChordQuality::Diminished :
				contain(norm, musico::core::pcmSuspended2) ? ChordQuality::Suspended2 :
				contain(norm, musico::core::pcmSuspended4) ? ChordQuality::Suspended4 :
				contain(norm, musico::core::pcmPower) ? ChordQuality::Power :
				ChordQuality::Unknown;
			if (base == ChordQuality::Unknown)continue;
			results.push_back(ChordInterpretation{ mask, base, root, false, false, false, 1.0f });
		}

		return results;
	}

	ChordInterpretation JazzInterpreter::analyze(const PitchClassMask& mask)const
	{
		ChordInterpretation result;

		for (int root = 0;root < 12;++root)
		{
			if (!mask.test(root))continue;

			PitchClassMask norm = rotate(mask, root);

			// ===== Analyze Chord Quality =====
			ChordQuality base =
				contain(norm, musico::core::pcmMajor) ? ChordQuality::Major :
				contain(norm, musico::core::pcmMinor) ? ChordQuality::Minor :
				contain(norm, musico::core::pcmAugmented) ? ChordQuality::Augmented :
				contain(norm, musico::core::pcmDiminished) ? ChordQuality::Diminished :
				contain(norm, musico::core::pcmSuspended2) ? ChordQuality::Suspended2 :
				contain(norm, musico::core::pcmSuspended4) ? ChordQuality::Suspended4 :
				contain(norm, musico::core::pcmPower) ? ChordQuality::Power :
				ChordQuality::Unknown;

			if (base == ChordQuality::Unknown)continue;

			result.root = root;
			result.quality = base;

			// ===== Analyze Extension =====
			bool hasMinor7 = norm.test(10);
			bool hasMajor7 = norm.test(11);

		}

		return result;
	}

}