//=======================================================================================
//!	@file	:	Audio.h
//!	@author	:	Toru Wakabayashi
//!	@date	:	2015/07/19
//! @brief	:   音声ファイルの管理クラス、解析クラス
//=======================================================================================
#pragma once

#include "Core.h"
#include "PCM.h"
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
            virtual void write() = 0;
            virtual void read() = 0;
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
            void write() override;
            void read() override;
            
        private:
            void* m_WavData;
            Chocolat::PCM::PCMData m_PCMData;
        };
        
        //=======================================================================================
        //!	@class	:	OggAudio
        //!	@brief	:	OggAudio
        //!	@par	:	Oggファイル解析クラス
        //!	@note	:   Oggファイルのデータを受け取り、解析を指示する
        //=======================================================================================
        class OggAudio : public AudioManager
        {
            void write() override;
            void read() override;
        };
        
        //=======================================================================================
        //!	@class	:	AiffAudio
        //!	@brief	:	AiffAudio
        //!	@par	:	Aiffファイル解析クラス
        //!	@note	:   Aiffファイルのデータを受け取り、解析を指示する
        //=======================================================================================
        class AiffAudio : public AudioManager
        {
            void write() override;
            void read() override;
        };
        
    }
}