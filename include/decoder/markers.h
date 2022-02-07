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
// Created by cleve on 2/2/2022.
//

#pragma once

namespace jpeg_lite::decoder
{
// JPEG-JFIF File Markers
//
// Refer to ITU-T.81 (09/92), page 32
enum jfif_markers
{
	JFIF_MARKERS_MIN = 0xFFC0 - 1,

	JFIF_SOF0 = 0xFFC0, // Start of Frame 0, Baseline DCT
	JFIF_SOF1 = 0xFFC1, // Start of Frame 1, Extended Sequential DCT
	JFIF_SOF2 = 0xFFC2, // Start of Frame 2, Progressive DCT
	JFIF_SOF3 = 0xFFC3, // Start of Frame 3, Lossless (Sequential)
	JFIF_DHT = 0xFFC4, // Define Huffman Table
	JFIF_SOF5 = 0xFFC5, // Start of Frame 5, Differential Sequential DCT
	JFIF_SOF6 = 0xFFC6, // Start of Frame 6, Differential Progressive DCT
	JFIF_SOF7 = 0xFFC7, // Start of Frame 7, Differential Loessless (Sequential)
	JFIF_SOF9 = 0xFFC9, // Extended Sequential DCT, Arithmetic Coding
	JFIF_SOF10 = 0xFFCA, // Progressive DCT, Arithmetic Coding
	JFIF_SOF11 = 0xFFCB, // Lossless (Sequential), Arithmetic Coding
	JFIF_SOF13 = 0xFFCD, // Differential Sequential DCT, Arithmetic Coding
	JFIF_SOF14 = 0xFFCE, // Differential Progressive DCT, Arithmetic Coding
	JFIF_SOF15 = 0xFFCF, // Differential Lossless (Sequential), Arithmetic Coding
	JFIF_SOI = 0xFFD8, // Start of Image
	JFIF_EOI = 0xFFD9, // End of Image
	JFIF_SOS = 0xFFDA, // Start of Scan
	JFIF_DQT = 0xFFDB, // Define Quantization Table
	JFIF_APP0 = 0xFFE0, // Application Segment 0, JPEG-JFIF Image
	JFIF_COM = 0xFFFE, // Comment

	JFIF_MARKERS_MAX
};
}

#include <magic_enum.hpp>

namespace magic_enum
{
template<>
struct customize::enum_range<jpeg_lite::decoder::jfif_markers>
{
	static constexpr int min = (int)jpeg_lite::decoder::jfif_markers::JFIF_MARKERS_MIN;
	static constexpr int max = (int)jpeg_lite::decoder::jfif_markers::JFIF_MARKERS_MAX;
};
}

#include <string>
#include <format>

namespace std
{
template<>
struct std::formatter<jpeg_lite::decoder::jfif_markers> : std::formatter<std::string>
{
	auto format(jpeg_lite::decoder::jfif_markers m, format_context& ctx)
	{
		return formatter<string>::format(std::string{ magic_enum::enum_name(m) }, ctx);
	}
};
}