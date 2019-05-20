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

#include "GPUProgramGL.hpp"

CGPUProgramGL::CGPUProgramGL()
{
	mnID = glCreateProgram();
};

CGPUProgramGL::~CGPUProgramGL()
{
	glDeleteProgram(mnID);
};

void CGPUProgramGL::AttachShader(IShader &aShader)
{
	glAttachShader(mnID, aShader.GetID());
};

bool CGPUProgramGL::Link()
{
	glLinkProgram(mnID);
	
	if(glGetProgram(mnID, GL_LINK_STATUS) == GL_FALSE)
		return false;
	
	return true;
};

void CGPUProgramGL::Bind()
{
	glUseProgram(mnID);
};