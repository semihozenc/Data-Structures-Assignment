#include <iostream>
using namespace std;
class Dugum {
	public:
		int veri;
		Dugum *pSonraki;
	public:
		Dugum(){
			pSonraki=NULL;
		}
};
void sonaEkle(Dugum *pBas, Dugum *pY){
	while(pBas->pSonraki!=NULL){
		pBas=pBas->pSonraki;	}
	pBas->pSonraki=pY;
};
Dugum *sondanCikar(Dugum *pBas){
	while(pBas->pSonraki->pSonraki!=NULL){
		pBas=pBas->pSonraki;	}
	Dugum *pTemp=pBas->pSonraki;
	pBas->pSonraki=NULL;
	return pTemp;
};
void arayaEkle(Dugum *pBas, Dugum *pY, int index){
	for(int i=0; i<(index-2); i++)
		pBas=pBas->pSonraki;
	pY->pSonraki=pBas->pSonraki;
	pBas->pSonraki=pY;
};
Dugum *aradanCikar(Dugum *pBas,int index){
	for(int i=0; i<index-2;i++)
		pBas=pBas->pSonraki;
	Dugum *pTemp=pBas->pSonraki;
	pBas->pSonraki=pBas->pSonraki->pSonraki;
	return pTemp;
};
void ekranaYaz(Dugum *dugumBasi){
	while(dugumBasi!=NULL){
		cout<<dugumBasi->veri<<endl;
		dugumBasi=dugumBasi->pSonraki;	
	};
};
int main(){
	Dugum *p1=new Dugum();
	Dugum *p2=new Dugum();
	Dugum *p3=new Dugum();
	p1->veri=12;
	p2->veri=23;
	p3->veri=32;
	p1->pSonraki=p2;
	p2->pSonraki=p3;	
	cout<<"Dugumumuzdeki veriler:"<<endl;
	ekranaYaz(p1);
	Dugum *p4=new Dugum();
	p4->veri=25;
	sonaEkle(p1,p4);
	cout<<endl<<"Sona eklenen veri sonucu olusan liste:"<<endl;
	ekranaYaz(p1);
	sondanCikar(p1);
	cout<<endl<<"Sondan cikarilan veri sonucu olusan liste:"<<endl;
	ekranaYaz(p1);
	Dugum *p5=new Dugum();
	p5->veri=1000;
	arayaEkle(p1,p5,3);
	cout<<"\nAraya eklenen veri sonucu olusan liste:"<<endl;
	ekranaYaz(p1);
	aradanCikar(p1,2);
	cout<<"\nAradan cikarilan veri sonucu liste:"<<endl;
	ekranaYaz(p1);
	getchar();
	return 0;
}
