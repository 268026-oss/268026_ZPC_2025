+++
date = '2025-09-28T19:52:30+02:00'
draft = false
title = 'Mini-projekt 4 - 3D skenovanie'
weight = 5
+++

# Mini projekt na 3D skenovanie pomocou Simscan

&nbsp;&nbsp;&nbsp;&nbsp;Jedná sa o skener SimScan ktorý funguje na princípe bez-kontaktnej metódy merania, ktorá vytvára presný digitálny 3D model fyzického objektu. Využíva laserové čiary a kamerové senzory, ktoré sledujú odraz laserového svetla z povrchu objektu. Na základe triangulácie (trojuholníkového výpočtu medzi laserom, kamerou a objektom) sa určuje presná poloha bodov na povrchu.

SimScan poskytuje:
- presnosť až 0,02 mm
- vysokú rýchlosť zbierania bodov
- použiteľnosť na mierne lesklé aj tmavé povrchy
- kompaktné rozmery vhodné pre ručné skenovanie malých až stredne veľkých objektov

## Postup skenovania:

&nbsp;&nbsp;&nbsp;&nbsp;Prvým krokom bolo skener rozložiť, zapojiť a všetko nastaviť podľa inštrukcií. Potom som otvoril program DefinSight a spustil kalibáciu, ktorá sa vykonáva pomocou kalibracnej dosky. Po kalibrácii bolo na rade skenovanie reflexných bodov. Mojim zadaným objektom bola sklenená fľaša od piva. Nalepil som na ňu reflexné body (6mm) na rôznych miestach tak aby boli viditeľné vždy aspoň 2 body a položil ju na skenovaciu dosku a začal so zbieraním bodov. Keď som mal všetky body dôkladne pozbierané tak som vytvoril pomocou označenia bodov na skenovacej rovnej doske.

<img src="/268026_ZPC_2025/images/flasastock.jpg" alt="Flasastock" style="display:block; margin: 0 auto; width:60%;">

&nbsp;&nbsp;&nbsp;&nbsp;Potom som skener prepol do režimu zbierania dát povrchu. Nastavil som parametre ktoré boli aj v prezantácii pri školení dostupné na: https://www.strojlab.cz/scan-lab. Na tejto stránke je podrobne opísaný celý postup aj s nastaveniami. Parametre, ktoré som zmenil bol resolution (rozlíšenie) a to z hodnoty 0,5mm na 0,3mm. Bolo to kvôli tomu lebo som chcel mať trošku viacej detailný povrch. Taktiež som nastavil, že budem skenovať small object shiny/dark (malé objekty lesklé alebo tmavé), kde bola expozícia 7.

&nbsp;&nbsp;&nbsp;&nbsp;Pri tomto druhom kroku skenovania som ale narazil na problém. Tým že tá sklenená fľaša bola lesklá a k tomu aj tmavá (hnedé tmavé sklo), tak mi skener nechcel dobre zachytávať povrch a laserové lúče sa rozptyľovali v skle. Rozhodol som sa pre to, že použijem špeciálny 3D skenovací matný sprej, ktorý na fľaši vytvorí matnú vrstvu a zlepší skenovanie.

&nbsp;&nbsp;&nbsp;&nbsp;Bolo potrebné najprv zbaviť fľašu nalapených bodov a potom ju ísť nasprejovať. Po sprejovaní som na fľašu nalepil opäť reflexné body a opakoval postup uvedený vyššie. Fľaša vizerala takto: 

<img src="/268026_ZPC_2025/images/flasanastrikana.jpg" alt="Flasastrikk" style="display:block; margin: 0 auto; width:60%;">

Po naskenovaní povrchu som fľašu otočil a oskenoval druhým skenom povrchu spodnú stranu. Následne som tieto dva skeny prepojil medzi sebou pomocou LaserPoint Splice. Potom som súbory uložil a ďalej pokračoval v programe GOM inspect. Taktiež som fľašu očistil od spreja (matného povrchu), čo išlo jednoducho s čistou vodou.

## GOM Inspect:
&nbsp;&nbsp;&nbsp;&nbsp;Tento program umožnuje upravovať .stl mesh a merať geometriu skenu. Po importovaní súboru som začal s odstraňovaním dier v modeli. Tie tam vznikli kvôli nalepeniu reflexnýc bodov. V týchto miestach som využil funkciu fill holes. Ďalej som pokračoval s miernymi úpravami meshu. Hlavne vyhladzovaním modelu. Nechcel som ho ale až príliš vyhladiť aby bolo pekne ma modeli vidno textúru povrchu. Ďalej som pokračoval s meraním rozmerov. Ako rozmery na meranie som si vybral povrch, objem, šírku diery na hrdle fľaše a celkovú výšku fľaše. Objem a povrch bol celkom jednoduchý, stačí si zvoliť funkciu a program sám vypočíta hodnoty. Hrdlo fľaše som definoval pomocou funkcie fitting cylinder a dal zobraziť údaje z geometrie na obrazovku do tabuľky. Ďalej som chcel vedieť celkovú výšku. To som spravil tak, že som spravil rovinu na spodnej a vrchnej strane pomocou 3 bodov. Keď som mal roviny tak som vytvoril body pomocou presečníku osy hrdla fľaše a vrchnou/spodnou rovinou. To mi vytvorilo bod v strede fľaše na hornej aj dolnej rovine. Potom som už len túto vzdialenosť odmeral pomocou funkcie measure.

### Neupravený súbor .stl:

![GOMstock](/268026_ZPC_2025/images/GOMstock.png)

## Výsledné hodnoty merania:
| Merané | Programové meranie | Skutočný rozmer | Rozdiel |
|:-------------:|:------------:|:------------:|:------------:|
| Objem | 429631,97 mm^3 | - | - |
| Povrch | 37535,68 mm^2 | - | - |
| Hrdlo fľaše | 17,74 mm | 17,6 mm | +0,14 |
| Výška | 226,14 mm | 226,3 mm | -0,16 |

&nbsp;&nbsp;&nbsp;&nbsp;Hodnoty meraní nie sú úplne najpresnejšie. Je to hlavne kvôli tomu, že fľaša nemá presné rozmery. Takže je možné, že pri ručnom meraní vznikla odýchlka. Tiež tu hrá rolu to, že fľaša má veľmi oblú geometriu a je lesklá. Napriek tomu si myslím, že namerané hodnoty dávajú zmysel, pri výrobe takýchto fľiaš je tolerancia tiež celkom veľká. Je tiež možné, že osa stredu fľaše je mierne vychýlená od spodku po vrch.

## Obrázok z GOM Inspect upravnený a nameraný:
![GOM](/268026_ZPC_2025/images/GOM.png)