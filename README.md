## [VERSIJA 0.1](https://github.com/DeividasRo/OP-Uzduotis/releases/tag/v0.1)

**Programa nuskaito vartotojo įvedamą informaciją apie kiekvieną studentą ir išveda rezultatų suvestinę**

-Kiekvieno studento duomenys yra saugomi struktūroje _Studentas_. Joje saugomi studento vardas, pavardė, namų darbų pažymiai, egzamino rezultatas ir galutinis bendras balas.

-Vartotojas gali įvesti kiek nori studentų, kol pats nenutraukia įvedimo ciklo. Kiekvieno studento duomenų įvedimas vyksta funkcijoje _StudentoIvedimas(Studentas)_.

-Vartotojas gali įvesti norimą kiekį namų darbų pažymių. Namų darbų bei egzamino rezultatai iš pradžių saugomi _string x_ kintamąjame, kad būtų lengviau tikrinti įvesties tinkamumą. Funkcija _TinkamoSveikojoSkaiciausIvedimas()_ tikrina ar ivestis yra tinkamas skaičius, tai yra neturi jokių netinkamų simbolių, išskyrus 'r', norint sugeneruoti atsitiktinę reikšmę, ir '-' prieš sveikąjį skaičių, norint užbaigti įvestį. Jei įvestis netinkama, vartotojas dėl to perspėjamas ir prašoma pažymį įvesti iš naujo.

-Vartotojas įvedęs informaciją apie visus studentus, gali pasirinkti norimą galutinio balo skaičiavimo būdą _IvestiSkaiciavimoBuda(string)_.

-Yra pateikti du .cpp failai, viename jų (main_ndC.cpp) namų darbų pažymiai saugomi dinaminiame C masyve, kitame (main.cpp) namų darbų pažymiai saugomi vektoriuje.

