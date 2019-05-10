#include<stdio.h>

#include<stdlib.h>

struct tree

{

	struct node *root;// êîðåíü

	int count; //êîë-âî ýë-îâ

};



struct node

{

	struct node *parent;//óê íà ïðåäêà

	struct node *left; // óêàçàòåëü íà ëåâîãî ïîòîìêà

	struct node *right; // óêàçàòåëü íà ïðàâîãî ïîòîìêà

	int value;

};



void init(struct tree* t)

{

	t->root = NULL;

	t->count = 0;

}



int insert(struct tree* t, int value) {

	struct node* tmp = (struct node*)malloc(sizeof(struct node));

	if (tmp == NULL) {

		return 2;

	}

	tmp->value = value;

	tmp->left = NULL;

	tmp->right = NULL;

	tmp->parent = NULL;

	struct node* t2 = t->root;

	if (t2 == NULL) {

		t2 = tmp;

		t->root = t2;

		t->count++;

		return 0;

	}



	for (;;) {

		if (t2->value == value) {

			return 1;

		}

		struct node* t3;

		if (t2->value > value)

		{

			if (t2->left == NULL) {

				t2->left = tmp;

				t2->left->parent = t2;

				tmp = NULL;

				t->count++;

				return 0;

			}

			else {

				t3 = t2;

				t2 = t2->left;

			}

		}

		else

		{

			if (t2->right == NULL) {

				t2->right = tmp;

				t2->right->parent = t2;

				tmp = NULL;

				t->count++;

				return 0;

			}

			else {

				t2 = t2->right;

			}

		}

	}

}



void direct_bypass(struct tree*t)

{

		int SIZE = 1;

		struct node** nodes = malloc(sizeof(struct node)*SIZE);

		int last_pos = SIZE - 1;

		printf("%d", t->root->value);

		nodes[last_pos] = t->root->right;

		last_pos--;

		nodes[last_pos] = t->root->left;

		last_pos--;

		while (last_pos != SIZE - 1) {

			last_pos++;

			struct node* tmp = nodes[last_pos];

			printf(" %d", tmp->value);

			if (tmp->right != NULL) {

				nodes[last_pos] = tmp->right;

				last_pos--;

			}

			if (tmp->left != NULL) {

				nodes[last_pos] = tmp->left;

				last_pos--;

			}

		}

		printf("\n");

}





int main() {

	int n = 7, a;

	struct tree tre;

	init(&tre);

	for (int i = 0; i < n; i++) {

		scanf("%d", &a);

		insert(&tre, a);

	}

	direct_bypass(&tre);

	

}
