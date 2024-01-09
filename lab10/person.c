#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// TODO: Βρες τα memory leaks και κάνε free εκεί που χρειάζεται!

struct person {
	char *fname;
	char *lname;
	char *mname;
};

struct person *person_init(char *firstname, char *lastname, char *middlename)
{
	struct person *p = malloc(sizeof(struct person));
	p->fname = malloc((strlen(firstname + 1) * sizeof(char)));
	p->lname = malloc((strlen(lastname + 1) * sizeof(char)));
	p->mname = malloc((strlen(middlename + 1) * sizeof(char)));

	strcpy(p->fname, firstname);
	strcpy(p->lname, lastname);
	strcpy(p->mname, middlename);

	return p;
}

struct person *child_of(struct person father, char *newname)
{
	struct person *p = malloc(sizeof(struct person));
	p->fname = malloc((strlen(newname + 1) * sizeof(char)));
	p->lname = malloc((strlen(father.lname + 1) * sizeof(char)));
	p->mname = malloc((strlen(father.mname + 1) * sizeof(char)));
	
	strcpy(p->fname, newname);
	strcpy(p->lname, father.lname);
	strcpy(p->mname, father.mname);

	return p;
}

int main(void)
{
	struct person *father = person_init("Christos", "Dokimopoulos", ""); 
	struct person *child = child_of(*father, "Nikos");

	printf("Father: %s %s\n", father->fname, father->lname);
	printf("Child: %s %s\n", child->fname, child->lname);

	free(father);
	free(child);

	return 0;
}
