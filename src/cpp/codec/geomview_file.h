

#ifndef __geomview_file_h__
#define __geomview_file_h__

/* ----------------------------------------------------------------------- */

#include <string>
#include <iostream>
#include <stack>

#include "Tools/util_vector.h"
#include "Tools/util_hashmap.h"
#include "appe_color.h"
#include "geom_geometry.h"
#include "scne_scene.h"
#include "geom_indexarray.h"

/* ----------------------------------------------------------------------- */


GEOM_BEGIN_NAMESPACE

/* ----------------------------------------------------------------------- */

class GeomViewBuilder  {

public :
	GeomViewBuilder(std::istream& input,std::ostream& output);
	~GeomViewBuilder() {}

	ScenePtr parse();
	GeometryPtr parseGeometry();
	GeometryPtr parseGeometry(std::string& token);

	std::ostream& output() { return __output; }
	std::istream& input() { return *(__input.top()); }

	std::string readline();
	std::string processToken();
	std::string readToken();
	float readFloat();
	int readInt();

	TOOLS(Vector2) readVector2();
	TOOLS(Vector3) readVector3();
	TOOLS(Vector4) readVector4();
	TOOLS(Vector3) readVector3(int n);
	TOOLS(Vector4) readVector4(int n);
	Color4  readUColor4();
	Color3  readUColor3();
	Color4  readColor4();
	Color3  readColor3();
	Index readIndex();
	Index readColoredIndex();


	static ScenePtr Parse(const std::string& filename, std::ostream& output);
	bool pushFile(const std::string&);
	bool popFile();
	bool endFile();
	bool endObject();
	bool endListObject();

protected :


	std::stack<std::istream *> __input;
	std::ostream& __output;
	std::string __token;
	hash_map_string<GeometryPtr> __defines;
};

/* ----------------------------------------------------------------------- */

class GenericBuilder {
public :
	GenericBuilder(GeomViewBuilder& d) :
	   __data(d){}

	virtual ~GenericBuilder(){}
	virtual bool setTag(const std::string&) = 0;
	virtual GeometryPtr parse() = 0;
	virtual void clear() = 0;

protected :
	GeomViewBuilder& __data;
};

/* ----------------------------------------------------------------------- */

class GenericPointBuilder : public GenericBuilder {
public :

	GenericPointBuilder(GeomViewBuilder& d) :
	   GenericBuilder(d),
	   __normals(false),
	   __textured(false),
	   __colored(false),
	   __dim4(false){}
	virtual ~GenericPointBuilder(){}

	bool hasNormal() const { return __normals; }
	bool isTextured() const { return __textured; }
	bool hasColor() const { return __colored; }
	bool isDim4() const { return __dim4; }
	virtual void clear() {
	   __normals = false;
	   __textured = false;
	   __colored = false; 
	   __dim4 = false;
	}

protected :
	bool __normals;
	bool __textured;
	bool __colored;
	bool __dim4;
};

/* ----------------------------------------------------------------------- */

class BezBuilder : public GenericPointBuilder {

public :
	BezBuilder(GeomViewBuilder&);
	virtual ~BezBuilder(){}

	virtual bool setTag(const std::string&);
	virtual GeometryPtr parse();
	virtual void clear();

protected :

	int __Nu;
	int __Nv;
};

/* ----------------------------------------------------------------------- */

class OffBuilder : public GenericPointBuilder {

public :
	OffBuilder(GeomViewBuilder&);
	virtual ~OffBuilder(){}

	virtual bool setTag(const std::string&);
	virtual GeometryPtr parse();
	virtual void clear();

protected :
	int __n;
};
/* ----------------------------------------------------------------------- */

class GVMeshBuilder : public GenericPointBuilder {

public :
	GVMeshBuilder(GeomViewBuilder&);
	virtual ~GVMeshBuilder(){}

	virtual bool setTag(const std::string&);
	virtual GeometryPtr parse();
	virtual void clear();

protected :
	bool __grid;
	bool __uwrapped;
	bool __vwrapped;
	int __n;
};

/* ----------------------------------------------------------------------- */

class QuadBuilder : public GenericPointBuilder {

public :
	QuadBuilder(GeomViewBuilder&);
	virtual ~QuadBuilder(){}

	virtual bool setTag(const std::string&);
	virtual GeometryPtr parse();

};

/* ----------------------------------------------------------------------- */

class VectBuilder : public GenericBuilder {

public :
	VectBuilder(GeomViewBuilder&);
	virtual ~VectBuilder(){}

	virtual bool setTag(const std::string&);
	virtual GeometryPtr parse();

	bool isDim4() const { return __dim4; }
	virtual void clear() {
	   __dim4 = false;
	}

protected :

	bool __dim4;
};


/* ----------------------------------------------------------------------- */

class GVSphereBuilder : public GenericBuilder {

public :
	GVSphereBuilder(GeomViewBuilder&);
	virtual ~GVSphereBuilder(){}

	virtual bool setTag(const std::string&);
	virtual GeometryPtr parse();
	virtual void clear() {}
protected :

};


/* ----------------------------------------------------------------------- */


GEOM_END_NAMESPACE

#endif
