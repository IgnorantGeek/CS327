This implementation of the rlg code has ported everything to C++. All .c file extensions have been changed to .cpp.
One caveat of this code is that there are still some warnings thrown by gcc when compiling. There are a lot of mismatched
int warnings that get thrown, so after I tried to track them all down and ended up breaking a bunch of stuff, I instead removed
the W flags from the makefile, so the code now compiles without warning flags. Which is OK for this version because a mismatched int
comparison would never happen. This iteration does not implement fog of war. I could not figure out how to get it to work properly
