#pragma once
#include"savekit.h"
#include"loadkit.h"
#include"InArray.h"
#include<string.h>
#include"Phi.h"
#include"BaseClass.h"
#include"parmaters.h"
#include<fstream>
#include<iostream>
using namespace std;
class CSA
{
public:
	//����n��ʾ��С,SA��ʾ��׺���飬sourcefile��ʾԭ�ļ���
	//������¼����ʱ�䣬����L��ʾPsi�Ĳ���������D��ʾSA�Ĳ�������
	CSA(){};
	CSA(const char * sourcefile,i32 L=128,i32 D=32,i32 phitype=0);
	bool Existential(const char * Pattern);
	void Counting(const char * Pattern,int &num);
	void Locating(const char * Pattern,i32 &num,i32 *&pos);
	
	i32 Save(const char * indexfile);
	i32 Load(const char * indexfile);
	
	double Size();
	void Decompress(i32 i,i32 len,unsigned char *p);
	~CSA(void);

	i32 Getalphabetsize();
	i32 GetN();
private:
	CSA(const CSA &);
	CSA& operator=(const CSA & right);
	
	void CreateSupportStructer(parmaters * csa);
	
	void Enumerative1(i32 l,i32 r,i32 *&pos);
	void Enumerative2(i32 l,i32 r,i32 *&pos);
	
	i32 Inverse(i32 i);
	i32 Phi_list(i32 i);//��������Ϊi�ĺ�׺�����ĸ�list������������incode����Ϳ��Իָ�������Ϊi�ĺ�׺������ĸ�ˡ�
	i32 Character(i32 i);
	
	i32 lookup(i32 i);
	void Search(const char * Pattern,i32 & L, i32 &R);
	void Search2(const char * Pattern,i32 &L,i32 &R);
	
	uchar * Getfile(const char * filename);
	void statics(uchar *T);
	i32 blog(i32 x);
	
	i32 SL,L,D,RD;
	InArray  * SAL;
	InArray * RankL;
	i32 n; 
	i32 * code;
	i32 * incode;//��¼����Ϊi���ַ���ASSIC��
	i32 alphabetsize;
	i32 * start;
	uchar lastchar;
	Phi * Phi0;
};
