<<<<<<< HEAD
# OOP_2uzd
=======
v1.0
Šio tyrimo tikslas yra ištirti programos spartą naudojant skirtingus konteinerius: vector, list, deque. 
Atlikti skirtingi veiksmai su konteineriais ir buvo matuojamas atlikimo veikimo laikas, pavaizduotas lentelėse:

1. Nuskaitymas iš failo į atitinkamą konteinerį.
   
    1.1. Rezultatai skaitymo į List konteinerį:

   | Įrašų skaičius faile | Pirmas bandymas | Antras bandymas | Trečias bandymas | Ketvirtas bandymas | Penktas bandymas | Vidurkis|
   |---------|------|-----------------|-----------------|-----------------|-----------------|-----------------|
   | 1000  | 0.001 | 0.002 | 0.002| 0.002| 0.002|0.0018 |
   | 10000 | 0.018 |  0.019 | 0.022 | 0.018| 0.019 | 0.0192|
   | 100000 | 0.195| 0.22 |  0.2| 0.216| 0.211 | 0.2084|
   | 1000000 | 2.023 | 2.013 | 2.009 | 2.012| 2.018|2.015 |
   | 10000000| 20.616 | 20.63| 20.564 | 20.446| 20.402| 20.5316|

   **1.2. Rezultatai skaitymo į Deque konteinerį:**

   | Įrašų skaičius faile | Pirmas bandymas | Antras bandymas | Trečias bandymas | Ketvirtas bandymas | Penktas bandymas | Vidurkis |
   |---------|------|-----------------|-----------------|-----------------|-----------------|----------|
   | 1000  | 0.002| 0.002 | 0.002| 0.002| 0.002| 0.002    |
   | 10000 | 0.02 |  0.021 | 0.021 | 0.021| 0.021 |   0.0208       |
   | 100000 | 0.214| 0.216 |  0.223| 0.219| 0.224 |      0.2184    |
   | 1000000 | 2.239 | 2.173 | 2.17 | 2.168| 2.173|       2.1846   |
   | 10000000 | 27.198 | 25.904| 25.995 | 26.309| 26.451|   26.3714       |
   1.3 Rezultatai skaitymo į Vector konteinerį:

| Įrašų skaičius faile | Pirmas bandymas | Antras bandymas | Trečias bandymas | Ketvirtas bandymas | Penktas bandymas | Vidurkis|
   |---------|------|-----------------|-----------------|-----------------|-----------------|-----------------|
| 1000  |  0.014           | 0.014           | 0.014            | 0.013| 0.014| 0.0138   |
| 10000 | 0.057           | 0.057           | 0.058            | 0.063| 0.064| 0.0598|
| 100000 | 0.379 |  0.377 |  0.378| 0.627| 0.839| 0.52|
| 1000000 | 3.818 | 3.7 | 3.797| 7.434| 6.293| 5.0084|
| 10000000 | 40.703 | 40.693 | 40.651| 68.402| 66.579| 51.4056|

2. Studentų rūšiavimas didėjimo tvarka (pagal galutinį pažymį iš vidurkio)
   
   2.1 Rūšiavimas su List:

| Įrašų skaičius faile | Pirmas bandymas | Antras bandymas | Trečias bandymas | Ketvirtas bandymas | Penktas bandymas | Vidurkis|
   |---------|------|-----------------|-----------------|-----------------|-----------------|-----------------|
| 1000  |  6.8375e-05          | 5.4833e-05         | 5.5208e-05            | 5.5625e-05| 5.425e-05| 5.76582E-5  |
| 10000 | 0.000776459         | 0.000714625         | 0.000778375           |0.000696541| 0.000743917| 0.0007419834|
| 100000 | 0.0101778 | 0.0134357 |  0.0186094| 0.0109893|0.0101133| 0.0126651|
| 1000000 | 0.413999 | 0.396489| 0.437618| 0.505107| 0.436495| 0.4379416|
| 10000000 | 8.34264 | 8.01193| 8.17679| 8.01488| 8.13933| 8.137114|
2.2. Rūšiavimas su Deque:

| Įrašų skaičius faile | Pirmas bandymas | Antras bandymas | Trečias bandymas | Ketvirtas bandymas | Penktas bandymas | Vidurkis|
|---------|------|-----------------|-----------------|-----------------|-----------------|-----------------|
| 1000  |  1.792e-06      |1.917e-06         | 1.875e-06           | 1.916e-06s| 1.916e-06| 1.8832E-6   |
| 10000 | 6.5625e-05      | 7.3292e-05         | 3e-05           | 6.0708e-05| 6.8958e-05| 5.97166E-5|
| 100000 | 0.00140246 | 0.00144383 |  0.00110646| 0.00239883| 0.00141058|0.001552432|
| 1000000 | 0.105023 | 0.0354815|0.0365577| 0.0287554| 0.0330828| 0.04778008|
| 10000000 | 1.07304 | 0.380618| 0.399486| 0.402701|  0.349551|  0.5210792|

2.3. Rūšiavimas su Vector

| Įrašų skaičius faile | Pirmas bandymas | Antras bandymas | Trečias bandymas | Ketvirtas bandymas | Penktas bandymas | Vidurkis|
|---------|------|-----------------|-----------------|-----------------|-----------------|-----------------|
| 1000  | 0.001           | 0.001           | 0.001            | 0.001| 0.001| 0.018    |
| 10000 | 0.012          | 0.014           | 0.014            | 0.014| 0.093| 0.0968|
| 100000 | 0.135 | 0.144 |  0.142| 0.148| 0.141| 0.142|
| 1000000 | 1.511 |1.436| 1.393| 1.475| 1.452| 1.4534|
| 10000000 | 18.33 | 17.973| 17.974| 17.814| 17.834| 17.985|

3. Įrašų dalijimas į du konteinerius

   3.1. Įrašų dalijimas į List

| Įrašų skaičius faile | Pirmas bandymas | Antras bandymas | Trečias bandymas | Ketvirtas bandymas | Penktas bandymas | Vidurkis |
|----------------------|-----------------|-----------------|------------------|--------------------|------------------|----------|
| 1000                 | 0.000135208     | 0.001           | 0.001            | 0.001              | 0.001            | 0.018    |
| 10000                | 0.00145558      | 0.014           | 0.014            | 0.014              | 0.093            | 0.0968   |
| 100000               | 0.035963        | 0.144           | 0.142            | 0.148              | 0.141            | 0.52     |
| 1000000              | 0.508848        | 1.436           | 1.393            | 1.475              | 1.452            | 5.0084   |
| 10000000             | 4.90112         | 5.40402         | 5.09065          | 4.66368            | 5.0537           | 51.4056  |

3.2. Įrašų dalijimas į Deque

| Įrašų skaičius faile | Pirmas bandymas | Antras bandymas | Trečias bandymas | Ketvirtas bandymas | Penktas bandymas | Vidurkis     |
|----------------------|-----------------|-----------------|------------------|--------------------|------------------|--------------|
| 1000                 | 0.000129417     | 3.7417e-05      | 3.425e-05        | 2.8083e-05         | 2.6167e-05       | 5.10668e-05  |
| 10000                | 0.000269834     | 0.000264333     | 0.000286709      | 0.000259           | 0.00028225       | 0.0002724252 |
| 100000               | 0.00298096      | 0.00301658      | 0.003529         | 0.00297167         | 0.00314108       | 0.003127858  |
| 1000000              | 0.0361712       | 0.0391695       | 0.0389418        | 0.0382549          | 0.0374115        | 0.03798978   |
| 10000000             | 2.93958         | 3.10767         | 3.02076          | 3.08732            | 2.97793          | 3.026652     |

3.3. Įrašų dalijimas į Vector

| Įrašų skaičius faile | Pirmas bandymas | Antras bandymas | Trečias bandymas | Ketvirtas bandymas | Penktas bandymas | Vidurkis |
|----------------------|-----------------|-----------------|------------------|--------------------|------------------|----------|
| 1000                 | 0.001           | 0.001           | 0.001            | 0.001              | 0.001            | 0.001    |
| 10000                | 0.007           | 0.007           | 0.007            | 0.011              | 0.011            | 0.0086   |
| 100000               | 0.062           | 0.063           | 0.063            | 0.103              | 0.101            | 0.0784   |
| 1000000              | 0.694           | 0.699           | 0.695            | 1.135              | 1.12             | 0.8686   |
| 10000000             | 6.554           | 6.594           | 6.566            | 10.4               | 10.341           | 8.091    |

Algoritmas, naudojamas praeitame tyrime, gali būti optimizuotas. Galime tuo įsitikinti naudodami 3 strategijas:

1 strategija - dalijimas į du konteinerius, kur tas pats studentas yra tiek bendrame studentų konteineryje, tiek "vargšiukų" arba "kietekų".
Ši strategija jau buvo panaudota praeitame tyrime ir rezultatai yra užfiksuoti lentelėse viršuje. Tačiau ši strategija yra labai neefektyvi atminties panaudojimo
atvėju. Užfiksuotas 10000000 įrašų skirstymas su deque:


2 strategija - bendro studentų konteinerio skaidymas panaudojant tik vieną konteinerį "vargšiukai". Tokiu būdu visi vagršiukai bus atskirame konteineryje,
o likę studentai bendrame konteineryje bus "kietekai". Lentelėje pateikti tyrimo vidurkiai:

List:

| Įrašų skaičius | Vidurkis      |
|----------------|---------------|
| 1000           | 0.00014743775 |
| 10000          | 0.00166201    |
| 100000         | 0.02433255    |
| 1000000        | 0.34394575    |
| 10000000       | 4.329365      |

Vector:

| Įrašų skaičius | Vidurkis     |
|----------------|--------------|
| 1000           | 3.6875E-5    |
| 10000          | 0.0003421418 |
| 100000         | 0.0037645168 |
| 1000000        | 0.0591652584 |
| 10000000       | 0.7618154    |

Deque:

| Įrašų skaičius | Vidurkis     |
|----------------|--------------|
| 1000           | 1.75832E-5   |
| 10000          | 0.0001462588 |
| 100000         | 0.002258808  |
| 1000000        | 0.34394575   |
| 10000000       | 0.543685     |


3 strategija - bus optimizuota antra strategija efektyvesnius algoritmus.

List:

| Įrašų skaičius | Vidurkis    |
|----------------|-------------|
| 1000           | 1.775E-6    |
| 10000          | 5.67E-5     |
| 100000         | 0.001672314 |
| 1000000        | 0.07585252  |
| 10000000       | 0.8578546   |

Vector:

| Įrašų skaičius | Vidurkis     |
|----------------|--------------|
| 1000           | 5.334E-7     |
| 10000          | 8.0086E-6    |
| 100000         | 8.61754E-5   |
| 1000000        | 0.0010766084 |
| 10000000       | 0.0113756404 |

Deque:

| Įrašų skaičius | Vidurkis    |
|----------------|-------------|
| 1000           | 1.1498E-6   |
| 10000          | 1.41084E-5  |
| 100000         | 0.000241125 |
| 1000000        | 0.003637294 |
| 10000000       | 0.9234382   |



v0.4
Atlikti du tyrimai programos veikimo greičio analizei.
Pirmasis tyrimas skirtas darbo su failais (failų sukurimas ir jo uždarymas) spartos analizei.
Matuojamas skirtingo dydžio failų sukūrimo laikas. Tyrimo patikimumui bandymas buvo atliekamas penkis kartus. Bandymų rezultatai yra pateikti lentelėje (laikas skaičiuojamas sekundėmis):

| Failo pavadinimas    | Pirmas bandymas | Antras bandymas | Trečias bandymas | Ketvirtas bandymas | Penktas bandymas | Vidurkis |
|----------------------|-----------------|-----------------|------------------|--------------------|------------------|----------|
| students1000.txt     | 0.014           | 0.013           | 0.014            | 0.014              | 0.014            | 0.014    |
| students10000.txt    | 0.071           | 0.071           | 0.071            | 0.07               | 0.071            | 0.71     |
| students100000.txt   | 0.627           | 0.622           | 0.63             | 0.619              | 0.616            | 0.6318   |
| students1000000.txt  | 6.186           | 6.207           | 6.347            | 6.2                | 6.238            | 6.2356   |
| students10000000.txt | 68.331          | 69.294          | 69.67            | 68.262             | 68.326           | 68.7766  |

Antrasis tyrimas skirtas duomenų apdorojimo spartos analizei. Atliekami šie veiksmai:

1. Duomenų nuskaitymas iš failo
2. Studentų rūšiavimas į dvi kategorijas
3. Surūšiuotų studentų išvedimą į naujus failus.

Be to, buvo matuojamas visos programos veikimo laikas.Kiekvienas žingsnis taip pat buvo kartojamas po 5 kartus ir pateiktas šių bandymų vidurkis. Rezultatai pateikiami lentelėje (laikas pateikiamas sekundėmis):

1000 įrašų:


|                                                 | Pirmas bandymas | Antras bandymas | Trečias bandymas | Ketvirtas bandymas | Penktas bandymas | Vidurkis |
|-------------------------------------------------|-----------------|-----------------|------------------|-----------------|-----------------|----------|
| Duomenų nuskaitymas iš failo                    | 0.014           | 0.014           | 0.014            | 0.013| 0.014| 0.0138   |
| Duomenų rūšiavimas didėjimo tvarka              | 0.02            | 0.02            | 0.02             | 0.015| 0.015| 0.018    |
| Studentų rūšiavimas į dvi kategorijas           | 0.001           | 0.001           | 0.001            | 0.001| 0.001 | 0.001    |
| Surūšiuotų studentų išvedimas į kietekų failą   | 0.003           | 0.003           | 0.003            | 0.003| 0.003 | 0.003    |
| Surūšiuotų studentų išvedimas į vagršiukų failą | 0.002           | 0.002           | 0.002            | 0.002| 0.002| 0.002    |
| Visos programos veikimo laikas                  | 0.04            | 0.04            | 0.04             |  0.036|  0.037| 0.0386 |

10000 įrašų:

|                                                 | Pirmas bandymas | Antras bandymas | Trečias bandymas | Ketvirtas bandymas | Penktas bandymas | Vidurkis|
|-------------------------------------------------|-----------------|-----------------|------------------|-----------------|----------------|-----------------|
| Duomenų nuskaitymas iš failo                    | 0.057           | 0.057           | 0.058            | 0.063| 0.064| 0.0598|
| Duomenų rūšiavimas didėjimo tvarka              | 0.099           | 0.099           | 0.098            | 0.095| 0.093| 0.0968|
| Studentų rūšiavimas į dvi kategorijas           | 0.007           | 0.007           | 0.007            | 0.011| 0.011 | 0.0086|
| Surūšiuotų studentų išvedimas į kietekų failą   | 0.015           | 0.013           | 0.012            | 0.021| 0.02 |  0.0162|
| Surūšiuotų studentų išvedimas į vagršiukų failą | 0.011           | 0.009           | 0.009            | 0.015|  0.014| 0.0116|
| Visos programos veikimo laikas                  | 0.189           | 0.185           | 0.184            | 0.036| 0.037| 0.1262|


100000 įrašų:

|                                                 | Pirmas bandymas | Antras bandymas | Trečias bandymas | Ketvirtas bandymas | Penktas bandymas | Vidurkis|
|-------------------------------------------------|------|-----------------|-----------------|-----------------|-----------------|-----------------|
| Duomenų nuskaitymas iš failo                    |  0.379 |  0.377 |  0.378| 0.627| 0.839| 0.52|
| Duomenų rūšiavimas didėjimo tvarka              |  0.626 | 0.59 | 0.587| 0.957| 0.953| 0.7426|
| Studentų rūšiavimas į dvi kategorijas           | 0.062|  0.063 | 0.063 | 0.103|  0.101 |0.0784|
| Surūšiuotų studentų išvedimas į kietekų failą   | 0.126| 0.126 | 0.124 | 0.218| 0.218 | 0.1624|
| Surūšiuotų studentų išvedimas į vagršiukų failą | 0.09 | 0.089 | 0.089 | 0.151| 0.145| 0.1128|
| Visos programos veikimo laikas                  |  2.002 | 1.861|  1.262|  2.088| 2.29| 1.9006|

1000000 įrašų:

|                                                 | Pirmas bandymas | Antras bandymas | Trečias bandymas | Ketvirtas bandymas | Penktas bandymas | Vidurkis|
|-------------------------------------------------|------|-----------------|-----------------|-----------------|-----------------|-----------------|
| Duomenų nuskaitymas iš failo                    | 3.818 | 3.7 | 3.797| 7.434| 6.293| 5.0084|
| Duomenų rūšiavimas didėjimo tvarka              |  5.846 | 5.778 |  5.755| 10.024| 9.641| 7.4088|
| Studentų rūšiavimas į dvi kategorijas           | 0.694 |   0.699 |  0.695 |1.135| 1.12 | 0.8686|
| Surūšiuotų studentų išvedimas į kietekų failą   |  1.288| 1.314 |  1.355| 2.15| 2.061 | 1.6336|
| Surūšiuotų studentų išvedimas į vagršiukų failą | 0.901 | 0.973 | 0.891 | 1.477| 1.458| 1.14|
| Visos programos veikimo laikas                  | 13.79|  13.515| 12.675| 22.511| 20.863| 16.6708|


10000000 įrašų:

|                                                 | Pirmas bandymas | Antras bandymas | Trečias bandymas | Ketvirtas bandymas | Penktas bandymas | Vidurkis|
|-------------------------------------------------|------|-----------------|-----------------|-----------------|-----------------|-----------------|
| Duomenų nuskaitymas iš failo                    | 40.703 | 40.693 | 40.651| 68.402| 66.579| 51.4056|
| Duomenų rūšiavimas didėjimo tvarka              |  60.468 | 60.957 | 60.41|  97.318| 96.196| 75.0698|
| Studentų rūšiavimas į dvi kategorijas           | 6.554 | 6.594 |  6.566 | 10.4| 10.341| 8.091|
| Surūšiuotų studentų išvedimas į kietekų failą   | 14.762| 15.332 |  15.472 | 22.336| 21.592 | 17.8988|
| Surūšiuotų studentų išvedimas į vagršiukų failą | 9.717| 9.702 | 9.959 | 16.731| 16.377| 12.4972|
| Visos programos veikimo laikas                  | 135.063 | 135.857| 134.898 | 218.088| 213.962| 167.5736|

>>>>>>> 409c246 (initial commit2)
