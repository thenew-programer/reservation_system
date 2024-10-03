#include "r_sys.h"

void recherche_par_nom()
{
	char nom[100];
    printf("Entrez le nom de la réservation à chercher : ");
    scanf("%s", nom);

    // Recherche de la réservation par référence
    int index = -1;
	for (int i = 0; i < count; i++)
	{
		if (strcmp(nom, reservations[i].nom) == 0)
		{
			index = i;
			break ;
		}
	}
    if (index == -1) {
        printf("Réservation non trouvée.\n");
        return;
    }
	_afficherReservation(reservations[index]);
}

void recherche_par_date()
{
	char date[100];
    printf("Entrez la date de la réservation à chercher : ");
    scanf("%s", date);

    // Recherche de la réservation par référence
    int index = -1;
	for (int i = 0; i < count; i++)
	{
		if (strcmp(date, reservations[i].date) == 0)
		{
			index = i;
			break ;
		}
	}
    if (index == -1) {
        printf("Réservation non trouvée.\n");
        return;
    }
	_afficherReservation(reservations[index]);
}

int recherche_menu(void)
{
    int choix;

	printf("\nMENU De Recherche\n");
	printf("1. Recherche d'une réservation par Nom\n");
	printf("2. Recherche d'une réservation par Reference\n");
	printf("3. Recherche d'une réservation par Date\n");
	printf("4. Return To Main Menu\n");
	printf("Entrez votre choix : ");
	scanf("%d", &choix);
	return (choix);
}

int	recherche_action(int choix)
{
	switch (choix) {
		case 1:
			recherche_par_nom();
			break ;
		case 2:
			afficherReservation();
			break ;
		case 3:
			recherche_par_date();
			break ;
		case 4:
			return (0);
		default:
			printf("Choix invalide. Veuillez réessayer.\n");
	}
	return (1);
}

void recherche()
{
	int choix;
	while (1)
	{
		clear_screen();
		choix = recherche_menu();
		if (recherche_action(choix) == 0) return ;
		printf("\n\nPress Enter to continue...");
		int c;
		while ((c = getchar()) != '\n' && c != EOF);
		getchar();
	}
}
