#include "JuceHeader.h"
#include <queue>
#include <map>
#include "RatIO.h"

#pragma once

class RatIOManager : juce::Timer
{


private:
	juce::OwnedArray<juce::OwnedArray<RatIO>> outputs;
	std::queue<int> events;
};

