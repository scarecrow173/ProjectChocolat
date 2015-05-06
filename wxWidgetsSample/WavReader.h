//
//  WavReader.h
//  wxtests
//
//  Created by toru-bayashi on 2015/03/08.
//  Copyright (c) 2015年 toru-wakabayashi. All rights reserved.
//
#pragma once
#include <fstream>

static unsigned int COLOR_SCALE = 256;

typedef struct {
    unsigned int id;       // "fmt "
    unsigned int bytes;    // fmtチャンクのバイト数
    unsigned short formatID; // フォーマットID
    unsigned short channels; // チャンネル数
    unsigned int rate;     // サンプリングレート
    unsigned int velocity; // データ速度
    unsigned short blocksize;// ブロックサイズ
    unsigned short bits;     // 量子化ビット数
    
    //unsigned short extension; // 拡張部分のサイズ (リニアPCMならば存在しない)
    // 拡張部分 (extension bytes)
} fmtChunk;

typedef struct {
    unsigned int id;       // "data"
    unsigned int bytes;    // 波形データのバイト数
} dataChunk;

typedef struct {
    unsigned int riffID; // "riff"
    unsigned int size_8; // ファイルサイズ-8
    unsigned int wavID;  // "WAVE"
    fmtChunk fmtchunk;
    dataChunk datachunk;
} wavFileHeader;

typedef struct {
    unsigned char *Lch;
    unsigned char *Rch;
    unsigned char *normalizedR; // 色数内に正規化した波形データ
    unsigned char *normalizedL; // 色数内に正規化した波形データ
} rawLR;

class WAVReader {
    wavFileHeader header;
    std::string filePath;
    unsigned char *raw; // 波形データ
    rawLR rawlr;
    bool load();
    
public:
    WAVReader(const char* path){
        filePath = path;
        load();
        initialize();
    }
    WAVReader(const std::string& path){
        filePath = path;
        load();
        initialize();
    }
    ~WAVReader(){
        delete[] raw;
    }
    
    size_t size(){ return header.size_8 + 8; };
    unsigned int bitrate(){ return header.fmtchunk.rate; };
    unsigned int bits(){ return header.fmtchunk.bits; }
    unsigned int channels(){ return header.fmtchunk.channels; };
    unsigned int dataBytes(){ return header.datachunk.bytes; };
    unsigned int formatType(){ return header.fmtchunk.formatID; };
    unsigned char* pcmData(){ return raw; };
    unsigned char* rawRData(){ return rawlr.Rch; };
    unsigned char* rawLData(){ return rawlr.Lch; };
    
    void initialize();
    void normalize();
    //    void endianCheck();
    int getOffsetBytes();
    void separateChannels();
    
};
