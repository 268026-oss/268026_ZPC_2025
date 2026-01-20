+++
date = '2025-09-28T19:52:30+02:00'
draft = false
title = 'Semestrálny projekt'
weight = 1
+++

&nbsp;&nbsp;&nbsp;&nbsp;V rámci výuky je aj semestrálny projekt. Tému pre tento projekt si volíme sami na základe tématiky Jak vyrobit (téměř) cokoliv - How to make (almost) anything. Tento projekt by mal obsahovať prvky 3D tlače, laserového rezania a elektroniky (arduino).

&nbsp;&nbsp;&nbsp;&nbsp;Ja som si za tému zvolil systém pre elektronické terče. Ide o systém, ktorý bude riadiť svetlá (červené a zelené) na terčoch a bude tým signalizovať kedy strelci majú strielať a kedy nie. Bude sa to využívať najmä pri rýchlopalných disciplínach kedy majú strelci len pár sekúnd na výstrel. Okrem prepínania svetiel bude mať systém aj rozpoznávanie neplatného výstrelu - ak bude výstrel mimo času, kedy je povolený (mimo zelené svetlo). Je to teda nástroj, ktorý bude riadiť strelcov a informovať rozhodcu (obsluha tohto zariadenia).

# Fázy a priebeh streleckej disciplíny:
## 1. Príprava
- Strelci su nastúpený na strelisku pri svojich stavoch (box z ktorého strieľajú)
- Rozhodca zavelí povel PRÍPRAVA a spustí program v systéme
- Program spustí časovač - 60 sekúnd (počas toho svieti na terčoch červené svetlo)
- Strelci majú 60 sekúnd aby sa pripravili na streľbu. To znamená, že si skúšajú mierenie, postoj, techniku streľby a taktiež nabíjajú zbraň

## 2. Streľba
- Po uplynutí predošlých 60 sekúnd systém upozorní rozhodcu aby zavelil povel POZOR
- Následne začína ďalší časovač 7 sekúnd - strelci namieria svoje zbrane dole mimo terč a čakajú na zelené svetlo
- Spustenie zeleného svetla - strelci namieria na terč a môžu strieľať
- Po uplynutí určitého času na streľbu (rôzne disciplíny majú rôzne časy), sa rozsvieti červené svetlo a strelci majú prestať strieľať
- Ak niekto zo strelcov vystrelí mimo tento čas (počas červeného svetla), systém to vyhodnotí a ukáže rozhodcovi, ktorý strelec to bol (následná penalizácia rozhodcom)

## 3. Ukončenie
- Systém vypíše UKONČENIE SÉRIE
- Rozhodca po skontrolovaní strelcov zavelí ZBRANE VYBIŤ A ODLOŽIŤ
- Rozhodca pozrie, či sú zbrane odložené a prechádza k terčom pre vyhodnocovanie terčov (koľko bodov dostane strelec)
- Postup sa opakuje od 1. bodu

Toto je základný priebeh všetkých disciplín podľa pravidiel. Počas všetkých fáz bude systém informovať rozhodcu o priebehu (v akej fáze je momentálne systém, ostávajúci čas, názov disciplíny, chybné výstrely).

# Disciplíny podľa pravidiel:
### 1. Rýchlopalná pištoľ 25m:
- Kaliber .22 LR 
- Jedna séria má 5 rán
- Časy série sú: 8 sekúnd, 6 sekúnd a 4 sekundy (čas, ktorý majú strelci na vystrelenie 5 rán)
- Série sa opakujú 2 krát: 2x8s, 2x6s a 2x4s (dokopy 30 výstrelov)

### 2. Športová pištoľ 25m:
- Kaliber .22 LR
- Jedna séria má 5 rán
- Časy série sú: 150 sekúnd, 20 sekúnd a 10 sekúnd
- Série sa opakujú 4 krát: 4x150s, 4x20s a 4x10s (dokopy 60 výstrelov)

### 3. Pištol 3/7 25m:
- Nie je oficiálna disciplína ISSF, ale veľmi rozšírená v Slovensku, Česku, Maďarsku, Poľsku
- Kaliber môže byť .22 LR alebo aj iné väčšie kalbire
- Jedna séria má 5 rán
- V sérií sa 5 krát strieda červené a zelené svetlo - 3 sekundy na výstrel, 7 sekúnd pauza (tento cyklus sa opakuje 5 krát pre 5 výstrelov)
- Dokopy 20-30 rán (podľa pravidiel jednotlivej súťaže)

# Systém a jeho časti
Systém som nahvrhol aby mal 4 časti.
## 1. Hlavná riadiaca jednotka
Jej úlohou je slúžiť ako ovládač pre rôzne programy systému. Sú na nej ovládacie prvky, displej a konektory pre prepojenie ostatných riadiacich jednotiek a svetiel.

<img src="/268026_ZPC_2025/images/cely.jpg" alt="Hlavna riadiaca jednotka" style="display:block; margin: 0 auto; width:70%;">

### 1.1 Vnútorné komponenty
Jadrom tejto jednotky je Arduino MEGA, ktoré riadi programy. Spracúvava signály z tlačidiel a Arduina NANO (jednotka na vyhodnocovanie signálu mikrofónov). Taktiež ovláda displej, ktorý slúži ako UI (user interface). 

Súčasťou je taktiež relé modul, pomocou ktorého sa spínajú svetlá. Ďalej obsahuje prevodník napätia z 12V na 5V - do riadiacej jednotky ide 12V kvôli svetlám, ale Arduino a ostané komponenty je potrebné napájať 5V.

### 1.2 Ovládacie prvky

<img src="/268026_ZPC_2025/images/ovladanie.jpg" alt="Ovladanie" style="display:block; margin: 0 auto; width:80%;">

- Hlavný spínač - slúži na zapnutie celého systému
- Tlačidlo STOP - okamžite stopne akúkoľvek prebiehajúcu disciplínu a zapne červené svetlá. Využíva sa v mimoriadnych prípadoch, napríklad ak nastane nejaká porucha v systéme alebo ak má niektorý zo strelcov vážnu závadu.
- Tlačidlo RESET - je pripojené na reset pin Arduina MEGA a Arduina NANO. Resetuje celý program, ktorý sa odznova načíta. Slúži na to, ak by vznikla nejaká chyba v systéme, ktorá zabraňuje pokračovaniu.
- Tlačidlo Svetlá vyp. - slúži na vypnutie svetiel, aby zbytočne nesvietili ak nikto zo strelcov nie je na strelisku alebo majú pauzu.
- Ovládací enkóder - slúži pre navigovanie v menu a voľbu programov.

### 1.3 Vstupy a výstupy
Vstupom je napájanie 12V zo zdroja. Vnútri je taktiež skrytý kábel na programovanie pre Arduino.

&nbsp;&nbsp;&nbsp;&nbsp;Výstupom sú konektory pre prepojenie Arduina NANO (mikrofónová sústava) a tiež Superseal konektory pre zapojenie svetiel. Superseal konektory som vybral kvôli tomu, že svetlá sú vonku pri terčoch, to znamená že nie su ochránené pred vonkajšími vplyvmi (počasie, vlhkosť...). Sú to konektory, ktoré majú v sebe tesenia, ktoré chránia spojenie.

### 1.4 Konštrukcia
&nbsp;&nbsp;&nbsp;&nbsp;Elektronika musela byť samozrejme chránená, preto som sa rozhodol vytvoriť box, ktorý všetky komponenty ochráni a bude slúžiť aj ako panel pre osadenie ovládacích prvkov. Ako materiál som si zvolil drevenú lisovanú dosku o hrúbke 4mm. 4mm som zvolil ako kompromis, keďže materiál musel byť dostatočne pevný a taktiež ho muselo byť možné vyrezať na laserovej rezačke. Konštrukciu som navrhol tak, že na rohoch sú zámky, pomocou ktorých sa dá poskladať. Rohy sú taktiež zlepené lepidlom na drevo. Spodok je vyberaťeľný aby bolo možné zapojiť vnútorné moduly a programovať arduino. Zvnútra som pridal aj spevnenie pomocou L-kového úchytu. Tiež som pridal aj úchyt pre displej. Ten je vyrobený pomocou 3D tlače z PLA filamentu.

<img src="/268026_ZPC_2025/images/vnutro.jpg" alt="Vnutro" style="display:block; margin: 0 auto; width:60%;">

### 1.5 Kód
&nbsp;&nbsp;&nbsp;&nbsp;V celom projekte som musel spraviť 2 kódy. Jeden pre Arduino MEGA a druhý pre Arduino NANO. Najväčším problémom pre mňa bolo spojazdenie displeja. Nikdy som nerobil s displejom tohto typu. Taktiež som prvý krát zisťoval, ako funguje komunikácia medzi dvoma vývojovými modulmi pomocou sériovej komunikácie.


### 1.6 Funkcie
&nbsp;&nbsp;&nbsp;&nbsp;Pri zapnutí sa modul načíta a zaháji komunikáciu cez serialPort. Potom sa zobrazí menu. V menu sú zobrazené jednotlivé disciplíny, ktoré sa dajú vybrať. Ako posledné je nastavenie mikrofónov. To slúži na určenie prahovej hodnoty citlivosti mikrofónov, aby nesnímali šum. Po potvrdení sa táto prahová hodnota uloží do pamäte a ostáva taká istá aj po resetovaní Arduina. Pri každom kroku sú na displeji napísané aj inštrukcie ovládania.

## 2. Riadiaca jednotka mikrofónov
<img src="/268026_ZPC_2025/images/nano.jpg" alt="nano" style="display:block; margin: 0 auto; width:70%;">

&nbsp;&nbsp;&nbsp;&nbsp;Ako bolo spomínané vyššie tento modul vyhodnocuje signál z mikrofónov. Z hlavnej jednotky sa vysiela signál - nastavenie citlivosti mikrofónov a spustenie programu. Jednotka funguje až keď sa spustí nejaká disciplína alebo sa nastavuje citlivosť, aby arduino zbytočne nepracovalo keď nemusí.

&nbsp;&nbsp;&nbsp;&nbsp;Tento modul má 5 vstupov pre mikrofóny, jeden výstup/vstup pre hlavnú jednotku a programovací port s USB C. Vnútro tvorí iba Arduino NANO, ktoré je prepojené s vonkajšími konektormi. Napájané je z hlavnej jednotky. Obal tohto modulu je jednoduchý box s úchytmi a otvormi pre konektory. Je vyrobený pomocou 3D tlače s PLA filamentu.

## 3. Mikrofóny
&nbsp;&nbsp;&nbsp;&nbsp;Tento modul je veľmi jednoduchý. Obsahuje mikrofónový modul, na ktorom sa dá dodatočne nastaviť citlivosť pomocou trimmeru (potenciometer). Zapojený je pomocou jedného konektoru, ktorý napája modul a vysiela analógový signál. Obal je vytvorený 3D tlačou s PLA filamentu.

<img src="/268026_ZPC_2025/images/mikrofon.jpg" alt="Mikrofon" style="display:block; margin: 0 auto; width:60%;">

## 4. Svetlá
&nbsp;&nbsp;&nbsp;&nbsp;Skladajú sa z červeného a zeleného LED modulu. Každý modul má 3 vysokovýkonné LED diódy, ktoré majú dokopy výkon 1,5W. Tieto vysokovýkonné moduly som zvolil, aby bolo svetlá jasne vidieť aj za zhoršených podmienok (slnko, hmla...). Moduly sú taktiež vodotesné, keďže budú vonku pri terčoch mimo budovy streliska. Moduly sú nalepené na ich kryt, ktorý je vytlačený 3D tlačou s PLA filametom.

<div style="display:flex; justify-content:center; gap:1rem;">
  <img src="/268026_ZPC_2025/images/ledmodulcerveny.avif" style="width:30%;">
  <img src="/268026_ZPC_2025/images/ledmodulzeleny.avif" style="width:30%;">
</div>
Použité LED moduly zo stránky: https://ampul.eu/cs/

# Zapojenie
Zapojenie nie je až tak zložité. Najviac spojení má displej s Arduinom MEGA, keďže potrebuje veľa analógových a digitálnych pinov.

## 1. Spojenia s Arduino MEGA
Takto vyzerá schéma:

<img src="/268026_ZPC_2025/images/schematerce.png" alt="schematerce" style="display:block; margin: 0 auto; width:100%;">

Odkaz na zapojenie:
https://app.cirkitdesigner.com/project/72876ebf-b46b-4fc0-9f84-2695f8683e1c

Presne tie moduly a enkódery som nenašiel ale princíp je ten istý. Enkóder je naschvál zapojený do komunikačných pinov, keďže sa v nich vytvára menší šum. To znamená, že enkóder je presnejší.

## 2. Spojenie s Arduino NANO
&nbsp;&nbsp;&nbsp;&nbsp;Tu som schému nerobil keďže tu je zapojenie veľmi jednoduché. V podstate konektor co ide z Arduina MEGA je zapojený tak isto do NANO (okrem rx a tx pinov ktoré musia byť prehodené aby komunikácia fungovala). Ostatok sú už len jednotlivé zapojenia mikrofónov, kde každý konektor má navedený 5V, GND a v strede analógový pin od A0-A4 pre jednotlivé mikrofóny.

# Zhodnotenie
&nbsp;&nbsp;&nbsp;&nbsp;S projektom som celkom spokojný. Systém funguje tak ako má a plní svoju funkciu. Som rád, že som dokázal pridať niektoré funkcie, nad ktorými som pôvodne neuvažoval. 

&nbsp;&nbsp;&nbsp;&nbsp;Čo sa týka vylepšenia, tak by som určite uvažoval nad inou vývojovou doskou. Arduino je veľmi dobrá univerzálna doska, ale zistil som, že má celkom pomalú rýchlosť procesora. To má za následok, že v systéme je celkom dlhá odozva, najmä pri displeji. Displej sa načíta pomaly a preto som musel pridať rôzne funkcie do kódu aby bol plynulejší. Takže ďaľším krokom pre tento projekt by bolo zameniť Arduino za niečo rýchlejšie - napríkad moduly ESP32. Tie sú omnoho rýchlejšie (až 240MHz) a väčšinou majú zabudovaný aj WiFi a Bluetooth modul.

&nbsp;&nbsp;&nbsp;&nbsp;Ak by som sa rozhodol nad EPS32, tak by som rozhodne prerobil systém na Bluetooth alebo WiFi, čo by umožnilo väčšiu modularitu systému. Bolo by to ale zložitejšie na programovanie, keďže s týmto modulom ešte nepracoval.
