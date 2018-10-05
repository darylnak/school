#ifndef BSTX_H
  #define BSTX_H

#include "dsexceptions.h"
#include <iostream>       // For NULL

  // Binary node and forward declaration because g++ does
  // not understand nested classes.
template <class Comparable>
class BinarySearchTreeX;

template <class Comparable>
class BinaryNodeX
{
    Comparable element;
    BinaryNodeX *left;
    BinaryNodeX *right;

    BinaryNodeX( const Comparable & theElement, BinaryNodeX *lt, BinaryNodeX *rt )
      : element( theElement ), left( lt ), right( rt ) { }
    friend class BinarySearchTreeX<Comparable>;
};


// BinarySearchTreeX class
//
// CONSTRUCTION: with ITEM_NOT_FOUND object used to signal failed finds
//
// ******************PUBLIC OPERATIONS*********************
// void insert( x )       --> Insert x
// void remove( x )       --> Remove x
// Comparable find( x )   --> Return item that matches x
// Comparable findMin( )  --> Return smallest item
// Comparable findMax( )  --> Return largest item
// boolean isEmpty( )     --> Return true if empty; else false
// void makeEmpty( )      --> Remove all items
// void printTree( )      --> Print tree in sorted order

template <class Comparable>
class BinarySearchTreeX
{
  public:
    explicit BinarySearchTreeX( const Comparable & notFound );
    BinarySearchTreeX( const BinarySearchTreeX & rhs );
    ~BinarySearchTreeX( );

    const Comparable & findMin( ) const;
    const Comparable & findMax( ) const;
    const Comparable & find( const Comparable & x ) const;
    bool isEmpty( ) const;
    void printTree( ) const;
    void makeEmpty( );
    void insert( const Comparable & x );
    void remove( const Comparable & x );
    int height() const;
    int sum() const;
    bool isAncestor(const Comparable & x, const Comparable & possibleAncestor) const;
    int highestFull() const;
    int deepestFull() const;

    const BinarySearchTreeX & operator=( const BinarySearchTreeX & rhs );

  private:
    BinaryNodeX<Comparable> *root;
    const Comparable ITEM_NOT_FOUND;

    const Comparable & elementAt( BinaryNodeX<Comparable> *t ) const;

    void insert( const Comparable & x, BinaryNodeX<Comparable> * & t ) const;
    void remove( const Comparable & x, BinaryNodeX<Comparable> * & t ) const;
    BinaryNodeX<Comparable> * findMin( BinaryNodeX<Comparable> *t ) const;
    BinaryNodeX<Comparable> * findMax( BinaryNodeX<Comparable> *t ) const;
    BinaryNodeX<Comparable> * find( const Comparable & x, BinaryNodeX<Comparable> *t ) const;
    void makeEmpty( BinaryNodeX<Comparable> * & t ) const;
    void printTree( BinaryNodeX<Comparable> *t ) const;
    BinaryNodeX<Comparable> * clone( BinaryNodeX<Comparable> *t ) const;
    int height(BinaryNodeX<Comparable> *t ) const;
    int sum(BinaryNodeX<Comparable> *t ) const;
    int highestFull(BinaryNodeX<Comparable> *t ) const;
    int deepestFull(BinaryNodeX<Comparable> *t ) const;
};

#include "BSTX.cpp"
#endif
