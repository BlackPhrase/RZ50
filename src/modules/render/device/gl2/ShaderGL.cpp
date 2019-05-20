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

#include "ShaderGL.hpp"

namespace rz::render::device
{

CShaderGL::CShaderGL(const tString &asFile, Type aeType)
{
	mnID = glCreateShader(aeType);
	
	glShaderSource(mnID, asText);
	Compile();
};

CShaderGL::~CShaderGL()
{
	glDeleteShader(mnID);
};

void CShaderGL::Bind()
{
	glUseProgram(mnProgramID);
};

/*
void CShaderGL::Unbind()
{
	glUseProgram(0);
};
*/

void CShaderGL::SetUniform4f(const char *asName, float a, float, b, float c, float d)
{
	glUniform4f(glGetUniformLocation(mnProgramID, asName), a, b, c, d); // TODO: inefficient
};

bool CShaderGL::Compile()
{
	glCompileShader(mnID);
	
	if(!glGetShader(mnID, GL_COMPILE_STATUS) == GL_FALSE)
		return false;
	
	return true;
};

}; // namespace rz::render::device