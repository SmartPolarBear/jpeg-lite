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

#include <string>
#include <memory>

namespace jpeg_lite::utility
{
class huffman_tree
{
public:
	huffman_tree();

private:
	class node : public std::enable_shared_from_this<node>
	{
	public:
		node() = default;

		explicit node(const std::shared_ptr<node>& parent, uint16_t value) : parent_(parent), value_(value)
		{
		}

		void insert_left(uint16_t val);
		void insert_right(uint16_t val);

		std::shared_ptr<node> right_sibling();
	private:
		uint16_t value_{ 0 };
		std::string code_{};

		std::shared_ptr<node> left_{ nullptr }, right_{ nullptr };
		std::weak_ptr<node> parent_{};
	};

	const std::shared_ptr<node> root_{ nullptr };
};
}