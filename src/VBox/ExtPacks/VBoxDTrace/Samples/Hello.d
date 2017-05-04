/* $Id: Hello.d 53688 2015-01-02 12:40:55Z vboxsync $ */
/** @file
 * VBoxDTrace - Hello world sample.
 */


/* This works by matching the dtrace:::BEGIN probe, printing the greeting and
   then quitting immediately. */
BEGIN {
    trace("Hello VBox World!");
    exit(0);
}

