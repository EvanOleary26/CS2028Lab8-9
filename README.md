IH 3/27/25 10:38am
 added remove and in order predecessor function needed for the two children case
 for the remove funtion, it no longer needs the parent parameter as the remove funtion itself will raise a notfound error 
   the if/else for the notfound error may need to be looked at just to confirm it's in the right place. Also the errors are just listed as a comment

EO 3/28/25 12:25pm
  added Word.h for storing words and their counts
    added operator overloads we should need and added ++ and -- to make counting words easier. 
  Fixed a couple of small bugs with code that was pulled from previous projects and such
  I plan to go through later and fix a lot of main with more up to date and relevant code.

EO 3/30/25 7:31pm
  worked on main, realized we dont need what we previously did, we only need the MobyDick.txt and PeterPan.txt files for filling up the tree.
  made Find in the Tree return a T not a T*

EO 3/31/25 12:37pm
  added most of setupTree function fixing some bugs with it. Added lines to increase the count of words when adding them

EO 3/31/25 8:00pm
  Tried adding and tree balancing to Insert, couldnt get it to work for now so im just commenting it out for now will look at it later, added a display function to the tree temporarily for testing using
  "4. Get all words in descending order" to call it. 

EO 4/2/25 2:14pm
  Fixed Balancing, added a message for what setup does for TA, got deconstructor for Tree completed