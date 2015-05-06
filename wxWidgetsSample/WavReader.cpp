//
//  WavReader.cpp
//  wxtests
//
//  Created by toru-bayashi on 2015/03/08.
//  Copyright (c) 2015年 toru-wakabayashi. All rights reserved.
//
#include "wxWidgetsSample.h"
#include "WavReader.h"

bool WAVReader::load(){
    FILE *fp = fopen(filePath.c_str(), "r");
    if (!fp){
        perror("WAV::load");
        exit(1);
    }
    fread((void*)&header, sizeof(header), 1, fp);
    unsigned int rawbytes = header.datachunk.bytes;
    raw = new unsigned char[rawbytes];
    // 波形データの読み込み
    //fread((void*)raw, sizeof(rawbytes), 1, fp); // 修正2009/09/26
    fread((void*)raw, rawbytes, 1, fp);
    fclose(fp);
    return true;
}

void WAVReader::initialize()
{
    rawlr.Rch = new unsigned char[dataBytes()/channels()];
    rawlr.Lch = new unsigned char[dataBytes()/channels()];
    rawlr.normalizedR = new unsigned char[dataBytes()/getOffsetBytes()];
    rawlr.normalizedL = new unsigned char[dataBytes()/getOffsetBytes()];
    //    void endianCheck();
    separateChannels();
    normalize();
}

// 8bit以外の丸め込み処理
void WAVReader::normalize()
{
    int index = 0;
    unsigned int rawbytes = dataBytes()/channels();
    for (int i=0; i<rawbytes; ++i)
    {
        if (bits() == 16)
        {
            rawlr.normalizedR[index] = rawlr.Rch[i] * rawlr.Rch[++i] / COLOR_SCALE;
            if (channels() == 2)
            {
                rawlr.normalizedL[index] = rawlr.Lch[++i] * rawlr.Lch[++i] / COLOR_SCALE;
            }
        }
        ++index;
    }
}

int WAVReader::getOffsetBytes()
{
    int ch,bt;
    ch = channels();
    bt = bits()/8;
    
    return ch*bt;
}

void WAVReader::separateChannels()
{
    int indexL = 0;
    int indexR = 0;
    unsigned int rawbytes = header.datachunk.bytes;
    switch (formatType())
    {
        case 0x01: // リニアPCM 0x0001
            for (int i=0; i<rawbytes; ++i)
            {
                if (bits() == 8)
                {
                    // 8bit/monoral
                    if (channels() == 1)
                    {
                        rawlr.Rch[indexR] = raw[i];
                    }
                    // 8bit/stereo
                    else if (channels() == 2)
                    {
                        rawlr.Rch[indexR] = raw[i];
                        rawlr.Lch[indexL] = raw[++i];
                    }
                }
                else if (bits() == 16)
                {
                    // 16bit/monoral
                    if (channels() == 1)
                    {
                        rawlr.Rch[indexR] = raw[i];
                        rawlr.Rch[++indexR] = raw[++i];
                    }
                    // 16bit/stereo
                    else if (channels() == 2)
                    {
                        rawlr.Rch[indexR] = raw[i];
                        rawlr.Rch[++indexR] = raw[++i];
                        rawlr.Lch[indexL] = raw[++i];
                        rawlr.Lch[++indexL] = raw[++i];
                    }
                }
                
                else
                {
                    printf("This \"bit depth\" is unsupported.\n");
                }
                ++indexR;
                ++indexL;
            }
            break;
            
        default:
            printf("This \"WAV format\" is unsupported.\n");
            break;
    }
}
