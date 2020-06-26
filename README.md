# Little Root         
 | Contributor | Social |      
|--|--|      
| Chahinaz CHOUALI | [Github](https://github.com/chouali) |
| Aargan COINTEPAS | [Github](https://github.com/AarganC) |
| Anthonny OLIMÉ | [Github](https://github.com/Citaman) |
| Bernard VONG | [Github](https://github.com/bernardVong) |      
        
      
### Le produit
Little Root est un outil connecté qui permet d’analyser une zone de plantation et guide chaque personne dans son quotidien botanique à travers des recommandations.

Il sera composé des fonctionnalités suivantes :
- **analyse avant plantation** : une personne qui souhaite se lancer dans une nouvelle plantation peut utiliser la sonde et la planter plusieurs semaines avant le jour J. Ensuite, Little Root déterminera **si les conditions sont bonnes pour certaines plantes** (sol fertile, ensoleillement suffisant, température correcte, pluviométrie)
- **suivi quotidien** : pour suivre la qualité du sol et de son environnement, recevoir des notifications si la plantation a besoin d'une attention particulière.
- **communauté active** : les personnes pourront partager leurs plantations et leurs conseils pour chaque plantation entre heureux possesseurs de Little Root.

      
### Développement
- IDE : [https://www.tinkercad.com/](https://www.tinkercad.com/)     
- Prototype : le [circuit](https://www.tinkercad.com/things/6lvrhF2EBL2)
      
### Composants


| Nom | Tinkercad | Circuit physique |      
|--|--|--|
| Nom | Tinkercad | Circuit physique |
| Carte mère | U1 Arduino Uno R3 | Arduino Uno R3 |
| Carte réseau 4G et GPS | - | DFRobot SIM7600CE-T 4G(LTE)+GPS Arduino Shield |
| Capteur de lumière ambiante  | Q Capteur de lumiere [phototransistor] | Photorésistance |
| Capteur de température | U2, U Capteur d'humidité  [TMP36] | Capteur LM35 |
| Capteur de distance par ultrasons | DIST1 | HC-SR04-P Module Ultrasonique  |
| Capteur d'inclinaison | TILT Capteur d'inclinaison | OPENSE059 Capteur d'inclinaison à bille |
| Capteur de dureté du sol | - | - |
| Moteur pour la dureté du sol | M1 Moteur vibrateur | 105020003 Module Grove Moteur vibreur |
| LED RGB | LED1 NeoPixel | NeoPixel Mini 3535 RGB LED |
| Panneau solaire | R Simulateur de panneau solaire | Panneau solaire 55x70mm 0.5W |
| Connecteur solaire | - | LiPo Rider Pro |
| Accumulateur solaire | - | Accu LiPo (capacité selon consommation) |
| Capteur Micro-SD | - | Module carte micro-SD DFR0229 |
| Résistance 10 k‚Ω | R1 | Résistance 10 k‚Ω |
| Résistance 7.5 k‚Ω  | R Resistance Photo sensor | - |
| Résistance 1 k‚Ω | R3, R4 | Résistance 1 k‚Ω |



Parmis  les objectifs de Little Root Surveiller la luminosité, la température de l'air et l’humidité du sol, l’ensoleillement, la température, l’humidité du de l’air .

Tous Les capteurs sont alimentés sur du 5V depuis Tinkercad.

Luminosité →  Capteur luminosité :
lorsqu'il fait sombre : le phototransistor ne laisse presque pas passer de courant et par conséquent, il n'y a presque pas de courant non plus dans la résistance, la tension renvoyé est donc de 0
lorsqu'il fait clair : le photo-transistor laisse passer plus de courant, courant qui circule également dans la résistance et augmente la différence de potentiel aux bornes de cette dernière. La tension relevée au borne de la résistance est donc plus grande lorsqu'il y a plus de lumière et varie entre 1 et 100. 

Ensoleillement → Capteur photorésistance :
Pour simuler les cellules photovoltaïques sur la surface de Little Root, on a utilisé un capteur photorésistance:  C’est un capteur de lumière dont la résistance varie en fonction de l'éclairement du soleil. Le but est de capter l’influence de l'énergie solaire pour le faire  fonctionner comme un générateur électrique pour Little Root et ainsi alimenter sa batterie. 

Température →  Capteur de température 
Pour évaluer  l'air ambiant extérieur on a utilisé un capteur de température 

Humidité → Simulation avec un capteur de température 
Pour évaluer l’humidité de l’air extérieur, on a simulé la valeur en utilisant un capteur de température. 

Déracinement → Capteur d’inclinaison
Lorsque des facteurs naturels comme la pluie ou le vent essaient de déraciner Little Root, ou lorsqu’il y’a une tentative de vol, ce capteur détecte s'il Little Root est inclinée ou pas :  En temps normal Little Root est dans une position horizontale =  0 dés qu’il y’a un changement de la position en  verticale = 1 

Capteur ultrasonique →  pour simuler la sonde terrestre qui permet d’évaluer la fertilité du sol,  ainsi que la présence des minéraux dans le sol, la dureté 

Les capteurs de distance à ultrasons utilisent le principe de l’écho pour déterminer la distance à laquelle se trouve un objet.
Ces capteurs donnent la valeur mesurée au millimètre près de la distance avec l’objet. 

