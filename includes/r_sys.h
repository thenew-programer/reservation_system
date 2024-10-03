#ifndef R_SYS_H
# define R_SYS_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define MAX_RESERVATIONS 100

struct Reservation {
    char nom[50];
    char prenom[50];
    char telephone[15];
    int age;
    char statut[20]; // "validé", "reporté", "annulé", "traité"
    int reference; // Référence unique générée automatiquement
    char date[11]; // Format: AAAA-MM-JJ
};

extern struct Reservation reservations[MAX_RESERVATIONS];
extern int count;
extern int ref;

/* Utils */
int		comp_status(char *, char *);
int		comp_date(char *, char *);
void	clear_screen();
int		trouverReservation(int);
void	_afficherReservation(struct Reservation);

/* Reservation */
void	afficherReservation(void);
void	afficherTousReservation(void);
void	modifierReservation(void);
void	supprimerReservation(void);
void	ajouterReservation(void);

/* Sorting */
int		tri_menu(void);
void	tri_par_nom(void);
void	tri_par_date(void);
void	tri_par_status(void);
int		tri_action(int);
void	tri(void);

/* Search */
void	recherche_par_nom(void);
void	recherche_par_date(void);
int		recherche_menu(void);
int		recherche_action(int);
void	recherche(void);

/* Statistics */
void	avg_age(void);
void	age_divs(void);
void	statut_divs(void);
int		stat_action(int);
int		stat_menu(void);
void	statistics(void);

#endif
