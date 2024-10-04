#include "binary_trees.h"
/**
 * build_avl_tree - builds an AVL tree from an array
 * @array: the array to be converted
 * @start:start index
 * @end: end index
 * @parent:parent node
 * Return:a pointer to the root node of
 * the created AVL tree, or NULL on failure
 */
avl_t *build_avl_tree(int *array, int start, int end, avl_t *parent)
{
	avl_t *node;
	int mid;

	if (start > end)
		return (NULL);
	mid = (start + end) / 2;
	node = malloc(sizeof(avl_t));
	if (!node)
		return (NULL);
	node->n = array[mid];
	node->parent = parent;
	node->left = build_avl_tree(array, start, mid - 1, node);
	node->right = build_avl_tree(array, mid + 1, end, node);
	return (node);

}
/**
 * sorted_array_to_avl - builds an AVL tree from an array
 * @array:a pointer to the first element of the array to be converted
 * @size: the number of element in the array
 * Return:a pointer to the root node of the created AVL tree,
 * or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size == 0)
		return (NULL);
	return (build_avl_tree(array, 0, size - 1, NULL));
}
