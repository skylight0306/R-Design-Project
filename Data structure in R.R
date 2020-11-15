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
library(readxl) #Ūexcel��
getwd()
dir()
setwd("R�{��")
dir()
#data2017 <- Data_type_change(data2017)
#Ū���ɮפ��O��data1,data2,data3
data1 <- read.csv("data2015.csv")
data2 <- read_excel("data2017.xlsx")
data3 <- read.delim("data2016.txt")

#�X�֤T��data
data1and2 <- cbind(data1,data2)
Alldata <- cbind(data1and2,data3)

Alldata

#�N�~�������ϰ�R�� 
Alldata$CITY = NULL 
Alldata$DISTRICT = NULL
Alldata


#�u�������������ID,SEX,AGE,ANNU_INCOME
Alldt <- Alldata[,c("ID","SEX","AGE","ANNU_INCOME")] 
Alldt


#�z��\��-> �~�ֶW�L60���B�ܤ֦��@��p��
name <- Alldata[ Alldata$CHILDREN > 0  & Alldata$AGE > 60, ] 
#�u�������������ID,CHILDREN,SEX,AGE,ANNU_INCOME
name <- name[,c("ID","CHILDREN","SEX","AGE","ANNU_INCOME")] 
name

#�I�ڤ覡
PAY <- "PAYBY"
Alldata[,PAY]

#�s�W���]�w�~�ְ϶�(�j��40,�p��40)  �p�GAGE���~�֤j��40�L�X"bigger than 40"
AGEgroup <- ifelse(Alldt$AGE > 40, "bigger than 40", "smaller than 40")
Alldt <- cbind(Alldt,AGEgroup)
Alldt

#�N�Ѽ�editable�אּtrue �u�n�N�ƹ������Y�i�s��ƭ�
datatable(Alldt,editable = TRUE)

datatable(Alldt,colnames = c('�Ǹ�','�ʧO','�~��','���J', '�~�ְ϶�') )



