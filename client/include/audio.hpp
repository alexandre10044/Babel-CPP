/*
** EPITECH PROJECT, 2019
** audio.hpp
** File description:
** audio
*/

#ifndef AUDIO_HPP_
    #define AUDIO_HPP_

    #include <portaudio.h>

    #include "entity.hpp"
    #include "opus.hpp"

    class audio {
        public:
            audio();
            ~audio();
            PaStreamParameters inputParams;
            PaStreamParameters outputParams;
            PaStream *stat;
            PaStream *stout;
            bool inCall;
            bool recording;
            bool listening;
            bool init;
            entity *inst;
            opusCodec *codec;

            void startRecord();
            void stopRecord();
            void startListening();
            void stopListening();
            void startCall();
            void handleData(std::string);
            void stopCall();
    };

#endif /* !AUDIO_HPP_ */