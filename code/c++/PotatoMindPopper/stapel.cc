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

Bestandsnaam/File name:                         stapel.cc
Datum van creatie/Date of Creation:             05-12-2021
Datum van afgifte/Date of Release:              13-12-2021
Meeste recente update/Latest Patch-date:        17-11-2022
Versie/Version/Patch:                           1.10.2
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


//Dit deel van het programma is buiten werking

//Uitleg bij de functies is van een medestudent,
  //vandaar dat er soms een vreemde woordkeus is gebruikt
  //Deze uitleg staat standaard in comment modes;
    //dit is ook de reden dat het programma warnings geeft over het
    //gebruik van '/*' binnen commentaar


/*
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "koffiebord.h"
#include "stapel.h"

using namespace std;

Stapel::zetOpStapel(koffiebord* bordStapel){
  bordStapelKopie = new koffiebord;
  bordStapelKopie -> h = bordStapel -> h;
  bordStapelKopie -> b = bordStapel -> b;
  bordStapelKopie -> bouwbord();

  bordStapelKopie -> kopieerVan(bordStapel);

  nieuweEntry = new StapelEntry;


*/
  /*
  Als dit wordt
    geroepen dan maak ik in de functie een nieuw koffiebord (ook echt met
    het woordje new) en dat koffiebord moet dezelfde hoogte en breedte
    hebben als het bord dat als parameter wordt doorgegeven in de functie.
  Jullie moeten denk ik ook bouwbord() roepen want de pointers van dat
    bord moeten gemaakt worden.

  Daarbij hebben we dus nu een heel nieuw
    bord gemaakt, en stel ik noem dat nieuwBord in mijn functie dan moet ik
    nu nieuwBord->kopieerVan(bord) doen om het bord dat aan de functie is
    gegevn te kopieren naar het nieuw gemaakte bord.
  Daarna maak ik een
    nieuwe StapelEntry (je mag het ook anders noemen ofc, dit is ook weer
    met het woord new).

  Van de StapelEntry zet ik het bord op nieuwBord,
    en vorige maak ik ingang.
  Daarna zet ik de ingang op de net gemaakte
    StapelEntry.
  */
/*
}//Stapel::zetOpStapel

Stapel::pakVanStapel(){
  if(ingangStapel == nullptr){
    return nullptr;
  }//if
  else if(ingangStapel != nullptr){
    ingangStapel -> bordStapel;
    ingangStapel = vorigeStapel; //-> bordStapel;
  }//else if
  return vorigeStapel;

*/
  /*
  Eerst kijk ik of de ingang een nullptr is.
  Als dat
    zo is, dan return ik een nullptr.
  Als dat niet zo is dan haal ik het bord op
    van de StapelEntry waar de ingang naartoe wijst en daarna zet ik de
    ingang naar de vorige van die StapelEntry.
  Dan return ik gewoon dat
    bord wat ik daarvoor heb opgehaald.
  */
/*
}//Stapel::pakVanStapel

koffiebord::kopieerVan(koffiebord* oudBord){
  koffiebord* nieuwBord;
  nieuwBord -> h = oudBord -> h;
  nieuwBord -> b = oudBord -> b;
  nieuwBord -> perc = oudBord -> perc;
  nieuwBord -> markeren = oudBord -> markeren;
  nieuwBord -> openen = oudBord -> openen;
  nieuwBord -> klaar = oudBord -> klaar;
  nieuwBord -> gewonnen = oudBord -> gewonnen;
  nieuwBord -> compPlay = oudBord -> compPlay;
  nieuwBord -> zetten = oudBord -> zetten;
  nieuwBord -> spellen = oudBord -> spellen;
  nieuwBord -> aantalk = oudBord -> aantalk;
  nieuwBord -> gemarkeerdKoffie = oudBord -> gemarkeerdKoffie;

  bordvakje* ingangNieuw = nieuwBord -> ingang;
  bordvakje* pointerXNieuw = ingangNieuw;
  bordvakje* pointerYNieuw = ingangNieuw;
  bordvakje* ingangOud = oudBord -> ingang;
  bordvakje* pointerXOud = ingangOud;
  bordvakje* pointerYOud = ingangOud;

  for(int r = 0; r < h; r++){
    for(int q = 0; q < b; q++){

      //change info here
      ingangNieuw -> aantal = ingangOud -> aantal;
      ingangNieuw -> geopendzichtbaar = ingangOud -> geopendzichtbaar;
      ingangNieuw -> gemarkeerd = ingangOud -> gemarkeerd;
      ingangNieuw -> koffie = ingangOud -> koffie;
      ingangNieuw -> info = ingangOud -> info;
      ingangNieuw -> x = ingangOud -> x;
      ingangNieuw -> y = ingangOud -> y;


      pointerXNieuw = pointerXNieuw -> buren[2];    //beweeg naar rechts
      pointerXOud = pointerXOud -> buren[2];    //beweeg naar rechts
    }//for
    pointerYNieuw = pointerYNieuw -> buren[4];      //beweeg naar beneden
    pointerYOud = pointerYOud -> buren[4];      //beweeg naar beneden
    pointerXNieuw = pointerYNieuw;                  //laat x weer vanaf links beginnen
    pointerXOud = pointerYOud;                  //laat x weer vanaf links beginnen
  }//for

*/
  /*
  Deze functie krijgt een pointer van
    een koffiebord als parameter en dan krijgt het bord die deze functie
    aanroept dezelfde inhoud als het bord dat wordt gegeven als parameter.
  Dit doe ik door de variabelen zoals aantalZetten, aantalKoffie, etc.
    natuurlijk gewoon te kopieren en dan alle vakjes van beide borden af te
    gaan en daarvan het aantal, koffie, open, etc. te kopieren.
  */
/*
}//koffiebord::zetOpStapel
*/
