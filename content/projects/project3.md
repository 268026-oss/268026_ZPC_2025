+++
date = '2025-09-28T19:52:30+02:00'
draft = false
title = 'Mini-projekt 3 - Laserová rezačka'
weight = 4
+++

# Mini projekt s využitím laserovej rezačky

&nbsp;&nbsp;&nbsp;&nbsp;Zadanie pre tento projekt znelo celkom jednoducho: vytvoriť nejaký objekt vyrezaním kartónu a bez lepenia. Bol tu však problém. Čo vytvoriť? Pri tomto projekte bolo nutné zapojiť nie len naše zručnosti a vedomosti, ale aj kreativitu. Pôvodne som chcel vytvoriť malý stôl ktorý by som zložil dokopy. Tento nápad mi však prišiel celkom nudný a nezaujímavý, preto som hľadaľ inšpiráciu na internete. Nakoniec som sa rozhodol vytvoriť si malé autíčko. 

&nbsp;&nbsp;&nbsp;&nbsp;Začal som vytvorením 3D modelu vo Fusion 360. Kartón, ktorý sme mali k dispozícii mal rozmery 1200x800x6. Pre mňa výška a šírka nebola až tak podstatná, dôležitá bola hlavne hrúbka 6mm. Podľa nej sa odvíjal skoro celý moj dizajn. Bolo nutné vytvárať rôzne zámky a drážky aby bolo možné diely pevne spojiť bez lepenia. Vytvoril som si preto jeden testovací kúsok kde som vyskúšal aké tolerancie mám na diely dať. Zistil som, že stačí diely spraviť napresno (napríklad 10mm diera a 10mm diel). Po tomto zistení som už vymodeloval celý diel.

## Takto vyzeral model vo Fusion 360:
![AutickoFusion](/268026_ZPC_2025/images/auticko.png)

&nbsp;&nbsp;&nbsp;&nbsp;Po tom ako som mal takúto sústavu som jednotlivé diely uložil a exportoval ich 2D sketch do formátu .dxf. Potom som zapol laserovú rezačku, umiestnil a zalepil kartón aby bol čo najrovnejší, nastavil rezaciu hlavu na vzdialenosť 6mm od materiálu. Nasledovalo importovanie súborov do programu lightburn. 

## Fotky rezačky a programu:
![Rezačka](/268026_ZPC_2025/images/rezacka.jpg)

![Lightburn](/268026_ZPC_2025/images/lightburn.jpg)

&nbsp;&nbsp;&nbsp;&nbsp;Rezal som spoločne aj so spolužiakovými modelmi, aby sme ušetrili materiál. Dôležité bolo samozrejme dobre nastaviť rezačku a porozmiestňovať jednotlivé modely. Nastaviť bolo potrebné:
- Rýchlosť (50mm/s) = ovlivňuje ako rýchlo sa pohybuje rezacia hlava
- Maximálny výkon (70%) = nastavuje výkon lasera
- Minimálny výkon (65%) = dôležité nastavenie napríklad pre rohy a krátke čiary. Bez tohto by sa mohlo stať, že v rohoch sa prepáli materiál.
- Počet priechodov (1) = koľko krát rezacia hlava prejde čiary.

V programe som ešte pridal aj zopár častí na gravírovania, ako napríklad text, moje vut číslo a svetlá auta.

## Rezanie:
![Rezanie](/268026_ZPC_2025/images/rezanie.jpg)

![Diely](/268026_ZPC_2025/images/diely.jpg)

&nbsp;&nbsp;&nbsp;&nbsp;Takto sa diely vyrezávali. Žiadne problémy nenastali a výsledok rezania vyzeral perfektne. Celkovo rezanie trvalo približne 20 minút, z toho najviac času zabralo gravírovanie. Po vyrezaní som diely opatrne začal skladať. Keďže som si vytvoril model najprv v 3D tak mi všetko krásne sedelo.

## Výsledok:
![AutoPredok](/268026_ZPC_2025/images/predokauto.jpg)

![AutoZadok](/268026_ZPC_2025/images/zadokauto.jpg)