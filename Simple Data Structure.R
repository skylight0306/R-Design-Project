rm(list=ls())
#�b��Ƨ������ɦW�i��|���U�ؤ��P�榡���Ǹ�
#�o�Ө�ƪ��ت��N�O�N�L�̥����Τ@���P�@�خ榡
#�Ҧp: Ds�@�~10627149 , 10627149�u�{�ƾ� , DataFlow10627149
#�N�令 10627149_Ds�@�~ , 10627149_�u�{�ƾ� , 10627149_DataFlow
Set_StudentID <- function(file, StudentID){
  #�]�w�n�ק諸��Ƨ�
  setwd(file) 

  #��M�]�t�S�w�Ǹ����ɦW
  name <- list.files( pattern = StudentID , recursive =  TRUE ,include.dirs = TRUE)
  
  #�C�X�]�t�S�w�Ǹ����ɦW
  name 
  
  #�N�S�w�Ǹ��������R��
  file.rename( from = name , to = gsub(StudentID ,"" , name)   ) 
  
  #�ܦ��Τ@�榡  "�Ǹ�_�ɦW"
  paste0(StudentID,seq = "_", name)
  
}

#�I�s���
Set_StudentID( "�j�Ǹ��", "10627149" )