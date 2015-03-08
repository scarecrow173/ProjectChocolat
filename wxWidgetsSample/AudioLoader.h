//
//  AudioLoader.h
//  wxtests
//
//  Created by toru-bayashi on 2015/03/08.
//  Copyright (c) 2015年 toru-wakabayashi. All rights reserved.
//

//#ifndef __wxtests__AudioLoader__
//#define __wxtests__AudioLoader__
#pragma once
#include "RtAudio.h"
#include "WavReader.h"

typedef struct {
    unsigned int	nRate;		/* Sampling Rate (sample/sec) */
    unsigned int	nChannel;	/* Channel Number */
    unsigned int	nFrame;		/* Frame Number of Wave Table */
    float           *wftable;	/* Wave Form Table(interleaved) */
    unsigned int	cur;		/* current index of WaveFormTable(in Frame) */
} CallbackData;

static int rtaudio_callback(
                            void			*outbuf,
                            void			*inbuf,
                            unsigned int		nFrames,
                            double			streamtime,
                            RtAudioStreamStatus	status,
                            void			*userdata);

class AudioLoader
{
public:
    AudioLoader(const char* path);
    WAVReader *wav;
    
    void AudioPlayback();
};

//#endif /* defined(__wxtests__AudioLoader__) */
