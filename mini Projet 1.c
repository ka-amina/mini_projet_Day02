//see discription of project here:https://github.com/aymanebenhima/workshop-c-language/blob/main/Day02/mini-projet.md
#include <stdio.h>
#include <string.h>

struct Book {
 int id;
 char Title[50];
 char Author[50];
 int Quantity;
 int Price;
};

void Choisir( int *Choix){

printf("1- Ajouter un livre au stock\n");
printf("2- Afficher tous les livres disponibles.\n");
printf("3- Rechercher un livre par son titre.\n");
printf("4- Mettre � jour la quantit� d'un livre.\n");
printf("5- Supprimer un livre du stock.\n");
printf("6- Afficher le nombre total de livres en stock.\n");
printf("Entrer votre choix : ");
scanf("%d", Choix);
}

struct Book EnterElement(struct Book book){
printf("entrer Id de livre\n");
scanf("%d",&book.id);
printf("\n entrer le titre de livre\n");
scanf("%s", book.Title);
printf("entrer l'auteur\n");
scanf("%s", book.Author);
printf("entrer la quntite\n");
scanf("%d",&book.Quantity);
printf("entrer le prix de livre\n");
scanf("%d",&book.Price);
return book;
}

void DisplayBooks(struct Book books[], int n){
for (int i = 0; i < n; i++) {
        printf("%d %s %s %d %d\n",
            books[i].id, books[i].Title, books[i].Author, books[i].Quantity, books[i].Price);
     printf("----------------------------------------------\n");
    }
}

void AddBook(struct Book* books, int *n){
  books[*n]= EnterElement(books[*n]);
    (*n)++;
    printf("le livre a ete ajoute avec succes\n");
}

void UpdateBook(struct Book* books, int n){
    int id, NewQuantity, found, i;
 printf("entrer l'id de livre a mettre a jour:");
 scanf("%d", &id);
 for(i=0; i<n; i++){
      if (books[i].id == id){
        found=1;
        printf("entrer la novelle quantite : ");
        scanf("%d", &NewQuantity);
        books[i].Quantity = NewQuantity;
        printf("la quantite mise a jours avec succes.\n");
        break;
      }
 }
 if (!found)
    printf("le livre No.%d n'est pas trouve.\n", id);
}

void SearchBook(struct Book books[], int n){
char Title[50];
int  found=0, i;
printf("entrer le titre de livre : \n");
scanf("%s", Title);
for (i=0; i<n; i++){
        found=1;
    if (strcmp(books[i].Title, Title)==0){
      printf("le livre est trouve : \n");
      printf("%d %s %s %d %d\n", books[i].id, books[i].Title, books[i].Author, books[i].Quantity, books[i].Price);
      printf("----------------------------------------------\n");
      break;
    }
}
}

void DeleteBook(struct Book books[], int *n) {
int id, i, j, found;
printf("entrer l'Id de livre que vous s'houaite a supprimer");
scanf("%d", &id);
for(i=0; i<*n; i++){
    if (books[i].id == id){
        found=1;
    for(j=i; j<*n; j++){
        books[j]=books[j+1];
    }
     (*n)--;
     printf("le livre a ete suprime avec succes.\n");
    }
}

}

void BookStock(struct Book books[], int n) {
int  i, Qte=0, Qte1=0, SommeQuantity=0;
for (i=0; i<n; i++){
    if (books[i].Quantity != 0){
        Qte = books[i].Quantity;
        SommeQuantity = Qte + Qte1;
        Qte1 = Qte;
    }
}
printf(" le Nombre Total de Livres en Stock est : %d \n", SommeQuantity);
}

int main(){
struct Book books[50];
int Choix,n,i, NewBook;

printf("entrer nombre des livres : ");
scanf("%d", &n);

for(i=0; i<n; i++){
    printf("entrer les information de livre No.%d \n", i+1);
    books[i]=EnterElement(books[i]);
}
printf("les livres sont ajout� avec succ�s\n");

do{
 Choisir(&Choix);

 switch(Choix){
 case 1:
    AddBook(books, &n);
    break;
 case 2:
   DisplayBooks(books, n);
   break;
 case 3:
    SearchBook(books, n);
    break;
 case 4:
    UpdateBook(books, n);
    break;
 case 5:
    DeleteBook(books, &n);
    break;
 case 6:
    BookStock(books, n);
 default:
    printf("Votre choix n'est pas dans la liste.\n");
    break;
 }
}while(Choix >= 1 && Choix <= 7);
return 0;
}