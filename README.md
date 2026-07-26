# Esp32 IDF Low level

[![forthebadge](https://forthebadge.com/images/badges/made-with-c.svg)](https://forthebadge.com)
[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](https://opensource.org/licenses/MIT)

Ce dépôt est un espace de travail regroupant un ensemble de mini-projets développés en **C**. L'objectif est l'apprentissage progressif de l'architecture interne de l'ESP32 via le framework ESP-IDF, en privilégiant les couches matérielles bas niveau (HAL LL) et l'OS temps réel FreeRTOS.

---

## 🏗️ Architecture

Contrairement à un projet monolithique, ce dépôt utilise une architecture en **Monorépôt**. Chaque dossier correspond à un projet totalement indépendant possédant sa propre configuration (`sdkconfig`), son propre code source (`main/`) et sa propre documentation détaillée.

### Structure du dépôt

```text
/
├── .gitignore               # Exclusion des dossiers de build et données sensibles
├── README.md                # Documentation globale (ce fichier)
├── LICENSE                  # Licence MIT
│
├── 01_blink/                # Projet 1 : Clignotement LED (Indépendant)
│   ├── CMakeLists.txt       
│   ├── sdkconfig            # Configuration matérielle spécifique à ce projet
│   ├── README.md            # Documentation spécifique (Loi des mailles, câblage)
│   └── main/                
│       ├── CMakeLists.txt   
│       └── main.c           # Code source LL
│
└── 02_interrupt/            # Projet 2 : (À venir)
    ├── ...
```


### 📌 Microcontrôleur supporté

L'ensemble des schémas, calculs de dimensionnement et configurations est optimisé pour le module suivant :

|Cible| Format| Statut|
|-----|-------|-------|
|ESP32-WROOM-32D| DevKitC V4 (30 broches)| ✅ Actif|

⚠️ Attention aux variantes : La version classique de l'ESP32 possède 36 broches (ESP32-WROOM-32 DevKit V1).
Le brochage (pinout) diffère grandement entre les deux versions. Vérifiez votre matériel avant de réaliser les câblages.


## 🚀 Guide de démarrage

Pour garantir un environnement reproductible, la chaîne de compilation est conteneurisée. Le déploiement se fait ensuite localement.

### 1. Prérequis

- Docker Desktop (actif en arrière-plan)
- Python 3 et l'outil `esptool`
- Un câble USB de transfert de données

### 2. Installation

Clonez ce dépôt sur votre machine locale :

```bash
git clone https://github.com/Bapt-h/esp32-idf-low-level.git
cd esp32-idf-low-level
```

### 3. Compilation (via Docker)
Déplacez-vous impérativement dans le dossier du projet que vous souhaitez compiler avant de lancer l'image Docker officielle d'Espressif (v5.1).

```bash
# Exemple pour le projet 01
cd 01_blink

# Lancement de la compilation
docker run --rm -v "$PWD":/project -w /project espressif/idf:release-v5.2 idf.py build
```

### 4. Envoi et exécution (Flash)
Identifiez le port série attribué à votre carte (ex: /dev/cu.usbserial-110 ou /dev/ttyUSB0). Toujours depuis le dossier du projet, téléversez le binaire et ouvrez le moniteur série :

```bash
idf.py -p /dev/cu.usbserial-110 flash monitor
```

(Utilisez `Ctrl+]` pour quitter le moniteur série).

## 🛠️ Comment travailler avec ce dépôt

Si vous souhaitez explorer ou modifier le code :

1. Choisissez un projet dans le tableau de la section suivante.

2. Naviguez dans le dossier correspondant.

3. Lisez impérativement le README.md local situé dans ce dossier : il contient les schémas électriques, les calculs de résistances et les explications sur les registres utilisés.

4. Les fichiers sources en C se trouvent dans le sous-dossier main/.

## 🗂️ Mini-projets et exemples disponibles

| Projet | Description | Concepts clés abordés | Lien |
|--------|-------------|-----------------------|------|
| 01_blink | Hello World matériel (Clignotement LED) | GPIO LL, FreeRTOS, Loi des mailles, Série E12 | Consulter |
| 02_interrupt | (À venir) Gestion d'un bouton poussoir | Interruptions matérielles, Anti-rebond | À venir📄 |

## Licence

MIT License. Voir le fichier [LICENSE](LICENSE) pour plus de détails.



