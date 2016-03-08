#include"stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
struct bagli
{
	int veri;
	bagli *next;
	bagli *previous;
};
typedef struct bagli LL;
void s_ekle(LL **B,int veri)//sona ekle
{
	LL *yeni=(LL *)malloc(sizeof(LL));

	yeni->veri=veri;
	yeni->next=NULL;
	yeni->previous=NULL;
	if (*B==NULL)
	{
		*B=yeni;
		return;
	}
	LL *son=*B;//gelen listeyi sona eşitlemiş. Aynı pTemp mantığındaki gibi. 
	while(son)
	{
		if(son->next==NULL) 	
		{
			son->next = yeni;
			yeni->previous=son;
			return;
		}
		son = son->next;
	}
}
void o_ekle(LL **B,int veri,int index)//seçimli ortadan ekle
{
	LL* pTemp=*B;

	LL *yeni=(LL*)malloc(sizeof(LL));
	yeni->veri=veri;
	while(pTemp->veri!=index)
		pTemp=pTemp->next;
	pTemp->next->previous=yeni;
	yeni->next=pTemp->next;//listenin bşlangıç adresi eklendi
	pTemp->next=yeni;
    yeni->previous=pTemp;
	
}

void szo_ekle(LL **B,int veri)//3. elemandan sonra seçimsiz bir şekilde ortadan ekle
{
	LL* pTemp=*B;

	LL *yeni=(LL*)malloc(sizeof(LL));
	yeni->veri=veri;
	int i=2;
	while(i>0){
		pTemp=pTemp->next;
		i--;
	}

	pTemp->next->previous=yeni;
	yeni->next=pTemp->next;//listenin bşlangıç adresi eklendi
	pTemp->next=yeni;
    yeni->previous=pTemp;
	
}




void yazdir(LL **B)
{
	LL *son = *B;
	printf("####################################\n\n\n");
	while(son) 
	{
		printf("Dugum Bilgileri------------------------\n");
		printf("Adres=  %d ",son);
		printf("Veri= %d\n",son->veri);
		printf("Sonraki Adres ->next= %d\n",son->next);
		printf("Onceki Adres ->previous= %d\n",son->previous);
		printf("\n");
		son=son->next;
		
			
	}
	printf("\n");
}






void o_cikar(LL **B,int index)//seçimli ortadan çıkar
{
	if(B==NULL)
		return;
	LL *pTemp=*B;
	while(pTemp->veri!=index)
		pTemp=pTemp->next;

	pTemp->previous->next=pTemp->next;
	pTemp->next->previous=pTemp->previous;
	
	delete pTemp;
	
}
void szo_cikar(LL **B)//seçimsiz 3.düğümü ortadan çıkar
{
	if(B==NULL)
		return;
	LL *pTemp=*B;
	int i=2;
	while(i>0){
		pTemp=pTemp->next;//Döngünün 2 sefer dönmesi 3. elemana ulaşmasına yeterlidir. ptemp(5) -- ptemp->next(10)---ptemp-next(15) Yazdığım üç eleman var ve döngüye bunlar girer 15 te döngü durur.
		//Döngü ptemp->next ile döndüğü için böyledir ve ptempte bir eleman vardır. 
		i--;	
	}
	pTemp->previous->next=pTemp->next;
	pTemp->next->previous=pTemp->previous;
	
	delete pTemp;
	
}

void s_cikar(LL **B)//sondan çıkar
{
	if(B==NULL)
		return;
	LL *son=*B;
	LL *tmp;
	while(son) 
	{
		if(son->next->next==NULL) 	
		{
			tmp=son->next->next;//burada bir yanlışlık var son->next nin silinmesi gerekiyor.
			son->next=NULL;
			delete tmp;

		}
		son = son->next;
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	LL *liste=NULL;
	printf("\n\nListenin Baslangic Adresi: %d\n",&liste);
	s_ekle(&liste,5);
	s_ekle(&liste,10);
	s_ekle(&liste,15);
	s_ekle(&liste,25);
	s_ekle(&liste,35);
	o_ekle(&liste,3,15);
	yazdir(&liste);
	o_cikar(&liste,25);
	yazdir(&liste);
	szo_cikar(&liste);
	yazdir(&liste);


	/*o_cikar(&liste);
	yazdir(liste);
	o_ekle(&liste,9);
	yazdir(liste);
	s_ekle(&liste,99);
	yazdir(liste);
	s_ekle(&liste,999);
	yazdir(liste);
	s_cikar(&liste);
	yazdir(liste);*/
	getchar();
	return 0;
}
