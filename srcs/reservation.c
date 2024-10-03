#include "r_sys.h"

// Fonction pour afficher une réservation existante
void afficherReservation(void)
{
	int reference;
    printf("Entrez la référence de la réservation à modifier : ");
    scanf("%d", &reference);

    // Recherche de la réservation par référence
    int index = trouverReservation(reference);
    if (index == -1) {
        printf("Réservation non trouvée.\n");
        return;
    }
	_afficherReservation(reservations[index]);
}

void afficherTousReservation(void)
{
	for (int i = 0; i < count; i++)
	{
		printf("\tReservation %d\n", i);
		_afficherReservation(reservations[i]);
	}
}

// Fonction pour modifier une réservation existante
void modifierReservation() {
    int reference;
    printf("Entrez la référence de la réservation à modifier : ");
    scanf("%d", &reference);

    // Recherche de la réservation par référence
    int index = trouverReservation(reference);
    if (index == -1) {
        printf("Réservation non trouvée.\n");
        return;
    }

    // Modification des détails de la réservation
    printf("Modification de la réservation %d.\n", reference);
    
    printf("Entrez le nouveau nom (actuel: %s): ", reservations[index].nom);
    scanf("%s", reservations[index].nom);

    printf("Entrez le nouveau prénom (actuel: %s): ", reservations[index].prenom);
    scanf("%s", reservations[index].prenom);

    printf("Entrez le nouveau numéro de téléphone (actuel: %s): ", reservations[index].telephone);
    scanf("%s", reservations[index].telephone);

    printf("Entrez le nouvel âge (actuel: %d): ", reservations[index].age);
    scanf("%d", &reservations[index].age);

    printf("Entrez le nouveau statut (validé, reporté, annulé, traité) (actuel: %s): ", reservations[index].statut);
    scanf("%s", reservations[index].statut);

    printf("Entrez la nouvelle date (format AAAA-MM-JJ) (actuel: %s): ", reservations[index].date);
    scanf("%s", reservations[index].date);

    printf("Réservation modifiée avec succès !\n");
}

// Fonction pour supprimer une réservation existante
void supprimerReservation() {
    int reference;
    printf("Entrez la référence de la réservation à supprimer : ");
    scanf("%d", &reference);

    // Recherche de la réservation par référence
    int index = trouverReservation(reference);
    if (index == -1) {
        printf("Réservation non trouvée.\n");
        return;
    }

    // Déplace toutes les réservations après celle supprimée pour combler le vide
    for (int i = index; i < count - 1; i++) {
        reservations[i] = reservations[i + 1];
    }
    count--; // Décrémenter le compteur de réservations

    printf("Réservation supprimée avec succès !\n");
}

// Fonction pour ajouter une nouvelle réservation
void ajouterReservation() {
    if (count >= MAX_RESERVATIONS) {
        printf("Impossible d'ajouter plus de réservations. Limite atteinte.\n");
        return;
    }

    struct Reservation newReservation;

    // Récupération des détails de la réservation
    printf("Entrez le nom: ");
    scanf("%s", newReservation.nom);

    printf("Entrez le prénom: ");
    scanf("%s", newReservation.prenom);

    printf("Entrez le numéro de téléphone: ");
    scanf("%s", newReservation.telephone);

    printf("Entrez l'âge: ");
    scanf("%d", &newReservation.age);

    printf("Entrez le statut (validé, reporté, annulé, traité): ");
    scanf("%s", newReservation.statut);

    // Génération automatique d'un numéro de référence unique
    newReservation.reference = ++ref;

    // Saisie de la date de réservation
    printf("Entrez la date de réservation (AAAA-MM-JJ): ");
    scanf("%s", newReservation.date);

    // Ajouter la nouvelle réservation au tableau
    reservations[count] = newReservation;
    count++;

    printf("Réservation ajoutée avec succès ! Référence: %d\n", newReservation.reference);
}
