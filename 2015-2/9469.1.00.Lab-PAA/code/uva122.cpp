//
//  uva122.cpp
//  lab-paa
//
//  Created by Matheus Cassiano Candido on 9/13/15.
//  Copyright (c) 2015 Matheus Cassiano Candido. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>

using namespace std;

typedef struct Data Data;
typedef struct Node Node;
typedef struct Tree Tree;


struct Data {
    bool has_value;
    int value;
};

struct Node {
    Node *left;
    Node *right;
    Data data;
};

struct Tree {
    Node *root;
    int size;
};

struct List {
    Node *first;
    Node *last;
    int size;
};

Node *init_node() {
    Node *node = (Node *) malloc(sizeof(Node));
    node->right = NULL;
    node->left = NULL;
    node->data.has_value = false;
    node->data.value = 0;
    return node;
}

void tree_init(Tree *tree) {
    tree->root = NULL;
    tree->size = 0;
}

void tree_insert_node(Tree *tree, int value, char *path) {
    int pathLen = (int) strlen(path);
    Node *node = tree->root;
    
    if (node == NULL) {
        node = init_node();
        tree->root = node;
    }
    
    for (int i = 0; i < pathLen; i++) {
        
        if (path[i] == 'L') {
            if (node->left == NULL)
                node->left = init_node();
            
            node = node->left;
        }
        
        if (path[i] == 'R') {
            if (node->right == NULL)
                node->right = init_node();
            
            node = node->right;
        }
    }
    
    // or a node is given a value more than once
    if (node->data.has_value)
        node->data.has_value = false;

    else {
        node->data.value = value;
        node->data.has_value = true;
        tree->size += 1;
    }
}


void extract_value_path(char *str, int *value, char *path) {
    *path = '\0';
    sscanf(str, "(%d,%[^)]s", value, path);
}

void print_level_order(Tree *tree) {
    Node *node = tree->root;
    
    queue<Node *> q;
    vector<int> level_order;
    
    q.push(node);
    
    while (!q.empty()) {
        node = q.front();
        q.pop();
        
        if (!node->data.has_value) {
            printf("%s\n", "not complete");
            return;
        }
        
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
        
        level_order.push_back(node->data.value);
    }
    
    printf("%d", level_order[0]);
    for (int i = 1; i < level_order.size(); i++)
        printf(" %d", level_order[i]);
    
    printf("\n");
}

void tree_free_node(Tree *tree, Node *node) {
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

void tree_empty_all(Tree *tree) {
    tree_free_node(tree, tree->root);
    tree->size = 0;
    tree->root = NULL;
}

int main(int argc, char **argv) {
    
    char buf[256], path[256];
    int value;
    Tree tree;
    tree_init(&tree);
    
    while (scanf("%s", buf) != EOF) {
        
        if (strcmp(buf, "()") == 0) {
            print_level_order(&tree);
            tree_empty_all(&tree);
            continue;
        }
        
        extract_value_path(buf, &value, path);
        tree_insert_node(&tree, value, path);
    }

    return 0;
    
}