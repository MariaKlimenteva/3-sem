//=============================================================================
#ifndef UTILS_H
#define UTILS_H
//-----------------------------------------------------------------------------
// TODO: Why is this in utils? This is a vital part of equation solving
// (even more so when you change signatures appropriately), guess where it belongs...

enum Number_of_root // TODO: Weird naming again. NumberOfRoots or number_of_roots
                    //       are both much more common and much more readable.
                    //       
                    //       And, yeah. Number_of_roots
                    //                                ^ Should be in plural!
{
    ONE_ROOT  =  1,
    TWO_ROOTS =  2,
    ZERO_ROOT = -1, // TODO: Why zero roots aren't represented by zero? Misleading!
                    //       Also, sort enum entries!

    //      ^  TODO: Zero roots
    //                        ^ Should be plural

    INF_ROOTS =  3
};

#endif // UTILS_H
