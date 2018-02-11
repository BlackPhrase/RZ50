#include <GL/gl.h>
#include "TextureGL.hpp"

namespace rz
{

void CTextureGL::Bind()
{
	glBindTexture(GL_TEXTURE_2D, mnID);
};

void CTextureGL::Unbind()
{
	glBindTexture(GL_TEXTURE_2D, 0);
};

}; // namespace rz