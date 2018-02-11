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