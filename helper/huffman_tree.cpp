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

#include "helper/huffman_tree.h"

using namespace jpeg_lite::utility;

jpeg_lite::utility::huffman_tree::huffman_tree()
		: root_(std::make_shared<node>(nullptr, 0))
{
}

void jpeg_lite::utility::huffman_tree::node::insert_left(uint16_t val)
{

}

void jpeg_lite::utility::huffman_tree::node::insert_right(uint16_t val)
{

}

std::shared_ptr<huffman_tree::node> jpeg_lite::utility::huffman_tree::node::right_sibling()
{
	return std::shared_ptr<node>();
}
