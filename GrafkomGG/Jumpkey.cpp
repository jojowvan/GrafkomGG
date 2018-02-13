#include <SFML/Graphics.hpp>
#include <time.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <mmsystem.h>
#pragma comment( lib, "winmm.lib" )
#include <cstring>

using namespace std;
using namespace sf;

struct point {
    int x,y;
};

int main()
{
    srand(time(0));

    RenderWindow app(sf::VideoMode(400, 533), "Jumpkey Game");
    app.setFramerateLimit(60);

    sf::Texture t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15;
    sf::Texture t16,t17,t18,t19,t20,t21,t22,t23,t24,t25,t26,t27,t28;
    sf::Texture t29,t30,t31,t32,t33,t34,t35,t36,t37,t38,t39;
    t1.loadFromFile("images/background.jpg");
    t2.loadFromFile("images/injekan.png");
    t3.loadFromFile("images/kiri.png");
    t4.loadFromFile("images/rocket.png");
    t5.loadFromFile("images/pakeRocket.png");
    t6.loadFromFile("images/kanan.png");
    t7.loadFromFile("images/injekanGede.png");
    t8.loadFromFile("images/home play.png");
    t9.loadFromFile("images/kaktusBulet.png");
    t10.loadFromFile("images/kaktusPanjang.png");
    t11.loadFromFile("images/1.png");
    t12.loadFromFile("images/2.png");
    t13.loadFromFile("images/3.png");
    t14.loadFromFile("images/4.png");
    t15.loadFromFile("images/5.png");
    t16.loadFromFile("images/6.png");
    t17.loadFromFile("images/7.png");
    t18.loadFromFile("images/8.png");
    t19.loadFromFile("images/9.png");
    t20.loadFromFile("images/0.png");
    t21.loadFromFile("images/home about.png");
    t22.loadFromFile("images/home credit.png");
    t23.loadFromFile("images/home exit.png");
    t24.loadFromFile("images/about.png");
    t25.loadFromFile("images/credit.png");
    t26.loadFromFile("images/pause.png");
    t27.loadFromFile("images/background1.png");
    t28.loadFromFile("images/background2.png");
    t29.loadFromFile("images/score.png");
    t30.loadFromFile("images/about1.png");
    t31.loadFromFile("images/pause1.png");
    t32.loadFromFile("images/injekan1.png");
    t33.loadFromFile("images/injekan2.png");
    t34.loadFromFile("images/injekan3.png");
    t35.loadFromFile("images/background3.png");
    t36.loadFromFile("images/pakeRocket1.png");
    t37.loadFromFile("images/banana.png");
    t38.loadFromFile("images/tulisan.png");
    t39.loadFromFile("images/poin.png");

    sf::Sprite sBackground(t1), sPlat(t2), sPers(t3), sRocket(t4), pakeRocket(t5), sPers1(t6), injekanGede(t7), home(t8), kaktusBulet(t9);
    sf::Sprite kaktusPanjang(t10), satu(t11), dua(t12), tiga(t13), empat(t14), lima(t15), enam(t16), tujuh(t17), delapan(t18), sembilan(t19);
    sf::Sprite nol(t20), homeAbout(t21), homeCredit(t22), homeExit(t23), about(t24), credit(t25), pause(t26),background1(t27),background2(t28);
    sf::Sprite score(t29), about1(t30), pause1(t31), sPlat1(t32), sPlat2(t33), sPlat3(t34), background3(t35), pakeRocket1(t36), banana(t37), tulisan(t38), poin(t39);
    sf::Window window;

    point plat[10];

    for (int i=0;i<10;i++) {
        plat[i].x=rand()%400;
        plat[i].y=rand()%533;
    }

	int x=100,y=50,h=200,jumlahRoket=60,posisi=1,sum=0,active=0,Counabout=0,Councredit=0,wp=0,akhir=0,angka;
	int kurang,Counabout1=0,scoree=0,pilih;
    float dy=0,coun=0,pembanding=0;

    vector<int> posisiSekarang;
    vector<float> posisiRoket;
    vector<int>::iterator it;

    PlaySound(TEXT("sounds/backsound.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

    while (app.isOpen())
    {

        //buat milih menu
        if (Keyboard::isKeyPressed(Keyboard::Down)) {
            sum++;
        }
        else if(Keyboard::isKeyPressed(Keyboard::Up)) {
            sum--;
        }

        //jaga biar menunya tetep nampilin gambar
        if(sum<0) {
            sum=19;
        }

        else if(sum>=20) {
            sum=0;
        }

        if(sum<5) {
            app.draw(home);
            if (Keyboard::isKeyPressed(Keyboard::Return)) {
                active = 1;     //counter buat play
            }
        }

         else if(sum<10) {
            app.draw(homeAbout);
             if (Keyboard::isKeyPressed(Keyboard::Return)) {
                Counabout = 1;     //counter buat about
            }
        }

        else if(sum<15) {
            app.draw(homeCredit);
             if (Keyboard::isKeyPressed(Keyboard::Return)) {
                Councredit = 1;     //counter buat credit
            }
        }

        else {
            app.draw(homeExit);
            if (Keyboard::isKeyPressed(Keyboard::Return)) {
                break;
            }
        }

        if(Counabout==1) {
            app.draw(about);
            if (Keyboard::isKeyPressed(Keyboard::Escape)) Counabout=0;
            else if (Keyboard::isKeyPressed(Keyboard::Right)) Counabout1=1;
        }

        if(Counabout1==1) {
            app.draw(about1);
            if (Keyboard::isKeyPressed(Keyboard::Escape)) {
                Counabout1=0;
                Counabout=0;
            }
            else if (Keyboard::isKeyPressed(Keyboard::Left)) {
                Counabout1=0;
            }
        }

        if(Councredit==1) {
            app.draw(credit);
            if (Keyboard::isKeyPressed(Keyboard::Escape)) Councredit=0;
        }

        if(wp==1) {
            if(pilih==1) {
                app.draw(pause);
                if (Keyboard::isKeyPressed(Keyboard::Return)) {
                    active=1;
                    wp=0;
                }
                if (Keyboard::isKeyPressed(Keyboard::Down)) {
                    pilih=2;
                }
            }
            else if(pilih==2) {
                app.draw(pause1);
                if (Keyboard::isKeyPressed(Keyboard::Return)) {
                    active=0;
                    scoree=0;
                    coun=0;
                    jumlahRoket=60;
                    sum=0;
                }
                if (Keyboard::isKeyPressed(Keyboard::Up)) {
                    pilih=1;
                }
            }
        }

        //play
        if(active==1 and akhir==0) {
        if (Keyboard::isKeyPressed(Keyboard::Right)) x+=3;
        if (Keyboard::isKeyPressed(Keyboard::Left)) x-=3;
        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            active = 0;
            wp = 1;
            pilih=1;
        }

        if (x>=380) x=-70;              //mentok kanan
        if (x<-70) x=380;               //mentok kiri

        dy+=0.2;
        y+=dy;

        if (y<h)

        for (int i=0;i<10;i++)          //camera
        {
          y=h;                          //menempatkan main character di posisi 200
          plat[i].y=plat[i].y-dy;       //biar bisa lompat ke injekan
          if (plat[i].y>533) {
            plat[i].y=0;                //biar munculnya dr layar paling atas
            plat[i].x=rand()%400;      //muncul plat
          }
        }

        for (int i=0;i<10;i++) {                                          //nginjek atau engga
        if ((x+50>plat[i].x) and (x+20<plat[i].x+68) and (y+70>plat[i].y) and (y+70<plat[i].y+14) and (dy>0)) {
            dy=-10;                                     //lompatnya pas
            PlaySound(TEXT("sounds/jump.wav"), NULL, SND_FILENAME | SND_ASYNC);
            }
        }

        if(coun<500) {
            app.draw(sBackground);          //draw background
        }

        else if(coun<750) {
            app.draw(background1);          //draw background
        }

        else if(coun<1000) {
            app.draw(background2);
        }

        else {
            app.draw(background3);
        }

        if (jumlahRoket>0) {
            if(coun<1000) {
                pakeRocket.setPosition(x,y);
                app.draw(pakeRocket);
            }
            else {
                pakeRocket1.setPosition(x,y);
                app.draw(pakeRocket1);
            }
            dy=-15;                     //roket
            jumlahRoket--;
        }

        else {
            if(Keyboard::isKeyPressed(Keyboard::Right)) {
                posisi = 1;
                sPers1.setPosition(x,y);         //set posisi character
                app.draw(sPers1);
            }
            else if(Keyboard::isKeyPressed(Keyboard::Left)) {
                posisi = 2;
                sPers.setPosition(x,y);         //set posisi character
                app.draw(sPers);
            }
            else {
                if(posisi==1) {
                    sPers1.setPosition(x,y);         //set posisi character
                    app.draw(sPers1);
                }
                else if(posisi==2) {
                    sPers.setPosition(x,y);         //set posisi character
                    app.draw(sPers);
                }
            }
        }

        if((x+60 > sRocket.getPosition().x) and (x+20 < sRocket.getPosition().x+40) and (y+70 > sRocket.getPosition().y) and (y+70 < sRocket.getPosition().y+60) and (dy>0)) { //perbaiki
                jumlahRoket=60;                          //amunisi roket
                PlaySound(TEXT("sounds/rocket2.wav"), NULL, SND_FILENAME | SND_ASYNC);
        }

        if((x+60 > banana.getPosition().x) and (x+20 < banana.getPosition().x+40) and (y+70 > banana.getPosition().y) and (y+70 < banana.getPosition().y+60) and (dy>0)) { //perbaiki
                coun+=1;
                poin.setPosition(x+20,y);
                app.draw(poin);
                PlaySound(TEXT("sounds/rocket2.wav"), NULL, SND_FILENAME | SND_ASYNC);      //suara banana
        }

        if((x+60 > kaktusPanjang.getPosition().x) and (x+20 < kaktusPanjang.getPosition().x+50) and (y+70 > kaktusPanjang.getPosition().y) and (y+70 < kaktusPanjang.getPosition().y+40) and (dy>0)) { //perbaiki
                scoree = 1;
                active = 0;
                PlaySound(TEXT("sounds/die.wav"), NULL, SND_FILENAME | SND_ASYNC);
        }

        if(y>500) {
            scoree = 1;
            active = 0;
            y = y-50;
            PlaySound(TEXT("sounds/die.wav"), NULL, SND_FILENAME | SND_ASYNC);
        }

        if((x+60 >= kaktusBulet.getPosition().x) and (x+20 < kaktusBulet.getPosition().x+40) and (y+70 > kaktusBulet.getPosition().y) and (y+70 < kaktusBulet.getPosition().y+40) and (dy>0)) { //perbaiki
                active=0;
        }

        if(coun>pembanding) {
            angka = coun;
        }

        else {
            angka = pembanding;
        }

        kurang=0;

        while(angka>0) {
        if(angka%10==0) {
            nol.setPosition(360-kurang,15);
            app.draw(nol);
        }

        else if(angka%10==1) {
            satu.setPosition(360-kurang,15);
            app.draw(satu);
        }

        else if(angka%10==2) {
            dua.setPosition(360-kurang,15);
            app.draw(dua);
        }

        else if(angka%10==3) {
            tiga.setPosition(360-kurang,15);
            app.draw(tiga);
        }

        else if(angka%10==4) {
            empat.setPosition(360-kurang,15);
            app.draw(empat);
        }

        else if(angka%10==5) {
            lima.setPosition(360-kurang,15);
            app.draw(lima);
        }

        else if(angka%10==6) {
            enam.setPosition(360-kurang,15);
            app.draw(enam);
        }

        else if(angka%10==7) {
            tujuh.setPosition(360-kurang,15);
            app.draw(tujuh);
        }

        else if(angka%10==8) {
            delapan.setPosition(360-kurang,15);
            app.draw(delapan);
        }

        else if(angka%10==9) {
            sembilan.setPosition(360-kurang,15);
            app.draw(sembilan);
        }
        kurang+=25;
        angka/=10;
    }

    tulisan.setPosition(360-kurang-60,15);
    app.draw(tulisan);

        for (int i=1;i<10;i++)                  //jumlah injekan
        {
        if(coun<500) {
            sPlat.setPosition(plat[i].x,plat[i].y);
            app.draw(sPlat);
        }

        else if(coun<750) {
            sPlat1.setPosition(plat[i].x,plat[i].y);
            app.draw(sPlat1);
        }

        else if(coun<1000) {
            sPlat2.setPosition(plat[i].x,plat[i].y);
            app.draw(sPlat2);
        }

        else {
            sPlat3.setPosition(plat[i].x,plat[i].y);
            app.draw(sPlat3);
        }

            if(i==3) {
                sRocket.setPosition(plat[i].x+10,plat[i].y-50);
                app.draw(sRocket);
            }
            if(coun<750) {
                if(i==2) {
                    kaktusPanjang.setPosition(plat[i].x+14,plat[i].y-40);
                    app.draw(kaktusPanjang);
                }

                if(i==1) {
                    banana.setPosition(plat[i].x+14,plat[i].y-20);
                    app.draw(banana);
                }
            }

            else if(coun<1000) {
                if(i==2 or i==5) {
                        kaktusPanjang.setPosition(plat[i].x+14,plat[i].y-40);
                        app.draw(kaktusPanjang);
                }

                if(i==1) {
                    banana.setPosition(plat[i].x+14,plat[i].y-20);
                    app.draw(banana);
                }
            }

            else {
                if(i==2 or i==5 or i==7) {
                        kaktusPanjang.setPosition(plat[i].x+14,plat[i].y-40);
                        app.draw(kaktusPanjang);
                }

                if(i==1) {
                    banana.setPosition(plat[i].x+14,plat[i].y-20);
                    app.draw(banana);
                }
            }
        }

        coun+=dy/-10.0;
        pembanding = coun;

        while(scoree==1) {
            app.draw(score);
            if(Keyboard::isKeyPressed(Keyboard::Escape)) {
                scoree=0;
                coun=0;
                jumlahRoket=60;
                sum=0;
                PlaySound(TEXT("sounds/backsound.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
                break;
            }

        angka = coun;
        kurang=0;

        while(angka>0) {
            if(angka%10==0) {
                nol.setPosition(225-kurang,270);
                app.draw(nol);
            }

            else if(angka%10==1) {
                satu.setPosition(225-kurang,270);
                app.draw(satu);
            }

            else if(angka%10==2) {
                dua.setPosition(225-kurang,270);
                app.draw(dua);
            }

            else if(angka%10==3) {
                tiga.setPosition(225-kurang,270);
                app.draw(tiga);
            }

            else if(angka%10==4) {
                empat.setPosition(225-kurang,270);
                app.draw(empat);
            }

            else if(angka%10==5) {
                lima.setPosition(225-kurang,270);
                app.draw(lima);
            }

            else if(angka%10==6) {
                enam.setPosition(225-kurang,270);
                app.draw(enam);
            }

            else if(angka%10==7) {
                tujuh.setPosition(225-kurang,270);
                app.draw(tujuh);
            }

            else if(angka%10==8) {
                delapan.setPosition(225-kurang,270);
                app.draw(delapan);
            }

            else if(angka%10==9) {
                sembilan.setPosition(225-kurang,270);
                app.draw(sembilan);
            }
            kurang+=33;
            angka/=10;
        }

            app.display();
        }
    }
        app.display();
    }

    return 0;
}
