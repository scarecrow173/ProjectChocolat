//
//  WavReader.h
//  wxtests
//
//  Created by toru-bayashi on 2015/03/08.
//  Copyright (c) 2015年 toru-wakabayashi. All rights reserved.
//
#pragma once

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

class WAVReader {
    wavFileHeader header;
    std::string filePath;
    unsigned char *raw; // 波形データ
    bool load();
    
public:
    WAVReader(const char* path){
        filePath = path;
        load();
    }
    WAVReader(const std::string& path){
        filePath = path;
        load();
    }
    ~WAVReader(){
        delete[] raw;
    }
    
    size_t size(){ return header.size_8 + 8; };
    unsigned int bitrate(){ return header.fmtchunk.rate; };
    unsigned int bits(){ return header.fmtchunk.bits; }
    unsigned int channels(){ return header.fmtchunk.channels; };
    unsigned int dataBytes(){ return header.datachunk.bytes; };
    unsigned char* pcmData(){ return raw; };
};
