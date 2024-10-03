#include "r_sys.h"

int	comp_status(char *st1, char *st2)
{
	int st1_i;
	int st2_i;
	char *status[] = {
		"validé",
		"reporté",
		"annulé",
		"traité"
	};

	st1_i = 0;
	st2_i = 0;
	for (int i = 0; i < 4; i++)
	{
		if (strcmp(st1, status[i]) == 0)
			st1_i = i;
		if (strcmp(st2, status[i]) == 0)
			st2_i = i;
	}
	return (st1_i - st2_i);
}

int comp_date(char *dt1, char *dt2)
{
	int ret;
	if ((ret = strncmp(dt1, dt2, 4)) == 0)
	{
		if ((ret = strncmp(dt1, dt2, 7)) == 0)
		{
			if ((ret = strcmp(dt1, dt2)) == 0)
			{
				return (0);
			}
		}
	}
	return (ret);
}

void clear_screen()
{
	#ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif
}

int trouverReservation(int reference)
{
    for (int i = 0; i < count; i++) {
        if (reservations[i].reference == reference) {
            return i; // Retourne l'index de la réservation si trouvée
        }
    }
    return -1; // Retourne -1 si non trouvée
}

void _afficherReservation(struct Reservation r)
{
	printf("Réservation trouvée\n");
	printf("ref: %d\t\tdate: %s\n", r.reference, r.date);
	printf("Nom: %s\tPrenom: %s\n", r.nom, r.prenom);
	printf("Age: %d\n", r.age);
	printf("Status: %s\n", r.statut);
	printf("Telephone: %s\n", r.telephone);
}
