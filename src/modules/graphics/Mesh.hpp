/// @file

#pragma once

#include <vector>
#include "Vertex.hpp"
#include "Edge.hpp"
#include "Face.hpp"

using tVertexVec = std::vector<CVertex>;
using tEdgeVec = std::vector<CEdge>;
using tFaceVec = std::vector<CFace>;

namespace rz
{

struct CVertex
{
	CVertex(const CVec3f &avPos) : mvPos(avPos){}
	
	float x, y, z;
	//CVec3f mvPos{0.0f};
};

class CMesh // : noncopyable
{
public:
	CMesh(const tVertexVec &avVertices, const tEdgeVec &avEdges, const tFaceVec &avFaces)
		: mvVertices(avVertices), mvEdges(avEdges), mvFaces(avFaces){}
	CMesh() = default;
	/*virtual*/ ~CMesh() = default;
	
	CMesh(const CMesh&) = delete;
	void operator=(const CMesh &) = delete;
	
	bool LoadFromFile(const char *asName);
	
	void Render();
private:
	tVertexVec mvVertices;
	tEdgeVec mvEdges;
	tFaceVec mvFaces;
	
	iVertexBuffer *mpVertBuff{nullptr};
};

class CMeshRenderer
{
public:
	CMeshRenderer() = default;
	~CMeshRenderer() = default;
	
	void Render(const CMesh &apMesh);
};

}; // namespace rz