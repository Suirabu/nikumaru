#ifndef REC_H
#define REC_H

// Decodes a rec file returning the length of the recorded run in frames, or -1
// on error
int rec_decode(const char* file_path);

// Decodes a dat file returning the length of the recorded run in frames, or -1
// on error
int dat_decode(const char* file_path);

#endif // REC_H
