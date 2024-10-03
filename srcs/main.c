#include "r_sys.h"

struct Reservation reservations[MAX_RESERVATIONS];
int count = 0; // Compteur de réservations
int ref = 0;

int menu()
{
    int choix;

	printf("\nMENU PRINCIPAL\n");
	printf("1. Ajouter une réservation\n");
	printf("2. Modifier une réservation\n");
	printf("3. Supprimer une réservation\n");
	printf("4. Afficher une réservation\n");
	printf("5. Tri des réservations\n");
	printf("6. Recherche d'une réservation\n");
	printf("7. Statistics\n");
	printf("8. Quitter\n");
	printf("Entrez votre choix : ");
	scanf("%d", &choix);
	return (choix);
}

int action(int choix)
{
	switch (choix) {
		case 1:
			ajouterReservation();
			break;
		case 2:
			modifierReservation();
			break;
		case 3:
			supprimerReservation();
			break;
		case 4:
			afficherReservation();
			break;
		case 5:
			tri();
			break;
		case 6:
			recherche();
			break;
		case 7:
			statistics();
			break ;
		case 8:
			printf("Au revoir !\n");
			exit(0);
		default:
			printf("Choix invalide. Veuillez réessayer.\n");
	}
	return (1);
}

int main() {
    int choix;

    while (1) {
		clear_screen();
		choix = menu();
		action(choix);
		printf("\n\nPress Enter to continue...");
		int c;
		while ((c = getchar()) != '\n' && c != EOF);
		getchar();
    }

    return 0;
}
