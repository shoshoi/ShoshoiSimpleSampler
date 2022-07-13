/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"




using std::cout; using std::cin;
using std::endl; using std::string;
#if _MSC_VER > 1922 && !defined(_SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING)
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#endif
#include <experimental/filesystem>


using namespace std::experimental::filesystem;




//==============================================================================
ShoshoiSimpleSamplerAudioProcessorEditor::ShoshoiSimpleSamplerAudioProcessorEditor(ShoshoiSimpleSamplerAudioProcessor& p)
    : AudioProcessorEditor(&p), audioProcessor(p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    addAndMakeVisible(midiKeyboardComponent);
    setSize(500, 500);
    auto area = getLocalBounds();
    midiKeyboardComponent.setMidiChannel(1);
    midiKeyboardState.addListener(&audioProcessor.getMidiMessageCollector());
}

ShoshoiSimpleSamplerAudioProcessorEditor::~ShoshoiSimpleSamplerAudioProcessorEditor()
{
    //�ȉ��̓��e��ǉ����܂����B
    midiKeyboardState.removeListener(&audioProcessor.getMidiMessageCollector());
}

//==============================================================================
void ShoshoiSimpleSamplerAudioProcessorEditor::paint(juce::Graphics& g)
{
    /*
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));

    g.setColour(juce::Colours::white);
    g.setFont(15.0f);

    String str = current_path().u8string();
    g.drawFittedText(str, getLocalBounds(), juce::Justification::centred, 1);
    */

    //[1]fillAll�ȊO�̓��e���폜���܂����B
    g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));
}

void ShoshoiSimpleSamplerAudioProcessorEditor::resized()
{

    //�ȉ��̓��e�ɕύX���܂����B
    auto area = getLocalBounds();
    midiKeyboardComponent.setBounds(area.removeFromTop(80).reduced(8));
}
