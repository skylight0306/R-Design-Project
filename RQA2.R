################################
rm(list=ls())
#
# ============================================================================== #
# Q&A 2.
# data.frame & list
#
origin <- "http://lib.stat.cmu.edu/datasets/wseries"
destF <- "wseries.txt"
download.file(url = origin, destfile = destF)
world.series <- scan(file = "wseries.txt", 
                     skip = 35, nlines = 23, what = list(year = character(0),
                                                         game = character(0)))
# if Error, type "Ctrl+Shift+H"
world.series[1]
world.series$game
str(world.series)
View(world.series)
#
# transform a list into a data.frame
ws.DF <- as.data.frame(world.series)
str(ws.DF)
#
# Sort it in ascending order of year
( sorted.year <- sort.list(ws.DF$year) )
( years <- ws.DF$year[sorted.year] )
#
( games <- ws.DF$game[sorted.year] )
( ws.sorted.DF <- data.frame(years = years, games = games) )
head(ws.sorted.DF)
# Try the list agin
# Sort it in ascending order of year
sorted.year <- order(world.series$year)
( years <- world.series$year[sorted.year] )
#
( games <- world.series$game[sorted.year] )
( ws.sorted.list <- list(years = years, games = games) ) 
sapply(ws.sorted.list, head)
#
################################
# ========================================================================= #
# Q2-1. Can you find out the overall winning percentage?
# ========================================================================= #
# Example: LWLlwwwW => 5 wins, 3 losses => 5/8
#          wLwWW => 4 wins, 1 loss => 4/5
#          wLwLwW => 4 wins, 2 losses => 4/6
#          win.ratio = (5/8 + 4/5 + 4/6) / 3 = .6972222
# Hint
if (!require(stringr)) {
  install.packages("stringr")
  library(stringr)
}
str_count("LWLlwwwW",'W')

#capital word mean Home court

Winratio <- 0
Homewin <- str_count(games,'W')
Awaywin <- str_count(games,'w')
all <- str_count(games)

Winratio <- sum(( Homewin + Awaywin ) / all)

win.ratio <-  round((Winratio / 90),digits = 7) # <<<<<<<< replace it with your codes
win.ratio
# ANS: win.ratio = 0.7171296
#     win    loss 
# "71.7%" "28.3%"
################################
# ========================================================================= #
# Q2-2. Can you find out the overall home and away winning percentages?
# ========================================================================= #
# Example: LWLlwwwW => 2W2L, 3w1l => hwp = 2/4, awp = 3/4
#          wLwWW => 2W1L, 2w => hwp = 2/3, awp = 1
#          wLwLwW => 1W2L, 3w => hwp = 1/3, awp = 1
#          overall hwp = (2/4 + 2/3 + 1/3) / 3 = .5
#          overall awp = (3/4 + 1 + 1) / 3 = .9166667
# Hint
( homeAll <- c('W','L') )
( home <- sapply(ws.DF$game,str_count,homeAll) )

( awayAll <- c('w','l') ) 
( away <- sapply(ws.DF$game,str_count,awayAll) )

#capital word mean Home court

Homeratio <- sum(home[1,] / (home[1,]+home[2,]) )
Awayratio <- sum(away[1,] / (away[1,]+away[2,]) )
  
  

hwp <- round((Homeratio / 90),digits = 7)  # <<<<<<<< replace it with your code
awp <- round((Awayratio / 90),digits = 7) # <<<<<<<< replace it with your code
hwp
awp

# ANS: hwp = 0.7481481, awp = 0.6751852
# home    away 
# "74.8%" "67.5%"
####