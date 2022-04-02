## VERSIJA 0.1

**Programa nuskaito vartotojo įvedamą informaciją apie kiekvieną studentą ir išveda rezultatų suvestinę**

-Kiekvieno studento duomenys yra saugomi struktūroje _Studentas_. Joje saugomi studento vardas, pavardė, namų darbų pažymiai, egzamino rezultatas ir galutinis bendras balas.

-Vartotojas gali įvesti kiek nori studentų, kol pats nenutraukia įvedimo ciklo. Kiekvieno studento duomenų įvedimas vyksta funkcijoje _StudentoIvedimas(Studentas)_.

-Vartotojas gali įvesti norimą kiekį namų darbų pažymių. Namų darbų bei egzamino rezultatai iš pradžių saugomi _string x_ kintamąjame, kad būtų lengviau tikrinti įvesties tinkamumą. Funkcija _TinkamoSveikojoSkaiciausIvedimas()_ tikrina ar ivestis yra tinkamas skaičius, tai yra neturi jokių netinkamų simbolių, išskyrus 'r', norint sugeneruoti atsitiktinę reikšmę, ir '-' prieš sveikąjį skaičių, norint užbaigti įvestį. Jei įvestis netinkama, vartotojas dėl to perspėjamas ir prašoma pažymį įvesti iš naujo.

-Vartotojas įvedęs informaciją apie visus studentus, gali pasirinkti norimą galutinio balo skaičiavimo būdą _IvestiSkaiciavimoBuda(string)_.

-Yra pateikti du .cpp failai, viename jų (main_ndC.cpp) namų darbų pažymiai saugomi dinaminiame C masyve, kitame (main.cpp) namų darbų pažymiai saugomi vektoriuje.

## VERSIJA 0.1a

-Pakeistas pažymių generavimas, dabar visi pažymiai generuojami iš karto, pasirinkus norimą pažymių kiekį.

-Įvedus nelogišką pažymį, vartotojo paprašoma jį įvesti iš naujo.

## VERSIJA 0.2

-Pridėta galimybė nuskaityti studentų duomenis iš failo.

-Studentai išvedami pagal vardą, abėcėliškai didėjančia tvarka.

-Šioje versijoje visiem studentam suteikiami atsitiktiniai vardai ir pavardės.

## VERSIJA 0.3

-Sukurti atskiri failai studento funkcijom (studentu_suvestine.cpp), bendrom skaičiavimų funkcijom (skaiciavimai.cpp) ir pagrindinis failas (main.cpp).

-Pridėtas išimcių valdymas patikrinti ar duomenu failas egzistuoja.

## VERSIJA 0.4

-Duomenu failai gali būti generuojami.

-Automatiškai generuojami vartotojo nustatyto dydžio studentų irašų duomenų failai.

-Duomenų failo generavimo, apdorojimo ir išvedimo laikas matuojamas ir išvedamas komandinėje eilutėje:

![image](https://user-images.githubusercontent.com/99316667/158587079-75147900-505f-47ae-8e60-902c2170be5c.png)

## VERSIJA 0.5

-Ištestuotas programos duomenų skaitymo bei skirstymo į kategorijas laikas naudojant tris skirtingus konteinerius - **vector**, **list** ir **deque**.

### Rezultatai
| Vector | List | Deque |
|--------|------|-------|
|![vector](https://user-images.githubusercontent.com/99316667/161388116-8cd18f86-f88b-4eb0-b868-e1d13f618fdc.png)|![list](https://user-images.githubusercontent.com/99316667/161388334-db976e2d-079a-4f2b-ad56-852f8423e447.png)|![deque](https://user-images.githubusercontent.com/99316667/161388127-5352f276-2f5c-414f-bcc8-e03d1d373633.png)|

### Sistemos parametrai
![specs](https://user-images.githubusercontent.com/99316667/161387499-d852a60b-95ac-47c4-aeca-5a3768fa49e0.png)


