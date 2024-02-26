
int rec_counts[6] = {66, 28, 15, 6, 1, 0};  

/* take the transition probabilities to be uniform */ 
float p[6] = {1.0/66, 1.0/28, 1.0/15, 1.0/6, 1.0/1, 0};

/* size_idx = 0 ==> size 13
 * size_idx = 5 ==> size 1
 */
int size_to_size_idx2[] = {-1, 5, -1, 4, -1, 3, -1, 2, -1, 1, -1, -1, -1, 0}; // rather unfortunate but renamed to avoid name clash
int size_idx_to_size[] = {13, 9, 7, 5, 3, 1};

int rec_sizes_odd[6][66] = {
  {1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7},
  {1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
  {1, 1, 2, 2, 2, 2, 4, 4, 4, 4, 4, 4, 4, 4, 4}, 
  {1, 1, 3, 3, 3, 3},
  {2},
  {}
};

int rec_sizes_even[6][66] = {
  {0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6},
  {0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
  {0, 0, 1, 1, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3},
  {0, 0, 2, 2, 2, 2},
  {1},
  {}
};

int odd_rec[5][66][7] = {
{  // size_idx = 0
  {6},
  {0},
  {5, 6},
  {0, 6},
  {0, 6},
  {0, 1},
  {4, 5, 6},
  {0, 5, 6},
  {0, 5, 6},
  {0, 1, 6},
  {0, 1, 6},
  {0, 1, 2},
  {3, 4, 5, 6},
  {0, 4, 5, 6},
  {0, 4, 5, 6},
  {0, 1, 5, 6},
  {0, 1, 5, 6},
  {0, 1, 2, 6},
  {0, 1, 2, 6},
  {0, 1, 2, 3},
  {2, 3, 4, 5, 6},
  {0, 3, 4, 5, 6},
  {0, 3, 4, 5, 6},
  {0, 1, 4, 5, 6},
  {0, 1, 4, 5, 6},
  {0, 1, 2, 5, 6},
  {0, 1, 2, 5, 6},
  {0, 1, 2, 3, 6},
  {0, 1, 2, 3, 6},
  {0, 1, 2, 3, 4},
  {1, 0, 2, 3, 4, 5, 6},
  {2, 1, 0, 3, 4, 5, 6},
  {3, 2, 1, 0, 4, 5, 6},
  {4, 3, 2, 1, 0, 5, 6},
  {5, 4, 3, 2, 1, 0, 6},
  {6, 5, 4, 3, 2, 1, 0},
  {0, 1, 2, 3, 4, 5, 6},
  {0, 2, 1, 3, 4, 5, 6},
  {0, 3, 2, 1, 4, 5, 6},
  {0, 4, 3, 2, 1, 5, 6},
  {0, 5, 4, 3, 2, 1, 6},
  {0, 2, 1, 3, 4, 5, 6},
  {0, 3, 2, 1, 4, 5, 6},
  {0, 4, 3, 2, 1, 5, 6},
  {0, 5, 4, 3, 2, 1, 6},
  {0, 6, 5, 4, 3, 2, 1},
  {0, 1, 2, 3, 4, 5, 6},
  {0, 1, 3, 2, 4, 5, 6},
  {0, 1, 4, 3, 2, 5, 6},
  {0, 1, 5, 4, 3, 2, 6},
  {0, 1, 3, 2, 4, 5, 6},
  {0, 1, 4, 3, 2, 5, 6},
  {0, 1, 5, 4, 3, 2, 6},
  {0, 1, 6, 5, 4, 3, 2},
  {0, 1, 2, 3, 4, 5, 6},
  {0, 1, 2, 4, 3, 5, 6},
  {0, 1, 2, 5, 4, 3, 6},
  {0, 1, 2, 4, 3, 5, 6},
  {0, 1, 2, 5, 4, 3, 6},
  {0, 1, 2, 6, 5, 4, 3},
  {0, 1, 2, 3, 4, 5, 6},
  {0, 1, 2, 3, 5, 4, 6},
  {0, 1, 2, 3, 5, 4, 6},
  {0, 1, 2, 3, 6, 5, 4},
  {0, 1, 2, 3, 4, 5, 6},
  {0, 1, 2, 3, 4, 6, 5}
},
{ // size_idx = 1
  {4},
  {0},
  {3, 4},
  {0, 4},
  {0, 4},
  {0, 1},
  {2, 3, 4},
  {0, 3, 4},
  {0, 3, 4},
  {0, 1, 4},
  {0, 1, 4},
  {0, 1, 2},
  {1, 0, 2, 3, 4},
  {2, 1, 0, 3, 4},
  {3, 2, 1, 0, 4},
  {4, 3, 2, 1, 0},
  {0, 1, 2, 3, 4},
  {0, 2, 1, 3, 4},
  {0, 3, 2, 1, 4},
  {0, 2, 1, 3, 4},
  {0, 3, 2, 1, 4},
  {0, 4, 3, 2, 1},
  {0, 1, 2, 3, 4},
  {0, 1, 3, 2, 4},
  {0, 1, 3, 2, 4},
  {0, 1, 4, 3, 2},
  {0, 1, 2, 3, 4},
  {0, 1, 2, 4, 3},
},
{ // size_idx = 2 
  {3},
  {0},
  {2, 3},
  {0, 3},
  {0, 3},
  {0, 1},
  {1, 0, 2, 3},
  {2, 1, 0, 3},
  {3, 2, 1, 0},
  {0, 1, 2, 3},
  {0, 2, 1, 3},
  {0, 2, 1, 3},
  {0, 3, 2, 1},
  {0, 1, 2, 3},
  {0, 1, 3, 2},
},
{ // size_idx = 3
  {2},
  {0}, 
  {1, 0, 2},
  {2, 1, 0},
  {0, 1, 2},
  {0, 2, 1},
},
{ // size_idx = 4
  {1, 0},
}
};
int even_rec[5][66][6]= {
{ // size_idx = 0
  {},
  {},  
  {5},
  {5},
  {0},
  {0},
  {4, 5},
  {4, 5},
  {0, 5},
  {0, 5},
  {0, 1},
  {0, 1},
  {3, 4, 5},
  {3, 4, 5},
  {0, 4, 5},
  {0, 4, 5},
  {0, 1, 5},
  {0, 1, 5},
  {0, 1, 2},
  {0, 1, 2},
  {2, 3, 4, 5},
  {2, 3, 4, 5},
  {0, 3, 4, 5},
  {0, 3, 4, 5},
  {0, 1, 4, 5},
  {0, 1, 4, 5},
  {0, 1, 2, 5},
  {0, 1, 2, 5},
  {0, 1, 2, 3},
  {0, 1, 2, 3},
  {0, 1, 2, 3, 4, 5},
  {1, 0, 2, 3, 4, 5},
  {2, 1, 0, 3, 4, 5},
  {3, 2, 1, 0, 4, 5},
  {4, 3, 2, 1, 0, 5},
  {5, 4, 3, 2, 1, 0},
  {1, 0, 2, 3, 4, 5},
  {2, 1, 0, 3, 4, 5},
  {3, 2, 1, 0, 4, 5},
  {4, 3, 2, 1, 0, 5},
  {5, 4, 3, 2, 1, 0},
  {0, 1, 2, 3, 4, 5},
  {0, 2, 1, 3, 4, 5},
  {0, 3, 2, 1, 4, 5},
  {0, 4, 3, 2, 1, 5},
  {0, 5, 4, 3, 2, 1},
  {0, 2, 1, 3, 4, 5},
  {0, 3, 2, 1, 4, 5},
  {0, 4, 3, 2, 1, 5},
  {0, 5, 4, 3, 2, 1},
  {0, 1, 2, 3, 4, 5},
  {0, 1, 3, 2, 4, 5},
  {0, 1, 4, 3, 2, 5},
  {0, 1, 5, 4, 3, 2},
  {0, 1, 3, 2, 4, 5},
  {0, 1, 4, 3, 2, 5},
  {0, 1, 5, 4, 3, 2},
  {0, 1, 2, 3, 4, 5},
  {0, 1, 2, 4, 3, 5},
  {0, 1, 2, 5, 4, 3},
  {0, 1, 2, 4, 3, 5},
  {0, 1, 2, 5, 4, 3},
  {0, 1, 2, 3, 4, 5},
  {0, 1, 2, 3, 5, 4},
  {0, 1, 2, 3, 5, 4},
  {0, 1, 2, 3, 4, 5},
}, 
{ // size_idx = 1
  {},
  {},
  {3},
  {3},
  {0},
  {0},
  {2, 3},
  {2, 3},
  {0, 3},
  {0, 3},
  {0, 1},
  {0, 1},
  {0, 1, 2, 3},
  {1, 0, 2, 3},
  {2, 1, 0, 3},
  {3, 2, 1, 0},
  {1, 0, 2, 3},
  {2, 1, 0, 3},
  {3, 2, 1, 0},
  {0, 1, 2, 3},
  {0, 2, 1, 3},
  {0, 3, 2, 1},
  {0, 2, 1, 3},
  {0, 3, 2, 1},
  {0, 1, 2, 3},
  {0, 1, 3, 2},
  {0, 1, 3, 2},
  {0, 1, 2, 3},
},
{ // size_idx = 2
  {},
  {}, 
  {2},
  {2},
  {0},
  {0},
  {0, 1, 2},
  {1, 0, 2},
  {2, 1, 0},
  {1, 0, 2},
  {2, 1, 0},
  {0, 1, 2},
  {0, 2, 1},
  {0, 2, 1},
  {0, 1, 2},
},
{ // size_idx = 3
  {},
  {},
  {0, 1},
  {1, 0},
  {1, 0},
  {0, 1},
},
{ // size_idx = 4
  {0},
}
};

int sign_rec[5][66][13]={ 
{ // full length
  {13},
  {1},
  {11, 12, 13},
  {1, 12, 13},
  {1, 2, 13},
  {1, 2, 3},
  {9, 10, 11, 12, 13},
  {1, 10, 11, 12, 13},
  {1, 2, 11, 12, 13},
  {1, 2, 3, 12, 13},
  {1, 2, 3, 4, 13},
  {1, 2, 3, 4, 5},
  {7, 8, 9, 10, 11, 12, 13},
  {1, 8, 9, 10, 11, 12, 13},
  {1, 2, 9, 10, 11, 12, 13},
  {1, 2, 3, 10, 11, 12, 13},
  {1, 2, 3, 4, 11, 12, 13},
  {1, 2, 3, 4, 5, 12, 13},
  {1, 2, 3, 4, 5, 6, 13},
  {1, 2, 3, 4, 5, 6, 7},
  {5, 6, 7, 8, 9, 10, 11, 12, 13},
  {1, 6, 7, 8, 9, 10, 11, 12, 13},
  {1, 2, 7, 8, 9, 10, 11, 12, 13},
  {1, 2, 3, 8, 9, 10, 11, 12, 13},
  {1, 2, 3, 4, 9, 10, 11, 12, 13},
  {1, 2, 3, 4, 5, 10, 11, 12, 13},
  {1, 2, 3, 4, 5, 6, 11, 12, 13},
  {1, 2, 3, 4, 5, 6, 7, 12, 13},
  {1, 2, 3, 4, 5, 6, 7, 8, 13},
  {1, 2, 3, 4, 5, 6, 7, 8, 9},
  {-3, -2, -1, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13},
  {-5, -4, -3, -2, -1, 6, 7, 8, 9, 10, 11, 12, 13},
  {-7, -6, -5, -4, -3, -2, -1, 8, 9, 10, 11, 12, 13},
  {-9, -8, -7, -6, -5, -4, -3, -2, -1, 10, 11, 12, 13},
  {-11, -10, -9, -8, -7, -6, -5, -4, -3, -2, -1, 12, 13},
  {-13, -12, -11, -10, -9, -8, -7, -6, -5, -4, -3, -2, -1},
  {1, -4, -3, -2, 5, 6, 7, 8, 9, 10, 11, 12, 13},
  {1, -6, -5, -4, -3, -2, 7, 8, 9, 10, 11, 12, 13},
  {1, -8, -7, -6, -5, -4, -3, -2, 9, 10, 11, 12, 13},
  {1, -10, -9, -8, -7, -6, -5, -4, -3, -2, 11, 12, 13},
  {1, -12, -11, -10, -9, -8, -7, -6, -5, -4, -3, -2, 13},
  {1, 2, -5, -4, -3, 6, 7, 8, 9, 10, 11, 12, 13},
  {1, 2, -7, -6, -5, -4, -3, 8, 9, 10, 11, 12, 13},
  {1, 2, -9, -8, -7, -6, -5, -4, -3, 10, 11, 12, 13},
  {1, 2, -11, -10, -9, -8, -7, -6, -5, -4, -3, 12, 13},
  {1, 2, -13, -12, -11, -10, -9, -8, -7, -6, -5, -4, -3},
  {1, 2, 3, -6, -5, -4, 7, 8, 9, 10, 11, 12, 13},
  {1, 2, 3, -8, -7, -6, -5, -4, 9, 10, 11, 12, 13},
  {1, 2, 3, -10, -9, -8, -7, -6, -5, -4, 11, 12, 13},
  {1, 2, 3, -12, -11, -10, -9, -8, -7, -6, -5, -4, 13},
  {1, 2, 3, 4, -7, -6, -5, 8, 9, 10, 11, 12, 13},
  {1, 2, 3, 4, -9, -8, -7, -6, -5, 10, 11, 12, 13},
  {1, 2, 3, 4, -11, -10, -9, -8, -7, -6, -5, 12, 13},
  {1, 2, 3, 4, -13, -12, -11, -10, -9, -8, -7, -6, -5},
  {1, 2, 3, 4, 5, -8, -7, -6, 9, 10, 11, 12, 13},
  {1, 2, 3, 4, 5, -10, -9, -8, -7, -6, 11, 12, 13},
  {1, 2, 3, 4, 5, -12, -11, -10, -9, -8, -7, -6, 13},
  {1, 2, 3, 4, 5, 6, -9, -8, -7, 10, 11, 12, 13},
  {1, 2, 3, 4, 5, 6, -11, -10, -9, -8, -7, 12, 13},
  {1, 2, 3, 4, 5, 6, -13, -12, -11, -10, -9, -8, -7},
  {1, 2, 3, 4, 5, 6, 7, -10, -9, -8, 11, 12, 13},
  {1, 2, 3, 4, 5, 6, 7, -12, -11, -10, -9, -8, 13},
  {1, 2, 3, 4, 5, 6, 7, 8, -11, -10, -9, 12, 13},
  {1, 2, 3, 4, 5, 6, 7, 8, -13, -12, -11, -10, -9},
  {1, 2, 3, 4, 5, 6, 7, 8, 9, -12, -11, -10, 13},
  {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, -13, -12, -11}
}, 
{ // 9 elem
  {9},
  {1}, 
  {7, 8, 9},
  {1, 8, 9},
  {1, 2, 9},
  {1, 2, 3},
  {5, 6, 7, 8, 9},
  {1, 6, 7, 8, 9},
  {1, 2, 7, 8, 9},
  {1, 2, 3, 8, 9},
  {1, 2, 3, 4, 9},
  {1, 2, 3, 4, 5},
  {-3, -2, -1, 4, 5, 6, 7, 8, 9},
  {-5, -4, -3, -2, -1, 6, 7, 8, 9},
  {-7, -6, -5, -4, -3, -2, -1, 8, 9},
  {-9, -8, -7, -6, -5, -4, -3, -2, -1},
  {1, -4, -3, -2, 5, 6, 7, 8, 9},
  {1, -6, -5, -4, -3, -2, 7, 8, 9},
  {1, -8, -7, -6, -5, -4, -3, -2, 9},
  {1, 2, -5, -4, -3, 6, 7, 8, 9},
  {1, 2, -7, -6, -5, -4, -3, 8, 9},
  {1, 2, -9, -8, -7, -6, -5, -4, -3},
  {1, 2, 3, -6, -5, -4, 7, 8, 9},
  {1, 2, 3, -8, -7, -6, -5, -4, 9},
  {1, 2, 3, 4, -7, -6, -5, 8, 9},
  {1, 2, 3, 4, -9, -8, -7, -6, -5},
  {1, 2, 3, 4, 5, -8, -7, -6, 9},
  {1, 2, 3, 4, 5, 6, -9, -8, -7},
},
{ // 7 elements
  {7},
  {1},
  {5, 6, 7},
  {1, 6, 7},
  {1, 2, 7},
  {1, 2, 3},
  {-3, -2, -1, 4, 5, 6, 7},
  {-5, -4, -3, -2, -1, 6, 7},
  {-7, -6, -5, -4, -3, -2, -1},
  {1, -4, -3, -2, 5, 6, 7},
  {1, -6, -5, -4, -3, -2, 7},
  {1, 2, -5, -4, -3, 6, 7},
  {1, 2, -7, -6, -5, -4, -3},
  {1, 2, 3, -6, -5, -4, 7},
  {1, 2, 3, 4, -7, -6, -5},
},
{ // 5 elements
  {5},
  {1},
  {-3, -2, -1, 4, 5},
  {-5, -4, -3, -2, -1},
  {1, -4, -3, -2, 5},
  {1, 2, -5, -4, -3},
},
{ // 3 elements
  {-3, -2, -1}
}
};

// now take positions
int pos_rec[5][66][2]={
{ // 13-elements
  {0,12}, 
  {1,13}, 
  {0,10}, 
  {1,11}, 
  {2,12}, 
  {3,13}, 
  {0,8}, 
  {1,9}, 
  {2,10}, 
  {3,11}, 
  {4,12}, 
  {5,13}, 
  {0,6}, 
  {1,7}, 
  {2,8}, 
  {3,9}, 
  {4,10}, 
  {5,11}, 
  {6,12}, 
  {7,13}, 
  {0,4}, 
  {1,5}, 
  {2,6}, 
  {3,7}, 
  {4,8}, 
  {5,9}, 
  {6,10}, 
  {7,11}, 
  {8,12}, 
  {9,13}, 
  {0,3}, 
  {0,5}, 
  {0,7}, 
  {0,9}, 
  {0,11}, 
  {0,13}, 
  {1,4}, 
  {1,6}, 
  {1,8}, 
  {1,10}, 
  {1,12}, 
  {2,5}, 
  {2,7}, 
  {2,9}, 
  {2,11}, 
  {2,13}, 
  {3,6}, 
  {3,8}, 
  {3,10}, 
  {3,12}, 
  {4,7}, 
  {4,9}, 
  {4,11}, 
  {4,13}, 
  {5,8}, 
  {5,10}, 
  {5,12}, 
  {6,9}, 
  {6,11}, 
  {6,13}, 
  {7,10}, 
  {7,12}, 
  {8,11}, 
  {8,13}, 
  {9,12}, 
  {10,13}
},{ // 9 elements
  {0,8}, 
  {1,9}, 
  {0,6}, 
  {1,7}, 
  {2,8}, 
  {3,9}, 
  {0,4}, 
  {1,5}, 
  {2,6}, 
  {3,7}, 
  {4,8}, 
  {5,9}, 
  {0,3}, 
  {0,5}, 
  {0,7}, 
  {0,9}, 
  {1,4}, 
  {1,6}, 
  {1,8}, 
  {2,5}, 
  {2,7}, 
  {2,9}, 
  {3,6}, 
  {3,8}, 
  {4,7}, 
  {4,9}, 
  {5,8}, 
  {6,9},  
},{ // 7 elements
  {0,6}, 
  {1,7}, 
  {0,4}, 
  {1,5}, 
  {2,6}, 
  {3,7}, 
  {0,3}, 
  {0,5}, 
  {0,7}, 
  {1,4}, 
  {1,6}, 
  {2,5}, 
  {2,7}, 
  {3,6}, 
  {4,7}, 
},{ // 5 elements
  {0,4}, 
  {1,5}, 
  {0,3}, 
  {0,5}, 
  {1,4}, 
  {2,5}, 
},{ // 3 elements
  {0,3},  
}
};