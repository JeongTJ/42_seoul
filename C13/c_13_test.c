#include <stdio.h>
#include "ex00/btree_create_node.c"
#include "ex01/btree_apply_prefix.c"
#include "ex02/btree_apply_infix.c"
#include "ex03/btree_apply_suffix.c"
#include "ex04/btree_insert_data.c"
#include "ex05/btree_search_item.c"
#include "ex06/btree_level_count.c"
#include "ex07/btree_apply_by_level.c"

int	intcmp(void *item1, void *item2) {
	int a = *((int *) item1);
	int b = *((int *) item2);
	a %= 16;
	b %= 16;
	if (a < b)
		return -1;
	else if (a > b)
		return 1;
	else
		return 0;
}

void print_int(void *item) {
	int x = *((int *) item);
	printf("%d ", x);
}

void debug(void *item, int current_level, int is_first_elem) {
	print_int(item);
	printf("%d %d\n", current_level, is_first_elem);
}

int main() {
	// Exercise 04
	t_btree *root = 0;
	int *ptr[32];
	for (int i = 0; i < 32; ++i) {
		ptr[i] = malloc(sizeof(int));
		*ptr[i] = i;
	}
	btree_insert_data(&root, ptr[8], intcmp);
	btree_insert_data(&root, ptr[3], intcmp);
	btree_insert_data(&root, ptr[1], intcmp);
	btree_insert_data(&root, ptr[6], intcmp);
	btree_insert_data(&root, ptr[4], intcmp);
	btree_insert_data(&root, ptr[7], intcmp);
	btree_insert_data(&root, ptr[10], intcmp);
	btree_insert_data(&root, ptr[14], intcmp);
	btree_insert_data(&root, ptr[13], intcmp);

	// Exercise 01~03
	btree_apply_prefix(root, print_int);
	printf("\n");
	btree_apply_infix(root, print_int);
	printf("\n");
	btree_apply_suffix(root, print_int);
	printf("\n\n");

	// Exercise 05
	for (int i = 0; i < 32; ++i) {
		void *item = btree_search_item(root, ptr[i], intcmp);
		if (item) {
			print_int(item);
		} else {
			printf("x ");
		}
		if (i % 16 == 15) {
			printf("\n");
		}
	}
	printf("\n");

	// Exercise 06
	printf("%d ", btree_level_count(root));
	printf("%d\n\n", btree_level_count(0));

	// Exercise 07
	btree_apply_by_level(root, debug);
	btree_apply_by_level(0, debug);
	return 0;
}
