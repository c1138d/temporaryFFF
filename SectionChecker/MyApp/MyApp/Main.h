// Main.h
#ifndef INCLUDED_MAIN
#define INCLUDED_MAIN

#include <vector>
#include <string>
using namespace std;         //  –¼‘O‹óŠÔŽw’è

typedef struct
{
	double dX;
	double dY;
	double dZ;
}ST_XYZ;

typedef struct
{
	int m_no;
	string m_strCatL;
	string m_strCmt;
}ST_S1_CONTENT;

typedef struct
{
	int m_no;
	string m_strCatL;
	vector<ST_XYZ> m_pdOver;
	string m_strCmt;
}ST_S2_CONTENT;


#endif