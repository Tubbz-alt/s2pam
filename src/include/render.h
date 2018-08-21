#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include <png.h>
#include <iostream>
#include <vector>
#include <fstream>

namespace render {
	void matrix_to_PGM(std::vector<std::vector<float>> m);
	void matrix_to_MFCC_file(std::vector<std::vector<float>> m, std::string audioFilename);
	inline void set_RGB(png_byte *ptr, float val);
	void vector_to_PNG(std::string path, std::string addStr, int unsigned height, int unsigned width, std::vector<float> v);
}
