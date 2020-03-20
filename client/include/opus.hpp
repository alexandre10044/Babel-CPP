/*
** EPITECH PROJECT, 2019
** opus.hpp
** File description:
** opus
*/

#ifndef OPUS_HPP_
    #define OPUS_HPP_

    #include "opus.h"

    class opusCodec {
        public:
            opusCodec();
            ~opusCodec();

            std::vector<unsigned char> serializeData(std::vector<unsigned char> buffer, int size);
            std::vector<unsigned char> deserializeData(std::vector<unsigned char> buffer, int size);

            OpusEncoder	*serialize;
		    OpusDecoder	*deserialize;
            int err;
    };

#endif /* !OPUS_HPP_ */