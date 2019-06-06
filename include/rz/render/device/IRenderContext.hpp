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

#pragma once

namespace rz::render::device
{

//struct IVertexBuffer;
//struct IIndexBuffer;
struct IBuffer; // TODO: I(Render)DataBuffer?
struct ITexture;
struct IGPUProgram;
struct IShader;

struct IRenderContext
{
	// BUFFERS
	
	///
	//virtual IVertexBuffer *CreateVertexBuffer() = 0;
	
	///
	//virtual IIndexBuffer *CreateIndexBuffer() = 0;
	
	///
	virtual IBuffer *CreateBuffer(IBuffer::Type aeType) = 0;
	
	///
	virtual void DestroyBuffer(IBuffer &aBuffer) = 0;
	
	// TEXTURES
	
	///
	virtual ITexture *CreateTexture(int anWidth, int anHeight, const unsigned char *apData) = 0;
	
	///
	virtual void DestroyTexture(ITexture &aTexture) = 0;
	
	///
	virtual void BindTexture(ITexture *apTexture, unsigned int anSlot = 0) = 0;
	
	// SHADERS
	
	///
	virtual IGPUProgram *CreateGPUProgram() = 0;
	
	///
	virtual void DestroyGPUProgram(IGPUProgram &aProgram) = 0;
	
	///
	virtual IShader *CreateShader(IShader::Type aeType, const char *asData) = 0;
	
	///
	virtual void DestroyShader(IShader &aShader) = 0;
	
	///
	virtual void UseGPUProgram(IGPUProgram *apProgram) = 0;
};

}; // namespace rz::render::device