/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic startup code for a JUCE application.

  ==============================================================================
*/

#include <JuceHeader.h>
#include "muLaw.h"

//==============================================================================
int main (int argc, char* argv[])
{

    // ..your code goes here!
    int numChannels = 5, numSamples = 50;
    MultiBuffer multiBuffer;
    std::srand(std::time(nullptr)); // use current time as seed for random generator
    float freq = 1000.0f, fs = 48000.0f;

    float val;
    for (int c = 0; c < numChannels; c++)
    {
        //val = (std::rand() * 2.0f / RAND_MAX) - 1.0f;
        multiBuffer.push_back(std::vector<float>(numSamples));
        for (int i = 0; i < numSamples; i++)
        {
            multiBuffer[c][i] = std::sin(2.0f * freq * pi * i / fs);
        }
    }
    printBuffer(multiBuffer);

    mu_compand(&multiBuffer);

    printBuffer(multiBuffer);

    return 0;
}
