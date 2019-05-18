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

namespace rz
{

struct IShader
{
	///
	virtual bool LoadFromFile(const char *asFileName) = 0;
	
	/// Binds the shader
	virtual void Bind() = 0;
	//virtual void Unbind() = 0;
	
	///
	virtual void SetUniform(const char *asName, float afValue) = 0;
	
	///
	virtual bool Compile() = 0;
	
	/// @return name of the shader
	virtual const char *GetName() const = 0;

	/// Shader types
	enum class Type : int
	{
		Invalid = -1,
		
		Vertex,
		Tessellation,
		Geometry,
		Fragment
	};
	
	/// @return type of the shader
	virtual Type GetType() const = 0;
};

}; // namespace rz