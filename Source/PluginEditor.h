/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class ShoshoiSimpleSamplerAudioProcessorEditor : public juce::AudioProcessorEditor
{
public:
    ShoshoiSimpleSamplerAudioProcessorEditor(ShoshoiSimpleSamplerAudioProcessor&);
    ~ShoshoiSimpleSamplerAudioProcessorEditor() override;

    //==============================================================================
    void paint(juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    ShoshoiSimpleSamplerAudioProcessor& audioProcessor;
    juce::MidiKeyboardState midiKeyboardState;
    juce::MidiKeyboardComponent midiKeyboardComponent{ midiKeyboardState, juce::MidiKeyboardComponent::horizontalKeyboard };

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ShoshoiSimpleSamplerAudioProcessorEditor)
};
