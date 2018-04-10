#include "helper.h"

using namespace std;

namespace helper {
void matrix_to_normalized_matrix(string path, vector<vector<float>> mSpectrum, vector<vector<float>>& m) {
	// get filename without path and fileending
	size_t found = path.find_last_of("/\\");
	string filename = path.substr(found+1);
	found = filename.find_last_of(".");
	filename = filename.substr(0,found);

	// get spectrogram dimensions
	unsigned int timeLength = mSpectrum.size();
	unsigned int freqLength = mSpectrum[0].size()-1;

	printf("Filename: %s\n", filename.c_str());
	printf("Spectrum time length in #samples: %d\n", timeLength);
	printf("Spectrum frequence length in #bands: %d\n", freqLength);

	float maxValue = 0;

	for (int i = 1; i < freqLength; i++) {
		for (int j = 0; j < timeLength; j++) {
			if (mSpectrum[j][i] > maxValue)
				maxValue = mSpectrum[j][i];
		}
	}

	for (int i = 1; i < freqLength; i++) {
		for (int j = 0; j < timeLength; j++) {
			mSpectrum[j][i] = mSpectrum[j][i] / maxValue;
			m[freqLength-i][j] = mSpectrum[j][i];
		}
	}
}

void matrix_to_normalized_vector(vector<vector<float>> mSpectrum, unsigned int& height, unsigned int& width, vector<float>& v) {

	// get spectrogram dimensions
	unsigned int timeLength = mSpectrum.size();
	unsigned int freqLength = mSpectrum[0].size()-1;

	height = freqLength-1;
	width = timeLength;

	float maxValue = 0;

	for (int i = 1; i < freqLength; i++) {
		for (int j = 0; j < timeLength; j++) {
			if (mSpectrum[j][i] > maxValue)
				maxValue = mSpectrum[j][i];
		}
	}

	for (int i = 1; i < freqLength; i++) {
		for (int j = 0; j < timeLength; j++) {
			v.push_back(mSpectrum[j][i] / maxValue);
		}
	}
}

void matrix_enlarge(std::vector<std::vector<float>> mInput, std::vector<std::vector<float>>& mOutput) {
	printf("================ Matrix Enlarge =============================================\n");
	printf("Input: \n\tHoehe: %d\n\tBreite: %d\n", mInput[0].size(), mInput.size());
	printf("-----------------------------------\n");
	printf("Output: \n\tHoehe: %d\n\tBreite: %d\n", mOutput[0].size(), mOutput.size());

	int counter = 1;
	for (int i = 0; i < mOutput[0].size(); i++) {
		for (int j = 0; j < mOutput.size(); j++) {
			mOutput[j][i] = mInput[j][counter];
		}
		printf("counter: %d\t", counter);
		if (i > 1 && i % ((int) floor(mOutput[0].size()/mInput[0].size())) == 0) {
			counter++;
		}
	}

	printf("\n=============================================================================\n");
}
}