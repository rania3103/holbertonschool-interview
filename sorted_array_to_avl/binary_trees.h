#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

#include <stddef.h>
#include <stdlib.h>
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
typedef struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
}binary_tree_t, avl_t;

void binary_tree_print(const binary_tree_t *);
avl_t *build_avl_tree(int *array, int start, int end, avl_t *parent);
avl_t *sorted_array_to_avl(int *array, size_t size);

#endif 
