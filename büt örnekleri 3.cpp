#include <stdio.h>

/*3) 2 ile 100 aras�nda bir tam say� giriniz. Girilen say� 2 ile 100 aras�nda de�ilse kullan�c�dan yeniden bir 
say� girmesi istensin. Girilen bu tam say�n�n pozitif b�lenlerinin say�s�n� bulunuz. 1 de�erini de girilen 
say�n�n pozitif b�leni olarak kabul ediniz.*/

int sayikontrol(){
	int sayi;
	
	printf("bir tam say� giriniz.(2 ile 100 aras�nda olsun.)\n");
	scanf("%d", &sayi);
	
	if(sayi<2 || sayi>100)
	sayi=sayikontrol();
	
	return sayi;
}
int main(){
	int sayi,i,sayac=0;
	
	sayi=sayikontrol();
	
	for(i=1;i<sayi+1;i++){
		if(sayi%i==0)
		sayac++;
	}
	
	printf("%d sayisini %d sayi bolmektedir.\n",sayi,sayac);
	
	return 0;
}
