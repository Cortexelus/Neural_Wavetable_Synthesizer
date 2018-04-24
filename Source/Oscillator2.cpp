/*
  ==============================================================================

    Oscillator.cpp
    Created: 21 Apr 2018 10:21:32am
    Author:  Lamtharn Hantrakul

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Oscillator2.h"
#include "WaveWindow.h"

//==============================================================================
Oscillator2::Oscillator2( WaveNetWaveTableAudioProcessor& p):
processor(p)
{   
    oscMenu.addItem("Sine", 1);
    oscMenu.addItem("Saw", 2);
    oscMenu.addItem("Triangle", 3);
    oscMenu.addItem("WaveNet", 4);
    oscMenu.setJustificationType(Justification::centred);
    addAndMakeVisible(&oscMenu);
    oscMenu.addListener(this);
    waveSelection = new AudioProcessorValueTreeState::ComboBoxAttachment(processor.tree, "wavetype2", oscMenu);
}

Oscillator2::~Oscillator2()
{
}

void Oscillator2::paint (Graphics& g)
{
    
}

void Oscillator2::resized()
{
    Rectangle<int> area = getLocalBounds().reduced(20,0);
    oscMenu.setBounds(area.removeFromTop(20));
}

void Oscillator2::comboBoxChanged(ComboBox* box)
{
    comboBoxChangeState = true;
}