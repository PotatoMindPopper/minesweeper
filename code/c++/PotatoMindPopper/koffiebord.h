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

Bestandsnaam/File name:                         koffiebord.h
Datum van creatie/Date of Creation:             05-12-2021
Datum van afgifte/Date of Release:              13-12-2021
Meeste recente update/Latest Patch-date:        17-11-2022
Versie/Version/Patch:                           1.16.5
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

class bordvakje {
  public:
    // member-variabelen
    bool geopendzichtbaar = false;
    bool gemarkeerd = false;
    bool koffie;
    int aantal = 0;
    bordvakje *buren[8];
    bordvakje *vorige;
    bordvakje *volgende;
    int info;
    int x = 0, y = 0;
    bordvakje();
};

class koffiebord {
  private:
    // member-variabelen
    int h, b;
    int perc;
    bool markeren = false;
    bool openen = false;
    bool klaar = false;
    bool gewonnen = false;
    bool compPlay = false;
    int zetten = 0;
    int spellen = 0;
    int aantalk = 0;
    int gemarkeerdKoffie = 0;
    bordvakje *ingang;
    bordvakje *uitgang;

  public:
    // Algemene functies
    koffiebord();  // constructor
    ~koffiebord(); // destructor
    double leesGetal(int maxi);
    void voegvoor();
    void bouwbord();
    void leegbord();
    void menu();
    bordvakje *nieten(bordvakje *p, bordvakje *q, int b, int t, int h);
    bordvakje *maakrij(int b, bordvakje *p, bordvakje *ingang);

    // Functies voor de menselijke gebruiker
    void drukaf(bordvakje *ingang, int h, int b);
    void strooikoffie(bordvakje *p);
    void buurkoffie(bordvakje *ingang, int h, int b);
    void vakjekiezen(int b, int h, bordvakje *ingang);
    void randomZet(int h, int b, bordvakje *ingang);
    void openVakje(bordvakje *&e);
    void alklaar(bordvakje *ingang, int h, int b);

    // Functies voor de computer
    void compzet();
    void randomZetComp();
    void strooikoffieComp();
    void buurkoffieComp();
    void alklaarComp();

    // Functie voor de stapel
    // Dit deel van het programma is buiten werking
    // void kopieerVan(koffiebord* oudBord);
};
