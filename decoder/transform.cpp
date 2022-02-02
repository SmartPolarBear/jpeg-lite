// Copyright (c) 2022 SmartPolarBear.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

//
// Created by cleve on 2/1/2022.
//

#include "decoder/transform.h"

#include <utility>
#include <cmath>

#include <gsl/gsl>

using namespace gsl;
using namespace std;

static inline constexpr int zigzags[8][8] =
		{
				{ 0,  1,  5,  6,  14, 15, 27, 28 },
				{ 2,  4,  7,  13, 16, 26, 29, 42 },
				{ 3,  8,  12, 17, 25, 30, 41, 43 },
				{ 9,  11, 18, 24, 31, 40, 44, 53 },
				{ 10, 19, 23, 32, 39, 45, 52, 54 },
				{ 20, 22, 33, 38, 46, 51, 55, 60 },
				{ 21, 34, 37, 47, 50, 56, 59, 61 },
				{ 35, 36, 48, 49, 57, 58, 62, 63 }
		};

static inline constexpr std::pair<gsl::index, gsl::index> coordinates[64] =
		{
				{ 0, 0 },
				{ 0, 1 },
				{ 1, 0 },
				{ 2, 0 },
				{ 1, 1 },
				{ 0, 2 },
				{ 0, 3 },
				{ 1, 2 },
				{ 2, 1 },
				{ 3, 0 },
				{ 4, 0 },
				{ 3, 1 },
				{ 2, 2 },
				{ 1, 3 },
				{ 0, 4 },
				{ 0, 5 },
				{ 1, 4 },
				{ 2, 3 },
				{ 3, 2 },
				{ 4, 1 },
				{ 5, 0 },
				{ 6, 0 },
				{ 5, 1 },
				{ 4, 2 },
				{ 3, 3 },
				{ 2, 4 },
				{ 1, 5 },
				{ 0, 6 },
				{ 0, 7 },
				{ 1, 6 },
				{ 2, 5 },
				{ 3, 4 },
				{ 4, 3 },
				{ 5, 2 },
				{ 6, 1 },
				{ 7, 0 },
				{ 7, 1 },
				{ 6, 2 },
				{ 5, 3 },
				{ 4, 4 },
				{ 3, 5 },
				{ 2, 6 },
				{ 1, 7 },
				{ 2, 7 },
				{ 3, 6 },
				{ 4, 5 },
				{ 5, 4 },
				{ 6, 3 },
				{ 7, 2 },
				{ 7, 3 },
				{ 6, 4 },
				{ 5, 5 },
				{ 4, 6 },
				{ 3, 7 },
				{ 4, 7 },
				{ 5, 6 },
				{ 6, 5 },
				{ 7, 4 },
				{ 7, 5 },
				{ 6, 6 },
				{ 5, 7 },
				{ 6, 7 },
				{ 7, 6 },
				{ 7, 7 }
		};


gsl::index jpeg_lite::decoder::transform::coordinate_to_zigzag(gsl::index x, gsl::index y)
{
	return zigzags[x][y];
}

std::pair<gsl::index, gsl::index> jpeg_lite::decoder::transform::zigzag_to_coordinate(gsl::index zigzag)
{
	return coordinates[zigzag];
}

int16_t jpeg_lite::decoder::transform::binary_string_to_int16(std::string_view sv)
{
	if (sv.empty())
	{
		return 0;
	}

	uint16_t raw{ 0 };
	for (index i = 0; auto c: sv)
	{
		if (c == '1')
		{
			raw |= (1 << i);
		}
		i++;
	}

	return *(int16_t*)(&raw);
}
