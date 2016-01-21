#include "..\include\audiobuffer.h"
#include "../include/file.h"
#include "../lib/openal/AL/al.h"
#include "../lib/openal/AL/alc.h"
AudioBuffer::AudioBuffer(const String & filename)
{
	uint32 RiffChunkSize, FmtChunkSize, SampleRate, ByteRate, bufferSize, data;
	void * buffer;
	char texto[5];
	texto[4] = 0;
	uint16 AudioFormat, Channels, BlockAlign, BitsPerSample, ExtraParamsSize;
	alBuffer = 0;
	File * wavFile = new File(filename, 0);
	wavFile->ReadInt();//"RIFF"
	RiffChunkSize= wavFile->ReadInt();
	wavFile->ReadInt();//"WAVE"
	wavFile->ReadInt();//"fmt"
	FmtChunkSize = wavFile->ReadInt();
	AudioFormat= wavFile->ReadInt16();
	Channels= wavFile->ReadInt16();
	SampleRate= wavFile->ReadInt();
	ByteRate= wavFile->ReadInt();
	BlockAlign= wavFile->ReadInt16();
	BitsPerSample= wavFile->ReadInt16();
	if (AudioFormat != 1 && FmtChunkSize>16) {
		ExtraParamsSize= wavFile->ReadInt16();
		wavFile->Seek(wavFile->Pos() + ExtraParamsSize);
	}
	do{
		wavFile->ReadBytes(texto,4);
	} while (String(texto) == "data");
	bufferSize = wavFile->ReadInt();
	buffer = malloc(bufferSize);
	wavFile->ReadBytes(buffer, bufferSize);
	ALenum format;
	if (BitsPerSample == 8) {
		if (Channels == 1) {
			format = AL_FORMAT_MONO8;
		}
		else {
			format = AL_FORMAT_STEREO8;
		}
	}
	else {
		if (Channels == 1) {
			format = AL_FORMAT_MONO16;
		}
		else {
			format = AL_FORMAT_STEREO16;
		}
	}
	alBufferData(alBuffer, format, buffer, bufferSize, SampleRate);
	free(buffer);
}

AudioBuffer::~AudioBuffer()
{
}
