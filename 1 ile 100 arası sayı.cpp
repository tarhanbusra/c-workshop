#include <stdio.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL,"Turkish");
	float gizli=10;
	float tahmin=0;
	float sayac=1;
	printf("1 ile 100 aras�nda tutulan gizli say�y� tahmin ederek bulmaya �al���n.\n");
	printf("Tahmininizi giriniz.\n");
	scanf(" %f", &tahmin);
	while(gizli>tahmin){
	printf("Tahmininiz gizli say�dan k���k.\n");
	sayac++;
	printf("Yeni tahmininizi girin.\n");
	scanf(" %f", &tahmin);	
    }
    while(tahmin>gizli){
    printf("Tahmininiz gizli say�dan b�y�k.\n");
	sayac++;
	printf("Yeni tahmininizi girin.\n");
	scanf(" %f", &tahmin);	
	}
	if(tahmin==gizli)
	printf("Tahmininiz do�ru. toplam %.f defada buldunuz.", sayac);
    return 0;
}
