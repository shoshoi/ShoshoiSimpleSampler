// SimpleSynth.cpp

#include "SimpleSynth.h"
#include <iostream>
#include <string>
#include <filesystem>
#define MAX_VOICES 16


void SimpleSynth::setup() {
	// add voices to our sampler
	for (int i = 0; i < MAX_VOICES; i++) {
		addVoice(new SamplerVoice());
	}

	WavAudioFormat wavFormat;

	ScopedPointer<AudioFormatReader> audioReader
		= wavFormat.createReaderFor(new MemoryInputStream(TestResource::file_wav,
			TestResource::file_wavSize,
			false),
			true);


	// allow our sound to be played on all notes
	BigInteger allNotes;
	allNotes.setRange(0, 128, true);

	// finally, add our sound
	addSound(new SamplerSound("default", *audioReader, allNotes, 60, 0, 10, 10.0));
}
