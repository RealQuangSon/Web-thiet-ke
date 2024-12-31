#include <string.h>
#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;
class Hoadon{
    private:
        int mahoadon;
        char tenhang[100];
        int tienban;
        static int tshd;
        static int tstb;
    public:
        Hoadon(){
            tshd++;
        }
        ~Hoadon(){
            tshd--;
            tstb-=tienban;
        }
        void nhaphoadon(){
            cout<<endl<<"Nhap so hoa don: ";cin>>mahoadon;
            cout<<endl<<"Nhap ten hang: ";cin.ignore(); cin.get(tenhang,100);
            cout<<endl<<"Nhap tien ban: ";cin>>tienban;tstb+=tienban;
        }
        void inhoadon(){
            cout<<setw(10)<<mahoadon<<setw(20)<<tenhang<<setw(10)<<tienban<<endl;
        }
        static void ints(){
            cout<<endl<<"Tong so hoa don: "<<tshd<<" Tong so tien ban: "<<tstb;
        }
        int tienbani(){
            return tienban;
        }
        friend void hoanvi(Hoadon &i,Hoadon &j){
            Hoadon tg ;
            swap(i.mahoadon,j.mahoadon);
            swap(i.tenhang,j.tenhang);
            swap(i.tienban,j.tienban);
        }
        Hoadon *next;
};
int Hoadon::tshd=0;
int Hoadon::tstb=0;
int main()
{
    Hoadon *head = NULL,*cuoi=NULL,*node=NULL;
    char ok='c';
    while (ok=='c'){
        Hoadon *hd=new Hoadon;
        hd->nhaphoadon();
        hd->next=NULL;
        if(head==NULL){
            head=hd;
            cuoi=hd;
        }
        else{
            cuoi->next=hd;
            cuoi=hd;
        }
        cout<<"Nhap tiep bam c: "<<endl;
        ok=getch();
        
    }
    Hoadon *duyet=head;
    while(duyet!=NULL){
        duyet->inhoadon();
        duyet=duyet->next;
    }
    Hoadon::ints();
    Hoadon *i,*j;
    i=head;
    while(i!=NULL){
        j=i->next;
        while(j!=NULL){
            if(i->tienbani()<j->tienbani()){
                hoanvi(*i,*j);
            }
            j=j->next;
        }
        i=i->next;
    }
    cout<<"Danh sach giam dan: "<<endl;
    duyet=head;
    while(duyet!=NULL){
        duyet->inhoadon();
        duyet=duyet->next;
    }
    getch();
    return 0;
}
