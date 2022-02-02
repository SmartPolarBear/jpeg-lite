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
	JFIF_BYTE_0 = 0x00,
	
	JFIF_BYTE_FF = 0xFF, // All markers start with this as the MSB
	JFIF_SOF0 = 0xC0, // Start of Frame 0, Baseline DCT
	JFIF_SOF1 = 0xC1, // Start of Frame 1, Extended Sequential DCT
	JFIF_SOF2 = 0xC2, // Start of Frame 2, Progressive DCT
	JFIF_SOF3 = 0xC3, // Start of Frame 3, Lossless (Sequential)
	JFIF_DHT = 0xC4, // Define Huffman Table
	JFIF_SOF5 = 0xC5, // Start of Frame 5, Differential Sequential DCT
	JFIF_SOF6 = 0xC6, // Start of Frame 6, Differential Progressive DCT
	JFIF_SOF7 = 0xC7, // Start of Frame 7, Differential Loessless (Sequential)
	JFIF_SOF9 = 0xC9, // Extended Sequential DCT, Arithmetic Coding
	JFIF_SOF10 = 0xCA, // Progressive DCT, Arithmetic Coding
	JFIF_SOF11 = 0xCB, // Lossless (Sequential), Arithmetic Coding
	JFIF_SOF13 = 0xCD, // Differential Sequential DCT, Arithmetic Coding
	JFIF_SOF14 = 0xCE, // Differential Progressive DCT, Arithmetic Coding
	JFIF_SOF15 = 0xCF, // Differential Lossless (Sequential), Arithmetic Coding
	JFIF_SOI = 0xD8, // Start of Image
	JFIF_EOI = 0xD9, // End of Image
	JFIF_SOS = 0xDA, // Start of Scan
	JFIF_DQT = 0xDB, // Define Quantization Table
	JFIF_APP0 = 0xE0, // Application Segment 0, JPEG-JFIF Image
	JFIF_COM = 0xFE, // Comment
};
}
