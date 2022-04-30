## VERSIJA 0.1

**Programa nuskaito vartotojo įvedamą informaciją apie kiekvieną studentą ir išveda rezultatų suvestinę**

Kiekvieno studento duomenys yra saugomi struktūroje _Studentas_. Joje saugomi studento vardas, pavardė, namų darbų pažymiai, egzamino rezultatas ir galutinis bendras balas.

Vartotojas gali įvesti kiek nori studentų, kol pats nenutraukia įvedimo ciklo. Kiekvieno studento duomenų įvedimas vyksta funkcijoje _StudentoIvedimas(Studentas)_.

Vartotojas gali įvesti norimą kiekį namų darbų pažymių. Namų darbų bei egzamino rezultatai iš pradžių saugomi _string x_ kintamąjame, kad būtų lengviau tikrinti įvesties tinkamumą. Funkcija _TinkamoSveikojoSkaiciausIvedimas()_ tikrina ar ivestis yra tinkamas skaičius, tai yra neturi jokių netinkamų simbolių, išskyrus 'r', norint sugeneruoti atsitiktinę reikšmę, ir '-' prieš sveikąjį skaičių, norint užbaigti įvestį. Jei įvestis netinkama, vartotojas dėl to perspėjamas ir prašoma pažymį įvesti iš naujo.

Vartotojas įvedęs informaciją apie visus studentus, gali pasirinkti norimą galutinio balo skaičiavimo būdą _IvestiSkaiciavimoBuda(string)_.

Yra pateikti du .cpp failai, viename jų (main_ndC.cpp) namų darbų pažymiai saugomi dinaminiame C masyve, kitame (main.cpp) namų darbų pažymiai saugomi vektoriuje.

## VERSIJA 0.1a

-Pakeistas pažymių generavimas, dabar visi pažymiai generuojami iš karto, pasirinkus norimą pažymių kiekį.

-Įvedus nelogišką pažymį, vartotojo paprašoma jį įvesti iš naujo.

## VERSIJA 0.2

Pridėta galimybė nuskaityti studentų duomenis iš failo.

Studentai išvedami pagal vardą, abėcėliškai didėjančia tvarka.

Šioje versijoje visiem studentam suteikiami atsitiktiniai vardai ir pavardės.

## VERSIJA 0.3

Sukurti atskiri failai studento funkcijom (studentu_suvestine.cpp), bendrom skaičiavimų funkcijom (skaiciavimai.cpp) ir pagrindinis failas (main.cpp).

Pridėtas išimcių valdymas patikrinti ar duomenu failas egzistuoja.

## VERSIJA 0.4

Duomenu failai gali būti generuojami.

Automatiškai generuojami vartotojo nustatyto dydžio studentų irašų duomenų failai.

Duomenų failo generavimo, apdorojimo ir išvedimo laikas matuojamas ir išvedamas komandinėje eilutėje:

![image](https://user-images.githubusercontent.com/99316667/158587079-75147900-505f-47ae-8e60-902c2170be5c.png)

## VERSIJA 0.5

Ištestuotas programos duomenų skaitymo bei skirstymo į kategorijas laikas naudojant tris skirtingus konteinerius - **vector**, **list** ir **deque**.

### Rezultatai
| Vector | List | Deque |
|--------|------|-------|
|![vector](https://user-images.githubusercontent.com/99316667/161388116-8cd18f86-f88b-4eb0-b868-e1d13f618fdc.png)|![list](https://user-images.githubusercontent.com/99316667/161388334-db976e2d-079a-4f2b-ad56-852f8423e447.png)|![deque](https://user-images.githubusercontent.com/99316667/161388127-5352f276-2f5c-414f-bcc8-e03d1d373633.png)|

### Sistemos parametrai
![specs](https://user-images.githubusercontent.com/99316667/161387499-d852a60b-95ac-47c4-aeca-5a3768fa49e0.png)

## VERSIJA 1.0

### Išmatuotas programos veikimas naudojant tris skirtingas strategijas:

#### STRATEGIJA 1
Studentai dalinami į atskirus vargšiukų ir moksliukų konteinerius, nieko neištrinant.  
Toks būdas gan greitas, tačiau užima daug atminties.

| Vector | List | Deque |
|--------|------|-------|
|![vector_strat1](https://user-images.githubusercontent.com/99316667/163709849-a3d836b3-83c3-4fbb-a789-dbf2bf6ac0b3.png)|![list_strat1](https://user-images.githubusercontent.com/99316667/163709850-f2aa2232-53f7-4e58-aedb-46112f0e697f.png)|![deque_strat1](https://user-images.githubusercontent.com/99316667/163709855-171b142d-aacd-4d2b-b1f4-700fa4bb6b04.png)|

#### STRATEGIJA 2
Studentai perkeliami į vargšiukų konteinerį, jeigu jie ten priklauso, ir ištrinami iš pradinio studentų konteinerio.  
*List* atveju reikėjo truputį pakeisti kodą, kadangi kitaip programa tiesiog nustodavo veikti su labai dideliais studentų kiekiais.

| Vector | List | Deque |
|--------|------|-------|
|![vector_strat2](https://user-images.githubusercontent.com/99316667/163709876-4400f415-fc39-4a4b-b9a9-d3499098246e.png)|![list_strat2](https://user-images.githubusercontent.com/99316667/163709882-7ec53457-9457-40c5-94a7-ed64722912c4.png)|![deque_strat2](https://user-images.githubusercontent.com/99316667/163709885-5f817cb3-6864-4e96-b50a-40114ea22cc4.png)|

#### STRATEGIJA 3
Studentai išrūšiuojami pagal galutinį vidurkį, tuomet randamas paskutinio studento pozicija, kurio galutinis vidurkis yra ne didesnis nei 5.00. Pagal tai galime atskirti studentus į moksliukus ir vargšiukus naudojant po viena kopijavimo operaciją abiems konteineriams. Po kiekvienos kopijavimo operacijos, tie studentai panaikinami iš pradinio studentų konteinerio.  

| Vector | List | Deque |
|--------|------|-------|
|![vector_strat3](https://user-images.githubusercontent.com/99316667/163709893-f0268f03-4a18-4008-a70e-509f53d8521c.png)|![list_strat3](https://user-images.githubusercontent.com/99316667/163709896-adb25ed4-7c07-469c-a7d0-cdb2591c91f9.png)|![deque_strat3](https://user-images.githubusercontent.com/99316667/163709898-e97c280f-857f-4c3a-a180-6dfbdaf0ac8e.png)|

### Vektoriaus optimizacija naudojant *partition* vietoj *sort*
Vektorius nerikiuojamas visiškai iš eilės pagal galutinį vidurkį, o elementai tik "sumėtomi" atsitiktine tvarka į dvi atskiras puses - mažesnę nei 5.00 ir ne mažesnę nei 5.00.

| Sort | Partition |
|------|-----------|
|![vector_strat3](https://user-images.githubusercontent.com/99316667/163709942-9ebe0056-5463-4e3d-8d90-672e25d56157.png)|![vector_optimized](https://user-images.githubusercontent.com/99316667/163709944-7ae95663-5d05-4748-9191-df33b4f1b0f0.png)|

### NAUDOJIMO INSTRUKCIJA

1. Yra trys aplankai su skirtingai realizuotu tuo pačiu projektu - vector, list ir deque
2. Makefile pagalba galima susigeneruoti .exe failą komandinėje eilutėje įvedus "make"
3. Programa turi kelias pagrindines opcijas:  
a) Rankinis duomenų įvedimas ir rezultatų išvedimas komandinėje eilutėje  
b) Automatinis duomenų failų generavimas į formatą "st<nurodytas_studentu_kiekis>.txt"  
c) Sugeneruotų duomenų failų rezultatų išvedimas į atskirus failus bei programos spartos analizė
4. Kiekvienas žingsnis reikalaujantis vartotojo atsako yra aiškiai aprašytas programos vykdymo eigoje.

## VERSIJA 1.1

Pakeitus Studento struktūrą į klasę, programos veikimo sparta beveik visiškai nepasikeitė.

| Struct | Class |
|--------|-------|
|![image](https://user-images.githubusercontent.com/99316667/166121690-018ea1ff-5e41-4d36-81e0-330d95cd8707.png)|![vector_class_test](https://user-images.githubusercontent.com/99316667/166121604-f8eb37c1-511d-48e9-86be-c1ac875ea3fa.png)|

Ištestuoti trys skirtingi kompiliatoriaus optimizavimo lygio *flagai* - O1, O2 ir O3. Visi jie paspartino programos veikimą, tačiau žemiausio lygio *flagas* buvo sparčiausias. Visgi ženklaus skirtumo tarp jų, testuojant 100.000 ir 1.000.000 dydžio studentų failus, nepastebėta.

| O1 | O2 | O3 |
|----|----|----|
|![O1_vector](https://user-images.githubusercontent.com/99316667/166121819-3ec06291-f634-411b-a5bf-2f5b5772f60f.png)|![O2_vector](https://user-images.githubusercontent.com/99316667/166121821-00b52c46-7b7e-4b7d-9332-b4d83759aa79.png)|![O3_vector](https://user-images.githubusercontent.com/99316667/166121822-de7f22e7-2940-430e-a036-8c6705e3ba5a.png)|





