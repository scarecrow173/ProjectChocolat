//
//  AudioLoader.cpp
//  wxtests
//
//  Created by toru-bayashi on 2015/03/08.
//  Copyright (c) 2015年 toru-wakabayashi. All rights reserved.
//

#include "AudioLoader.h"

//static int
//rtaudio_callback(
//                 void			*outbuf,
//                 void			*inbuf,
//                 unsigned int		nFrames,
//                 double			streamtime,
//                 RtAudioStreamStatus	status,
//                 void			*userdata)
//{
//	(void)inbuf;
//	float	*buf = (float*)outbuf;
//	unsigned int remainFrames;
//	CallbackData	*data = (CallbackData*)userdata;
//    
//	remainFrames = nFrames;
//	while (remainFrames > 0) {
//	    unsigned int sz = data->nFrame - data->cur;
//	    if (sz > remainFrames)
//            sz = remainFrames;
//	    memcpy(buf, data->wftable+(data->cur*data->nChannel),
//               sz * data->nChannel * sizeof(float));
//	    data->cur = (data->cur + sz) % data->nFrame;
//	    buf += sz * data->nChannel;
//	    remainFrames -= sz;
//	}
//	return 0;
//}

AudioLoader::AudioLoader(const char* path)
{
    wav = new WAVReader(path);
    
    // wav file infomation print out
    const char* desc[] = {"size", "rate", "bits", "ch", "data bytes", ""};
    unsigned int val[] = {wav->size(), wav->bitrate(), wav->bits(), wav->channels(), wav->dataBytes()};
    for (int i = 0; desc[i][0] != '\0'; i++)
        printf("%s\t%u\n", desc[i], val[i]);
    float duration = ((float)wav->dataBytes() / (wav->bits() / 8) / wav->channels()) / wav->bitrate();
    printf("duration\t%.2fsec\n", duration);
    
}

//void AudioLoader::AudioPlayback()
//{
//    RtAudio *Rtwav = new RtAudio();
//    RtAudio::StreamParameters parameters;
//    parameters.deviceId = Rtwav->getDefaultOutputDevice();
//    parameters.nChannels = wav->channels();
//    parameters.firstChannel = 0;
//    unsigned int sampleRate = wav->bitrate();
//    unsigned int bufferFrames = 256; // 256 sample frames
//    double data[2];
//    
//    CallbackData wavTable;
//    
//    try {
//        Rtwav->openStream( &parameters, NULL, RTAUDIO_FLOAT64,
//                       sampleRate, &bufferFrames, rtaudio_callback, (void *)&data );
//        Rtwav->startStream();
//    }
//    catch ( RtAudioError& e ) {
//        e.printMessage();
//        exit( 0 );
//    }
//}

//int AudioLoader()
//{
//    RtAudio *audio;
//    unsigned int bufsize = 4096;
//    CallbackData data;
//
//    try {
//        audio = new RtAudio(RtAudio::MACOSX_CORE);
//    }catch  (RtAudioError e){
//        fprintf(stderr, "fail to create RtAudio: %s¥n", e.what());
//        return 1;
//    }
//    if (!audio){
//        fprintf(stderr, "fail to allocate RtAudio¥n");
//        return 1;
//    }
//    /* probe audio devices */
//    unsigned int devId = audio->getDefaultOutputDevice();
//
//    /* Setup output stream parameters */
//    RtAudio::StreamParameters *outParam = new RtAudio::StreamParameters();
//
//    outParam->deviceId = devId;
//    outParam->nChannels = 2;
//
//    audio->openStream(outParam, NULL, RTAUDIO_FLOAT32, 44100,
//                      &bufsize, rtaudio_callback, &data);
//
//    /* Create Wave Form Table */
//    data.nRate = 44100;
//    /* Frame Number is based on Freq(440Hz) and Sampling Rate(44100) */
//    /* hmm... nFrame = 44100 is enough approximation, maybe... */
//    data.nFrame = 44100;
//    data.nChannel = outParam->nChannels;
//    data.cur = 0;
//    data.wftable = (float *)calloc(data.nChannel * data.nFrame, sizeof(float));
//    if (!data.wftable)
//    {
//        delete audio;
//        fprintf(stderr, "fail to allocate memory¥n");
//        return 1;
//    }
//    for(unsigned int i = 0; i < data.nFrame; i++) {
//        float v = sin(i * M_PI * 2 * 440 / data.nRate);
//        for(unsigned int j = 0; j < data.nChannel; j++) {
//            data.wftable[i*data.nChannel+j] = v;
//        }
//    }
//
//    audio->startStream();
//    sleep(10);
//    audio->stopStream();
//    audio->closeStream();
//    delete audio;
//
//    return 0;
//}
