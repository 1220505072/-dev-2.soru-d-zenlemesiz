#include <stdio.h>

/*          SORUDA B�NARY SEARCH ALGOR�TMAS� KULLANARAK COZMEM�Z� �ST�YOR FAKAT BU ALGOR�TMA S�RAL� D�Z�LERDE KULAN�L�R. 
B�ZE VER�LEN D�Z� S�RAL� DEG�L BU YUZDEN BAZ� ELEMANLARDA HATAL� CAL�S�R.
HATAL� CAL�SMAMAS� �C�N D�Z�Y� S�RALAMAL�Y�Z                */

int binary_Arama(int bllk[], int sol, int sag, int favori_Eleman);

int main() {
    int dizi[] = {4, 8, 3, 84, 47, 76, 9, 24, 68}; //dizi
    int h = sizeof(dizi) / sizeof(dizi[0]); //dizinin eleman say�s�n� hesapla(sizeof(dizi): dizinin toplam boyutunu (bayt cinsinden) ; sizeof(dizi[0]) dizinin bir eleman�n�n boyutunu (bayt cinsinden) verir.)

    int favori_Eleman;
    printf("Verilen dizide aranacak elemani giriniz: ");
    scanf("%d", &favori_Eleman);          //kullanicidan aramak istedigi elemani al

    int index = binary_Arama(dizi, 0, h - 1, favori_Eleman);  //fonksiyonu �a��rarak, dizide aranan eleman�n indeksini hesaplar ve index de�i�kenine atar.

    if (index != -1) {   //-1'e e�it olup olmad���n� kontrol et.
        printf("Aranan eleman %d , aranan eleman dizinin %d. indexidir.", favori_Eleman, index); //d�nen de�er -1 de�ilse, bu demek oluyor ki aranan eleman dizide bulunmu�tur
    } else {
        printf("Aranan eleman %d, dizide bulunamadi.", favori_Eleman); // -1'e e�itse, aranan eleman dizide bulunamam��t�r
    }

    return 0;
}

int binary_Arama(int bllk[], int sol, int sag, int favori_Eleman) { //fonksiyon olustur
    if (sol <= sag) {   // dizinin s�n�r� hala ge�erli mi kontrol edilir
        int mid = (sol + sag) / 2; //dizinin ortas�ndaki eleman�n indeksini bulur (mid)

        if (bllk[mid] == favori_Eleman) {  //bu eleman aranan elemanla e�le�irse
            return mid;    //bu eleman�n indeksini (mid) d�nd�r�r.
        } else if (bllk[mid] < favori_Eleman) {  //E�er ortadaki eleman aranan elemandan k���kse
            return binary_Arama(bllk, mid + 1, sag, favori_Eleman); //fonksiyon sa� yar�da (mid+1 ile sag aras�nda) tekrar �a�r�l�r
        } else {  //E�er ortadaki eleman aranan elemandan b�y�kse
            return binary_Arama(bllk, sol, mid - 1, favori_Eleman);  //fonksiyon sol yar�da (sol ile mid-1 aras�nda) tekrar �a�r�l�r
        }
    }

    return -1;  //eger aranan eleman dizide bulunmazsa, fonksiyon -1 de�erini d�nd�r�r
}

