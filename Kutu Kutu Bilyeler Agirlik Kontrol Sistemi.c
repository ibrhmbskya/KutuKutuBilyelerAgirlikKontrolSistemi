#include<stdio.h>
#include<stdlib.h>


int main()
{


    // Degiskenlerin tanimlandigi bolum.

    int i,bilyeSayisi,bilyeAgirligi,birinciBilyeAgirligi,ikinciBilyeAgirligi,kontrolAgirlik,n;
    int toplamKutuSayisi=0,iadeKutuSayisi=0,tekHataliKabulKutuSayisi,hatasizKabulKutuSayisi=0;
    int agirTekHataliKabulKutu=0,hafifTekHataliKabulKutu=0,agirlikFarki,hataSayisi,kutuHatalimi;
    int iadeBilyeSayisi=0,kabulBilyeSayisi=0,agirTekHataliFarkDegeri,hafifTekHataliFarkDegeri;
    int agirTekHataliFarkDegeriToplam=0,hafifTekHataliFarkDegeriToplam=0,hatasizKutuEnCokBilyeSayisi=0,hatasizKutuEnCokBilyeAgirlik=0;
    int hatasizKutuEnHafifBilyeSayisi=0,hatasizKutuEnHafifBilyeAgirligi=0,maxFark=0,farkliOlanBilyeAgirligi,maxYuzdeDegeri=0;

    float agirlikFarkiYuzdesi,iadeKutuYuzdesi,tekHataliKabulKutuYuzdesi,hatasizKabulKutuYuzdesi;
    float agirTekHataliKabulKutuYuzdesi,hafifTekHataliKabulKutuYuzdesi,agirTekHataliFarkYuzdesi,hafifTekHataliFarkYuzdesi;
    float agirTekHataliFarkYuzdeOrtalama=0,hafifTekHataliFarkYuzdeOrtalama=0,agirTekHataliFarkDegerOrtalama,hafifTekHataliFarkDegerOrtalama;
    float hafifTekHataliFarkYuzdesiToplam=0,agirTekHataliFarkYuzdesiToplam=0,maxFarkYuzde=0,maxYuzde=0;


    char devam,maxFarkIsaret,maxYuzdeDegerIsaret;

    /*
        Bir kutu bittikten sonra baska kutu varsa programi tekrar calistiran
        programin temel dongusu olan while dongusu, devam degiskenine 'e' atanarak
        programa ilk giris saglandi.
    */


    devam='e';
    while(devam=='e' || devam=='E'){
            toplamKutuSayisi++;
            printf("Lutfen kutudaki bilye sayisini giriniz:");
            scanf("%d",&bilyeSayisi);

            //Bilye sayisi yanlis girilirse tekrar aldiran while dongusu.
            while(bilyeSayisi<10){
                printf("\nHatali giris!\nLutfen kutudaki bilye sayisini tekrar giriniz:");
                scanf("%d",&bilyeSayisi);
            }


            //Degiskenlere 0 atanan bolum.
            hataSayisi=0;
            birinciBilyeAgirligi=0;
            ikinciBilyeAgirligi=0;
            kontrolAgirlik=0;
            kutuHatalimi=0;

            /*
                Kullanicinin girdigi bilye sayisina gore
                dongu sayisini belirleyen for yapisi.
            */
            for(i=1;i<=bilyeSayisi;i++){
                printf("\n %d. bilyenin mg cinsinden degerini giriniz:",i);
                scanf("%d",&bilyeAgirligi);

                //Bilye agirligi yanlis girilirse tekrar aldiran while dongusu.
                while(bilyeAgirligi<=0){


                    printf("\nHatali giris!\nLutfen %d. bilyenin mg cinsinden degerini tekrar giriniz:",i);
                    scanf("%d",&bilyeAgirligi);
                }

                /*
                    Ilk girilen iki bilyeyi birinci ve ikinci
                    bilye agirligina atamayi saglayan if yapilari.
                */
                if(i==1){
                    birinciBilyeAgirligi=bilyeAgirligi;
                }
                if(i==2){
                    ikinciBilyeAgirligi=bilyeAgirligi;
                }

                /*
                    Ilk iki bilyenin esit olup olmadigini kontrol eden
                    eger esitse, icerisinde kontrol agirligi belirleyen
                    ve bu kontrol agirliga göre kutuda hata olup olmadigini
                    belirleyen if blogu.
                */
                if(birinciBilyeAgirligi==ikinciBilyeAgirligi){
                    kontrolAgirlik=birinciBilyeAgirligi;
                    if(bilyeAgirligi!=kontrolAgirlik){
                        hataSayisi++;
                        farkliOlanBilyeAgirligi=bilyeAgirligi;

                    }
                    if(hataSayisi==2){
                        printf("\nKutu hatalidir");
                        kutuHatalimi=1;
                        iadeKutuSayisi++;
                        iadeBilyeSayisi+=bilyeSayisi;

                        break;
                    }


                }

                /*
                    Eger ilk iki bilye esit degilse girilen 3.bilye ilk iki bilyeden
                    herhangi birine esit oldugu durumu kontrol eden else if yapisi.
                */
                else if(birinciBilyeAgirligi==bilyeAgirligi||ikinciBilyeAgirligi==bilyeAgirligi){


                    /*
                        3. bilyenin ilk iki bilyeden hangisine esit oldugunu,
                        buna gore hangisine esitse onu kontrol agirlik olarak atayan
                        ve sadece 3. bilye girildiginde kontrol yapan if yapisi.
                    */
                    if(i==3){

                        if(birinciBilyeAgirligi==bilyeAgirligi){
                            kontrolAgirlik=birinciBilyeAgirligi;
                            farkliOlanBilyeAgirligi=ikinciBilyeAgirligi;
                            hataSayisi=1;


                        }
                        if(ikinciBilyeAgirligi==bilyeAgirligi){
                            kontrolAgirlik=ikinciBilyeAgirligi;
                            farkliOlanBilyeAgirligi=birinciBilyeAgirligi;
                            hataSayisi=1;


                        }
                    }

                        //Hatayi kontrol eden if blogu.
                        if(kontrolAgirlik!=bilyeAgirligi&&kontrolAgirlik!=0){
                            printf("\nKutu hatalidir!");
                            kutuHatalimi=1;
                            iadeKutuSayisi++;
                            iadeBilyeSayisi+=bilyeSayisi;

                            break;
                        }

                }

                /*
                    ilk iki kontrol blogundan hc birine uyum saglamazsa
                    kutunun hatali oldugunu bulduran else yapisi.
                */
                else{
                    printf("\nKutu hatalidir!");
                    kutuHatalimi=1;
                    iadeKutuSayisi++;
                    iadeBilyeSayisi+=bilyeSayisi;

                    break;
                }


            }

                /*
                    Tum bilye girisleri bittikten sonra kutunun,hatali olmadigi
                    durumda devreye giren ve bilyelerin esit agirlikta olup
                    olmadigini, bir bilye farklıysa daha hafifmi yoksa daha agirmi
                    oldugunu ve bu durumlara göre uygun yazdırma islemlerini yapan
                    if else yapilari.
                */

                if(kutuHatalimi!=1){
                        kabulBilyeSayisi+=bilyeSayisi;
                    if(hataSayisi==0){
                        printf("\nKutudaki bilyelerin hepsi esit agirlikta.");
                        hatasizKabulKutuSayisi++;
                        if(hatasizKutuEnCokBilyeSayisi<bilyeSayisi){
                            hatasizKutuEnCokBilyeSayisi=bilyeSayisi;
                            hatasizKutuEnCokBilyeAgirlik=bilyeAgirligi;
                        }

                        if(hatasizKutuEnHafifBilyeAgirligi>bilyeAgirligi){
                            hatasizKutuEnHafifBilyeAgirligi=bilyeAgirligi;
                            hatasizKutuEnHafifBilyeSayisi=bilyeSayisi;
                        }

                    }
                    else{
                        if(kontrolAgirlik>farkliOlanBilyeAgirligi){
                            printf("\nFarkli olan bilye %d daha hafiftir, yuzde %.2f",kontrolAgirlik-farkliOlanBilyeAgirligi,(float)(kontrolAgirlik-farkliOlanBilyeAgirligi)/kontrolAgirlik*100);
                            hafifTekHataliKabulKutu++;
                            hafifTekHataliFarkDegeriToplam += (kontrolAgirlik-farkliOlanBilyeAgirligi);
                            hafifTekHataliFarkYuzdesiToplam +=(float)(kontrolAgirlik-farkliOlanBilyeAgirligi)/kontrolAgirlik*100;
                            if(maxFark<(kontrolAgirlik-farkliOlanBilyeAgirligi)){
                                maxFark=(kontrolAgirlik-farkliOlanBilyeAgirligi);
                                maxFarkYuzde=(float)(kontrolAgirlik-farkliOlanBilyeAgirligi)/kontrolAgirlik*100;
                                maxFarkIsaret='-';
                                }

                            if(maxYuzde<((float)(kontrolAgirlik-farkliOlanBilyeAgirligi)/kontrolAgirlik*100)){
                                maxYuzde=(float)(kontrolAgirlik-farkliOlanBilyeAgirligi)/kontrolAgirlik*100;
                                maxYuzdeDegeri=(kontrolAgirlik-farkliOlanBilyeAgirligi);
                                maxYuzdeDegerIsaret='-';

                            }
                        }
                        else{
                            printf("\nFarkli olan bilye %d daha agirdir, yuzde %.2f",farkliOlanBilyeAgirligi-kontrolAgirlik,(float)(farkliOlanBilyeAgirligi-kontrolAgirlik)/kontrolAgirlik*100);
                            agirTekHataliKabulKutu++;
                            agirTekHataliFarkDegeriToplam += (farkliOlanBilyeAgirligi-kontrolAgirlik);
                            agirTekHataliFarkYuzdesiToplam += (float)(farkliOlanBilyeAgirligi-kontrolAgirlik)/kontrolAgirlik*100;
                            if(maxFark<(farkliOlanBilyeAgirligi-kontrolAgirlik)){
                                maxFark=(farkliOlanBilyeAgirligi-kontrolAgirlik);
                                maxFarkYuzde=(float)(farkliOlanBilyeAgirligi-kontrolAgirlik)/kontrolAgirlik*100;
                                maxFarkIsaret='+';

                            }
                            if(maxYuzde<(float)(farkliOlanBilyeAgirligi-kontrolAgirlik)/kontrolAgirlik*100){
                                maxYuzde=(float)(farkliOlanBilyeAgirligi-kontrolAgirlik)/kontrolAgirlik*100;
                                maxYuzdeDegeri=(farkliOlanBilyeAgirligi-kontrolAgirlik);
                                maxYuzdeDegerIsaret='+';

                            }


                        }

                    }

                }


        printf("\nYeni kutu ile devam etmek ister misiniz?(e/E,h/H):");
        fflush(stdin);
        scanf("%c",&devam);

        /*
            Istenilen karakter disinda giris yapilirsa
            while yapisiyla tekrar aldiriliyor.
        */
        while(devam!='E' && devam!='e' && devam!='H' && devam!='h'){
            printf("\nHatali giris yaptiniz. Yeni kutu ile devam etmek ister misiniz?(e/E,h/H):");
            fflush(stdin);
            scanf("%c",&devam);
        }

    }

    /*
        Tum girisler bittikten sonra gerekli islemleri printflerin icinde yapan
        ve printflerle yazdırılma islemini yapan kod blogu.
    */
    printf("\nUretim hatasi olan kutu sayisi:%d\ntum kutular icindeki yuzdesi:%.2f",iadeKutuSayisi,(float)iadeKutuSayisi/toplamKutuSayisi*100);
    printf("\n---------------------------------------------------------------------");
    printf("\nIade edilen bilye sayisi:%d\nKabul edilen bilye sayisi:%d",iadeBilyeSayisi,kabulBilyeSayisi);
    printf("\n---------------------------------------------------------------------");




    /*
        Asagidaki printfleri if else lerin icinde yazdirmamin
        sebebi deger bulunmayan girdiler girildiginde '-1 #j' gibi
        sacma degerler dondurmesi.if elseler sayesinde bu degerler varsa yazdiriyor
        yoksa olmadigini belirtiyorum.
    */
    if(hatasizKabulKutuSayisi>0){
        printf("\nIcindeki tum bilyelerin esit agirlikta oldugu kutu sayisi:%d\nUretim hatasi olmayan kutular icindeki yuzdesi:%.2f",hatasizKabulKutuSayisi,(float)hatasizKabulKutuSayisi/(hatasizKabulKutuSayisi+hafifTekHataliKabulKutu+agirTekHataliKabulKutu)*100);
        printf("\n---------------------------------------------------------------------");
    }
    else{
        printf("\nIcindeki tum bilyelerin esit agirlikta oldugu kutu sayisi:0\nUretim hatasi olmayan kutular icindeki yuzdesi:0");
        printf("\n---------------------------------------------------------------------");
    }

    if(hafifTekHataliKabulKutu>0){
        printf("\nIcindeki bir bilyenin digerlerinden daha hafif oldugu kutu sayisi:%d\nUretim hatasi olmayan kutular icindeki yuzdesi:%.2f",hafifTekHataliKabulKutu,(float)hafifTekHataliKabulKutu/(hatasizKabulKutuSayisi+hafifTekHataliKabulKutu+agirTekHataliKabulKutu)*100);
        printf("\n---------------------------------------------------------------------");
    }
    else{
        printf("\nIcindeki bir bilyenin digerlerinden daha hafif oldugu kutu sayisi:0\nUretim hatasi olmayan kutular icindeki yuzdesi:0");
        printf("\n---------------------------------------------------------------------");
    }

    if(agirTekHataliKabulKutu>0){
        printf("\nIcindeki bir bilyenin digerlerinden daha agir oldugu kutu sayisi:%d\nUretim hatasi olmayan kutular icindeki yuzdesi:%.2f",agirTekHataliKabulKutu,(float)agirTekHataliKabulKutu/(hatasizKabulKutuSayisi+hafifTekHataliKabulKutu+agirTekHataliKabulKutu)*100);
        printf("\n---------------------------------------------------------------------");
    }
    else{
        printf("\nIcindeki bir bilyenin digerlerinden daha agir oldugu kutu sayisi:0\nUretim hatasi olmayan kutular icindeki yuzdesi:0");
        printf("\n---------------------------------------------------------------------");
    }

    if((float)agirTekHataliFarkDegeriToplam/agirTekHataliKabulKutu>0){
        printf("\nBir bilyenin digerlerinden daha agir oldugu kutulardaki\nagir olan bilyelerin agirlik farki degerlerinin ortalamalari:%.2f",(float)agirTekHataliFarkDegeriToplam/agirTekHataliKabulKutu);
        printf("\n---------------------------------------------------------------------");
    }
    else{
        printf("\nBir bilyenin digerlerinden daha agir oldugu kutulardaki\nagir olan bilyelerin agirlik farki degerlerinin ortalamalari:0");
        printf("\n---------------------------------------------------------------------");
    }

    if((float)agirTekHataliFarkYuzdesiToplam/agirTekHataliKabulKutu>0){
        printf("\nBir bilyenin digerlerinden daha agir oldugu kutulardaki\nagir olan bilyelerin yuzdelerinin ortalamalari:%.2f",(float)agirTekHataliFarkYuzdesiToplam/agirTekHataliKabulKutu);
        printf("\n---------------------------------------------------------------------");
    }
    else{
        printf("\nBir bilyenin digerlerinden daha agir oldugu kutulardaki\nagir olan bilyelerin yuzdelerinin ortalamalari:0");
        printf("\n---------------------------------------------------------------------");
    }

    if((float)hafifTekHataliFarkDegeriToplam/hafifTekHataliKabulKutu>0){
        printf("\nBir bilyenin digerlerinden daha hafif oldugu kutulardaki\nhafif olan bilyelerin agirlik farki degerlerinin ortalamalari:%.2f",(float)hafifTekHataliFarkDegeriToplam/hafifTekHataliKabulKutu);
        printf("\n---------------------------------------------------------------------");
    }
    else{
        printf("\nBir bilyenin digerlerinden daha hafif oldugu kutulardaki\nhafif olan bilyelerin agirlik farki degerlerinin ortalamalari:0");
        printf("\n---------------------------------------------------------------------");
    }

    if((float)hafifTekHataliFarkYuzdesiToplam/hafifTekHataliKabulKutu>0){
        printf("\nBir bilyenin digerlerinden daha hafif oldugu kutulardaki\nhafif olan bilyelerin yuzdelerinin ortalamalari:%.2f",(float)hafifTekHataliFarkYuzdesiToplam/hafifTekHataliKabulKutu);
        printf("\n---------------------------------------------------------------------");
    }
    else{
        printf("\nBir bilyenin digerlerinden daha hafif oldugu kutulardaki\nhafif olan bilyelerin yuzdelerinin ortalamalari:0");
        printf("\n---------------------------------------------------------------------");
    }

    if(hatasizKutuEnCokBilyeSayisi>0){
        printf("\nTum bilyelerin esit agirlikta oldugu kutular arasinda,\nicinde en cok bilye olan kutudaki bilye sayisi:%d,bilyenin agirligi:%d",hatasizKutuEnCokBilyeSayisi,hatasizKutuEnCokBilyeAgirlik);
        printf("\n---------------------------------------------------------------------");
    }
    else{
        printf("\nTum bilyelerin esit agirlikta oldugu kutular arasinda,\nicinde en cok bilye olan kutudaki bilye sayisi:0,bilyenin agirligi:YOK!");
        printf("\n---------------------------------------------------------------------");
    }

    if(hatasizKutuEnHafifBilyeSayisi>0){
        printf("\nTum bilyelerin esit agirlikta oldugu kutular arasinda,\nicinde en hafif bilyeler olan kutudaki bilye sayisi:%d,bilyenin agirligi:%d",hatasizKutuEnHafifBilyeSayisi,hatasizKutuEnHafifBilyeAgirligi);
        printf("\n---------------------------------------------------------------------");
    }
    else{
        printf("\nTum bilyelerin esit agirlikta oldugu kutular arasinda,\nicinde en hafif bilyeler olan kutudaki bilye sayisi:0,bilyenin agirligi:YOK!");
        printf("\n---------------------------------------------------------------------");
    }

    if(maxFark>0){
        printf("\nFarkli olan bilyenin agirliginin diger bilyelerin agirligiyla\narasindaki farkin degerinin en buyuk oldugu\nfarkin degeri:%d, yuzdesi:%.2f ve isareti:%c",maxFark,maxFarkYuzde,maxFarkIsaret);
        printf("\n---------------------------------------------------------------------");
    }
    else{
        printf("\nFarkli olan bilyenin agirliginin diger bilyelerin agirligiyla\narasindaki farkin degerinin en buyuk oldugu\nfarkin degeri:0, yuzdesi:0 ve isareti:YOK!");
        printf("\n---------------------------------------------------------------------");
    }

    if(maxYuzdeDegeri>0){
        printf("\nFarkli olan bilyenin agirliginin diger bilyelerin agirligiyla\narasindaki farkin yuzdesinin en buyuk oldugu\nfarkin degeri:%d, yuzdesi:%.2f ve isareti:%c",maxYuzdeDegeri,maxYuzde,maxYuzdeDegerIsaret);
        printf("\n---------------------------------------------------------------------");
    }
    else{
        printf("\nFarkli olan bilyenin agirliginin diger bilyelerin agirligiyla\narasindaki farkin yuzdesinin en buyuk oldugu\nfarkin degeri:0, yuzdesi:0 ve isareti:YOK!");
        printf("\n---------------------------------------------------------------------");
    }




    return 0;
}
