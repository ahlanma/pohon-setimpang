 #include <iostream>
#include <iomanip>
#include <conio.h>
#include <stdlib.h>
using namespace std;


int tabel() {
	int tabel;
 	for(tabel=0;tabel<=63;tabel++) {
  		cout<<"-";
 	}
 	cout<<endl;
}


void header() {
 	tabel();
 	cout<<" NO   NIM        ALGO        MPP        PTI        RATA - RATA"<<endl;
 	tabel();
}


int main() {
 
 	int no[100];
 	int nim[100];
 	int algo[100],mpp[100],pti[100];
 	int save,print;
 	int data_count;
 	float sum_algo=0,sum_mpp=0,sum_pti=0;
 	float avg_algo,avg_mpp,avg_pti;
 	float avg_perdata[100],sum_perdata[100];
 	int jumlah_halaman,akhir,nav,mulai,sisa,page=1;
 	char move; 

 	cout<<"===================="<<endl;
 	cout<<"|| PROGRAM PAGING ||"<<endl;
 	cout<<"===================="<<endl;
 	cout<<"INPUT DATA : ";
 	cin>>data_count;
 	tabel();

 	for(save=0;save<data_count;save++) {
  		cout<<"Input NIM : ";
  		cin>>nim[save];
  		cout<<"Input ALGO : ";
  		cin>>algo[save];
  		cout<<"Input  MPP : ";
  		cin>>mpp[save];
  		cout<<"Input  PTI : ";
  		cin>>pti[save];
  		cout<<endl;
  		sum_perdata[save]=algo[save]+pti[save]+mpp[save];
  		avg_perdata[save]=sum_perdata[save]/3;
  		no[save]=save+1;
 	}

 	mulai=1;
 	akhir=3;
 	jumlah_halaman = data_count/akhir;
 	sisa = data_count%akhir;
 	if(sisa>0) {
  		jumlah_halaman++;
 	}

 	do{
 	      system("cls");
   		if(move=='N' || move=='n'){ 
    			if(akhir < data_count){
     				page+=1;
     				mulai+=3;
     				akhir+=3;
    			}
   		} 
   		else if(move=='P' || move=='p') { 
    			if(mulai >= 3) {
     				page-=1;
     				mulai-=3;
     				akhir-=3;
    			} 
   		}

   		tabel();
   		cout<<"\t\t    "<<"Halaman Ke "<<page<<" Dari "<<jumlah_halaman<<" Halaman";
    		cout<<endl;
   		header();
   		for(print=mulai-1;print<akhir;print++) {
    			if(no[print]!=0 && nim[print]!=0 && algo[print]!=0 && pti[print]!=0 && mpp[print]!=0){
    				cout<<" "<<left<<setw(5)<<no[print]<<setw(11)<<nim[print]<<setw(13)<<algo[print]<<setw(11)<<mpp[print]<<setw(11)<<pti[print]<<setw(10)<<avg_perdata[print]<<endl;
    				tabel();
    			}
  		}
  		cout<<"\t\t      ";
     		for(nav=1;nav<=jumlah_halaman;nav++){
      		if(nav==page){
       			cout<<"["<<nav<<"]";
      		} else {
       			cout<<" "<<nav<<" ";
      		}
     		}
  		cout<<endl<<endl;
  		cout<<"Lanjut [Y/y] / EXIT [PRESS ANY KEY..] : ";
  		cin>>move;
 	} 
	while(move=='Y' || move=='y');
 	return(EXIT_SUCCESS);
	getch();
}

