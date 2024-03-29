#include<stdlib.h>
#include<time.h>
#include<stdio.h>


/*************** DEFINE ***************/
#define VOISIN_MAX  7
#define LOVE_MAX    10
#define lambda 0.4 //si au dessus devient malade, donc 1-lambda prob rester sain
#define gamma 0.8 //si au dessus, devient immunisé, sinon décès
//on considère pour le moment que l'état "malade" dure qu'un jour t
#define MAX 10 //taille de tab Population 10 x 10


/*************** PROTOTYPES ***************/
void writeFile(int L);
int calcul_nb_arcs;
void creation_graphe(graphe* G)
void first_sick(void);
void step(Graphe* G);
int Lenght_tab(int tab[]);


/*************** STRUCTURES ***************/
typedef struct _individu
{ 
  	int id; //on les identifie/différencie par des nombres
	int potentiel;
 	enum  etat;
	float force;
	float dead;
 	 _individu* voisin;
} individu;



typedef struct 
{
	int	nb_individus;
	individu** liste_successeurs; 
} graphe;


typedef struct _voisin
{
    int id, indice;
    struct _voisin* nxt;
} voisin;

typedef struct _ind
{
    int id;
    voisin** list_voisin;
} ind;

typedef struct _list
{
    int nb_id;
    ind** list_voisin;
} list;
  
enum (SAIN, MALADE, IMMUNISE, MORT, VAMPIRE, GHOUL, DETRUIT);


/*************** FONCTIONS ***************/

void writeFile(int L) {
    int v, l;   //L'id du voisin, le degré de love
    int j;      //Le nombre de voisin   
    srand(time(NULL));
    
    char name_file[20];
    FILE *fp;
    
    printf("Entrez le nom du fichier créer: ");
    scanf("%s", name_file);
    fp = fopen(name_file, "w");
    fprintf(fp, "%d\n", L);
    
    for(int i = 1; i <= L; i++) {  //On itère sur l'id de l'individu
        j = rand()%VOISIN_MAX; //On choisit son nombre de voisin
        for(int k = 0; k <= j; k++){    //On itère sur l'id de voisin
            v = rand()%L + 1;       //On choisit l'id du voisin
            if(v != i){                     //On s'assure que                                           l'individu n'est pas son                                    propre voisin                           
                l = rand()%LOVE_MAX + 1; //On choisit le degré de love
                fprintf(fp, "%d %d %d\n", i, v, l); //On écrit
            }
        }
    }
    fclose(fp);
}
//Probleme: Eviter le cas pathologique de doublons et determiner le nopmbre d'arc dans le graphe



int calcul_nb_arcs
{
	int nb_arcs;
	FILE *fp;
	printf("Enter file name :");
	scanf("%c", &f);
	fp = fopen(f, "r");
  
	if (fp != NULL) // le fichier est trouve
	{
		while (fscanf(fp,"%d%d%d", &id, &id_voisin, &affinité) == 3)) //on lit jusqu'à la fin du fichier
		{
			nb_arcs += 1;
		}
	}
	else printf("Le fichier n'a pas été trouvé.");
	fclose(fp);
	return nb_arcs;
}  


void creation_graphe(graphe* G)
{
	int nb_arcs;
	nb_arcs = calcul_nb_arcs();

	FILE *fp;
	printf("Enter file name :");
	scanf("%c", &f);
	fp = fopen(f, "r");

	if (fp != NULL) // le fichier est trouve
	{
		int nb_individus;
		fscanf(fp, "%d", &nb_individus);	
		G->nb_individus 	= nb_individus;
		G->successeurs	= (individu**)malloc(nb_individus * sizeof(individu*));

		for (int i = 0; i < nb_individus; i++) 
		{	
			G->successeurs[i]	= NULL;
		}
		
		for (int i = 0; i < nb_arcs; i++) 
		{
			fscanf(fp, "%d %d %d", &id, &id_voisin, &affinite);
			//u--; // decrement pour gerer le decalage entre le numeros des sommets dans le fichiers et les index dans les tableaux
			//v--;
			//ajout d'un arc (u,v) : un maillon est ajoute en debut de la liste de successeurs de u
			individu* p		= (individu*) malloc(sizeof(individu));
			p->individu = id_voisin - 1;
			p->etat		= 0;
			p->love = affinite;
			p->voisin			= G->successeurs[id-1];
			G->successeurs[id-1]	= p; //-1 car les id commencent a 1
		}
	}
  
	else printf("Le fichier n'a pas été trouvé.");

	fclose(fp);
}



/*void first_sick(int L) //nombre nodes
{	//au hasard, faire en sorte que qqun soit malade
	int i = 0, L;
	i = srand(time())%(L-1) + 1;
	if (Liste[i]->chance_malade >= lambda)
	{
		Liste[i]->etat = 1; //malade
		i++
	}
}
*/

void first_sick(int L) //nb nodes
{
	int id;
	printf("CHOOSE THE FIRST SICK : \n"); //Entrer l'id
	printf("(enter an id)\n");
	scanf("%d", &id);
	Liste[id]->etat = 1; //malade
	if (id > L+1)
	{	printf("THIS ID DOES NOT EXIST\n");
	}
}

int Lenght_tab(int tab[])
{	printf("Lenght : %lu", sizeof(tab) / sizeof(int));
 	return sizeof(tab) / sizeof(int);
}


void step(Graphe* G)
{	//for all indiv de la liste a rediger
	
	{
		if (L[i]->etat == 1) //si malade
		{
			if (force >= gamma) //si a des chances d'etre immu
			{
				L[i]->etat = 2 //devient immu
				L[i]->faiblesse = 0; //ne peut pas retomber malade
				L[i]->dead = 0; //ne peut pas en mourir
			}
			
			else
			{
				L[i]->etat = 3; //si pas immu, meurt
				L[i]->dead = 1;
				L[i]->faiblesse = 0; //le sujet est mort, on ne le traite plus nn plus
			}
		}
	 	propagation(L[i]);
		i++;
		}
}


int main(void) {
	int L = 10;
	writeFile(L);
	Graphe G;
	creation_graphe(&G);
}

