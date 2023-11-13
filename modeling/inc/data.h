#pragma once

class topology
{
public:


private:

};


class point
{
public:
	float pos[3];
	float normal[3];
	float color[3];

	void setpos(float x, float y, float z) {
		pos[0] = x;
		pos[1] = y;
		pos[2] = z;
	}
	void setcolor(float x, float y, float z) {
		color[0] = x;
		color[1] = y;
		color[2] = z;
	}
	
	float distance(point p1);
	
private:

};


class vertex:public topology {
public:
	
	point entpoint;

	topology* coedge;
	vertex* prevertex;
	vertex* nextvertex;

	void setpoint(point p) {
		entpoint = p;
	}

private:
	
public:

	vertex() = default;
};

class coedge :public topology {
public:
	

	coedge* precoedge;
	coedge* nextcoedge;

	topology* m_edge;

	vertex* startvertex;
	vertex* endvertex;

	topology* m_loop;
private:

public:

	coedge() = default;
};

class edge :public topology {
public:
	

	edge* preedge;
	edge* nextedge;

	coedge* m_coedge1;
	coedge* m_coedge2;

private:

public:

	edge() = default;
};


class loop :public topology
{
public:

	loop* preloop;
	loop* nextloop;

	topology* m_face;

	coedge* m_coedge;


private:


public:

	loop() = default;
};

class face :public topology
{
public:
	

	topology* m_body;

	face* preface;

	face* nextface;

	loop* m_loop;

private:


public:

	face() = default;
};



class body {
public:
	
	
	body* prebody;
	body* nectbody;

	face* m_face;

	vertex* m_vertex;

private:

public:

	body() = default;
};

bool operator!=(point p1, point p2);

