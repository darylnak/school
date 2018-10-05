#include "defragmenter.h"

/**
 * Author: Daryl Nakamoto
 * Date: 11/19/17
 *
 *
 *
 * This program has been developed with speed in mind.
 * In lieu of extra methods, excellent documentation has been written.
 */

//
//  PROGRAM START
//

/**
 * Purpose:     Defrag a simulated hard disk
 * Description: A contiguous chain of files will be created starting at index 2 of hard disk.
 *              Blocks not in use will be found at the end (after the last file; getNext() == 0).
 */
Defragmenter::Defragmenter(DiskDrive* diskDrive)
{
  /**
   * Purpose:     Setup initial values.
   * Description: N/A
   */
  int currBlockPos; // track current block position
  int prevLocation; // track previous location of block
  int found;
  int currDiskPos = 2; // current position in disk. Initial position is index 2
  int lastInserted = diskDrive->getCapacity() - 1; // keep track of last inserted position
  int numFiles = diskDrive->getNumFiles();
  int numLeft;

  DiskBlock* currBlock = new DiskBlock; // current disk block
  short maxBlockArray = 13089; // maximum size for RAM
  int maxHashSize = 165379; // maximum hash table size

  //
  //  END: Initial values set.
  //

  /**
   * Purpose:     Setup data structures.
   * Description: N/A
   */
  DiskBlock* RAM = new DiskBlock [maxBlockArray]; // RAM for disk blocks (pointers)
  HashTable blockIndexTracker(maxHashSize); // keep track of disk block positions. -1 to indicate not found

  StackAr<short> next_RAM_Slot(maxBlockArray);  // keep track of next available slot in RAM
  for(short i = maxBlockArray - 1; i >= 0; --i) // initialize free slots
    next_RAM_Slot.push(i);                      //

  //
  //  END: Data structures set.
  //

  /**
   * Purpose:       Initialize defragmentation.
   * Description:   Loop through directory and create contiguous file chains.
   */
  for(short i = 0; i < numFiles; ++i)
  {
    prevLocation = diskDrive->directory[i].getFirstBlockID(); // Get first known location of head
    diskDrive->directory[i].setFirstBlockID(currDiskPos); // change first BlockID of file to correct position
    numLeft = diskDrive->directory[i].getSize();

    /**
     *  Purpose:     Defrag one file.
     *  Description: Continue defragging the hard disk, creating a contiguous chain for a single file.
     *               Stop when end of file has been reached.
     *               getNext() == 1 means end of file has been reached.
     *               getNext() == 0 means ABSOLUTE last file fragment has been reached.
     */

    while(numLeft) // continue defrag until end of file
    {
      /**
       * Purpose:     Get next fragment.
       * Description: Keep looking through the hash table until find(newLocation) fails, then check if in RAM.
       */
      currBlockPos = blockIndexTracker.find(prevLocation); // get last known location of fragment

      if(currBlockPos < 0) // block was not moved (index not in hash table); do not need to search
      {
        DiskBlock* temp = diskDrive->readDiskBlock(prevLocation);
        *currBlock = *temp;
        delete temp;
        diskDrive->FAT[prevLocation] = false; // mark spot as false. Block in this location of disk will be moved.
        currBlockPos = prevLocation; // last location was first location
      }
      else // need to find file fragment
      {
        found = blockIndexTracker.find(currBlockPos); // looking for "true" position

        while(found >= 0) // Implies another location. Keep looking through hash table until "true" position found
        {
          blockIndexTracker.remove(prevLocation); // delete last known entry. Need to delete trail left behind.
          prevLocation = currBlockPos; // keep track of last position. Need this to delete hash entry
          currBlockPos = found; // remember latest known position
          found = blockIndexTracker.find(found); // get next possible position
                                                 // if -1, currBlockPos and prevLocation are set correctly.
        }

        // "true" position found. Get disk block

        if(currBlockPos >= 1000000) // inside RAM; >1,000,000 indicates inside RAM
        {
          currBlockPos -= 1000000; // convert to index inside RAM
          *currBlock = RAM[currBlockPos]; // get disk block from RAM
          next_RAM_Slot.push(currBlockPos); // this index will be freed. Push it to next_RAM_Slot
          currBlockPos = -1;
        }
        else // disk block is at position currBlockPos in the disk
        {
          DiskBlock* temp = diskDrive->readDiskBlock(currBlockPos);
          *currBlock = *temp;
          delete temp;
         // currBlock = diskDrive->readDiskBlock(currBlockPos); // Get disk block
          diskDrive->FAT[currBlockPos] = false; // mark spot as false. This block will be moved.
          // note free location in disk. This will help when finding a spot for barrier block
        }
      }

      //
      //  END: Found fragment.
      //

      /**
      * Purpose:     Insert file fragment.
      * Description: Insert the next fragment of a given file at the correct location in disk.
      */
      if(!diskDrive->FAT[currDiskPos]) // The current disk position is free! Do not need to move a barrier block
        diskDrive->FAT[currDiskPos] = true; // make block active before writing fragment to disk

      else // Need to move barrier block before inserting fragment
      {
        if(!next_RAM_Slot.isEmpty()) // Put barrier block in RAM and insert correct block
        {
          DiskBlock* temp = diskDrive->readDiskBlock(currDiskPos); // put barrier block in free RAM slot
          RAM[next_RAM_Slot.top()] = *temp;
          blockIndexTracker.insert(currDiskPos, next_RAM_Slot.topAndPop() + 1000000);
          delete temp;
          // get index in RAM and pop it from stack of free RAM slots
          // note location in hash table
        }
        else // RAM was full. Move barrier block elsewhere in disk
        {
          if(currBlockPos > lastInserted)
            lastInserted = currBlockPos;

          while(diskDrive->FAT[lastInserted])
          {
            --lastInserted;
          }

          diskDrive->FAT[lastInserted] = true;                      //
          DiskBlock* temp = diskDrive->readDiskBlock(currDiskPos);  //
          diskDrive->writeDiskBlock(temp, lastInserted);            //  Write barrier block to 'pos i' in disk
          blockIndexTracker.insert(currDiskPos, lastInserted);      //  and note new position in hash table
          delete temp;                                              //
        }
      } // barrier block moved.

      // Begin writing fragment to disk

      blockIndexTracker.remove(prevLocation); // remove disk block entry from hash table
      diskDrive->writeDiskBlock(currBlock, currDiskPos); // write fragment to correct spot in disk
      prevLocation = currBlock->getNext(); // check for next location. Valid if need to defrag more

      ++currDiskPos; // move to next spot for insertion in disk
      --numLeft; // track if file is done

      //
      //  END: Inserted fragment.
      //
    }
  }

  //
  //  END: Hard disk has been defragged
  //

} // Defragmenter()