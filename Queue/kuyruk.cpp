//B200109008 Semih Özenç
#include<iostream>
using namespace std;
struct eleman{
  int veri;
  eleman* sonraki;
};
eleman *son = new eleman;
int kuyrukboyutu = 0;
enqueue(int data)
{
  eleman* yeni = new eleman;
  yeni->veri = data;
  if(kuyrukboyutu==0)
  {
    yeni->sonraki = NULL;
  }
  else
  {
    yeni->sonraki = son;
  }
  son = yeni;
  kuyrukboyutu++;
  cout<<data<<" eklendi. Kuyruk boyutu: "<<kuyrukboyutu<<endl;
}
dequeue()
{
  if(kuyrukboyutu>0)
  {
    eleman *ptr = son;
    for(int i=1;i<kuyrukboyutu;i++)
    {
      ptr = ptr->sonraki;
    }
    cout<<ptr->veri<<" kuyruktan cikti."<<endl;
    ptr->sonraki = NULL;
    kuyrukboyutu--;
  }
  else
  {
    cout<<"kuyruk zaten bos!"<<endl;
  }
}
yazdir()
{
  eleman *ptr = son;
  cout<<"Kuyruk son durumu:"<<endl;
  for(int i=1;i<=kuyrukboyutu;i++)
  {
    cout<<i<<". eleman: "<<ptr->veri<<endl;
    ptr = ptr->sonraki;
  }
}
main()
{
  enqueue(15);     
  enqueue(21);  
  enqueue(12);    
  dequeue();      
  enqueue(33); 
  dequeue();    
  yazdir();        
}
