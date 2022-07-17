#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;
int main() {
	ifstream asilMetin("metin.txt");	//Dosyamizi Objesi Olusturalim
	string icerik;
	char message[300];
	char message2[300];		//Gerekli Degiskenleri Olusturalim
	if(asilMetin.is_open()){		//Dosyamizda Islemlere Baslayalim
		while(getline(asilMetin,icerik)){
			int l;
			l=icerik.length();
			for(int i=0;i<l;i++){
				message[i]=icerik.at(i);
			}
			asilMetin.close();
		}
	}		//Metin Dosyamizdaki Icerigi Okumus Bulunuyoruz	Ve Bu Dosyada Isimizi Bitiriyoruz
	for(int i=0;i<strlen(message);i++){
		if(message[i]>='a' && message[i]<='z'){
		message[i]=message[i]-32;
	    }
	}
	char harfler[]="ABCDEFGHIJKLMNOPRQSTUVWXYZ";			
	char matris[26][26];

	for(int i=0;i<26;i++){
		int k;
		for(int j=0;j<26;j++){
			matris[i][j]=harfler[k%26];
			k++;
		}
		k++;
	}
	char key[100];
	cout<<"anahtari girin:";
	gets(key);
	int sayac=0;
	for(int i=0;i<strlen(message);i++){
		if(key[i]<='a' && key[i]<='z'){
			 sayac++;
		}
		int x,y;
		if(sayac==strlen(key)){
			cout<<"sifre olusturuldu ve dosyaya kaydedildi:";
			for(int i=0;i<strlen(message);i++){
				message[i]=message[i]+32;
				x=message[i]-'a';
				y=key[i%strlen(key)]-'a';
				message2[i]=matris[x][y];
			}
		}
		else{
			cout<<"sifre olusturuldu ve dosyaya kaydedildi:";
			for(int i=0;i<strlen(message);i++){
				message[i]=message[i];
				x=message[i]-'A';
				y=key[i%strlen(key)]-'A';
				message2[i]=matris[x][y];
				cout<<message2[i];
					}
		}		
	ofstream sifreliMetin("sifreli.txt");
	if(sifreliMetin.is_open()){
		for(int i=0;i<strlen(message2);i++){
			sifreliMetin<<message2[i];
		}
		sifreliMetin.close();
	}
	return 0;
	}
}
