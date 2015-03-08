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
