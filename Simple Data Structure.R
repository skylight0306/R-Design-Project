rm(list=ls())
#在資料夾中的檔名可能會有各種不同格式的學號
#這個函數的目的就是將他們全部統一成同一種格式
#例如: Ds作業10627149 , 10627149工程數學 , DataFlow10627149
#將改成 10627149_Ds作業 , 10627149_工程數學 , 10627149_DataFlow
Set_StudentID <- function(file, StudentID){
  #設定要修改的資料夾
  setwd(file) 

  #找尋包含特定學號的檔名
  name <- list.files( pattern = StudentID , recursive =  TRUE ,include.dirs = TRUE)
  
  #列出包含特定學號的檔名
  name 
  
  #將特定學號的部分刪除
  file.rename( from = name , to = gsub(StudentID ,"" , name)   ) 
  
  #變成統一格式  "學號_檔名"
  paste0(StudentID,seq = "_", name)
  
}

#呼叫函數
Set_StudentID( "大學資料", "10627149" )
