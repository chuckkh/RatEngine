/*
  ==============================================================================

    RatEngine.h
    Created: 11 Feb 2022 2:06:16am
    Author:  Home

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "RatIOManager.h"
class RatEngine : public juce::InterprocessConnection
{
public:
    //RatEngine(bool, int);
    //RatEngine(int);
    RatEngine(int);
    ~RatEngine();
    void messageReceived(const MemoryBlock& message) override;
    void connectionMade() override;
    void connectionLost() override;
    void endItAll();
    void run();
//    void timerCallback();

private:
    int cbport;
    bool active = true;
    juce::OwnedArray<RatIOManager> ioManagers;
};