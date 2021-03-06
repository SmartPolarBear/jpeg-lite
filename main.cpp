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

#include "decoder/image.h"

#include <iostream>
#include <string>
#include <filesystem>
#include <format>

#include <argparse/argparse.hpp>

using namespace jpeg_lite::decoder;

using namespace std;

int main(int argc, char* argv[])
{
	argparse::ArgumentParser arg_parser{ "jpeg_lite" };

	arg_parser.add_argument("-i", "--image")
			.help("the JPEG image file")
			.required()
			.nargs(1);

	try
	{
		arg_parser.parse_args(argc, argv);
	}
	catch (const std::runtime_error& err)
	{
		cerr << err.what() << endl;
		cerr << arg_parser;
		return 1;
	}

	const auto img = arg_parser.get<string>("--image");

	if (!filesystem::exists(img))
	{
		cerr << format("{} does not exist.", img) << endl;
		return 1;
	}


	jpeg_image image{ img };

	return 0;
}
