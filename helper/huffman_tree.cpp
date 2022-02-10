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

#include <stdexcept>
#include <gsl/gsl>

using namespace jpeg_lite::utility;

void jpeg_lite::utility::huffman_tree::node::insert_left()
{
	if (left_)
	{
		throw std::runtime_error("Already have left child");
	}

	left_ = std::make_shared<huffman_tree::node>(shared_from_this());
	left_->code_.append("0");
}

void jpeg_lite::utility::huffman_tree::node::insert_right()
{
	if (right_)
	{
		throw std::runtime_error("Already have right child");
	}

	right_ = std::make_shared<huffman_tree::node>(shared_from_this());
	right_->code_.append("1");
}

std::shared_ptr<huffman_tree::node> jpeg_lite::utility::huffman_tree::node::right_sibling()
{
	auto pa = parent_.lock();

	if (pa && pa->left_.get() == this)
	{
		return pa->right_;
	}

	int level = 0;
	auto iter = shared_from_this();
	while (iter->parent_.lock() && iter->parent_.lock()->right_ == iter)
	{
		iter = iter->parent_.lock();
		level++;
	}

	if (!iter->parent_.lock()) // parent
	{
		return nullptr;
	}

	while (level > 0)
	{
		iter = iter->left_;
		level--;
	}

	return iter;
}

void huffman_tree::node::complete_children()
{
	insert_left();
	insert_right();
}

jpeg_lite::utility::huffman_tree::huffman_tree(std::span<size_type> size, std::span<value_type> values)
		: root_(std::make_shared<node>(nullptr))
{
	root_->insert_left();
	root_->insert_right();

	auto left_most = root_->left_;

	for (size_t consumed = 0; const auto s: size)
	{
		if (!s)
		{
			for (auto iter = left_most; iter; iter = iter->right_sibling())
			{
				iter->complete_children();
				left_most = left_most->left_;
			}
		}
		else
		{
			std::span<value_type> val = { values.data() + consumed, s };
			for (const auto v: val)
			{
				left_most->value_ = v;
				left_most = left_most->right_sibling();
			}

			left_most->complete_children();

			auto iter = left_most->right_sibling();
			left_most = left_most->left_;
			while (iter)
			{
				iter->complete_children();
				iter = iter->right_sibling();
			}
		}
		consumed += s;
	}
}

std::optional<uint16_t> huffman_tree::decode(std::span<value_type> code)
{
	Expects(!code.empty());
	auto iter = root_;
	for (gsl::index i{ 0 }; const auto c : code){
		auto bit = ((c >> i) & 1);
		if (bit)
		{
			iter = iter->left_;
		}
		else
		{
			iter = iter->right_;
		}
		i = (i + 1) % 16;
	}
	Ensures(iter);
	return iter->value_;
}

