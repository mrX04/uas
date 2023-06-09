#include<iostream>
#include<fstream>
using namespace std;

int main() {
	
	string simpan[4];
	
	for (int i=0;i<4;i++){
		cin>>simpan[i];
	}
	
	ofstream readFile("Barang.txt");
	
	for(int i=0;i<4;i++){
		readFile<<simpan[i]<<"\n";
	}
}
