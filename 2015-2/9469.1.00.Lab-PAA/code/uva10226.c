#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Data {
    int count;
    char cityName[30];
};

struct Node {
    struct Node *left;
    struct Node *right;
    struct Data data;
};

struct Tree {
    struct Node *root;
    int size;
};

void tree_init(struct Tree *tree) {
    tree->size = 0;
    tree->root = NULL;
}

int tree_empty(struct Tree *tree) {
    return (tree->size == 0);
}

int compare_city(char *city1, char *city2) {
    return strcmp(city1, city2);
}

void tree_insert_city_recursive(struct Tree *tree, char *cityName, struct Node *node);

void tree_insert_city(struct Tree *tree, char *cityName) {
    
    if (tree == NULL)
        return;
    
    else if (tree_empty(tree)) {
        tree->root = (struct Node *) malloc(sizeof(struct Node));
        tree->root->left = NULL;
        tree->root->right = NULL;
        
        memcpy(tree->root->data.cityName, cityName, strlen(cityName) + 1);
        tree->root->data.count = 1;
    }
    
    else
        tree_insert_city_recursive(tree, cityName, tree->root);
    
    tree->size += 1;
}

void tree_insert_city_recursive(struct Tree *tree, char *cityName, struct Node *node) {
    
    if (node == NULL)
        return;
    
    struct Data *tmpCity = &(node->data);
    int comparison = compare_city(cityName, tmpCity->cityName);
    
    if (comparison == 0)
        tmpCity->count += 1;
    
    /* city is greater than tmpCity, insert to the right */
    else if (comparison > 0) {
        
        if (node->right == NULL) {
            node->right = (struct Node *) malloc(sizeof(struct Node));
            node->right->left = NULL;
            node->right->right = NULL;
            
            memcpy(node->right->data.cityName, cityName, strlen(cityName) + 1);
            node->right->data.count = 1;
            return;
        }
        
        tree_insert_city_recursive(tree, cityName, node->right);
    }
    
    else {
        
        if (node->left == NULL) {
            node->left = (struct Node *) malloc(sizeof(struct Node));
            node->left->left = NULL;
            node->left->right = NULL;
            
            memcpy(node->left->data.cityName, cityName, strlen(cityName) + 1);
            node->left->data.count = 1;
            return;
        }
        
        tree_insert_city_recursive(tree, cityName, node->left);
    }
    
}

void traverse_tree_in_order(struct Tree* tree, struct Node *node, void (*f)(struct Tree *, struct Node *)) {
    
    if (node == NULL)
        return;
    
    if (node->left)
        traverse_tree_in_order(tree, node->left, f);
    
    f(tree, node);
    
    if (node->right)
        traverse_tree_in_order(tree, node->right, f);
    
}

void print_data(struct Tree *tree, struct Node *node) {
    
    float ratio = (float) node->data.count / (float) tree->size;
    printf("%s %0.4f\n", node->data.cityName, 100.0 * ratio);
}

void print_tree_in_order(struct Tree *tree) {
    traverse_tree_in_order(tree, tree->root, print_data);
}

void tree_free_node(struct Tree *tree, struct Node *node) {
    
    if (node != NULL) {
        
        if (node->left) {
            tree_free_node(tree, node->left);
            node->left = NULL;
        }
        
        if (node->right) {
            tree_free_node(tree, node->right);
            node->right = NULL;
        }
        
        free(node);
        tree->size -= 1;
    }
}

void tree_empty_all(struct Tree *tree) {
    
    tree_free_node(tree, tree->root);
    tree->size = 0;
    tree->root = NULL;
}


int main(int argc, char **argv) {
    
    int numberOfTestCases;
    char cityNameBuffer[31];
    
    struct Tree tree;
    tree_init(&tree);
    
    
    scanf("%d\n", &numberOfTestCases);
    int i;

    for (i = 0; i < numberOfTestCases; i++) {
    
        while (fgets(cityNameBuffer, 30, stdin) != NULL) {
            
            if (strcmp(cityNameBuffer, "\n") == 0)
                break;
            
            if (cityNameBuffer[strlen(cityNameBuffer) - 1] == '\n')
                cityNameBuffer[strlen(cityNameBuffer) - 1] = '\0';
            tree_insert_city(&tree, cityNameBuffer);
            
        }

        print_tree_in_order(&tree);
        tree_empty_all(&tree);

        if (i != numberOfTestCases - 1)
            printf("\n");
    }
    
    return 0;
}