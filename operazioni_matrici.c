/***************************************************************************************/
/* Programma che calcola il prodotto e la somma di due matrici acquisite dinamicamente */
/***************************************************************************************/


/*****************************/
/* Inclusione delle librerie */
/*****************************/

#include <stdio.h>
#include <stdlib.h>

/********************************/
/* Dichiarazione delle funzioni */
/********************************/

/* Funzione per stampa a schermo del menu */
int messaggio ();

/* Funzione per creazione e popolamento della matrice */
double** crea_matrice (int*,	/* output: numero righe */
		       int*);	/* output: numero colonne*/

/* Funzione per stampa della matrice */
void stampa_matrice (int,	/* input: numero di righe */
	             int,	/* input: numero di colonne */
		     double**);	/* input: matrice */

/* Funzione per eseguire la somma fra matrici */
double** somma_matrici (double**,  /* input: prima matrice */
			double**,  /* input: seconda matrice */	
			int*,	   /* output: esito di controllo */
			int,	   /* input: numero righe prima matrice */
			int,       /* input: numero colonne prima matrice */
			int,	   /* input: numero righe seconda matrice */
			int);      /* input: numero colonne seconda matrice */

/* Funzione per eseguire il prodotto fra matrici */
double** prodotto_matrici (double**,	/* input: prima matrice */
			   double**,	/* input: seconda matrice */
			   int*,	/* output: selezione per commutativita' */
			   int*,	/* output: esito di controllo */
			   int,		/* input: numero righe prima  matrice*/
			   int,		/* input: numero colonne seconda matrice*/
			   int,		/* input: numero righe seconda matrice */
			   int);	/* input: numero colonne seconda matrice */

/* Funzione per eseguire il calcolo del prodotto */
double** calcola_prodotto (double**,	/* input: prima matrice */
			   double**,	/* input: seconda matrice */
			   int*,	/* output: esito di controllo */
			   int,		/* input: numero righe seconda matrice */
			   int,		/* input: numero colonne prima matrice */
			   int,		/* input: numero righe prima matrice */
			   int);	/* input: numero colonne seconda matrice */

/* Funzione per pulizia buffer */
void pulisci_buffer ();

/******************************/
/* Definizione delle funzioni */
/******************************/

/* Definizione della funzione main */
int main (void)
{
	/* Dichiarazione delle variabili locali alla funzione */
	int   selezione,                 /* input: valore di tipo intero per definire la scelta dell'utente */
              esito;                     /* output: valore di tipo intero per controllo dell'input */
	int   num_righe_matrice1,	 /* lavoro: numero righe prima matrice */
	      num_colonne_matrice1,	 /* lavoro: numero colonne prima  matrice */
	      num_righe_matrice2,	 /* lavoro: numero righe seconda matrice */
	      num_colonne_matrice2,      /* lavoro: numero colonne seconda matrice */
	      selezione_prodotto;	 /* lavoro: valore commutativita' prodotto */
       double **matrice_1 = NULL,	 /* lavoro: prima matrice creata */
	      **matrice_2 = NULL,	 /* lavoro: seconda matrice creata */
       	      **matrice_somma = NULL, 	 /* lavoro: matrice contenente la somma fra le due matrici */
              **matrice_prodotto = NULL; /* lavoro: matrice contenente il prodotto fra le due matrici selezionate */

	/* inizio ciclo per controllo input del menu */
	do					
	{
		/* stampa del messaggio e acquisizione dell'input di selezione */
		selezione = messaggio();   

		/* applicazione della selezione scelta dall'utente */
		switch(selezione)	
		{
			case 1:		
			    matrice_1 = crea_matrice (&num_righe_matrice1,	/* output: dimensione righe */ 
					    	      &num_colonne_matrice1);	/* output: dimensione colonne */
			break;
		        case 2:		
			    matrice_2 = crea_matrice (&num_righe_matrice2, 	/* output: dimensione righe*/
					    	      &num_colonne_matrice2);	/* output: dimensione colonne */
			break;
			case 3:		
			    stampa_matrice (num_righe_matrice1,   /* input: dimensione righe prima matrice */
					    num_colonne_matrice1, /* input: dimensione colonne prima matrice */
					    matrice_1);		  /* input: prima matrice creata in precedenza */
			break;
			case 4:		
			    stampa_matrice (num_righe_matrice2,   /* input: dimensione righe seconda matrice */
					    num_colonne_matrice2, /* input: dimensione colonne seconda matrice */
					    matrice_2);		  /* input: seconda matrice creata in precedenza */
			break;
			case 5:		
			    matrice_somma = somma_matrici (matrice_1, 	  /* input: prima matrice creata in precedenza */
					    		   matrice_2, 	  /* input: seconda matrice creata in precedenza */
							   &esito, 	  /* output: variabile per controllo dell'esito della funzione */
							   num_righe_matrice1, 	  /* input: dimensione righe prima matrice */
							   num_righe_matrice2,	  /* input: dimensione righe seconda matrice */
							   num_colonne_matrice1,  /* input: dimensione colonne prima matrice */
							   num_colonne_matrice2); /* input: dimensione colonne seconda matrice */

			    /* istruzione per controllo dell'esito della funzione */
			    if (esito == 1)	
			    {
				    printf("La matrice somma e': \n");			
				    stampa_matrice (num_righe_matrice1,		/* input: dimensione righe prima matrice */
						    num_colonne_matrice2,	/* input: dimensione colonne seconda matrice */
						    matrice_somma);		/* input: matrice somma */
			    }
			    else
			    {
				    printf("Non e' possibile eseguire la somma!\n");	
			    }
			break;
			case 6:		
			    matrice_prodotto = prodotto_matrici (matrice_1,		/* input: prima matrice creata in precedenza */
					    			 matrice_2,		/* input: seconda matrice creata in precedenza */
								 &esito,		/* output: variabile controllo esito funzione */
								 &selezione_prodotto,   /* output: valore commutatività prodotto */
								 num_righe_matrice1,	/* input: dimensione righe prima matrice */
								 num_colonne_matrice2,	/* input: dimensione colonne seconda matrice */
								 num_righe_matrice2,	/* input: dimensione righe seconda matrice */
								 num_colonne_matrice1);	/* input: dimensione colonne prima matrice */

			    /* istruzione per controllo dell'esito della funzione */
			    if (esito == 1)					
			    {
				    if(selezione_prodotto == 1)
				    {
				    	printf("La matrice prodotto e': \n");		
				    	stampa_matrice (num_righe_matrice1,	/* input: dimensione righe prima matrice */
						        num_colonne_matrice2,	/* input: dimensione colonne seconda matrice */
						    	matrice_prodotto);	/* input: matrice prodotto */
				    }
				    else
				    {
					printf("La matrice prodotto e': \n");
				    	stampa_matrice (num_righe_matrice2,	/* input: dimensione righe seconda matrice */
							num_colonne_matrice1,	/* input: dimensione colonne prima matrice */
							matrice_prodotto);	/* input: matrice prodotto */
				    }
			    }
			    else
			    {
				    printf("Non e' possibile eseguire il prodotto!\n");	
			    }
		        break;
		}
	}
	while (selezione != 7);	

	/* valore di ritorno della main al SO */
	return (0);	
}

/* Definizione della funzione per stampa del menu iniziale e della scelta dell'utente */
int messaggio ()
{
	/* dichiarazione delle variabili locali alla funzione */
	int selezione;		/* input: valore di tipo intero per la selezione dell'utente */
	int esito_lettura;	/* lavoro: valore che definisce la validazione dell'input  */

	/* inizio ciclo di acquisizione e validazione input con stampa del menu */
	do			
	{
		printf("\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *");	
		printf("\n* (Digitare: 1) Generazione prima matrice                           *");
		printf("\n* (Digitare: 2) Generazione seconda matrice                 	    *");
		printf("\n* (Digitare: 3) Stampare la prima matrice                           *");
		printf("\n* (Digitare: 4) Stampare la seconda matrice                         *");
		printf("\n* (Digitare: 5) Eseguire la somma fra la due matrici                *");
		printf("\n* (Digitare: 6) Eseguire il prodotto fra le due matrici             *");
		printf("\n* (Digitare: 7) Per terminare il programma                          *\n");
		printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
		esito_lettura = scanf("%d", 
				      &selezione);

		if ((esito_lettura != 1) || 				
		    (selezione > 7 || selezione < 1))			
		{
			printf("Input di selezione errato!\n");		
			pulisci_buffer();			
		}	
	}
	while ((esito_lettura != 1) ||			
	       (selezione > 7 || selezione < 1));
	pulisci_buffer();
	
	/* valore restituito dalla funzione: valore di selezione */
	return (selezione);		
}

/* Definizione della funzione per l'acquisizione della matrice */
double** crea_matrice (int *num_righe_matrice,		/* output: dimensione righe matrice */
		       int *num_colonne_matrice)	/* output: dimensione colonne matrice */
{
	/* dichiarazione delle variabili locali alla funzione */
	int    riga,			/* input: variabile contenente le righe della matrice */
    	       colonna;			/* input: variabile contenente le colonne della matrice */
	double **matrice_creata;        /* output: matrice creata */
	int    esito_lettura_righe,	/* lavoro: valore che definisce la validazione input */
	       esito_lettura_matrice,	/* lavoro: valore che definisce la validazione input */
	       esito_lettura_colonne;	/* lavoro: valore che definisce la validazione input */
	double riga_tmp,		/* lavoro: variabile temporanea per validazione input */
       	       colonna_tmp;		/* lavoro: variabile temporanea per validazione input */

	/* inizio ciclo per acquisizione e validazione input */
	do	
	{
		printf("Inserire il numero di righe desiderate (> 0):\n");		
		esito_lettura_righe = scanf("%lf", 
					    &riga_tmp);			
		riga = riga_tmp;						
		if (esito_lettura_righe != 1 || riga <= 0 || riga_tmp != riga)	
		{
			printf("Input non accettabile. Riprova!\n");		
			pulisci_buffer();				
		}
	}
	while (esito_lettura_righe != 1 || riga <= 0 || riga_tmp != riga);
	pulisci_buffer();	

	/* assegnamento valore di riga alla variabile puntatore per salvataggio dato */
	*num_righe_matrice = riga;	       	

	/* inizio ciclo per acquisizione e validazione input */
	do	
	{
		printf("Inserire il numero di colonne desiderate (> 0):\n");		
		esito_lettura_colonne = scanf("%lf", 
					      &colonna_tmp);			
		colonna = colonna_tmp;						
		if (esito_lettura_colonne != 1 || colonna <= 0 || colonna_tmp != colonna)
		{
			printf("Input non accettabile. Riprova!\n");		
			pulisci_buffer();				
		}
	
	}
	while (esito_lettura_colonne != 1 || colonna <= 0 || colonna_tmp != colonna);
	pulisci_buffer();
	
	/* assegnamento valore di colonna alla variabile puntatore per salvataggio dato */
	*num_colonne_matrice = colonna;	

	/* creazione dinamica delle righe della matrice */
	matrice_creata = (double**)malloc((*num_righe_matrice)*sizeof(int*));

	/* ciclo per creazione dinamica delle colonne in base alle righe */
	for(riga = 0; 
	    (riga < *num_righe_matrice); 
	    riga++)
		matrice_creata[riga] = (double *)malloc((*num_righe_matrice)*(*num_colonne_matrice)*sizeof(int));

	/* ciclo riga per colonna */
	for(riga = 0; 
	    (riga < *num_righe_matrice); 
	    riga++)
	{	
		for(colonna = 0; 
		    (colonna < *num_colonne_matrice); 
		    colonna++)
		{
			/* inizio ciclo di acquisizione e validazione input */
			do
			{
				printf("Digita il valore da inserire nella posizione (%d,%d) \n", 
				       riga, 
				       colonna);
				esito_lettura_matrice = scanf("%lf", 
							      &matrice_creata[riga][colonna]);	
				if (esito_lettura_matrice != 1)	
				{
					printf("Input non accettabile. Riprova!\n"); 
					pulisci_buffer();
				}
			}
			while (esito_lettura_matrice != 1);
			pulisci_buffer();	
		}	
	}

	/* stampa messaggio per creazione avvenuta con successo */
	printf("\n");
	printf("La matrice e' stata creata correttamente!\n");	

	/* matrice restituita dalla funzione */
	return (matrice_creata);	
}

/* Definizione della funzione per la stampa della matrice */
void stampa_matrice (int    num_righe_matrice, 	 /* input: dimensione righe matrice */
		     int    num_colonne_matrice, /* input: dimensione colonne matrice */
		     double **matrice)		 /* input: matrice da stampare */
{
	/* dichiarazione delle variabili locali alla funzione */
	int riga,	/* lavoro: indice di ciclo */
	    colonna;	/* lavoro: indice di ciclo */

	/* controllo di eventuale matrice nulla */
	if (matrice == NULL)
	{
		printf("Matrice non ancora creata!");
	}
	else
	{
		/* cicli per stampa matrice con formattazione a due cifre decimali */
		for(riga = 0; 
		    (riga < num_righe_matrice); 
	   	    riga++)
		{
			printf("\n");
			for(colonna = 0; 
			    (colonna < num_colonne_matrice); 
			    colonna++)
				printf("[%.2lf]\t", 
				       matrice[riga][colonna]);

		}
		printf("\n\n");
	}
}

/* Definizione della funzione per la creazione della matrice somma */
double** somma_matrici (double **matrice_1,   	     /* input: prima matrice */
			double **matrice_2,   	     /* input: seconda matrice */
			int    *esito,	      	     /* output: valore di controllo */
			int    num_righe_matrice1,   /* input: numero righe prima matrice */
			int    num_righe_matrice2,   /* input: numero righe seconda matrice */
			int    num_colonne_matrice1, /* input: numero colonne prima matrice */
			int    num_colonne_matrice2) /* input: numero colonne seconda matrice */
{
	/* dichiarazione delle variabili locali alla funzione */
	double **matrice_somma = NULL;  /* output: matrice somma */
	int	riga,			/* lavoro: indice creazione matrice */
		colonna;		/* lavoro: indice creazione matrice */

	/* istruzione di controllo per eventuali matrici nulle */
	if ((matrice_1 == NULL || matrice_2 == NULL))

	{
		/* valore esito negativo */
		*esito = 0;
	}
	else
	{
		/* istruzione di controllo per eseguire la somma */
		if ((num_righe_matrice1 == num_righe_matrice2) && 
		    (num_colonne_matrice1 == num_colonne_matrice2))
		{
			/* valore esito positivo */
			*esito = 1;

			/* allocazione memoria per le righe della matrice somma */
			matrice_somma = (double **)malloc((num_righe_matrice1)*sizeof(int *));

			/* allocazione memoria per le colonne della matrice somma */
			for(riga = 0; 
			    (riga < num_righe_matrice1); 
			    riga++)
				matrice_somma[riga] = (double *)malloc((num_righe_matrice1)*(num_colonne_matrice2)*sizeof(int));

			/* cicli per riempimento matrice somma */
			for(riga = 0; 
			    (riga < num_righe_matrice1); 
			    riga++)
			{
				for(colonna = 0; 
				    (colonna < num_colonne_matrice2); 
				    colonna++)
				{
					matrice_somma[riga][colonna] = matrice_1[riga][colonna] + matrice_2[riga][colonna]; 
				}
			}
		}
		else
		{
			/* valore esito negativo */
			*esito = 0;
		}
	}

	/* matrice somma restituita dalla funzione */
	return (matrice_somma);
}

/* Definizione della funzione per la creazione della matrice prodotto */
double** prodotto_matrici (double **matrice_1,          /* input: prima matrice */
			   double **matrice_2,	        /* input: seconda matrice */
			   int    *esito,		/* output: esito della funzione */
			   int    *selezione,	        /* output: esito riguardante la commutativita' */
			   int    num_righe_matrice1,   /* input: numero righe prima matrice */
			   int    num_colonne_matrice2, /* input: numero colonne prima matrice */
			   int    num_righe_matrice2,   /* input: numero righe seconda matrice */
			   int    num_colonne_matrice1) /* input: numero colonne seconda matrice */
{
	/* dichiarazione delle variabili locali alla funzione */
	double  selezione_tmp;             /* input: variabile temporanea per scelta utente */
    double  **matrice_prodotto = NULL; /* output: matrice prodotto*/
	int	    esito_prodotto,				   /* lavoro: valore che definisce la validazione dell'input */
	     	esito_selezione;	   /* lavoro: valore che definisce la validazione dell'input */

	/* ciclo per validazione e acquisizione input utente*/
	do
	{
		printf("(Digitare 1) Prodotto fra la prima matrice e la seconda (AxB)\n");
		printf("(Digitare 2) Prodotto fra la seconda matrice e la prima (BxA)\n");	
		esito_selezione = scanf("%lf", 
					&selezione_tmp);
		*selezione = selezione_tmp;
		if (esito_selezione != 1 || ( *selezione != selezione_tmp))
		{
			printf("Input non valido! Riprova.\n");
			pulisci_buffer();
		}
	}
	while (esito_selezione != 1 || (*selezione != selezione_tmp));
	pulisci_buffer();

	/* istruzione nel caso la selezione acquisita sia stata AxB */
	if (*selezione == 1)
	{
		/* calcolo del prodotto AxB e assegnamento alla matrice prodotto */
		matrice_prodotto = calcola_prodotto (matrice_1,
						     matrice_2,
						     &esito_prodotto,
						     num_righe_matrice2,
						     num_colonne_matrice1,
						     num_righe_matrice1,
						     num_colonne_matrice2);
		/* istruzione nel caso il prodotto sia andato o no a buon fine */
		if (esito_prodotto == 0)
			*esito = 0;
		else
			*esito = 1;
	}
	else 
	{
		/* calcolo del prodotto BxA e assegnamento alla matrice prodotto */
		matrice_prodotto = calcola_prodotto (matrice_2,
                                                     matrice_1,
                                                     &esito_prodotto,
                                                     num_righe_matrice1,
                                                     num_colonne_matrice2,
                                                     num_righe_matrice2,
                                                     num_colonne_matrice1);
		/* istruzione nel caso il prodotto sia andato o no a buon fine */
		if (esito_prodotto == 0)
            *esito = 0;
        else
            *esito = 1;
	}

	/* matrice prodotto restituita dalla funzione */
	return (matrice_prodotto);
	
}

/* Definizione della funzione per il calcolo del prodotto fra matrici */
double** calcola_prodotto (double **matrice_1,		/* input: prima matrice */
			   double **matrice_2,		/* input: seconda matrice */
			   int    *esito,		/* output: esito della funzione */
			   int    num_righe_matrice2,	/* input: numero righe seconda matrice */
			   int    num_colonne_matrice1,	/* input: numero colonne prima matrice */
			   int    num_righe_matrice1,	/* input: numero righe prima matrice */
			   int    num_colonne_matrice2)	/* input: numero colonne seconda matrice */
{
	/* dichiarazione delle variabili locali alla funzione */
	double **matrice_prodotto = NULL; /* output: matrice prodotto */
	int    riga,                      /* lavoro: indice di lavoro nella creazione delle righe */
	       colonna,                   /* lavoro: indice di lavoro nella creazione delle colonne */
	       i;	                  /* lavoro: indice di lavoro riempimento matrice prodotto */

	/* controllo nel caso una delle due matrici o enrambe siano nulle */
	if (matrice_1 == NULL || matrice_2 == NULL)
	{
		/* valore esito negativo */
		*esito = 0;
	}
	else
	{
		/* valore esito positivo */
		*esito = 1;

		/* istruzione per condizione per eseguire il prodotto */
		if (num_colonne_matrice1 == num_righe_matrice2)
		{
			/* creazione righe */
			matrice_prodotto = (double **)malloc((num_righe_matrice1)*sizeof(double *));

			for(riga = 0; 
			    (riga < num_righe_matrice1); 
			    riga++)
			{
				/* creazione colonne in base alle righe */
				matrice_prodotto[riga] = (double *)malloc((num_colonne_matrice2)*sizeof(double));
			}

			/* creazione matrice prodotto */
			for(riga = 0; 
			    (riga < num_righe_matrice1); 
			    riga++)
			{
				for(colonna = 0; 
				    (colonna < num_colonne_matrice2); 
				    colonna++)
				{
					matrice_prodotto[riga][colonna] = 0;

					for(i = 0; 
					    (i < num_righe_matrice2); 
					    i++)
					{
						matrice_prodotto[riga][colonna] += matrice_1[riga][i] * matrice_2[i][colonna];
					}
				}
			}
		}
		else
		{
			/* valore esito negativo */
			*esito = 0;
		}
	}

	/* matrice prodotto restituita dalla funzione */
	return (matrice_prodotto);

}

/* Definizione funzione per pulizia buffer */
void pulisci_buffer()
{
	while(getchar() != '\n');
}





