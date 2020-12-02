// There is a continous stream of data in the form of:
// Input: (1, "abcd"), (2, "efgh"), (4, "mnop"), (5, "qrst"), (3, "ijkl")
//
// Write a program to output the data from the stream in realtime in order, so 1,2,3,4,5..
// You cannot queue up the incoming data from the stream.
// So for example if the first incoming bit of data is (1, "abcd"), and the second is (4, "mnop"), you cannot output (4, "mnop") until you get 2, 3.


// solutions... use a min heap lmao easy question