//=======================================================================================
//!	@file	:	Mic.cpp
//!	@brief	:	Micクラスのメンバ関数宣言
//!	@author	:	Akiyoshi Koyama
//!	@date	:	2015/05/01
//!	@note	:	RtAudioの機能を利用しているが
//!				それ以外のパラメータは汎用的なので置き換えはしやすいはず。
//=======================================================================================
#include "Audio.h"
#include "Mic.h"
using namespace Chocolat;
using namespace Audio;

//-------------------------------------------------------------
//!	@brief		: コンストラクタ
//-------------------------------------------------------------
Mic::Mic(Core::U32 _channnels, eSampleRate _sampleRate, MicDeviceHandle _hDevice)
	: m_Channels(_channnels)
	, m_SampleRate((Core::U32)_sampleRate)
	, m_hMicDevice(_hDevice)
	, m_BufferFrames(512)
	, m_InputPrameter()
{
	m_hMicDevice = _hDevice == 0 ? m_RtController.getDefaultInputDevice() : _hDevice;
	m_InputPrameter.deviceId = m_hMicDevice;
	m_InputPrameter.nChannels = 1;
	m_InputPrameter.firstChannel = 0;
	m_RtController.openStream(nullptr, &m_InputPrameter, RTAUDIO_SINT8, m_SampleRate, &m_BufferFrames, &InputRecodeData, this);
}
//-------------------------------------------------------------
//!	@brief		: デストラクタ
//-------------------------------------------------------------
Mic::~Mic()
{
	Off();
}
//-------------------------------------------------------------
//!	@brief		: マイクを有効化
//-------------------------------------------------------------
void Mic::On()
{
	if (!m_RtController.isStreamRunning())
		m_RtController.startStream();
}
//-------------------------------------------------------------
//!	@brief		: マイクを無効化
//-------------------------------------------------------------
void Mic::Off()
{
	if (m_RtController.isStreamRunning())
		m_RtController.stopStream();
}
//-------------------------------------------------------------
//!	@brief		: マイクの更新
//-------------------------------------------------------------
void Mic::Update()
{}
//-------------------------------------------------------------
//!	@brief		: PCMデータ取得
//!	@return		: PCMデータ
//-------------------------------------------------------------
Core::Byte* Mic::GetBuffer(bool _needClean)
{
	Core::Byte* output = &m_DynamicBuffer[0];
	if (_needClean)
		m_DynamicBuffer.clear();
	return output;
}
//-------------------------------------------------------------
//!	@brief		: PCMデータのsizeを取得
//!	@return		: バッファサイズ
//-------------------------------------------------------------
Core::U32 Mic::GetBufferSize()
{
	return m_DynamicBuffer.size();
}
//-------------------------------------------------------------
//!	@brief					: Mic入力データの受け取り用Method
//! @param [_output]		: UNUSED(RtAudioのインターフェースのためあるだけ)
//! @param [_input]			: 入力されたデータのポインタ。型はopenStream時に指定したもの
//! @param [_nBufferFrames]	: Bufferのサイズ。openStream時に指定したサイズでくるはず
//! @param [_streamTime]	: UNUSED(RtAudioのインターフェースのためあるだけ)
//! @param [_status]		: UNUSED(RtAudioのインターフェースのためあるだけ)
//! @param [_data]			: 拡張データ。呼び出し元インスタンス
//!	@return					: 
//-------------------------------------------------------------
int Mic::InputRecodeData(
	void* /*_output*/, void* _input, unsigned int _nBufferFrames,
	double /*_streamTime*/, RtAudioStreamStatus /*_status*/, void* _data)
{
	Mic* target = (Mic*)_data;
	Core::U32 AddedSize = _nBufferFrames * target->m_Channels;
	Core::U32 CurrentSize = target->m_DynamicBuffer.size();
	target->m_DynamicBuffer.resize(AddedSize + CurrentSize);
#ifdef _CHOCOLAT_WINDOWS_
    memcpy_s(&target->m_DynamicBuffer[CurrentSize], AddedSize, _input, AddedSize);
#elif _CHOCOLAT_OSX_
    memcpy(&target->m_DynamicBuffer[CurrentSize], _input, AddedSize);
#endif

	return 0;
}
//===============================================================
//	End of File
//===============================================================