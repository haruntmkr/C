// kuyrukcliste.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>

using namespace std;
#define max 10
struct Kuyruk
	{
		int D[max];
		int top;
		int KB;
		int KS;
	};
typedef struct Kuyruk kuyruk;
void ekle(kuyruk *k,int veri)
{
	if(k->top>=max)
	{
		return;
	}
	if(k->KB==-1)
	{
	k->KB=0;
	}
	if(k->KS==max-1)
	{
		k->KS=0;
	}
	else
	{
		k->KS++;
	}
	k->D[k->KS]=veri;
	k->KS++;
	k->top++;
}
void sil(kuyruk *k)
{
	if(k->top<=0)
	{
	return;
	}
	cout<<"Cikarilan eleman= "<<k->D[k->KB]<<endl;
	if(k->KB==max)
	k->KB=0;
	else
	k->KB++;
	k->top--;
	if(k->top<=0)
	{
	k->KB=-1;
	k->KS=-1;
	}
}
void yazdir(kuyruk *k)//çalýþmýyor. lakin bunu çalýþtýrmak gerek.
{
	if(k->top<=0)
	{
	return;
	}
	cout<<endl<<"Dairesel Kuyruk Baþtan Sona =";
	for(int i=0;i<k->top;i++)
	{
	cout<<" "<<k->D[i];
	
	}



}






//-------------------------------------kaydýrmalý kuyruk
/*struct Kuyruk
{
	int top;
	int D[max];


};
typedef struct Kuyruk kuyruk;
*/



/*
void ekle(kuyruk *k,int veri)
{
	if(k->top>max)
	{
	cout<<"kuyruk dolu";
	}
	k->D[k->top]=veri;
	k->top++;
}
void cikar(kuyruk* k){
	if(k->top<=0)
		cout<<"kuyruk bos"<<endl;
	cout<<"cikarilan eleman= "<<k->D[0]<<endl;
	
	for(int i=0;i<k->top-1;i++)
	{
		k->D[i]=k->D[i+1];

	
	}
	k->top--;

}

void yazdir(kuyruk *k)
{
	cout<<endl<<"Kuyruk Bastan Sona= ";
	for(int i=0;i<k->top;i++)
	{
		cout<<" "<<k->D[i];
	}
	cout<<endl;
}

*/
///----------------------------------------------------kaydýrmalý kuyruk sonu
int _tmain(int argc, _TCHAR* argv[])
{
	
	kuyruk k;
	k.KB=-1;
	k.KS=-1;
	k.top=0;
	ekle(&k,7);
	ekle(&k,2);
	ekle(&k,1);
	ekle(&k,8);
	ekle(&k,6);
	ekle(&k,9);
	yazdir(&k);

	/*kuyruk ku;
	ku.top=0;
	ekle(&ku,3);
	ekle(&ku,7);
	ekle(&ku,1);
	ekle(&ku,2);
	ekle(&ku,4);
	yazdir(&ku);
	cikar(&ku);
	yazdir(&ku);
	cikar(&ku);
	yazdir(&ku);
	cikar(&ku);
	yazdir(&ku);*/
	return 0;
}

