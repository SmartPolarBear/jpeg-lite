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
// Created by cleve on 2/4/2022.
//

#include "decoder/image.h"
#include "decoder/segments.h"

#include <iostream>
#include <fstream>
#include <format>
#include <stdexcept>
#include <filesystem>
#include <ranges>
#include <span>

#include <gsl/gsl>

using namespace jpeg_lite::decoder;

using namespace std;
using namespace gsl;
using namespace std::views;

jpeg_lite::decoder::jpeg_image::jpeg_image(std::string_view file)
		: size_(filesystem::file_size(file.data())),
		  data_(make_unique<char[]>(size_))
{
	fstream fs{ file.data(), ios::in | ios::binary };

	if (!fs.is_open())
	{
		throw invalid_argument{
				std::format("{} cannot be opened", file) };
	}

	fs.seekg(0);
	fs.read(data_.get(), size_);

	if (!fs)
	{
		throw invalid_argument{
				std::format("{} cannot be read", file) };
	}

	parse_segments();
}

void jpeg_lite::decoder::jpeg_image::parse_segments()
{
	gsl::index pos = 0;
	while (pos < size_)
	{
		auto h = reinterpret_cast<segment_header*>(data_.get() + pos);
		clog << to_string(*h);

		switch (marker_of(*h))
		{
		case JFIF_SOF0:
			break;
		case JFIF_SOF1:
			break;
		case JFIF_SOF2:
			break;
		case JFIF_SOF3:
			break;
		case JFIF_DHT:
			parse_huffman(pos);
//			pos += length_of(*h);
			break;
		case JFIF_SOF5:
			break;
		case JFIF_SOF6:
			break;
		case JFIF_SOF7:
			break;
		case JFIF_SOF9:
			break;
		case JFIF_SOF10:
			break;
		case JFIF_SOF11:
			break;
		case JFIF_SOF13:
			break;
		case JFIF_SOF14:
			break;
		case JFIF_SOF15:
			break;
		case JFIF_SOI:
			break;
		case JFIF_EOI:
			break;
		case JFIF_SOS:
			break;
		case JFIF_DQT:
			break;
		case JFIF_APP0:
			break;
		case JFIF_COM:
			break;
		default:
			pos += length_of(*h);
			break;
		}

		pos += length_of(*h);
	}
}

void jpeg_image::parse_huffman(gsl::index pos)
{
	const auto dht = reinterpret_cast<dht_segment*>(data_.get() + pos);
	Expects(marker_of(dht->header) == JFIF_DHT);

	const auto flags = value_of(dht->flags);
	clog << std::format("Parsing DHT {},{}\nCounts:\n",
			flags & 0xF,
			((flags >> 4) & 0b1) ? "AC" : "DC");

	size_t total{ 0 };
	for (const auto c:
			dht->counts | value_transform)
	{
		clog << std::format("{} ", c);
		total += c;
	}
	clog << "\nElements:\n";

	std::span<uint8_t> symbols{ dht->symbols, total };
	for (const auto symbol: symbols | value_transform)
	{
		clog << std::format("{} ", symbol);
	}
	clog << "\n";
}
