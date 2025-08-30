# 🚀 Plan de progression – Simulation en C++

## 1. Mise en place du projet
- Créer une structure de projet en C++ (ex. avec **CMake** ou un IDE comme CLion / VSCode).
- Organiser ton code en **fichiers séparés** (`.hpp` pour les en-têtes, `.cpp` pour l’implémentation).
- Décider si tu veux commencer en **console (texte)** ou directement avec une **lib graphique simple** (SFML, SDL).

---

## 2. Bases du langage appliquées à ton projet
- Définir une **classe `Fish`** :
    - Attributs : position, vitesse, direction.
    - Méthodes : mise à jour du mouvement.
- Définir une **classe `World`** :
    - Contient une collection de poissons (`std::vector<Fish>`).
    - Responsable de mettre à jour tous les agents à chaque “tick”.

---

## 3. Simulation minimale
- Créer une **boucle de simulation** :
    - Chaque tick :
        - Mettre à jour la position de chaque poisson.
        - Appliquer des règles simples (ex. rester dans les limites du monde).
- Vérifier que tu peux afficher **l’état du monde** (même juste en texte).

---

## 4. Introduction des comportements collectifs
- Implémenter progressivement les règles du **modèle Boids** :
    1. **Séparation** (éviter les collisions).
    2. **Alignement** (suivre la direction moyenne des voisins).
    3. **Cohésion** (rejoindre le groupe).
- Tester chaque règle séparément, puis les combiner.

---

## 5. Améliorations réalistes
- Ajouter des **contraintes physiques simples** :
    - Vitesse maximale.
    - Accélération limitée.
    - Champ de vision (angle et distance de perception).
- Ajouter des **paramètres configurables** (nombre de poissons, rayon de vision, vitesse…).

---

## 6. Visualisation
- Si console → afficher un monde 2D en caractères (`.`, `o`, `#`).
- Si graphique → utiliser une lib comme **SFML** (facile pour afficher des points/cercles en 2D).
- Observer le comportement émergent.

---

## 7. Extensions possibles
- Ajouter un **prédateur** (nouvelle classe `Predator`).
- Simuler un **obstacle** (rochers, bords).
- Implémenter des comportements différents selon les espèces (poissons solitaires, poissons de banc).
- Ajouter de l’**évolution** :
    - Chaque poisson a un “ADN” (paramètres de vitesse, vision, etc.).
    - Ceux qui survivent se reproduisent.

---

## 8. Étude et analyse
- Observer comment les règles simples donnent un comportement complexe.
- Comparer différents paramètres (ex. petit vs grand champ de vision).
- Étudier la stabilité du banc face aux perturbations (ex. introduction d’un prédateur).  
