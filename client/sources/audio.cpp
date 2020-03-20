/*
** EPITECH PROJECT, 2019
** audio.cpp
** File description:
** audio
*/

#include <iostream>

#include "../include/audio.hpp"
#include "../include/opus.hpp"

std::vector<unsigned char> buffer;

audio::audio()
{
    inCall = false;
    recording = false;
    listening = false;
    codec = new opusCodec();
    // Init
    if (Pa_Initialize() != paNoError) {
        std::cout << "Can't Pa_Initialize" << std::endl;
        return;
    }
    // Input
    inputParams.device = Pa_GetDefaultInputDevice();
	if (inputParams.device == paNoDevice) {
        std::cout << "Can't Pa_GetDefaultInputDevice" << std::endl;
        return;
    }
	inputParams.channelCount = 2;
	inputParams.sampleFormat = paFloat32;
	inputParams.suggestedLatency = Pa_GetDeviceInfo(inputParams.device)->defaultLowInputLatency;
	inputParams.hostApiSpecificStreamInfo = NULL;
    // Output
    outputParams.device = Pa_GetDefaultOutputDevice();
	if (outputParams.device == paNoDevice) {
        std::cout << "Can't Pa_GetDefaultOutputDevice" << std::endl;
        return;
    }
    outputParams.channelCount = 2;
	outputParams.sampleFormat = paFloat32;
	outputParams.suggestedLatency = Pa_GetDeviceInfo(outputParams.device)->defaultLowOutputLatency;
	outputParams.hostApiSpecificStreamInfo = NULL;
    init = true;
    std::cout << "Port audio initialized." << std::endl;
}

audio::~audio()
{
    stopCall();
    stopRecord();
    stopListening();
	Pa_Terminate();
}

int	recordCallback(const void *tmp_buff, void *, unsigned long frm, const PaStreamCallbackTimeInfo *, PaStreamCallbackFlags, void *)
{
    buffer.assign(reinterpret_cast<const float *>(tmp_buff), reinterpret_cast<const float *>(tmp_buff) + frm * 2);
    std::cout << "Record data sent !" << std::endl;
    return (0);
}

int	listencallback(const void *, void *tmp_buff, unsigned long frm, const PaStreamCallbackTimeInfo *, PaStreamCallbackFlags, void *)
{
    buffer.assign(reinterpret_cast<const float *>(tmp_buff), reinterpret_cast<const float *>(tmp_buff) + frm * 2);
    std::cout << "Listening record data !" << std::endl;
    return (0);
}

void audio::startRecord()
{
    if (recording || !init)
        return;
    if (Pa_OpenStream(&stat, &inputParams, NULL, 48000, 480,
        paClipOff, recordCallback, this) != paNoError) {
        std::cout << "Can't Pa_GetDefaultInputDevice" << std::endl;
        return;
    }
	if (Pa_StartStream(stat) != paNoError) {
        std::cout << "Can't Pa_StartStream" << std::endl;
        return;
    }
    recording = true;
}

void audio::stopRecord()
{
    if (!recording || !init)
        return;
    if (Pa_CloseStream(stat) != paNoError) {
        std::cout << "Can't Pa_CloseStream" << std::endl;
        return;
    }
    recording = false;
}

void audio::startListening()
{
    if (listening || !init)
        return;
    if (Pa_OpenStream(&stout, NULL, &outputParams, 48000, 480, paClipOff, listencallback, this) != paNoError) {
        std::cout << "Can't Pa_OpenStream" << std::endl;
        return;
    }
	if (Pa_StartStream(stout) != paNoError) {
        std::cout << "Can't Pa_StartStream" << std::endl;
        return;
    }
    listening = true;
}

void audio::stopListening()
{
    if (!listening || !init)
        return;
    if (Pa_CloseStream(stat) != paNoError) {
        std::cout << "Can't Pa_CloseStream" << std::endl;
        return;
    }
    listening = false;
}

void audio::handleData(std::string data)
{
    //handleData(data);
    (void)data;
}

void audio::startCall()
{
    if (inCall || !init)
        return;
    startRecord();
    inCall = true;
}

void audio::stopCall()
{
    if (!inCall || !init)
        return;
    stopRecord();
    inCall = false;
}