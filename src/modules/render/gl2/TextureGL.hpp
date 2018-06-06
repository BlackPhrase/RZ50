/* 
 * This file is part of RZ Engine
 * Copyright (c) 2017-2018 BlackPhrase
 * 
 * This program is free software: you can redistribute it and/or modify  
 * it under the terms of the GNU General Public License as published by  
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "render/ITexture.hpp"

namespace rz
{

class CTextureGL final : public ITexture
{
public:
	CTextureGL() = default; //{glGenTextures(1, &mnID);}
	~CTextureGL() = default; //{glDeleteTextures(1, &mnID);}
	
	void Bind() override;
	void Unbind() override;
	
	unsigned int GetID() const override {return mnID;}
	
	int GetWidth() const override {return mnWidth;}
	int GetHeight() const override {return mnHeight;}
	
	int GetBPP() const override {return mnBPP;}
private:
	unsigned int mnID{0};
	int mnWidth{0};
	int mnHeight{0};
	int mnBPP{0};
};

}; // namespace rz