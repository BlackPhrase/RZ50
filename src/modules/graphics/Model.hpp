/// @file

#pragma once

#include <vector>

namespace rz
{

struct ITexture;

class CMesh;
using tMeshVec = std::vector<CMesh*>;

class CModel
{
public:
	CModel();
	~CModel();
	
	void SetTexture(ITexture *apTexture);
	ITexture *GetTexture() const;
	
	CMesh *GetMesh(uint anIndex) const;
private:
	tMeshVec mvMeshes;
};

}; // namespace rz