#include "r_sys.h"

int tri_menu()
{
    int choix;

	printf("\nMENU De Tri\n");
	printf("1. Tri des réservations par Nom\n");
	printf("2. Tri des réservations par date\n");
	printf("3. Tri des réservations par statut\n");
	printf("4. Afficher tous les reservations\n");
	printf("4. Return To Main Menu\n");
	printf("Entrez votre choix : ");
	scanf("%d", &choix);
	return (choix);

}


void tri_par_nom()
{
	int sorted;
	struct Reservation tmp;

	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		for (int i = 0; i < count - 1; i++)
		{
			if (strcmp(reservations[i].nom, reservations[i].nom) > 0)
			{
				tmp = reservations[i];
				reservations[i] = reservations[i + 1];
				reservations[i + 1] = tmp;
				sorted = 0;
			}
		}
	}
}

void tri_par_date()
{
	int	sorted;
	struct Reservation tmp;

	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		for (int i = 0; i < count - 1; i++)
		{
			if (comp_date(reservations[i].date, reservations[i].date) > 0)
			{
				tmp = reservations[i];
				reservations[i] = reservations[i + 1];
				reservations[i + 1] = tmp;
				sorted = 0;
			}
		}
	}
}

void tri_par_status()
{
	int sorted;
	struct Reservation tmp;

	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		for (int i = 0; i < count - 1; i++)
		{
			if (comp_status(reservations[i].statut, reservations[i].statut) < 0)
			{
				tmp = reservations[i];
				reservations[i] = reservations[i + 1];
				reservations[i + 1] = tmp;
				sorted = 0;
			}
		}
	}

}

int tri_action(int choix)
{
	switch (choix) {
		case 1:
			tri_par_nom();
			break ;
		case 2:
			tri_par_date();
			break ;
		case 3:
			tri_par_status();
			break ;
		case 4:
			afficherTousReservation();
			break;
		case 5:
			return 0;
		default:
			printf("Choix invalide. Veuillez réessayer.\n");
	}
	return (1);
}

void tri()
{
	int	choix;

	while (1)
	{
		clear_screen();
		choix = tri_menu();
		if (tri_action(choix) == 0)
			return ;
		printf("\n\nPress Enter to continue...");
		int c;
		while ((c = getchar()) != '\n' && c != EOF);
		getchar();
	}
}
