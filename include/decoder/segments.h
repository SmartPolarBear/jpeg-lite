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
#pragma once

#include "decoder/markers.h"

#include <type_traits>
#include <format>
#include <cstdint>


namespace jpeg_lite::decoder
{

#pragma pack(push, 1)
struct segment_header
{
	uint16_t marker;
	uint16_t length;
};
#pragma pack(pop)

std::string to_string(const jpeg_lite::decoder::segment_header& seg)
{
	return std::format("<Segment {}, length {}>\n", static_cast<jfif_markers>(seg.marker), seg.length);
}

static_assert(std::is_standard_layout_v<segment_header>);
static_assert(sizeof(segment_header) == 4);

}

