rm(list=ls())
if (!require(data.table)) {
  install.packages("data.table")
  library(data.table)
} # data.table

if (!require(DT)) {
  install.packages("DT")
  library(DT)
} # DT

library(DT)
library(readxl) #讀excel檔
getwd()
dir()
setwd("R程式")
dir()
#data2017 <- Data_type_change(data2017)
#讀取檔案分別為data1,data2,data3
data1 <- read.csv("data2015.csv")
data2 <- read_excel("data2017.xlsx")
data3 <- read.delim("data2016.txt")

#合併三個data
data1and2 <- cbind(data1,data2)
Alldata <- cbind(data1and2,data3)

Alldata

#將居住城市區域刪除 
Alldata$CITY = NULL 
Alldata$DISTRICT = NULL
Alldata


#只取資料欄位當中的ID,SEX,AGE,ANNU_INCOME
Alldt <- Alldata[,c("ID","SEX","AGE","ANNU_INCOME")] 
Alldt


#篩選功能-> 年齡超過60歲且至少有一位小孩
name <- Alldata[ Alldata$CHILDREN > 0  & Alldata$AGE > 60, ] 
#只取資料欄位當中的ID,CHILDREN,SEX,AGE,ANNU_INCOME
name <- name[,c("ID","CHILDREN","SEX","AGE","ANNU_INCOME")] 
name

#付款方式
PAY <- "PAYBY"
Alldata[,PAY]

#新增欄位設定年齡區間(大於40,小於40)  如果AGE欄位年齡大於40印出"bigger than 40"
AGEgroup <- ifelse(Alldt$AGE > 40, "bigger than 40", "smaller than 40")
Alldt <- cbind(Alldt,AGEgroup)
Alldt

#將參數editable改為true 只要將滑鼠雙擊即可編輯數值
datatable(Alldt,editable = TRUE)

datatable(Alldt,colnames = c('序號','性別','年齡','收入', '年齡區間') )




