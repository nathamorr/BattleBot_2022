# Battlebot 2022

![](Modelisation%203D/robot_3d_illustration.JPEG)

### Règles du tournoi

Création d'un robot de bataille en respectant les règles suivantes :
- robot roulant => Poids max 900g;
- dimension max : le robot doit rentrer dans un cube de 25cm de côté avec ou sans partie dépliable;
- un bouton d'arrêt d'urgence est présent et accessible;
- le robot doit être radiocommandé;
- l'arme doit pouvoir être désactivée via la communication;
- si le contrôleur est deconnecté du robot, celui-ci s'arrête.

### Branchement

Le branchement est fait avec : 1 batterie de 14.8V, un ESP32, 3 moteurs, 1 pont en H, 2 abaisseurs de tension vers 5V  et 3.3V.

### Communication / Pilotage

Le robot est équipé d'un ESP32 afin de gérer la communication Bluetooth avec la manette PS4.

Le robot se déplace avec le stick gauche (Stick L), qui est calculé avec les différentes valeurs obtenues en mettant le stick dans différentes positions et avec les conditions définies avec les courbes: y=x et y=-x.  

Le pilote peut appuyer sur le bouton rond pour faire tourner l'arme.  

### Résultat

Robot vainqueur du tournoi organisé par l'IMERIR : https://www.youtube.com/watch?v=_SuwAHqlyNo  
Nathan AMORRICH / Vincent GRECK / Valentin LECORNUE
