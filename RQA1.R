################################
rm(list=ls())

#
# ============================================================================== #
# Q&A 1.
# Modify the following function to produce the same out as shown below.


HanoiTower <- function(n,A,B,C) {
  timee <<-0
  hanoi(n,A,B,C)
  cat("It takes ", timee, " steps in total.\n")
}
hanoi <- function(n,A,B,C){
  if(n == 1) {  
    timee <<- timee + 1
    cat( timee, "Move a sheet from", A, "to", C, "\n")

  }
  else {     
    hanoi(n-1, A, C, B);
    hanoi(1, A, B, C);
    hanoi(n-1, B, A, C);
  }
}

HanoiTower(3,'A','B','C')
HanoiTower(4,'A','B','C')
HanoiTower(5,'A','B','C')
# Goal: Write a hanoi function to (1) number each line as 1, 2, 3, ... 
#                                 (2) output the total number of steps at the end.
#                                 (3) can be used for different n's again and again
# a sample output:
# > (2,'A', 'B', 'C')
# 1 Move a sheet from A to B 
# 2 Move a sheet from A to C 
# 3 Move a sheet from B to C 
# It takes 3 steps in total.
#
# > hanoi(3, "A", "B", "C")
# 1 Move sheet A to C 
# 2 Move sheet A to B 
# 3 Move sheet C to B 
# 4 Move sheet A to C 
# 5 Move sheet B to A 
# 6 Move sheet B to C 
# 7 Move sheet A to C 
# It takes 7 steps in total.
#
# ============================================================================== #
################################