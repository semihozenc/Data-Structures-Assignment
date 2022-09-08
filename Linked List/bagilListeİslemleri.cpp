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
		pBas=pBas->pSonraki;
}
pBas->pSonraki=pY;
};
Dugum *sondanCikar(Dugum *pBas){
	while(pBas->pSonraki->pSonraki!=NULL){
		pBas=pBas->pSonraki;	}
	Dugum *pTemp3=pBas->pSonraki;
	pBas->pSonraki=NULL;
	return pTemp3;
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
	Dugum *pTemp6=pBas->pSonraki;
	pBas->pSonraki=pBas->pSonraki->pSonraki;
	return pTemp6;
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
	Dugum *pTemp=p1;
	cout<<"Dugumumuzdeki veriler:"<<endl;
	while(pTemp!=NULL){            //pTemp->pSonraki yerine direkt pTemp!=NULL yazarsak son elemaný da ekrana yazdýrýrýz.
		cout<<pTemp->veri<<endl;
		pTemp=pTemp->pSonraki;
	};
	//cout<<pTemp->veri; //Son Elemaný ekrana yazdýrýyor.
	Dugum *p4=new Dugum();
	p4->veri=25;
	sonaEkle(p1,p4);
	cout<<endl<<"Eklenen veri sonucu olusan liste:"<<endl;
	Dugum *pTemp1=p1;
	while(pTemp1->pSonraki!=NULL){
		cout<<pTemp1->veri<<endl;
		pTemp1=pTemp1->pSonraki;
	};
	cout<<pTemp1->veri; //Son eleman
	sondanCikar(p1);
	cout<<endl<<"Cikarilan veri sonucu olusan liste:"<<endl;
	Dugum *pTemp4=p1;
	while(pTemp4->pSonraki!=NULL){
		cout<<pTemp4->veri<<endl;
		pTemp4=pTemp4->pSonraki;
	};
	cout<<pTemp4->veri; //Son eleman
	Dugum *p5=new Dugum();
	p5->veri=1000;
	arayaEkle(p1,p5,3);
	cout<<"\nAraya eklenen veri sonucu olusan liste:"<<endl;
	Dugum *pTemp5=p1;
	while(pTemp5!=NULL){
		cout<<pTemp5->veri<<endl;
		pTemp5=pTemp5->pSonraki;
	};
	cout<<"\nAradan cikarilan veri sonucu liste:"<<endl;
	aradanCikar(p1,3);
	Dugum *pTemp7=p1;
	while(pTemp7!=NULL){
		cout<<pTemp7->veri<<endl;
		pTemp7=pTemp7->pSonraki;
	};
	getchar();
	return 0;
}
