/*
-----------*********Disclaimer*********-----------
Namen/Names:                            PotatoMindPopper
Jaar van aankomst/Year of arrival:      2021
Studierichting/Field of Study:          Informatica (Specialisatie)
Studentnummer/Student number:           *********

Universiteit/University:                Universiteit Leiden
Afdeling/Department:                    LIACS
Studierichting/Field of Study:          Informatica
Vak/Subject:                            Programmeermethoden
Docenten/Teachers:                      Walter Kosters + Jonathan Vis
Opgave/Task:                            Koffiesweeper
Link naar Opgave/Link to task:
    https://liacs.leidenuniv.nl/~kosterswa/pm/op4pm.php

Bestandsnaam/File name:                         main.cc
Datum van creatie/Date of Creation:             05-12-2021
Datum van afgifte/Date of Release:              13-12-2021
Meeste recente update/Latest Patch-date:        17-11-2022
Versie/Version/Patch:                           1.19.4
Gebruikte editor/Used editor:                   Code::Blocks 20.03
Gebruikte compiler/Used compiler:
    GNU GCC Compiler 8.1.0 (Built within Code::Blocks 20.03)
Gebruikte terminal/Used terminal:
    cb_console_runner (Built within Windows 10)
Gebruikte OS/Used OS:
    Windows 10 Pro 21H1 (For PC) + Windows 10 Home 21H1 (For Laptop)

Wat moet de gebruiker doen met dit programma:
Met dit programma kan de gebruiker het programma minesweeper spelen.
Dit houdt in dat er mijnen worden geplaatst in een eindige wereld,
  die ontdekt moeten worden door de gebruiker, maar niet geopend
  moeten worden. Doet de gebruiker dat wel, dan is het spel afgelopen.
Naast dat de gebruiker zelf kan spelen, kan er gekozen worden voor een
  computer. Deze zal verschillende potjes spelen en daarna het
  resultaat terug geven.
Onze versie bevat koffiekopjes in plaats van mijnen en vandaar dat het
  spel ook koffiesweeper heet.
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "koffiebord.h"

using namespace std;

//Dit is de constructor van het bord, die alle waardes op standaard
  //zet bij aanroepen
koffiebord::koffiebord(){
  klaar = false;
  openen = false;
  markeren = false;
  gewonnen = false;
  compPlay = false;
  h = 0;
  b = 0;
  perc = 0;
  zetten = 0;
  spellen = 0;
  aantalk = 0;
  gemarkeerdKoffie = 0;
}//koffiebord::koffiebord constructor

//Dit is de destructor van het bord, die alle vakjes weghaald
koffiebord::~koffiebord() {
    bordvakje* x = ingang;
    bordvakje* y = ingang -> buren[4];
    //Alle vakjes langs
    while(y != nullptr) {
        while(x != nullptr) {
            bordvakje* temp = x;
            x = x -> buren[2];
            delete temp;
        }//while
        x = y;
        y = y -> buren[4];
    }//while
    //Laatste rij wegwerken
    while(x != nullptr) {
        bordvakje* temp = x;
        x = x -> buren[2];
        delete temp;
    }//while
}//koffiebord::~koffiebord destructor

//Dit is de constructor van een vakje, die alle waardes op
  //standaard zet bij aanroepen
bordvakje::bordvakje(){
  x = 0;
  y = 0;
  info = 0;
  aantal = 0;
  koffie = false;
  gemarkeerd = false;
  geopendzichtbaar = false;
}//bordvakje constructor

//inlezen van getallen
double koffiebord::leesGetal(int maxi) {
  int getal = 0;
  char kar = cin.get();
  while(kar == '\n') {
    kar = cin.get();
  }//while
  while(kar != '\n') {
    if(kar >= '0' && kar <= '9') {
      getal = getal*10 + (kar - '0');
    }//if
    kar = cin.get();
  }//while
  if(getal < 0 || getal > maxi) {
    cout << getal << " Dit valt buiten het limiet (0-" << maxi <<").";
    if(getal < 0) {
      getal = getal*(0-1);
    }//if
    while(getal > maxi) {
      getal = getal-1;
    }//while
    cout << "De nieuwe waarde is " << getal << " geworden. " << endl;
  }//if
  return getal;
}//koffiebord::leesGetal

//Hier wordt het bord gebouwd door de bouwende functies aan te roepen
void koffiebord::bouwbord(){
  bordvakje* p;
  bordvakje* q;
  ingang = new bordvakje;
  p = ingang;
  zetten = 0;

  for(int t = 0; t < h; t++){
    q = p;
    if(t > 0){
      p = new bordvakje;
    }//if
    maakrij(b,p,ingang);
    strooikoffie(p);
    if(t>0){
      nieten(p,q,b,t,h);
    }//if
  }//for
  buurkoffie(ingang,h,b);
}//koffiebord::bouwbord

//Hier worden de rijen voor het bord gemaakt
bordvakje* koffiebord::maakrij(int b,bordvakje* p, bordvakje* ingang){
  p -> buren[0] = nullptr;
  p -> buren[4] = nullptr;
  p -> buren[1] = nullptr;
  p -> buren[5] = nullptr;
  p -> buren[7] = nullptr;
  p -> buren[3] = nullptr;
  p -> buren[2] = nullptr;
  p -> buren[6] = nullptr;
  for(int k = 0; k < b; k++){
    if(k == 0){
      p -> vorige = nullptr;
      p -> volgende = nullptr;
      p -> info = k;
      p -> koffie = false;
      p -> geopendzichtbaar = false;
      p -> gemarkeerd = false;
      p -> aantal = 0;
    }//if
    else{
      p -> volgende = new bordvakje;
      p -> volgende -> koffie = false;
      p -> volgende -> geopendzichtbaar = false;
      p -> volgende -> gemarkeerd = false;
      p -> volgende -> info = k;
      p -> volgende -> aantal = 0;
      p -> volgende -> vorige = p;
      p -> volgende -> volgende = nullptr;
      p = p -> volgende;
    }//else
  }//for
  return ingang;
}//koffiebord::maakrij

//Hier worden de de pointers, voor het bord, aan elkaar geniet
bordvakje* koffiebord::nieten(bordvakje* p, bordvakje* q,
                              int b, int t, int h){

  for(int k = 0; k < b; k++){
    q -> buren[2] = q -> volgende;
    q -> buren[3] = p -> volgende;
    q -> buren[4] = p;
    q -> buren[5] = p -> vorige;
    q -> buren[6] = q -> vorige;
    p -> buren[0] = q;
    p -> buren[7] = q -> vorige;
    p -> buren[1] = q -> volgende;
    p -> buren[2] = p -> volgende;
    p -> buren[6] = p -> vorige;
    if(t == h-1){
      p -> buren[3] = nullptr;
      p -> buren[4] = nullptr;
      p -> buren[5] = nullptr;
    }//if
    if(t == 1){
      q -> buren[0] = nullptr;
      q -> buren[1] = nullptr;
      q -> buren[7] = nullptr;
    }//if
    p = p -> volgende;
    q = q -> volgende;
  }//for
  return ingang;
}//koffiebord::nieten

//Hier wordt het bord afgedrukt voor de gebruiker
void koffiebord::drukaf(bordvakje* ingang, int h, int b){
  bordvakje* z = ingang;
  cout << endl;
  cout <<"    ";
  for(int r = 0; r < b; r++){
    if(r > 9){
      cout << r%10  << " ";
    }//if
    else
      cout << r << " ";
  }//for
  cout << endl;
  for(int t = 0; t < h; t++){
    if(t < 10){
      cout << " ";
    }//if
    cout << t <<": ";
    for(int k = 0; k < b; k++){
      if(z -> geopendzichtbaar){
        cout << z -> aantal << " ";
      }//else if
      else if(z -> gemarkeerd){
        cout << "K ";
      }//else if
      else
        cout <<". ";
      z = z -> volgende;
    }//for
    z = ingang;
    for(int v = 0; v <= t; v++){
      z = z -> buren[4];
    }//for
  cout << endl;
  }//for
}//koffiebord::drukaf

//Hier wordt de koffie geteld in de buurvakjes, voor de gebruiker
void koffiebord::buurkoffie(bordvakje* ingang, int h, int b){
  bordvakje* z;
  z = ingang;
  for(int t = 0; t < h; t++){
    for(int k = 0; k < b; k++){
      for(int r = 0; r < 8; r++){
        if(z -> buren[r] != nullptr){
          if(z -> buren[r] -> koffie){
            z -> aantal++;
          }//if
        }//if
      }//for
    z = z -> volgende;
    }//for
    z = ingang;
    for(int v = 0; v<= t; v++){
      z = z -> buren[4];
    }//for
  }//for
}//koffiebord::buurkoffie

//Hier wordt koffie gestrooid voor de gebruiker
void koffiebord::strooikoffie(bordvakje* p){
  while(p){
    int rNum = rand() % 100;
    if(rNum < perc){
      p -> koffie = true;
      aantalk++;
      gemarkeerdKoffie = aantalk;
    }//if
    else if(rNum > perc){
      p -> koffie = false;
    }//else if
   p = p -> volgende;
  }//while
}//koffiebord::strooikoffie

//Hier wordt het vakje gekozen, gemarkeerd en het spel gestopt
  //als je een koffie kiest
void koffiebord::vakjekiezen(int b, int h, bordvakje* ingang){
  int i = 0, j = 0;
  bordvakje* e = ingang;
  cout << "Geef rij ";
  j = leesGetal(h-1);
  cout << "Geef kolom ";
  i = leesGetal(b-1);
  for(int q = 0; q < i; q++){
    e = e -> buren[2];
}//for
  for(int w = 0; w < j; w++){
    e = e -> buren[4];
  }//for
  if(markeren){
    if(!e -> gemarkeerd){
      e -> gemarkeerd = true;
      gemarkeerdKoffie--;
    }//if
    else if(e -> gemarkeerd){
      cout << "Dit vakje was al gemarkeerd, probeer het nog "
              "eens." << endl;
    }//else if
  }//if
  if(openen){
    if(!e -> geopendzichtbaar){
      openVakje(e);
      zetten++;
    }//if
    else if(e -> geopendzichtbaar){
      cout <<"Dit vakje was al open, probeer het nog een keer."<<endl;
    }//else if
  }//if
}//koffiebord::vakjekiezen

//Alle waardes in de vakjes worden naar standaard gezet
void koffiebord::leegbord(){
  klaar = false;
  bordvakje* pointerX = ingang;
  bordvakje* pointerY = ingang;
  for(int r = 0; r < h; r++){
    for(int q = 0; q < b; q++){
      pointerX -> geopendzichtbaar = false;
      pointerX -> gemarkeerd = false;
      pointerX -> koffie = false;
      pointerX -> aantal = 0;
      pointerX = pointerX -> buren[2];
    }//for
    pointerY = pointerY -> buren[4];
    pointerX = pointerY;
  }//for
  zetten = 0;
}//koffiebord::leegbord

//Hier wordt koffie gestrooid voor de computer
void koffiebord::strooikoffieComp(){
  bordvakje* strooiX = ingang;
  bordvakje* strooiY = ingang;
  while(strooiX != nullptr){
    for(int r = 0; r < h; r++){
      for(int q = 0; q < b; q++){
        int rNum = rand() % 100;
        if(rNum < perc){
          strooiX -> koffie = true;
        }//if
        else if(rNum > perc){
          strooiX -> koffie = false;
        }//else if
        strooiX = strooiX -> buren[2];
      }//for
      strooiY = strooiY -> buren[4];
      strooiX = strooiY;
    }//for
  }//while
}//koffiebord::strooikoffie

//De koffieteller van buurvakjes, gebruikt door de computer
void koffiebord::buurkoffieComp(){
  bordvakje* buurkoffieX = ingang;
  bordvakje* buurkoffieY = ingang;
  for(int t = 0; t < h; t++){
    for(int k = 0; k < b; k++){
      for(int r = 0; r < 8; r++){
        if(buurkoffieX -> buren[r] != nullptr){
          if(buurkoffieX -> buren[r] -> koffie){
            buurkoffieX -> aantal++;
          }//if
        }//if
      }//for
      buurkoffieX = buurkoffieX -> buren[2];
    }//for
    buurkoffieY = buurkoffieY -> buren[4];
    buurkoffieX = buurkoffieY;
  }//for
}//koffiebord::buurkoffieComp

//Start de computer als speler
void koffiebord::compzet(){
  cout << "Hoeveel spellen moet de computer spelen?:  .. ";
  spellen = leesGetal(9999);
  int gewonnenSpellen[30] = {0};
  int verlorenSpellen[30] = {0};
  bouwbord();
  for(int t = 0; t < spellen; t++){
    leegbord();
    strooikoffieComp();
    buurkoffieComp();
    while(!klaar){
      randomZetComp();
      alklaarComp();
      zetten++;
    }//while
    if(zetten >= 30){
      zetten = 29;
    }//if
    if(gewonnen){
      gewonnenSpellen[zetten]++;
    }//if
    else{
      verlorenSpellen[zetten]++;
    }//else
  }//for
  cout << endl << "Zo te zien is de computer klaar met spelen" <<endl;
  cout << "Hieronder een aantal resultaten." << endl << endl;
  cout << endl << "Gewonnen spellen door de computer en benodigde "
                  "zetten" << endl;
  for(int i = 0; i < 30; i++){
    cout << i << "  " << gewonnenSpellen[i] << endl;
  }//for
  cout << endl << "Verloren spellen door de computer en benodigde "
                  "zetten" << endl;
  for(int i = 0; i < 30; i++){
    cout << i << "  " << verlorenSpellen[i] << endl;
  }//for
  cout << endl << "Resultaten gezien? Zo niet, kijk hierboven."<<endl;
  cout << "Voor de rest is het spel klaar en zal het nu afgesloten "
          "worden. Wij wensen u nog een prettig dag!" << endl << endl;
}//koffiebord::compzet

//Hier worden random zetten gedaan, nadat de gebruiker daarvoor
  //heeft gekozen
void koffiebord::randomZet(int h, int b, bordvakje* ingang){
  bordvakje* e = ingang;
  int randi = rand() % b;
  int randj = rand() % h;
  cout << endl << "De random zet was op kolom " << randi << " en rij "
  << randj << " geplaatst." << endl << endl;
    //i en j zijn coordinaten van open te breken vakje
  for(int q = 0; q < randi; q++){
    e = e -> buren[2];
  }//for
  for(int w = 0; w < randj; w++){
    e = e -> buren[4];
  }//for
  openVakje(e);
  zetten++;
}//koffiebord::randomZet

//Hier worden de random zetten berekent en uitgevoerd voor de computer
void koffiebord::randomZetComp(){
  bordvakje* eKolom = ingang;
  bordvakje* eRij = ingang;
  int randi = rand() % b;
  int randj = rand() % h;
  for(int q = 0; q < randj-1; q++){
    for(int w = 0; w < randi-1; w++){
      eKolom = eKolom -> buren[2];
    }//for
    eRij = eRij -> buren[4];
    eKolom = eRij;
  }//for
  openVakje(eKolom);
}//koffiebord::randomZetComp

//Hier wordt een vakje geopend, en is er nog de mogelijkheid tot
  //het openen van lege buren
void koffiebord::openVakje(bordvakje*&e){
  if(zetten < 1 && e -> koffie){
    for(int r = 0; r < 8; r++){
      if(e -> buren[r]){
        e -> buren[r] -> aantal--;
      }//if
    }//for
    e -> koffie = false;
    gemarkeerdKoffie--;
  }//if
  e -> geopendzichtbaar = true;
  if(e -> aantal == 0){
    for(int r = 0; r < 8; r++){
      if(e -> buren[r] != nullptr &&
         !e -> buren[r] -> geopendzichtbaar &&
         !e -> buren[r] -> koffie){
        openVakje(e -> buren[r]);
      }//if
    }//for
  }//if
  if(e -> koffie && e -> geopendzichtbaar){
    klaar = true;
    if(!compPlay){
      cout << "Boem, verloren" << endl;
    }//if
  }//if
}//koffiebord::openVakje

//Hier wordt gekeken of alle lege vakjes opgevraagd zijn,
  //door de gebruiker.
void koffiebord::alklaar(bordvakje* ingang, int h, int b){
  bordvakje* z = ingang;
  int open = 0;
  int mogelijkKoffie = aantalk;
  int asfd = h*b;
  for(int t = 0; t < h; t++){
    for(int k = 0; k < b; k++){
      if(((z -> geopendzichtbaar))){
        open++;
      }//if
      z = z -> volgende;
    }//for
    z = ingang;
    for(int v = 0; v <= t; v++){
      z = z -> buren[4];
    }//for
  }//for
  open = open + mogelijkKoffie;
  if(open >= asfd){
    cout << "GEWONNEN, Hoezee!" << endl;
    klaar = true;
  }//if
}//koffiebord::alklaar

//Hier wordt gekeken of alle lege vakjes opgevraagd zijn,
  //door de computer.
void koffiebord::alklaarComp(){
  bordvakje* zKolom = ingang;
  bordvakje* zRij = ingang;
  int open = 0;
  int mogelijkKoffie = aantalk;
  int asfd = h*b;
  for(int t = 0; t < h; t++){
    for(int k = 0; k < b; k++){
      if(zKolom -> geopendzichtbaar){
        open++;
      }//if
      zKolom = zKolom -> buren[2];
    }//for
    zRij = zRij -> buren[4];
    zKolom = zRij;
  }//for
  open = open + mogelijkKoffie;
  if(open == asfd){
    gewonnen = true;
    klaar = true;
  }//if
}//koffiebord::alklaarComp
