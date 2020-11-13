rm(list=ls())
#製作一個健康報告
#分別輸入(性別,身高(cm),體重(kg))
#性別女生為0   男生為1
Get_HealthReport <- function(sex, height, weight) {
  #透過資料運算出使用者最理想的體重
  #女生最理想體重計算公式為(身高-70)*60% = 理想體重
  if (sex == 0) { #女生
    weight_best <- ( height - 70) * 6 / 10
  }
  
  #男生最理想體重為(身高-80)*70% = 理想體重  
  else if ( sex == 1){ #男生
    weight_best <- ( height - 80) * 7 / 10
  }

  
  #計算bmi值 身高以cm表示
  height <- height / 100
  bmi <- weight / height**2
  
  if (bmi < 18.5) {
    bmi_label <- "偏瘦"
  } 
  else if (bmi >= 18.5 & bmi < 25) {
    bmi_label <- "正常"
  }
  else if (bmi >= 25 & bmi < 30) {
    bmi_label <- "偏胖"
  }
  else if (bmi >= 30 & bmi < 35) {
    bmi_label <- "肥胖"
  } 
  else if (bmi >= 35 & bmi < 40) {
    bmi_label <- "重度肥胖"
  } 
  else {
    bmi_label <- "極重度肥胖"
  }
  
  #製作健康表單  
  #分別列出使用者的bmi值,身體狀況,理想體重
  health_list <- list( bmi = bmi, label = bmi_label, Bestweight = weight_best )
  
  return(health_list)
}

#輸入名字 
#呼叫函數(性別,身高,體重)
name <- Get_HealthReport(1,180,65)
name$bmi
name$label
name$Bestweight


