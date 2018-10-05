#include "BSTX.h"
#include <iostream>
using namespace std;

/**
 * Implements an unbalanced binary search tree.
 * Note that all "matching" is based on the compares method.
 * @author Mark Allen Weiss
 */
/**
 * Construct the tree.
 */
template <class Comparable>
BinarySearchTreeX<Comparable>::BinarySearchTreeX( const Comparable & notFound ) :
  root(NULL), ITEM_NOT_FOUND( notFound )
{
}


/**
 * Copy constructor.
 */
template <class Comparable>
BinarySearchTreeX<Comparable>::
BinarySearchTreeX( const BinarySearchTreeX<Comparable> & rhs ) :
  root( NULL ), ITEM_NOT_FOUND( rhs.ITEM_NOT_FOUND )
{ 
    *this = rhs;
}

/**
 * Destructor for the tree.
 */
template <class Comparable>
BinarySearchTreeX<Comparable>::~BinarySearchTreeX( )
{
  makeEmpty( );
}

/**
 * Insert x into the tree; duplicates are ignored.
 */
template <class Comparable>
void BinarySearchTreeX<Comparable>::insert( const Comparable & x )
{
    insert( x, root );
}

/**
 * Remove x from the tree. Nothing is done if x is not found.
 */
template <class Comparable>
void BinarySearchTreeX<Comparable>::remove( const Comparable & x )
{
    remove( x, root );
}


/**
 * Find the smallest item in the tree.
 * Return smallest item or ITEM_NOT_FOUND if empty.
 */
template <class Comparable>
const Comparable & BinarySearchTreeX<Comparable>::findMin( ) const
{
    return elementAt( findMin( root ) );
}

/**
 * Find the largest item in the tree.
 * Return the largest item of ITEM_NOT_FOUND if empty.
 */
template <class Comparable>
const Comparable & BinarySearchTreeX<Comparable>::findMax( ) const
{
    return elementAt( findMax( root ) );
}

/**
 * Find item x in the tree.
 * Return the matching item or ITEM_NOT_FOUND if not found.
 */
template <class Comparable>
const Comparable & BinarySearchTreeX<Comparable>::
                         find( const Comparable & x ) const
{
    return elementAt( find( x, root ) );
}

/**
 * Make the tree logically empty.
 */
template <class Comparable>
void BinarySearchTreeX<Comparable>::makeEmpty( )
{
    makeEmpty( root );
}

/**
 * Test if the tree is logically empty.
 * Return true if empty, false otherwise.
 */
template <class Comparable>
bool BinarySearchTreeX<Comparable>::isEmpty( ) const
{
    return root == NULL;
}

/**
 * Print the tree contents in sorted order.
 */
template <class Comparable>
void BinarySearchTreeX<Comparable>::printTree( ) const
{
    if( isEmpty( ) )
        cout << "Empty tree" << endl;
    else
        printTree( root );
}

/**
 * Deep copy.
 */
template <class Comparable>
const BinarySearchTreeX<Comparable> &
BinarySearchTreeX<Comparable>::
operator=( const BinarySearchTreeX<Comparable> & rhs )
{
    if( this != &rhs )
    {
        makeEmpty( );
        root = clone( rhs.root );
    }
    return *this;
}

/**
 * Internal method to get element field in node t.
 * Return the element field or ITEM_NOT_FOUND if t is NULL.
 */
template <class Comparable>
const Comparable & BinarySearchTreeX<Comparable>::
elementAt( BinaryNodeX<Comparable> *t ) const
{
    return t == NULL ? ITEM_NOT_FOUND : t->element;
}

/**
 * Internal method to insert into a subtree.
 * x is the item to insert.
 * t is the node that roots the tree.
 * Set the new root.
 */
template <class Comparable>
void BinarySearchTreeX<Comparable>::
insert( const Comparable & x, BinaryNodeX<Comparable> * & t ) const
{
    if( t == NULL )
        t = new BinaryNodeX<Comparable>( x, NULL, NULL );
    else if( x < t->element )
        insert( x, t->left );
    else if( t->element < x )
        insert( x, t->right );
    else
        ;  // Duplicate; do nothing
}

/**
 * Internal method to remove from a subtree.
 * x is the item to remove.
 * t is the node that roots the tree.
 * Set the new root.
 */
template <class Comparable>
void BinarySearchTreeX<Comparable>::
remove( const Comparable & x, BinaryNodeX<Comparable> * & t ) const
{
    if( t == NULL )
        return;   // Item not found; do nothing
    if( x < t->element )
        remove( x, t->left );
    else if( t->element < x )
        remove( x, t->right );
    else if( t->left != NULL && t->right != NULL ) // Two children
    {
        t->element = findMin( t->right )->element;
        remove( t->element, t->right );
    }
    else
    {
        BinaryNodeX<Comparable> *oldNode = t;
        t = ( t->left != NULL ) ? t->left : t->right;
        delete oldNode;
    }
}

/**
 * Internal method to find the smallest item in a subtree t.
 * Return node containing the smallest item.
 */
template <class Comparable>
BinaryNodeX<Comparable> *
BinarySearchTreeX<Comparable>::findMin( BinaryNodeX<Comparable> *t ) const
{
    if( t == NULL )
        return NULL;
    if( t->left == NULL )
        return t;
    return findMin( t->left );
}

/**
 * Internal method to find the largest item in a subtree t.
 * Return node containing the largest item.
 */
template <class Comparable>
BinaryNodeX<Comparable> *
BinarySearchTreeX<Comparable>::findMax( BinaryNodeX<Comparable> *t ) const
{
    if( t != NULL )
        while( t->right != NULL )
            t = t->right;
    return t;
}

/**
 * Internal method to find an item in a subtree.
 * x is item to search for.
 * t is the node that roots the tree.
 * Return node containing the matched item.
 */
template <class Comparable>
BinaryNodeX<Comparable> *
BinarySearchTreeX<Comparable>::
find( const Comparable & x, BinaryNodeX<Comparable> *t ) const
{
    if( t == NULL )
        return NULL;
    else if( x < t->element )
        return find( x, t->left );
    else if( t->element < x )
        return find( x, t->right );
    else
        return t;    // Match
}
/****** NONRECURSIVE VERSION*************************
template <class Comparable>
BinaryNodeX<Comparable> *
BinarySearchTreeX<Comparable>::
find( const Comparable & x, BinaryNodeX<Comparable> *t ) const
{
    while( t != NULL )
        if( x < t->element )
            t = t->left;
        else if( t->element < x )
            t = t->right;
        else
            return t;    // Match

    return NULL;   // No match
}
*****************************************************/

/**
 * Internal method to make subtree empty.
 */
template <class Comparable>
void BinarySearchTreeX<Comparable>::
makeEmpty( BinaryNodeX<Comparable> * & t ) const
{
    if( t != NULL )
    {
        makeEmpty( t->left );
        makeEmpty( t->right );
        delete t;
    }
    t = NULL;
}

/**
 * Internal method to print a subtree rooted at t in sorted order.
 */
template <class Comparable>
void BinarySearchTreeX<Comparable>::printTree( BinaryNodeX<Comparable> *t ) const
{
    if( t != NULL )
    {
        printTree( t->left );
        cout << t->element << endl;
        printTree( t->right );
    }
}

/**
 * Internal method to clone subtree.
 */
template <class Comparable>
BinaryNodeX<Comparable> *
BinarySearchTreeX<Comparable>::clone( BinaryNodeX<Comparable> * t ) const
{
    if( t == NULL )
        return NULL;
    else
        return new BinaryNodeX<Comparable>( t->element, clone( t->left ), clone( t->right ) );
}

template <class Comparable>
int BinarySearchTreeX<Comparable>::height() const
{
   return height(root);
}

template <class Comparable>
int BinarySearchTreeX<Comparable>::height(BinaryNodeX<Comparable> *t) const
{
  return 0;  // to be written by student
}

template <class Comparable>
int BinarySearchTreeX<Comparable>::sum() const
{
   return sum(root);
}


template <class Comparable>
int BinarySearchTreeX<Comparable>::sum(BinaryNodeX<Comparable> *t) const
{
  return 0; // to be written by student
}

template <class Comparable>
bool BinarySearchTreeX<Comparable>::isAncestor(const Comparable & x,
  const Comparable & possibleAncestor) const

{
  return true;  // to be written by student
}


template <class Comparable>
int BinarySearchTreeX<Comparable>::highestFull() const
{
  return highestFull(root);
}


template <class Comparable>
int BinarySearchTreeX<Comparable>::highestFull(BinaryNodeX<Comparable> *t) const
{
  return 0;  // to be written by student
}

template <class Comparable>
int BinarySearchTreeX<Comparable>::deepestFull() const
{
   return deepestFull(root);
}

template <class Comparable>
int BinarySearchTreeX<Comparable>::deepestFull(BinaryNodeX<Comparable> *t) const
{
  return 0;  // to be written by student
}


