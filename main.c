#include "btree.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void printBtree(btree_node *root)
{
    if (root)
    {
        printf("( ");

        for (int i = 0; i < root->n; i++)
        {
            if (root->noChildren)
            {
                printBtree(root->children[i]);
            }
            printf(" %d- %s ", root->keys[i], root->vals[i]);
        }
        if (root->noChildren)
        {
            printBtree(root->children[root->n]);
        }

        printf(" )");
    }
    else
    {
        printf("<>");
    }
}

int main()
{

    btree database = btree_new(3);

    int choice = 0;
    while(choice != 5) {
        printf("\nB-Tree mini data base\n");
        printf("1) To add a key\n");
        printf("2) To Delete a key\n");
        printf("3) To Search a key\n");
        printf("4) To Print the database\n");
        printf("5) To exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        int id;
        char* name;
        switch(choice){
            case 1:
                name = (char*)malloc(sizeof(char)*20);
                printf("Enter the id: ");
                scanf("%d", &id);
                getchar();
                printf("Enter the name: ");
                fgets(name, 20, stdin);
                name[strlen(name)-1] = '\0';
                btree_insert(&database, id, name);
                break;
            case 2: {
                int id;
                printf("Enter the id you want to delete: ");
                scanf("%d", &id);
                btree_delete(&database, id);
                printf("%d deleted successfully!", id);
                break;
            }
            case 3: {
                int id;
                printf("Enter the id you want to search: ");
                scanf("%d", &id);
                name = btree_search(database, id);
                if(name != NULL) {
                    printf("name: %s\n", name);
                }
                else {
                    printf("person with %d id does not exist\n", id);
                }
                break;
            }
            case 4: {
                printf("Current DataBase: \n");
                printBtree(database.root);
                break;
            }
            case 5: break;
            default:printf("Enter a valid choice\n");
        }
    }


    btree_free(&database);

    return 0;
}