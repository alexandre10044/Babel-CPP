/*
** EPITECH PROJECT, 2019
** opus.cpp
** File description:
** opus
*/

#include <iostream>
#include <vector>

#include "../include/opus.hpp"

opusCodec::opusCodec()
{
    serialize = opus_encoder_create(48000, 2, OPUS_APPLICATION_VOIP, &err);
	if (err != OPUS_OK) {
		std::cout << "Opus failed !" << std::endl;
        return;
    }
    deserialize = opus_decoder_create(48000, 2, &err);
    if (err != OPUS_OK)
		std::cout << "Opus failed !" << std::endl;
    else
		std::cout << "Opus OK !" << std::endl;
}

opusCodec::~opusCodec()
{

}

std::vector<unsigned char> opusCodec::serializeData(std::vector<unsigned char> buffer, int size)
{
    buffer.resize(size);
	size = opus_encode_float(serialize, (const float *)buffer.data(), 480, buffer.data(), size);
	return (buffer);
}

std::vector<unsigned char> opusCodec::deserializeData(std::vector<unsigned char> buffer, int size)
{
    buffer.resize(size);
	size = opus_decode_float(deserialize, buffer.data(), size, (float*)buffer.data(), 480, 0) * 2;
	return (buffer);
}