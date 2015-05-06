//=======================================================================================
//!	@file	:	Mic.h
//!	@author	:	Akiyoshi Koyama
//!	@date	:	2015/05/01
//=======================================================================================
#pragma once
#include "Audio.h"
#include <vector>
namespace Chocolat
{
	namespace Audio
	{
		//=======================================================================================
		//!	@class	:	Mic
		//!	@brief	:	Mic
		//!	@par	:	マイクの実装。
		//!	@note	:	RtAudioの機能を利用しているが
		//!				それ以外のパラメータは汎用的なので置き換えはしやすいはず。
		//=======================================================================================
		class Mic
		{
		public:
			//!	マイクのデバイスハンドル。
			typedef Core::U32 MicDeviceHandle;
			//! サンプルレート指定用
			enum eSampleRate
			{
				Rate4000 = 4000,
				Rate5512 = 5512,
				Rate8000 = 8000,
				Rate9600 = 9600,
				Rate11025 = 11025,
				Rate16000 = 16000,
				Rate22050 = 22050,
				Rate32000 = 32000,
				Rate44100 = 44100,
				Rate48000 = 48000,
				Rate88200 = 88200,
				Rate96000 = 96000,
				Rate176400 = 176400,
				Rate192000 = 192000,

			};
			/**
			*	バッファフォーマット指定用。
			*	とりあえず8bit固定にしているので未使用。
			*	指定はできた方がいいと思われる。
			*/
			enum eBufferFormat
			{
				Format_8 = 0,
				Format_16,
				Format_24,
				Format_32,
				Fromat_Float,
				Fromat_Double,
			};
			
			/**
			*	コンストラクタ。バッファフォーマット指定するとしたら引数を追加する。
			*	@param _channnels	チャンネル数(default=1)
			*	@param _sampleRate	サンプルレート(default=44100)
			*	@param _hDevice		デバイス指定(default=0)
			*/
			Mic(Core::U32 _channnels = 1, eSampleRate _sampleRate = Rate44100, MicDeviceHandle _hDevice = 0);
			
			/**
			*	デストラクタ。
			*	ストリームの停止。バッファの解放。
			*/
			virtual ~Mic();

			//! 録音開始。
			void On();
			
			//! 録音停止。
			void Off();
			
			//! 更新。特にいらなかったかも・・・
			void Update();
			
			/** 
			*	PCMデータの取得
			*	@param _needClean バッファをクリアするか。
			*/
			Core::Byte* GetBuffer(bool _needClean = false);

			/** 
			*	BufferSizeの取得。GetBufferとほぼセット
			*	GetBufferでバッファをクリアした場合は0になっていることがあるので注意。
			*/
			Core::U32 GetBufferSize();

		private:
			/**
			*	RtAudioのデータ受け取り用関数ポインタ
			*	@param	_output			使用していない
			*	@param	_input			マイクの入力データ。
			*	@param	_nBufferFrames	1Channelのデータサイズ
			*	@param	_streamTime		使用していない
			*	@param	_status			使用していない
			*	@param	_data			拡張データ。Micのインスタンスを渡すようにしている。
			*/
			static int InputRecodeData(void* _output, void* _input, unsigned int _nBufferFrames,
				double _streamTime, RtAudioStreamStatus _status, void* _data);

			
			bool m_IsRunning;
			
			Core::U32 m_Channels;
			Core::U32 m_SampleRate;
			MicDeviceHandle m_hMicDevice;
			eBufferFormat m_Format;
			Core::U32 m_BufferFrames;

			std::vector<Core::Byte> m_DynamicBuffer;

			RtAudio m_RtController;
			RtAudio::StreamParameters m_InputPrameter;

		};
	}
}
//===============================================================
//	End of File
//===============================================================