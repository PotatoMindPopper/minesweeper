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
Versie/Version/Patch:                           1.16.2
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

//inlezen van een karakter en een ENTER afhandelen
char leesOptie() {
  char kar = cin.get();
  char storedKar = '$';
  while(kar == '\n') {
    kar = cin.get();
  }//while
  while(kar != '\n') {
    if((kar >= 'a' && kar <= 'z') || (kar >= 'A' && kar <= 'Z')) {
      storedKar = kar;
    }//if
    kar = cin.get();
  }//while
  return storedKar;
}//leesOptie

//Dit is om consistent te blijven in het stellen van
  //vragen aan de gebruiker
void tekst(int zetten, int gemarkeerd){
  cout << endl << "U heeft " << zetten << " zet(ten) gezet." << endl;
  cout << "U moet nog " << gemarkeerd <<
          " kopjes koffie markeren." << endl;
  cout << "[Z]et [R]andom [M]arkeer [T]erug [S]top   .. ";
}//tekst

//Introductie en eigenschappen bepalen voor het spel
void tekstBeginSpel(){
  cout << "Het spel zal nu beginnen." << endl;
  cout << "U mag nu zelf de grootte van het bord kiezen - maximaal "
          "100 bij 100." << endl;
  cout << "Daarnaast mag u ook het percentage bepalen voor het "
          "aantal kopjes koffie, die verstopt zullen worden - "
          "maximaal 100%." << endl;
  cout << "Ook kunt u kiezen of u zelf wilt spelen of dat de "
          "computer moet spelen." << endl;
  cout << "Begin nu met het invullen van de waardes." << endl << endl;
}//tekstBeginSpel

//Met het infoblokje wordt de gebruiker opgewarmd met verschillende
  //informatie over het programma
void infoblokje();

int main(){
  koffiebord k;
  bordvakje bova;
  infoblokje();
  k.menu();
}//main

//Het hoofdmenu waar het spel mee draait
void koffiebord::menu(){
  char compmens = '$';
  tekstBeginSpel();
  cout << "Hoogte van het bord (h):                   .. ";
  h = leesGetal(100);
  cout << "Breedte van het bord (b):                  .. ";
  b = leesGetal(100);
  cout << "Percentage van het aantal koffie (p):      .. ";
  perc = leesGetal(100);
  cout << "Gaat de [C]omputer of de [M]ens spelen, " << endl <<
          " of wilt u het spel nu al [E]indigen?      .. ";
  compmens = leesOptie();
  while(((compmens!='C'&&compmens!='c')&&
         (compmens!='M'&&compmens!='m')&&
         (compmens!='E'&&compmens!='e'))){
    cout << "Dit was niet een goed antwoord, probeer het hier nog "
            "een keer: ";
    compmens = leesOptie();
  }//while
  switch(compmens){
    case 'C': case 'c':
      compPlay = true;
      compzet();
      break;
    //Computerzet
    case 'E': case 'e':
      cout << endl << "Wat jammer nou, toch wensen wij u een "
                      "fijne dag!" << endl;
      break;
    //Einde
    case 'M': case 'm':
      bouwbord();
      char kar = '$';
      cout << endl << "Er zijn/is " << aantalk << " Koffie(s)" << endl;
      while(!klaar){
        drukaf(ingang,h,b);
        tekst(zetten, gemarkeerdKoffie);
        kar = leesOptie();
        switch(kar){
          case 'Z': case 'z':
            openen = true;
            vakjekiezen(b,h,ingang);
            openen = false;
            break;
          //Zetten
          case 'R': case 'r':
            randomZet(h,b,ingang);
            break;
          //Random zet
          case 'M': case 'm':
            markeren = true;
            vakjekiezen(b,h,ingang);
            markeren = false;
            break;
          //Markeren
          case 'T': case 't':
            cout << endl << "Deze optie is nog niet beschikbaar in "
                            "deze beta versie van het spel." << endl;
            cout << "De releasedatum van het volledige spel staat "
                    "halverwege 2022." << endl;
            cout << "Om deze reden zal u weer terug gaan naar het "
                    "menu." << endl;
            break;
          //Terug
          case 'S': case 's':
            klaar = true;
            break;
          //Stoppen
          default:
            cout << endl << "Geen geldige optie gekozen, probeer "
                            "opnieuw." << endl;
          //standaard
        }//switch
        alklaar(ingang,h,b);
      }//while
      drukaf(ingang,h,b);
      cout << "Het spel is beeindigt na "<<zetten<<" zet(ten)"<<endl;
      break;
    //Menszet
  }//switch
}//koffiebord::menu

//Een informatief stukje tekst voor de gebruiker
  //voordat het spel begint
void infoblokje(){
  char typToCont = '$';
  cout << "Beste gebruiker, welkom bij Minesweeper!" << endl;
  cout << "U zal zo een potje Mijnenveger, in de vorm van "
          "koffiesweeper, gaan spelen." << endl;
  cout << "Dit kan tegen uzelf of tegen een computer." << endl;
  cout << "Voordat we het spel starten, hebben we eerst wat "
          "informatie voor u." << endl;
  cout << "Zo heeft de game een aantal acties nodig. Deze doelen "
          "staan hieronder: " << endl;
  cout << "-   Zoek en open elk vakje dat geen kopje koffie "
          "bevat." << endl;
  cout << "      Een geopend vakje, dat geen koffie bevat zal een "
                  "nummer bevatten."<<endl<<"      Dit nummer geeft "
                  "aan hoeveel kopjes koffie om dit vakje zitten."
                  <<endl<<"      Hierbij gaat het om vakjes die "
                  "naast elkaar zitten of schuin van elkaar staan."
                  << endl;
  cout << "-   Zoek en markeer de plekjes waar u denkt dat een "
          "kopje koffie zit." << endl;
  cout << "Winnen doet u door alle vakjes te openen zonder een "
          "kopje koffie te open. " << endl << "Verliezen doet u "
          "door een kopje koffie te openen." << endl << endl;
  cout << "Nu de game een beetje is uitgelegd, komen er nog een "
          "aantal technische/persoonlijke informatiestukken aan bod."
          << endl;
  cout << "Zo zijn de auteurs van dit programma: PotatoMindPopper" << endl;
  cout << "En is dit programma gemaakt in Code::Blocks 20.03." <<endl;
  cout << "Daarnaast is de meest recente update uitgevoerd op "
          "17-11-2022." << endl << endl;
  cout << "Extra informatie: " << endl;
  cout << "- Wanneer er om een optie gevraagd wordt, druk dan na "
            "het intypen van de optie op ENTER, " << endl <<
            "  zodat het programma door zal gaan." << endl;
  cout << "- Een gemarkeerd vakje krijgt de letter 'K' op het "
            "bord." << endl;
  cout << "- Aan de buitenkant van het bord staan de nummers van de "
            "desbetreffende kolom of rij." << endl;
  cout << "- Momenteel speelt u een beta versie van dit spel."<<endl<<
            "  Dit kan ervoor zorgen dat sommige opties niet geheel "
            "naar behoren werken, onze excuzes voor het ongemak."
             << endl << endl;
  cout << "Typ X hier om door te gaan: ";
  typToCont = leesOptie();
  if(typToCont == 'X' || typToCont == 'x') {
    cout << "Dit is correct en u wordt doorgestuurd naar het "
            "programma." << endl << endl;
            for(int i = 0; i < 28; i++){
              cout << endl;
            }//for
  }//if
  else {
    cout << "Dit was niet het goede antwoord, maar u zult "
            "doorgestuurd worden naar het programma." << endl << endl;
            for(int i = 0; i < 28; i++){
              cout << endl;
            }//for
  }//else
}//infoblokje
