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
#pragma once

#include "types.h"

#include <utility>
#include <cstdint>
#include <string_view>
#include <bit>

#include <gsl/gsl>

namespace jpeg_lite::decoder::transform
{
[[nodiscard]] FORCE_INLINE gsl::index coordinate_to_zigzag(gsl::index x, gsl::index y);

[[nodiscard]] FORCE_INLINE std::pair<gsl::index, gsl::index> zigzag_to_coordinate(gsl::index zigzag);

[[nodiscard, maybe_unused]] int16_t binary_string_to_int16(std::string_view sv);

[[nodiscard]] static inline FORCE_INLINE constexpr int16_t value_category(int16_t val)
{
	if (val == 0x0000)
		return 0;
	return std::bit_width(static_cast<uint16_t>(val > 0 ? val : -val));
}
}