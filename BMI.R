rm(list=ls())
#�s�@�@�Ӱ��d���i
#���O��J(�ʧO,����(cm),�魫(kg))
#�ʧO�k�ͬ�0   �k�ͬ�1
Get_HealthReport <- function(sex, height, weight) {
  #�z�L��ƹB��X�ϥΪ̳̲z�Q���魫
  #�k�ͳ̲z�Q�魫�p�⤽����(����-70)*60% = �z�Q�魫
  if (sex == 0) { #�k��
    weight_best <- ( height - 70) * 6 / 10
  }
  
  #�k�ͳ̲z�Q�魫��(����-80)*70% = �z�Q�魫  
  else if ( sex == 1){ #�k��
    weight_best <- ( height - 80) * 7 / 10
  }

  
  #�p��bmi�� �����Hcm����
  height <- height / 100
  bmi <- weight / height**2
  
  if (bmi < 18.5) {
    bmi_label <- "���G"
  } 
  else if (bmi >= 18.5 & bmi < 25) {
    bmi_label <- "���`"
  }
  else if (bmi >= 25 & bmi < 30) {
    bmi_label <- "���D"
  }
  else if (bmi >= 30 & bmi < 35) {
    bmi_label <- "�έD"
  } 
  else if (bmi >= 35 & bmi < 40) {
    bmi_label <- "���תέD"
  } 
  else {
    bmi_label <- "�����תέD"
  }
  
  #�s�@���d����  
  #���O�C�X�ϥΪ̪�bmi��,���骬�p,�z�Q�魫
  health_list <- list( bmi = bmi, label = bmi_label, Bestweight = weight_best )
  
  return(health_list)
}

#��J�W�r 
#�I�s���(�ʧO,����,�魫)
name <- Get_HealthReport(1,180,65)
name$bmi
name$label
name$Bestweight

