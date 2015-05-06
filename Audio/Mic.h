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
		//!	@par	:	�}�C�N�̎����B
		//!	@note	:	RtAudio�̋@�\�𗘗p���Ă��邪
		//!				����ȊO�̃p�����[�^�͔ėp�I�Ȃ̂Œu�������͂��₷���͂��B
		//=======================================================================================
		class Mic
		{
		public:
			//!	�}�C�N�̃f�o�C�X�n���h���B
			typedef Core::U32 MicDeviceHandle;
			//! �T���v�����[�g�w��p
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
			*	�o�b�t�@�t�H�[�}�b�g�w��p�B
			*	�Ƃ肠����8bit�Œ�ɂ��Ă���̂Ŗ��g�p�B
			*	�w��͂ł������������Ǝv����B
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
			*	�R���X�g���N�^�B�o�b�t�@�t�H�[�}�b�g�w�肷��Ƃ����������ǉ�����B
			*	@param _channnels	�`�����l����(default=1)
			*	@param _sampleRate	�T���v�����[�g(default=44100)
			*	@param _hDevice		�f�o�C�X�w��(default=0)
			*/
			Mic(Core::U32 _channnels = 1, eSampleRate _sampleRate = Rate44100, MicDeviceHandle _hDevice = 0);
			
			/**
			*	�f�X�g���N�^�B
			*	�X�g���[���̒�~�B�o�b�t�@�̉���B
			*/
			virtual ~Mic();

			//! �^���J�n�B
			void On();
			
			//! �^����~�B
			void Off();
			
			//! �X�V�B���ɂ���Ȃ����������E�E�E
			void Update();
			
			/** 
			*	PCM�f�[�^�̎擾
			*	@param _needClean �o�b�t�@���N���A���邩�B
			*/
			Core::Byte* GetBuffer(bool _needClean = false);

			/** 
			*	BufferSize�̎擾�BGetBuffer�ƂقڃZ�b�g
			*	GetBuffer�Ńo�b�t�@���N���A�����ꍇ��0�ɂȂ��Ă��邱�Ƃ�����̂Œ��ӁB
			*/
			Core::U32 GetBufferSize();

		private:
			/**
			*	RtAudio�̃f�[�^�󂯎��p�֐��|�C���^
			*	@param	_output			�g�p���Ă��Ȃ�
			*	@param	_input			�}�C�N�̓��̓f�[�^�B
			*	@param	_nBufferFrames	1Channel�̃f�[�^�T�C�Y
			*	@param	_streamTime		�g�p���Ă��Ȃ�
			*	@param	_status			�g�p���Ă��Ȃ�
			*	@param	_data			�g���f�[�^�BMic�̃C���X�^���X��n���悤�ɂ��Ă���B
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