#include "..\include\audiosource.h"

AudioSource::AudioSource(AudioBuffer * buffer)
{
	alGenSources(1, &source);

	alSourcef(source, AL_PITCH, 1.0);
	alSourcef(source, AL_GAIN, 1.0);
	alSource3f(source, AL_POSITION, 0.0, 0.0, 0.0);
	alSource3f(source, AL_VELOCITY, 0.0, 0.0, 0.0);
	alSourcef(source, AL_LOOPING, false);
	alSourcef(source, AL_BUFFER, buffer->GetBuffer());
}

AudioSource::~AudioSource()
{
	alDeleteSources(1, &source);
}

bool AudioSource::IsPlaying() const
{
	int32 value;
	alGetSourcei(source, AL_SOURCE_STATE, &value);
	return value== AL_PLAYING;
}
