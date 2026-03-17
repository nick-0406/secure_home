# Système d’authentification par télécommande IR avec Arduino

## Description

Ce projet met en place un **système simple d’authentification** utilisant une **télécommande infrarouge (IR)** pour saisir un code.  
L’utilisateur doit entrer un **code à 4 chiffres** via la télécommande. Le système vérifie ensuite si ce code correspond au mot de passe enregistré.

Le système utilise :

- un **récepteur infrarouge** pour recevoir les commandes de la télécommande
- un **écran LCD I2C** pour afficher les messages
- une **LED verte** pour indiquer une authentification réussie
- une **LED rouge** pour indiquer une erreur
- un **buzzer** pour les notifications sonores
- un **capteur de présence** pour déclencher le processus

L’utilisateur dispose de **trois tentatives** pour saisir le bon code.

---

## Matériel utilisé

- Arduino (Uno / Nano / Mega)
- Récepteur infrarouge
- Télécommande IR
- Écran LCD I2C 16x2
- LED verte
- LED rouge
- Buzzer
- Capteur de présence
- Bouton poussoir
- Fils de connexion

---

## Connexions Arduino

| Composant | Pin Arduino |
|-----------|-------------|
| Récepteur IR | 2 |
| Capteur de présence | 3 |
| LED verte | 5 |
| LED rouge | 6 |
| Buzzer | 7 |
| Bouton | 8 |
| Activation LCD | 9 |
| Capteur tactile | 10 |
| LCD I2C | SDA / SCL |

Adresse LCD utilisée :


0x27


---

## Principe de fonctionnement

1. Le système attend qu’une personne soit détectée par le **capteur de présence**.

2. Lorsqu’une présence est détectée, le message suivant apparaît sur le LCD :


presentez-vous
devant la camera


3. L’utilisateur doit ensuite **saisir un code à 4 chiffres** à l’aide de la télécommande IR.

4. Chaque chiffre saisi est affiché sur l’écran LCD.

5. Le code entré est comparé au mot de passe enregistré dans le programme.

Mot de passe par défaut :


0 0 0 0


---

## Gestion des tentatives

- L’utilisateur dispose de **3 tentatives maximum**.
- À chaque erreur :


Erreur !


Le compteur d’erreurs est affiché.

---

## Authentification réussie

Si le code est correct :


BIENVENU !!


Actions déclenchées :

- LED verte allumée
- buzzer actif
- message affiché sur le LCD

---

## Authentification échouée

Si les trois tentatives sont incorrectes :


Erreur d'authentification


Actions déclenchées :

- LED rouge allumée
- buzzer activé
- message d'erreur affiché

---

## Bibliothèques utilisées

Le projet utilise les bibliothèques suivantes :

```cpp
#include <IRremote.hpp>
#include <LiquidCrystal_I2C.h>

Installation via l’IDE Arduino :

Sketch → Include Library → Manage Libraries

Rechercher :

IRremote

LiquidCrystal I2C

Utilisation

Connecter les composants aux pins indiquées.

Installer les bibliothèques nécessaires.

Téléverser le programme sur l’Arduino.

Alimenter le système.

Le système attendra une présence puis demandera la saisie du code via la télécommande IR.

Améliorations possibles

Ajouter un système de changement de mot de passe

Ajouter un clavier matriciel en alternative à la télécommande

Ajouter un verrou électrique ou servo moteur

Ajouter une temporisation de sécurité après plusieurs erreurs

Auteur

Projet réalisé par Nick
Projet Arduino : système d’authentification par télécommande infrarouge.