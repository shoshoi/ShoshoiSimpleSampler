// SimpleSynth.h

#pragma once
#include <JuceHeader.h>
#include "TestResource.h"

using namespace juce;

class SimpleSynth : public Synthesiser {
public:
	void setup();
private:
	// manager object that finds an appropriate way to decode various audio files.  Used with SampleSound objects.
	AudioFormatManager audioFormatManager;
};