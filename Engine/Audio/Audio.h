//=======================================================================================
//!	@file	:	Audio.h
//!	@author	:	toru_wakabayashi
//!	@date	:	2015/07/19
//! @brief	:   音声ファイルの管理
//=======================================================================================
#pragma once

#include "Core.h"

#include "RtAudio.h"
namespace Chocolat
{
namespace Audio
{
    //=======================================================================================
    //!	@class	:	AudioManager
    //!	@brief	:	AudioManager
    //!	@par	:	音声ファイル管理用（抽象インターフェース？）
    //!	@note	:   複数の音声ファイルに対応するための抽象クラス
    //=======================================================================================
    class AudioManager
    {
        virtual void analyze() = 0;
    };
    
    //=======================================================================================
    //!	@class	:	WavAudio
    //!	@brief	:	WavAudio
    //!	@par	:	Wavファイル解析クラス
    //!	@note	:   Wavファイルのデータを受け取り、解析を指示する
    //=======================================================================================
    class WavAudio : public AudioManager
    {
    public:
        //! WavコンストラクタでWavデータを受け取る
        WavAudio(/*File f*/) /* : wavdata_(f)*/;
        void analyze() override;
        
    private:
        void* wavdata_;
    };
    
    class OggAudio : public AudioManager
    {
        void analyze() override;
    };
    
    class AiffAudio : public AudioManager
    {
        void analyze() override;
    };
    
    class Bitrate
    {
    public:
        Bitrate(Chocolat::Core::U16 bitrate) : bitrate_(bitrate){};
    private:
        Chocolat::Core::U16 bitrate_;
    };
    
    class PCMFormat
    {
    public:
        PCMFormat(Chocolat::Core::U16 formatID) : formatID_(formatID){};
    private:
        Chocolat::Core::U16 formatID_;
    };
    
    class Channel
    {
    public:
        Channel(Chocolat::Core::U16 channel) : channel_(channel){};
    private:
        Chocolat::Core::U16 channel_;
    };
    
    class SampleRate
    {
    public:
        SampleRate(Chocolat::Core::U32 samplerate) : samplerate_(samplerate){};
    private:
        Chocolat::Core::U32 samplerate_;
    };
    
    class BlockAlignment
    {
    public:
    private:
        void* wavheader_;
        void* chunkFMT_;
        void* chunkDATA_;
    };

    class PCM
    {
    public:
    private:
        Bitrate bitrate_;
        PCMFormat pcmformat_;
        Channel channel_;
        SampleRate samplerate_;
        BlockAlignment blockalignment_;
    };
    
}
}