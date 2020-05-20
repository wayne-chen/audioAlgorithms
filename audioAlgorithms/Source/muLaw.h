#pragma once

#include <cmath>
#include <ctime>
#include <cstdlib>

#include <exception>
#include <vector>
#include <iostream>

const float mu = 255.0f; // 8-bit companding
const float pi = std::acos(-1);

typedef std::vector<std::vector<float> > MultiBuffer;

void printBuffer(MultiBuffer multiBuffer)
{
    std::cout << std::endl << "======================== BUFFER ========================";
    for(auto& buffer : multiBuffer)
    {
        std::cout << std::endl << "\t[ ";
        for (auto &val : buffer)
        {
            std::cout << val << " ";
        }
        std::cout << "]";
    }
    std::cout << std::endl << "====================== END BUFFER ======================";
}

void mu_compand(MultiBuffer* multiBuffer)
{
    try
    {
        auto numChannels = multiBuffer->size();
        std::cout << numChannels << std::endl;
        auto numSamples = multiBuffer->at(0).size();
        std::cout << numSamples << std::endl;
        // compand samples
        for (int c = 0; c < numChannels; c++)
        {
            for (int i = 0; i < numSamples; i++)
            {
                float prev = multiBuffer->at(c)[i];
                float sign = (prev < 0) ? -1.0f : 1.0f;
                multiBuffer->at(c)[i] = sign * std::log(1.0f + (mu * std::abs(prev)))  // numerator
                    / std::log(1.0f + mu);  // denominator
            }
        }
    }
    catch(std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
}

void mu_decode(float** buf, int numChannels, int numSamples)
{
    // compand samples
    for (int c = 0; c < numChannels; c++)
    {
        for (int i = 0; i < numSamples; i++)
        {
                        
            float prev = buf[c][i];
            int sign = (prev < 0) ? -1 : 1;
            buf[c][i] = sign * std::log(1.0f + (mu * std::abs(prev)))  // numerator
                / std::log(1.0f + mu);  // denominator
        }
    }
}
