#include <iostream>
using namespace std;

int main()
{
    int jum;
    
    cout<<"========================="<<endl;
    cout<<"|| PROGRAM SEGMENTASI ||"<<endl;
    cout<<"========================="<<endl;
    cout<<"Input Jumlah Nilai : ";
    cin>>jum;
    cout<<endl;
    int *nilai;
    nilai = new int[jum];
    cout<<"INPUT Nilai :"<<endl;
    for (int i = 0; i < jum; i++){
    	cout<<"Nilai "<<i+1<<" : ";
        cin>>*(nilai+i);
    }
    cout<<endl;
    system("cls");
    cout<<"NILAI "<<endl;
    for (int j = 0; j < jum; j++){
        cout<<"Nilai "<<j+1<<" = "<<*(nilai+j)<<endl;
    }    
    delete [] nilai;
    return 0;
}
