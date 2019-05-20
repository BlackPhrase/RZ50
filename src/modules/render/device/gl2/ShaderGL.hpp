/* 
 * This file is part of RZ Engine
 * Copyright (c) 2019 BlackPhrase
 * 
 * This program is free software: you can redistribute it and/or modify  
 * it under the terms of the GNU Lesser General Public License as published by  
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License 
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

/// @file

#pragma once

#include "render/IShader.hpp"

namespace rz::render::device
{

class CShaderGL final : public IShader
{
public:
	CShaderGL(const tString &asFile, Type aeType);
	~CShaderGL();
	
	void Bind() override;
	//void Unbind() override;
	
	void SetUniform4f(const char *asName, float a, float, b, float c, float d) override;
private:
	void Create();
	void Parse();
	void Compile();
	
	GLuint mnID{0};
};

}; // namespace rz::render::device