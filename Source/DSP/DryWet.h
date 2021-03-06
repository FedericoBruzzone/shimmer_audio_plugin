#pragma once
#include <JuceHeader.h>
#include "../Parameters.h"

class DryWet
{
public:
	DryWet();
	~DryWet();

	void prepareToPlay(double sr, int maxNumSamples);

	void releaseResources();

	void setDry(const AudioBuffer<float>& buffer);

	void merge(AudioBuffer<float>& buffer);

	void setDryWetRatio(float newValue);

private:

	float dryWetRatio = 0.5f;
	SmoothedValue<float, ValueSmoothingTypes::Linear> dryLevel;
	SmoothedValue<float, ValueSmoothingTypes::Linear> wetLevel;

	AudioBuffer<float> drySignal;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(DryWet)
};	