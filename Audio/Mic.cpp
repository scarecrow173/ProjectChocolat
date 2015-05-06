//=======================================================================================
//!	@file	:	Mic.cpp
//!	@brief	:	Mic�N���X�̃����o�֐��錾
//!	@author	:	Akiyoshi Koyama
//!	@date	:	2015/05/01
//!	@note	:	RtAudio�̋@�\�𗘗p���Ă��邪
//!				����ȊO�̃p�����[�^�͔ėp�I�Ȃ̂Œu�������͂��₷���͂��B
//=======================================================================================
#include "Audio.h"
#include "Mic.h"
using namespace Chocolat;
using namespace Audio;

//-------------------------------------------------------------
//!	@brief		: �R���X�g���N�^
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
//!	@brief		: �f�X�g���N�^
//-------------------------------------------------------------
Mic::~Mic()
{
	Off();
}
//-------------------------------------------------------------
//!	@brief		: �}�C�N��L����
//-------------------------------------------------------------
void Mic::On()
{
	if (!m_RtController.isStreamRunning())
		m_RtController.startStream();
}
//-------------------------------------------------------------
//!	@brief		: �}�C�N�𖳌���
//-------------------------------------------------------------
void Mic::Off()
{
	if (m_RtController.isStreamRunning())
		m_RtController.stopStream();
}
//-------------------------------------------------------------
//!	@brief		: �}�C�N�̍X�V
//-------------------------------------------------------------
void Mic::Update()
{}
//-------------------------------------------------------------
//!	@brief		: PCM�f�[�^�擾
//!	@return		: PCM�f�[�^
//-------------------------------------------------------------
Core::Byte* Mic::GetBuffer(bool _needClean)
{
	Core::Byte* output = &m_DynamicBuffer[0];
	if (_needClean)
		m_DynamicBuffer.clear();
	return output;
}
//-------------------------------------------------------------
//!	@brief		: PCM�f�[�^��size���擾
//!	@return		: �o�b�t�@�T�C�Y
//-------------------------------------------------------------
Core::U32 Mic::GetBufferSize()
{
	return m_DynamicBuffer.size();
}
//-------------------------------------------------------------
//!	@brief					: Mic���̓f�[�^�̎󂯎��pMethod
//! @param [_output]		: UNUSED(RtAudio�̃C���^�[�t�F�[�X�̂��߂��邾��)
//! @param [_input]			: ���͂��ꂽ�f�[�^�̃|�C���^�B�^��openStream���Ɏw�肵������
//! @param [_nBufferFrames]	: Buffer�̃T�C�Y�BopenStream���Ɏw�肵���T�C�Y�ł���͂�
//! @param [_streamTime]	: UNUSED(RtAudio�̃C���^�[�t�F�[�X�̂��߂��邾��)
//! @param [_status]		: UNUSED(RtAudio�̃C���^�[�t�F�[�X�̂��߂��邾��)
//! @param [_data]			: �g���f�[�^�B�Ăяo�����C���X�^���X
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