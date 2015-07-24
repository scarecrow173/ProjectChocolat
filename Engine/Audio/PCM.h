//=======================================================================================
//!	@file	:	PCM.h
//!	@author	:	Toru Wakabayashi
//!	@date	:	2015/07/22
//! @brief	:   WavPCMデータ用定義群
//=======================================================================================
#pragma once

namespace Chocolat
{
    namespace PCM
    {
        enum PCMFormat
        {
            PCM = 0x01,
            ADPCM = 0x02,
        };

        enum SampleRate
        {
            Sample4000 = 4000,
            Sample5512 = 5512,
            Sample8000 = 8000,
            Sample9600 = 9600,
            Sample11025 = 11025,
            Sample16000 = 16000,
            Sample22050 = 22050,
            Sample32000 = 32000,
            Sample44100 = 44100,
            Sample48000 = 48000,
            Sample88200 = 88200,
            Sample96000 = 96000,
            Sample176400 = 176400,
            Sample192000 = 192000,
        };

        class BitSample
        {
        public:
            BitSample(Chocolat::Core::U16 _bitSample) : m_BitSample(_bitSample){};
            
        private:
            Chocolat::Core::U16 m_BitSample;
        };

        class Channel
        {
        public:
            Channel(Chocolat::Core::U16 _channel) : m_Channel(_channel){};
        private:
            Chocolat::Core::U16 m_Channel;
        };

        class RawData
        {
        public:
            RawData(Chocolat::Core::U8 _rawdata) : m_RawData(_rawdata){};
        private:
            Chocolat::Core::U8 m_RawData;
        };

        class BlockWavHeader
        {
        public:
        private:
            Chocolat::Core::U32 m_RiffID; // "riff"
            Chocolat::Core::U32 m_Size_8; // ファイルサイズ-8
            Chocolat::Core::U32 m_WavID;  // "WAVE"
        };

        class BlockChunkFMT
        {
        public:
        private:
            Chocolat::Core::U32 m_FmtId;        // "fmt "
            Chocolat::Core::U32 m_FmtBytes;     // fmtチャンクのバイト数
            Chocolat::Core::U16 m_FormatID;     // フォーマットID
            Chocolat::Core::U16 m_Channels;     // チャンネル数
            Chocolat::Core::U32 m_SampleRate;   // サンプリングレート
            Chocolat::Core::U32 m_Velocity;     // データ速度
            Chocolat::Core::U16 m_Blocksize;    // ブロックサイズ
            Chocolat::Core::U16 m_Bits;         // 量子化ビット数
            Chocolat::Core::U16 m_Extension;      // 拡張部分のサイズ (リニアPCMならば存在しない)
        };

        class BlockChunkDATA
        {
        public:
        private:
            Chocolat::Core::U32 m_DataID; // "data"
            Chocolat::Core::U32 m_FollowSize;
        };

        class BlockAlignment
        {
        public:
            
        private:
            RawData* m_RawData;
            BlockWavHeader*  m_WavHeader;
            BlockChunkFMT*   m_ChunkFMT;
            BlockChunkDATA*  m_ChunkDATA;
        };
        
        class PCMData
        {
        public:
            PCMData(void* wavdata);
            void analyze();
            void reconstruction();
        private:
            BitSample* m_BitSample;
            PCMFormat* m_PcmFormat;
            Channel* m_Channel;
            SampleRate* m_SampleSample;
            BlockAlignment* m_BlockAlignment;
        };
    }
}
