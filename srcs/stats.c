#include "r_sys.h"

void avg_age()
{
	long long	sum;
	int			i;

	sum = 0;
	for (i = 0; i < count; i++)
		sum += reservations[i].age;
	printf("La Moyenne d'âge des patients ayant réservé est: %Lf.02\n", (long double)sum / i);
}

void age_divs()
{
	int f_div, s_div, l_div;

	f_div = s_div = l_div = 0;
	for (int i = 0; i < count; i++)
	{
		if (reservations[i].age >= 0 && reservations[i].age <= 18)
			f_div++;
		else if (reservations[i].age >= 19 && reservations[i].age <= 35)
			s_div++;
		else
			l_div++;
	}
	printf("Le nombre de patients par tranche d'âge:\n");
	printf("\t0-18 ans: %d\n\t19-35 ans: %d\n\t36+ ans: %d\n", f_div, s_div, l_div);
}

void statut_divs()
{
	int valide, reporte, annule, traite;

	valide = reporte = annule = traite = 0;
	for (int i = 0; i < count; i++)
	{
		if (strcmp(reservations[i].statut, "validé") == 0)
			valide++;
		else if (strcmp(reservations[i].statut, "reporté") == 0)
			reporte++;
		else if (strcmp(reservations[i].statut, "annulé") == 0)
			annule++;
		else
			traite++;
	}
	printf("Le Nombre total de réservations par statut:\n");
	printf("\tvalidé: %d\n\treporté: %d\n\tannulé: %d\n\ttraité: %d\n", valide, reporte, annule, traite);

}

int stat_action(int choix)
{
	switch (choix) {
		case 1:
			avg_age();
			break ;
		case 2:
			age_divs();
			break ;
		case 3:
			statut_divs();
			break ;
		case 4:
			return (0);
		default:
			printf("Choix invalide. Veuillez réessayer.\n");
	
	}
	return (1);
}

int stat_menu()
{
    int choix;

	printf("\nMENU De Statistics\n");
	printf("1. Moyenne d'âge des patients ayant réservé\n");
	printf("2. Nombre de patients par tranche d'âge (ex. : 0-18 ans, 19-35 ans, 36+ ans)\n");
	printf("3. Nombre total de réservations par statut\n");
	printf("4. Return To Main Menu\n");
	printf("Entrez votre choix : ");
	scanf("%d", &choix);
	return (choix);
}

void statistics()
{
	int choix;
	while (1)
	{
		clear_screen();
		choix = stat_menu();
		if (stat_action(choix) == 0) return ;
		printf("\n\nPress Enter to continue...");
		int c;
		while ((c = getchar()) != '\n' && c != EOF);
		getchar();
	}
}
