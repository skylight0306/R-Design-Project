rm(list=ls())


#=====================================================================

#	主題:擷取並分解程式碼 
# 目標:針對程式資料撰寫可擷取每個程式內容
#      並分解成有助於估算相似度的數個程式單元（稱為表示法）
#      將程式單元輸出寫入自訂的檔案格式，不得破壞原本的檔案！ 
#
# 內容:創建一個資料夾(Output_File)其中還整理多個資料夾分別存取切割後的
#      主要程式(刪除註解內容),註解內容,Void凾數,Int函數,Class內容
#=====================================================================


#查看當前的路徑
getwd()
#設定到切割的.cpp檔
#setwd("R程式")
setwd("R1082hw3data")
wd <- getwd()
dir()

#將.cpp檔存入變數中
cpp_file <- list.files(pattern = ".cpp")
dir.create("Output_File")
setwd("Output_File")
dir.create("Main_code")
dir.create("Comment_code")
dir.create("Void_code")
dir.create("Token_code")
dir.create("Int_code")
dir.create("Class_code")
setwd(wd)


Split_code <- function(data,x){
  
  
  code <- readLines(data)
  
  #切開註解 分成沒有註解的內容 和 註解的內容
  Split_comment <- strsplit(code,split = "//")
  
  
  #initial Main_code,Com_code,Int_code,Void_code,Class_code
  Main_code <- c("")
  Com_code <- c("")
  Int_code <- c("")
  Void_code <- c("")
  Class_code <- c("")
  
  
  
  
  
  #分別儲存下來
  for(y in c(1:length(Split_comment)))
  {
    Main_code[y] <- Split_comment[[y]][1]
    Com_code[y] <- Split_comment[[y]][2]
  }

  #如果[.,<>/*=()+-]這些標點符號就切割成一個token
  Split_token <- strsplit(Main_code,split = "[.,<>/*=()+-]")
  #設定一個list來存取
  Token_code <- matrix(list(""), nrow=length(Main_code))
  
  #Token_line <- list("")
  #Token_code <- list(Token_line)
  
  #儲存主要程式(沒有註解的)token
  for(y in c(1:length(Main_code)))
  {
    # y = 3
    for(z in c(1:length(Split_token[[y]])) )
    {
      # z = 1
        Token_code[[y]][z] <- Split_token[[y]][z]

    }
      
  }  
  
  #切割具有int,void,class的程式碼
  Int_code <- grep("int",Main_code, value=T)    
  Void_code <- grep("void",Main_code, value=T)
  Class_code <- grep("class",Main_code, value=T)
#Token_code[[1]][2] <- 45
  
  
  

  
#if( !is.na(Split_token[[y]][z] != "\t" ))

  
 #儲存各個程式的資料
  
  ComName <- paste("Comment",x,sep = "_")
  ComName <- paste("Output_File/Comment_code/", ComName,sep = "")
  ComName <- paste(ComName,".txt",sep = "")
  write.table(Com_code, file = ComName,sep = "")
  
  MainName <- paste("MainCode",x,sep = "_")
  MainName <- paste("Output_File/Main_code/", MainName,sep = "")
  MainName <- paste(MainName,".txt",sep = "")
  write.table(Main_code, file = MainName,sep = "")  
  
  TokenName <- paste("TokenCode",x,sep = "_")
  TokenName <- paste("Output_File/Token_code/", TokenName,sep = "")
  TokenName <- paste(TokenName,".txt",sep = "")
  write.table(Token_code, file = TokenName,sep = "")    
  
  IntName <- paste("IntCode",x,sep = "_")
  IntName <- paste("Output_File/Int_code/", IntName,sep = "")
  IntName <- paste(IntName,".txt",sep = "")
  write.table(Int_code, file = IntName,sep = "")  
  
  VoidName <- paste("VoidCode",x,sep = "_")
  VoidName <- paste("Output_File/Void_code/", VoidName,sep = "")
  VoidName <- paste(VoidName,".txt",sep = "")
  write.table(Void_code, file = VoidName,sep = "")   
  
  ClassName <- paste("ClassCode",x,sep = "_")
  ClassName <- paste("Output_File/Class_code/", ClassName,sep = "")
  ClassName <- paste(ClassName,".txt",sep = "")
  write.table(Class_code, file = ClassName,sep = "")   
  
  
}



Read_file <- function(x=1){
  
  #讀入資料夾內所有的檔案
  for(x in c(1:length(cpp_file)) )
  {
    data <- file(cpp_file[x], open = 'r')
    Split_code(data,x)
    close(data)
  }
}


Read_file()


