#include <iostream>
using namespace std;
struct Dugum {
	int veri;
	struct Dugum *sol,*sag;
};
void ekranaYaz(Dugum *dugumBasi){
	while(dugumBasi!=NULL){
		cout<<dugumBasi->veri<<endl;
		dugumBasi=dugumBasi->sag;
	}		
};
void sonaEkle(Dugum *pBas, Dugum *pY){
	while(pBas->sag!=NULL){
		pBas=pBas->sag;
	};
	pBas->sag=pY;
	pY->sol=pBas;
	pY->sag=NULL;	
};
Dugum *sondanCikar(Dugum *pBas){
	while(pBas->sag->sag!=NULL){
		pBas=pBas->sag;	}
	Dugum *pTemp=pBas->sag;
	pBas->sag=NULL;
	return pTemp;
	}
int main(){
	Dugum *p1=new Dugum();
	Dugum *p2=new Dugum();
	Dugum *p3=new Dugum();
	p1->veri=12;
	p2->veri=23;
	p3->veri=32;
	p1->sol=NULL;
	p1->sag=p2;
	p2->sol=p1;
	p2->sag=p3;
	p3->sol=p2;
	p3->sag=NULL;
	cout<<"Dugumumuzdeki veriler:"<<endl;
	ekranaYaz(p1);
	Dugum *p4=new Dugum();
	p4->veri=25;
	sonaEkle(p1,p4);
	cout<<"Sona eklenen veri sonucu olusan liste:"<<endl;
	ekranaYaz(p1);
	sondanCikar(p1);
	cout<<"Sondan cikarilan veri sonucu olusan liste:"<<endl;
	ekranaYaz(p1);
	getchar();
	return 0;
}
