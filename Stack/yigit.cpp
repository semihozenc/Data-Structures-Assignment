#include <iostream>
#include <cstdlib>
using namespace std;
struct Node {
   int veri;
   struct Node *sonraki;
};
struct Node* top = NULL;
void push(int val) {
   struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
   newnode->veri = val;
   newnode->sonraki = top;
   top = newnode;
}
void pop() {
   if(top==NULL)
   cout<<"Yigit Tasmasi"<<endl;
   else {
      cout<<"Eklenen eleman "<< top->veri <<endl;
      top = top->sonraki;
   }
}
void display() {
   struct Node* ptr;
   if(top==NULL)
   cout<<"Yigit Bos";
   else {
      ptr = top;
      cout<<"Yigit Elemanlari: ";
      while (ptr != NULL) {
         cout<< ptr->veri <<" ";
         ptr = ptr->sonraki;
      }
   }
   cout<<endl;
}
int main() {
   int ch, val;
   cout<<"1) Yigita ekle"<<endl;
   cout<<"2) Yigittan cikar"<<endl;
   cout<<"3) Yigittaki Elemanlar"<<endl;
   cout<<"4) Cikis"<<endl;
   do {
      cout<<"Sec: "<<endl;
      cin>>ch;
      switch(ch) {
         case 1: {
            cout<<"Eklenecek degeri gir:"<<endl;
            cin>>val;
            push(val);
            break;
         }
         case 2: {
            pop();
            break;
         }
         case 3: {
            display();
            break;
         }
         case 4: {
            cout<<"Cikis"<<endl;
            break;
         }
         default: {
            cout<<"Gecersiz giris"<<endl;
         }
      }
   }while(ch!=4);
   return 0;
}
